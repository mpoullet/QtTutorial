#include <iostream>
#include <QtCore/QCoreApplication>
#include "MyClass.h"

void printMyClass(const MyClass &m) {
	std::cout << "Value: " << m.getText() << "; Length : " << m.getLengthOfText() << std::endl;
}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	MyClass *a, *b, *c;

	a = new MyClass( "foo", &app );
	b = new MyClass( "ba-a-ar", &app );
	c = new MyClass( "baz", &app );

	printMyClass(*a);
	a->setText( b->getText() );
	printMyClass(*a);

	int result = a->getLengthOfText() - c->getLengthOfText();
	std::cout << "res: " << result << std::endl;

	return 0;
}
