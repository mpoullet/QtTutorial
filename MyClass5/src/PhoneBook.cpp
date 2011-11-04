#include "PhoneBook.h"
#include "SAXPhoneBookHandler.h"

#include <QXmlSimpleReader>
#include <QXmlInputSource>

/**
* Instantiates a new phone book.
*/
PhoneBook::PhoneBook() {
	mContacts = new QList<Contact>;
}

/**
* Destroys a phone book.
*/
PhoneBook::~PhoneBook() {
	delete mContacts;
}

/**
* Instantiates a new phone book.
*
* @param xmlStream
*            the xml stream
*/
PhoneBook::PhoneBook(const QString& xmlStream) {
	mContacts = new QList<Contact>;

	QXmlSimpleReader xmlReader;
	QXmlInputSource *source = new QXmlInputSource;
	source->setData(xmlStream);

	SAXPhoneBookHandler *handler = new SAXPhoneBookHandler();
	xmlReader.setContentHandler(handler);
	xmlReader.setErrorHandler(handler);

	if (!(xmlReader.parse(source))) 
		qDebug() << "XML Parsing of " << xmlStream << " failed.";
}

/**
* Adds the contact.
*
* @param contact
*            the contact
*/
void PhoneBook::addContact(const Contact& contact) {
	*mContacts << contact;
}

/**
* Gets the contacts.
*
* @return the contacts
*/
const QList<Contact>& PhoneBook::getContacts() const {
	return *mContacts;
}

/**
* Gets the id.
*
* @return the id
*/
const QString& PhoneBook::getId() const {
	return mId;
}

/**
* Sets the id.
*
* @param id
*            the new id
*/
void PhoneBook::setId(const QString& id) {
	mId = id;
}

/**
* Gets the name.
*
* @return the name
*/
const QString& PhoneBook::getName() const {
	return mName;
}

/**
* Sets the name.
*
* @param name
*            the new name
*/
void PhoneBook::setName(const QString& name) {
	mName = name;
}
