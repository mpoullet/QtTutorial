#include "ContactNumber.h"

/**
* Instantiates a new contact number.
*/
ContactNumber::ContactNumber()
{
	mType = ContactNumber::NUMBER_TYPE.OTHER;
	mIsHauptnummer = false;
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
	mCustomType = "";
}

/**
* Sets the type to custom type.
*
* @param type
*            the custom type
*/
void ContactNumber::setType(const QString &type)
{
	mType = ContactNumber::NUMBER_TYPE.OTHER;
	mCustomType = (type == NULL) ? "" : type;
}

/**
* Checks if is hauptnummer.
*
* @return true, if is hauptnummer
*/
bool ContactNumber::isHauptnummer() const
{
	return mIsHauptnummer;
}

/**
* Sets the hauptnummer.
*
* @param isHauptnummer
*            the new hauptnummer
*/
void ContactNumber::setHauptnummer(bool isHauptnummer)
{
	mIsHauptnummer = isHauptnummer;
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
	if (mNumber.indexOf("@") >= 0)
	{
		// for SIP address as number return internal shortcut number
		QString quickdial = getQuickdial();
		switch (quickdial.length())
		{
		case 1: return "**70" + quickdial;
		case 2: return "**7" + quickdial;
		}
		return "";
	}

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
	mNumber = (number == NULL) ? "" : number;
}

const QString& ContactNumber::getQuickdial() const
{
	return mQuickdial;
}

void ContactNumber::setQuickdial(const QString& quickdial)
{
	mQuickdial = (quickdial == NULL) ? "" : quickdial;
}

const QString& ContactNumber::getAddressDisplay() const
{
	return getNumberRaw();
}

const QString& ContactNumber::getAddress() const
{
	return getNumber();
}
