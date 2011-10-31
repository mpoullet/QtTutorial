#include <QtCore/QCoreApplication>
#include <QDebug>
#include <qtsoap.h>

#include "MyClass.h"

void printMyClass(const MyClass &m) {
	qDebug() << "Value: " << m.getText() << "; Length : " << m.getLengthOfText();
}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	MyClass *a, *b, *c;

	a = new MyClass( "foo", &app );
	b = new MyClass( "bar", &app );
	c = new MyClass( "baz", &app );

	printMyClass(*a);
	printMyClass(*b);
	printMyClass(*c);

	QObject::connect(
		a, SIGNAL(textChanged(const QString&)),
		b, SLOT(setText(const QString&)) );
	QObject::connect(
		b, SIGNAL(textChanged(const QString&)),
		c, SLOT(setText(const QString&)) );
	QObject::connect(
		c, SIGNAL(textChanged(const QString&)),
		b, SLOT(setText(const QString&)) );

	b->setText("test");

	printMyClass(*a);
	printMyClass(*b);
	printMyClass(*c);

	a->setText("Qt");

	printMyClass(*a);
	printMyClass(*b);
	printMyClass(*c);

	QtSoapHttpTransport http = new QtSoapHttpTransport(&app);

	return 0;
}
