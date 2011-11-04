#include "SAXCallLogHandler.h"

SAXCallLogHandler::SAXCallLogHandler()
{
}

bool SAXCallLogHandler::characters(const QString &str) 
{
	qDebug() << __FUNCTION__ << ": " << str;

	itemText = str;
	return true;
}

bool SAXCallLogHandler::startElement( const QString&, const QString&, const QString &qName, const QXmlAttributes &attributes )
{
	qDebug() << __FUNCTION__ << ": " << qName;

	return true;
}

bool SAXCallLogHandler::endElement( const QString&, const QString&, const QString &qName )
{
	qDebug() << __FUNCTION__ << ": " << qName;

	return true;
}
