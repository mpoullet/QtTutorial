#include <QDebug>
#include "MyClass.h"

MyClass::MyClass( const QString &text, QObject *parent ) : QObject( parent )
{
	m_text = text;
}

MyClass::~MyClass() {
	qDebug() << "Deleting MyClass Object: " << m_text;
}

const QString &MyClass::getText() const {
	return m_text;
}

void MyClass::setText( const QString &text ) {
	if( m_text == text )
		return;
	m_text = text;
	emit textChanged( m_text );
}

int MyClass::getLengthOfText() const {
	return m_text.size();
}
