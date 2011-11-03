/* 
* Copyright 2011 by AVM GmbH <info@avm.de>
*
* This software contains free software; you can redistribute it and/or modify 
* it under the terms of the GNU General Public License ("License") as 
* published by the Free Software Foundation  (version 3 of the License). 
* This software is distributed in the hope that it will be useful, but 
* WITHOUT ANY WARRANTY; without even the implied warranty of 
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the copy of the 
* License you received along with this software for more details.
*/

#pragma once

#include <QString>

class ContactNumber {

public:

	enum NUMBER_TYPE
	{
		HOME, MOBILE, WORK, INTERN, OTHER
	};

	/**
	* Instantiates a new contact number.
	*/
	ContactNumber();

	/**
	* Gets the type.
	*
	* @return the type
	*/
	NUMBER_TYPE getType() const;

	/**
	* Sets the type.
	*
	* @param type
	*            the new type
	*/
	void setType(NUMBER_TYPE type);

	/**
	* Sets the type to custom type.
	*
	* @param type
	*            the custom type
	*/
	void setType(const QString&);

	/**
	* Checks if is hauptnummer.
	*
	* @return true, if is hauptnummer
	*/
	bool isHauptnummer() const;

	/**
	* Sets the hauptnummer.
	*
	* @param isHauptnummer
	*            the new hauptnummer
	*/
	void setHauptnummer(bool);

	/**
	* Gets the plain number.
	*
	* @return the number
	*/
	const QString& getNumberRaw() const;

	/**
	* Gets the callable number.
	*
	* @return the number
	*/
	const QString& getNumber() const;

	/**
	* Sets the number.
	*
	* @param number
	*            the new number
	*/
	void setNumber(const QString&);

	const QString& getQuickdial() const;
	void setQuickdial(const QString&);

	const QString& getAddressDisplay() const;

	const QString& getAddress() const;

private:
	NUMBER_TYPE mType;
	QString mCustomType;
	bool mIsHauptnummer;
	QString mNumber;
	QString mQuickdial;
};
