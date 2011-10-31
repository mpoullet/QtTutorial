#pragma once

#include <QObject>
#include <string>

using std::string;

class MyClass : public QObject
{
public:
	MyClass( const string& text, QObject *parent = 0 );
	const string& getText() const;
	void setText( const string& text );
	int getLengthOfText() const;

	~MyClass();

private:
	string m_text;
};
