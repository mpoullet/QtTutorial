#include <iostream>
#include "MyClass.h"

MyClass::MyClass( const string &text, QObject *parent ) : QObject( parent )
{
	m_text = text;
}

MyClass::~MyClass() {
	std::cout << "Deleting MyClass Object: " << m_text << std::endl;
}

const string &MyClass::getText() const {
	return m_text;
}

void MyClass::setText( const string &text ) {
	m_text = text;
}

int MyClass::getLengthOfText() const {
	return m_text.size();
}
