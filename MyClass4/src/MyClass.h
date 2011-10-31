#pragma once

#include <QObject>
#include <QString>

class MyClass : public QObject
{
	Q_OBJECT
public:
	MyClass( const QString& text, QObject *parent = 0 );
	const QString& getText() const;
	int getLengthOfText() const;

	~MyClass();

	public slots:
		void setText( const QString& text );
	signals:
		void textChanged( const QString& );

private:
	QString m_text;
};
