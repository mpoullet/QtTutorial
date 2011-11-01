#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include <QtGui/QCursor>
#include <QtCore/QFile>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextBrowser>
#include <QtGui/QLayout>
#include <QtGui/QPushButton>

#include "SoapWidget.h"

SoapWidget::SoapWidget(QWidget *parent)
	: QWidget(parent), http(this)
{
	// Generate the GUI.
	quitButton = new QPushButton("&Quit", this);
	portString = new QLineEdit(this);
	useSSL = new QCheckBox(this);
	namespaceString = new QLineEdit(this);
	soapMethodString = new QLineEdit(this);
	controlURLString = new QLineEdit(this);

	resultView = new QTextBrowser(this);
	QVBoxLayout *layout = new QVBoxLayout(this);

	QLabel *nLabel = new QLabel("Namespace: ", this);
	QPushButton *searchButton = new QPushButton("Request!", this);
	QHBoxLayout *nBar = new QHBoxLayout();
	nBar->addWidget(nLabel);
	nBar->addWidget(namespaceString);
	nBar->addWidget(searchButton);
	layout->addLayout(nBar);

	QLabel *mLabel = new QLabel("Method: ", this);
	QHBoxLayout *mBar = new QHBoxLayout();
	mBar->addWidget(mLabel);
	mBar->addWidget(soapMethodString);
	layout->addLayout(mBar);

	QLabel *cLabel = new QLabel("Control URL: ", this);
	QHBoxLayout *cBar = new QHBoxLayout();
	cBar->addWidget(cLabel);
	cBar->addWidget(controlURLString);
	layout->addLayout(cBar);

	QLabel *tLabel = new QLabel("Port: ", this);
	QHBoxLayout *tBar = new QHBoxLayout();
	tBar->addWidget(tLabel);
	tBar->addWidget(portString);
	tBar->addWidget(useSSL);
	layout->addLayout(tBar);

	layout->addWidget(resultView);
	layout->addWidget(quitButton);

	// Connect signals to slots. Note the submitRequest() slots.
	connect(&http, SIGNAL(responseReady()), SLOT(getResponse()));
	connect(quitButton, SIGNAL(clicked()), SLOT(close()));
	connect(controlURLString, SIGNAL(returnPressed()), SLOT(submitRequest()));
	connect(searchButton, SIGNAL(clicked()), SLOT(submitRequest()));
	connect(http.networkAccessManager(), SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)), SLOT(getAuthentication(QNetworkReply*,QAuthenticator*)));

	// Pressing enter should trigger a search, unless focus has been
	// explicitly moved.
	searchButton->setDefault(true);

	// Default request
	namespaceString->setText("urn:dslforum-org:service:DeviceInfo:1");
	soapMethodString->setText("GetSecurityPort");
	controlURLString->setText("/upnp/control/deviceinfo");
	portString->setText("49000");
	useSSL->setChecked(false);

	//namespaceString->setText("urn:dslforum-org:service:WLANConfiguration:1");
	//soapMethodString->setText("GetGenericAssociatedDeviceInfo");
	//controlURLString->setText("/upnp/control/wlanconfig1");
}

void SoapWidget::submitRequest()
{
	// Check that we have a search string.
	if ((namespaceString->text() == "") || (soapMethodString->text() == "") || (controlURLString->text() == "")) {
		QMessageBox::warning(this, tr("Missing control URL string"),
			tr("Please enter a control URL string."));
		return;
	}

	// Prepare to submit request.

	/*
	FRITZ!App Fon 7 Request:
	<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/" s:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
	<s:Body>
	<u:GetSecurityPort xmlns:u="urn:dslforum-org:service:DeviceInfo:1">
	</u:GetSecurityPort>
	</s:Body>
	</s:Envelope>

	Qt SOAP Request:
	<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/" SOAP-ENV:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/" xmlns:xsd="http://www.w3.org/1999/XMLSchema">
	<SOAP-ENV:Body xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/">
	<u:GetSecurityPort xmlns="urn:dslforum-org:service:DeviceInfo:1"/>
	</SOAP-ENV:Body>
	</SOAP-ENV:Envelope>
	*/
	QtSoapMessage request;
	QString soapMethod = "u:" + soapMethodString->text();
	request.setMethod(QtSoapQName(soapMethod, namespaceString->text()));

	QString soapAction = namespaceString->text() + "#" + soapMethodString->text();
	http.setAction(soapAction);
	http.setHost("192.168.178.1", useSSL->isChecked(), portString->text().toInt());
	http.submitRequest(request, controlURLString->text());

	// Set the cursor to wait mode.
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
}

void SoapWidget::getResponse()
{
	// Set cursor back to normal shape.
	QApplication::restoreOverrideCursor();

	// Reset resultView.
	resultView->clear();

	// Get the response, check for error.
	const QtSoapMessage &resp = http.getResponse();
	if (resp.isFault()) {
		resultView->setHtml(tr("<b>Request failed</b>: ")
			+ resp.faultString().value().toString());
		return;
	}

	// Extract the return value from this method response, check for
	// errors.
	const QtSoapType &res = resp.returnValue();
	if (!res.isValid()) {
		resultView->append(tr("Invalid return value"));
		return;
	}

	// Update the resultView.
	resultView->setHtml(resp.toXmlString());
}

void SoapWidget::getAuthentication(QNetworkReply *reply, QAuthenticator *ator)
{
    resultView->setText(reply->readAll());
    ator->setUser(QString("avm"));
    ator->setPassword(QString("avmavm"));
}
