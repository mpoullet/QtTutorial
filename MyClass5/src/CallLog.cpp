#include "CallLog.h"
#include "SAXCallLogHandler.h"

#include <QXmlSimpleReader>
#include <QXmlInputSource>

/**
* Instantiates a new call log.
*/
CallLog::CallLog() {
	calls = new QList<Call>;
}

/**
* Instantiates a new call log.
*
* @param xmlStream
*            the xml stream
*/
CallLog::CallLog(const QString& xmlStream) {
	calls = new QList<Call>;

	QXmlSimpleReader xmlReader;
	QXmlInputSource *source = new QXmlInputSource;
	source->setData(xmlStream);

	SAXCallLogHandler *handler = new SAXCallLogHandler();
	xmlReader.setContentHandler(handler);
	xmlReader.setErrorHandler(handler);

	if (!(xmlReader.parse(source))) 
		qDebug() << "XML Parsing of " << xmlStream << " failed.";
}

/**
* Gets the calls.
*
* @return the calls
*/
const QList<Call>& CallLog::getCalls() const {
	return *calls;
}

/**
* Adds the call.
*
* @param call
*            the call
*/
void CallLog::addCall(const Call& call) {
	*calls << call;
}
