#include <QXmlDefaultHandler>
#include <QDebug>

class SAXPhoneBookHandler : public QXmlDefaultHandler
{
public:
	SAXPhoneBookHandler();

	bool characters(const QString &str);
	bool endElement( const QString&, const QString&, const QString &);
	bool startElement( const QString&, const QString&, const QString &, const QXmlAttributes & );

private:
	QString itemText;
};
