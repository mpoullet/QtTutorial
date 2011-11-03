#include <QtGui>
#include <QDebug>
#include <Qlabel>
#include <QLineEdit>
#include <QVBoxLayout>

#include "SoapWidget.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	SoapWidget soapWidget;

	soapWidget.show();
	return app.exec();
}
