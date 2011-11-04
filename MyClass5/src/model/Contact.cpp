#include "Contact.h"

/**
* Instantiates a new contact.
*/
Contact::Contact() {
	mCategory = 0;
	mNumbers = new QList<ContactNumber>;
	mEmails = new QList<ContactEmail>;
}

/**
* Instantiates a new contact.
*/
Contact::~Contact() {
	delete mNumbers;
	delete mEmails;
}

/**
* Adds the number.
*
* @param cn
*            the cn
*/
void Contact::addNumber(const ContactNumber& cn) {
	*mNumbers << cn;
}

/**
* Gets the contact numbers.
*
* @return the contact numbers
*/
const QList<ContactNumber>& Contact::getContactNumbers() const {
	return *mNumbers;
}

/**
* Adds the email address.
*
* @param email
*            the email
*/
void Contact::addEmail(const ContactEmail& email) {
	*mEmails << email;
}

/**
* Gets the contact email addresses.
*
* @return the contact email addresses
*/
const QList<ContactEmail>& Contact::getContactEmails() const {
	return *mEmails;
}

/**
* Gets the category.
*
* @return the category
*/
int Contact::getCategory() const {
	return mCategory;
}

/**
* Sets the category.
*
* @param category
*            the new category
*/
void Contact::setCategory(int category) {
	mCategory = category;
}

/**
* Gets the real name.
*
* @return the real name
*/
const QString& Contact::getRealName() const {
	return mRealName;
}

/**
* Sets the real name.
*
* @param realName
*            the new real name
*/
void Contact::setRealName(const QString& realName) {
	if (realName.isEmpty()) {
		mRealName.clear();
	} else {
		mRealName = realName;
	}
}

/**
* Gets the Hauptnummer or an other preferred number.
*
* @return the number
*/
ContactNumber Contact::getMainNumber() const {
	// return number with main property
	// if no main number available, choose one in order of NUMBER_TYPE
	ContactNumber firstNumber;
	foreach (ContactNumber cn, *mNumbers) {
		if (cn.isMainNumber()) {
			return cn;
		} else if (firstNumber.getType() > cn.getType()) {
			firstNumber = cn;
		}
	}

	return firstNumber;
}
