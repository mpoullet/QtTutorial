#include <QtGui>
#include <QDebug>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>

#include "MyClass.h"

void printMyClass(const MyClass &m) {
	qDebug() << "Value: " << m.getText() << "; Length : " << m.getLengthOfText();
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget widget;
	QLineEdit *lineEdit = new QLineEdit;
	QTextEdit *textResponse = new QTextEdit;
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget( lineEdit );
	layout->addWidget( textResponse );
	widget.setLayout( layout );
	MyClass *bridge = new MyClass( "", &app );

	QObject::connect(
		lineEdit, SIGNAL(textChanged(const QString&)),
		bridge, SLOT(setText(const QString&)) );
	QObject::connect(
		bridge, SIGNAL(textChanged(const QString&)),
		textResponse, SLOT(setText(const QString&)) );

	widget.show();
	return app.exec();
}
