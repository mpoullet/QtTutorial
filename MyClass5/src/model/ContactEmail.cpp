#include "ContactEmail.h"

/**
* Instantiates a new contact email.
*/
ContactEmail::ContactEmail()
{
	mType = ContactEmail::OTHER;
}

/**
* Sets the type.
*
* @param type
*            the new type
*/
void ContactEmail::setType(EMAIL_TYPE type)
{
	mType = type;
	mCustomType.clear();
}

/**
* Sets the type to custom type.
*
* @param type
*            the custom type
*/
void ContactEmail::setType(const QString& type)
{
	mType = ContactEmail::OTHER;
	if (type.isEmpty()) {
		mCustomType.clear();
	} else {
		mCustomType = type;
	}
}

/**
* Gets the email address.
*
* @return the email address
*/
const QString& ContactEmail::getEmail() const
{
	return mEmail;
}

/**
* Sets the email address.
*
* @param email
*            the new email address
*/
void ContactEmail::setEmail(const QString& email)
{
	if (email.isEmpty()) {
		mEmail.clear();
	} else {
		mEmail = email;
	}
}
