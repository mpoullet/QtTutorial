#pragma once

#include <QtGui/QWidget>
#include <QtSoapHttpTransport>
#include <QAuthenticator>
#include <QNetworkReply>
#include <QCheckBox>

class QLineEdit;
class QTextBrowser;
class QPushButton;

class SoapWidget : public QWidget
{
	Q_OBJECT
public:
	SoapWidget(QWidget *parent = 0);

private slots:
	void submitRequest();
	void getResponse();
	void getAuthentication(QNetworkReply*, QAuthenticator*);

private:
	QtSoapHttpTransport http;

	QLineEdit *portString;
	QCheckBox *useSSL;
	QLineEdit *namespaceString;
	QLineEdit *soapMethodString;
	QLineEdit *controlURLString;
	QTextBrowser *resultView;
	QPushButton *quitButton;
	QPushButton *requestButton;
};
