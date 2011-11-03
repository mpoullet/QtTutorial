#pragma once

#include <QtGui/QWidget>
#include <QtSoapHttpTransport>
#include <QAuthenticator>
#include <QNetworkReply>
#include <QNetworkProxy>
#include <QList>
#include <QSslError>
#include <QCheckBox>
#include <QTreeWidget>

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
		void getSslErrors(QNetworkReply*, QList<QSslError>);
		void getProxyAuthentication(QNetworkProxy, QAuthenticator*);

private:
	static const QString host;
	QtSoapHttpTransport http;

	QLineEdit *portString;
	QCheckBox *useSSL;
	QLineEdit *namespaceString;
	QLineEdit *soapMethodString;
	QLineEdit *controlURLString;
	QTextBrowser *resultView;
	QPushButton *quitButton;
	QPushButton *requestButton;
	QTreeWidget *treeWidget;
};
