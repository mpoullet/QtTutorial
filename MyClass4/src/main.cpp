#include <QtGui>
#include <QDebug>
#include <Qlabel>
#include <QLineEdit>
#include <QVBoxLayout>

#include <QtSoapHttpTransport>
#include <QtSoapMessage>

#include "MyClass.h"

void printMyClass(const MyClass &m) {
	qDebug() << "Value: " << m.getText() << "; Length : " << m.getLengthOfText();
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget widget;
	QLineEdit *lineEdit = new QLineEdit;
	QLabel *label = new QLabel;
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget( lineEdit );
	layout->addWidget( label );
	widget.setLayout( layout );
	MyClass *bridge = new MyClass( "", &app );

	QObject::connect(
		lineEdit, SIGNAL(textChanged(const QString&)),
		bridge, SLOT(setText(const QString&)) );
	QObject::connect(
		bridge, SIGNAL(textChanged(const QString&)),
		label, SLOT(setText(const QString&)) );
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
	request.setMethod(QtSoapQName("u:GetSecurityPort", "urn:dslforum-org:service:DeviceInfo:1"));
	
	QtSoapHttpTransport http = new QtSoapHttpTransport(&app);
	http.setAction("urn:dslforum-org:service:DeviceInfo:1#GetSecurityPort");
	http.setHost("192.168.178.1", false, 49000);
	// Control URL
	http.submitRequest(request, "/upnp/control/deviceinfo");

	widget.show();
	return app.exec();
}
