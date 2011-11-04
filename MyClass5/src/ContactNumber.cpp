#include "ContactNumber.h"

/**
* Instantiates a new contact number.
*/
ContactNumber::ContactNumber()
{
	mType = ContactNumber::OTHER;
	mIsMainNumber = false;
}

/**
* Gets the type.
*
* @return the type
*/
ContactNumber::NUMBER_TYPE ContactNumber::getType() const
{
	return mType;
}

/**
* Sets the type.
*
* @param type
*            the new type
*/
void ContactNumber::setType(NUMBER_TYPE type)
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
void ContactNumber::setType(const QString &type)
{
	mType = ContactNumber::OTHER;
	if (type.isEmpty()) {
		mCustomType.clear();
	} else {
		mCustomType = type;
	}
}

/**
* Checks if is hauptnummer.
*
* @return true, if is hauptnummer
*/
bool ContactNumber::isMainNumber() const
{
	return mIsMainNumber;
}

/**
* Sets the hauptnummer.
*
* @param isMainNumber
*            the new hauptnummer
*/
void ContactNumber::setMainNumber(bool isMainNumber)
{
	mIsMainNumber = isMainNumber;
}

/**
* Gets the plain number.
*
* @return the number
*/
const QString& ContactNumber::getNumberRaw() const
{
	return mNumber;
}

/**
* Gets the callable number.
*
* @return the number
*/
const QString& ContactNumber::getNumber() const
{
	return mNumber;
}

/**
* Sets the number.
*
* @param number
*            the new number
*/
void ContactNumber::setNumber(const QString& number)
{
	if (number.isEmpty()) {
		mNumber.clear();
	} else {
		mNumber = number;
	}
}

const QString& ContactNumber::getQuickdial() const
{
	return mQuickdial;
}

void ContactNumber::setQuickdial(const QString& quickdial)
{
	if (quickdial.isEmpty()) {
		mQuickdial.clear();
	} else {
		mQuickdial = quickdial;
	}
}

const QString& ContactNumber::getAddressDisplay() const
{
	return getNumberRaw();
}

const QString& ContactNumber::getAddress() const
{
	return getNumber();
}
