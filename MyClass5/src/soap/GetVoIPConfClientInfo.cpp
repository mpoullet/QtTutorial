#include "GetVoIPConfClientInfo.h"

GetVoIPConfClientInfo::GetVoIPConfClientInfo(QTreeWidget *treeWidget)
{
	this->treeWidget = treeWidget;
	item = NULL;
}

bool GetVoIPConfClientInfo::characters(const QString &str) {
	itemText = str;
	return true;
}

bool GetVoIPConfClientInfo::startElement( const QString&, const QString&, const QString &qName, const QXmlAttributes &attributes )
{
	qDebug() << __FUNCTION__ << ": " << qName;

	for( int i=0; i<attributes.count(); i++ )
	{
		qDebug() << "attribute: " << attributes.localName( i );
	}

	if (qName == "NewX_AVM-DE_ClientUsername") {
		item = new QTreeWidgetItem;
		treeWidget->addTopLevelItem(item);
		item->setText(0, "Username");
	}
	else if (qName == "NewX_AVM-DE_ClientRegistrar") {
		item = new QTreeWidgetItem;
		treeWidget->addTopLevelItem(item);
		item->setText(0, "Registrar");
	}
	else if (qName == "NewX_AVM-DE_PhoneName") {
		item = new QTreeWidgetItem;
		treeWidget->addTopLevelItem(item);
		item->setText(0, "Phone");
	}
	else if (qName == "NewX_AVM-DE_ClientId") {
		item = new QTreeWidgetItem;
		treeWidget->addTopLevelItem(item);
		item->setText(0, "Id");
	}
	else if (qName == "NewX_AVM-DE_OutGoingNumber") {
		item = new QTreeWidgetItem;
		treeWidget->addTopLevelItem(item);
		item->setText(0, "OutGoingNumber");
	}

	return true;
}

bool GetVoIPConfClientInfo::endElement( const QString&, const QString&, const QString &qName )
{
	qDebug() << __FUNCTION__ << ": " << qName;

	if (qName == "NewX_AVM-DE_ClientUsername") {
		item->setText(1, itemText);
		item->setTextAlignment(1, Qt::AlignLeft);
	}
	else if (qName == "NewX_AVM-DE_ClientRegistrar") {
		item->setText(1, itemText);
		item->setTextAlignment(1, Qt::AlignLeft);
	}
	else if (qName == "NewX_AVM-DE_PhoneName") {
		item->setText(1, itemText);
		item->setTextAlignment(1, Qt::AlignLeft);
	}
	else if (qName == "NewX_AVM-DE_ClientId") {
		if (itemText.isEmpty())
			item->setText(1, "");
		else item->setText(1, itemText);
		item->setTextAlignment(1, Qt::AlignLeft);
	}
	else if (qName == "NewX_AVM-DE_OutGoingNumber") {
		item->setText(1, itemText);
		item->setTextAlignment(1, Qt::AlignLeft);
	}

	return true;
}

