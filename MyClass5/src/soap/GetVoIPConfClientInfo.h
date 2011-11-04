#include <QXmlDefaultHandler>
#include <QTreeWidget>
#include <QDebug>

class GetVoIPConfClientInfo : public QXmlDefaultHandler
{
public:
	GetVoIPConfClientInfo(QTreeWidget *);

	bool characters(const QString &str);
	bool endElement( const QString&, const QString&, const QString &);
	bool startElement( const QString&, const QString&, const QString &, const QXmlAttributes & );

private:
	QTreeWidget *treeWidget;
	QTreeWidgetItem *item;
	QString itemText;
};
