#include "SAXPhoneBookHandler.h"

SAXPhoneBookHandler::SAXPhoneBookHandler()
{
}

bool SAXPhoneBookHandler::characters(const QString &str) 
{
	qDebug() << __FUNCTION__ << ": " << str;

	itemText = str;
	return true;
}

bool SAXPhoneBookHandler::startElement( const QString&, const QString&, const QString &qName, const QXmlAttributes &attributes )
{
	qDebug() << __FUNCTION__ << ": " << qName;

	return true;
}

bool SAXPhoneBookHandler::endElement( const QString&, const QString&, const QString &qName )
{
	qDebug() << __FUNCTION__ << ": " << qName;

	return true;
}
