#include <QXmlDefaultHandler>
#include <QDebug>

class SAXCallLogHandler : public QXmlDefaultHandler
{
public:
	SAXCallLogHandler();

	bool characters(const QString &str);
	bool endElement( const QString&, const QString&, const QString &);
	bool startElement( const QString&, const QString&, const QString &, const QXmlAttributes & );

private:
	QString itemText;
};
