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
#include <QList>

#include "ContactEmail.h"
#include "ContactNumber.h"

class Contact {

public:
	/**
	* Instantiates a new contact.
	*/
	Contact();

	/**
	* Destructs a contact.
	*/
	~Contact();

	/**
	* Adds the number.
	*
	* @param cn
	*            the cn
	*/
	void addNumber(const ContactNumber&);

	/**
	* Gets the contact numbers.
	*
	* @return the contact numbers
	*/
	const QList<ContactNumber>& getContactNumbers() const;

	/**
	* Adds the email address.
	*
	* @param email
	*            the email
	*/
	void addEmail(const ContactEmail&);

	/**
	* Gets the contact email addresses.
	*
	* @return the contact email addresses
	*/
	const QList<ContactEmail>& getContactEmails() const;

	/**
	* Gets the category.
	*
	* @return the category
	*/
	int getCategory() const;

	/**
	* Sets the category.
	*
	* @param category
	*            the new category
	*/
	void setCategory(int);

	/**
	* Gets the real name.
	*
	* @return the real name
	*/
	const QString& getRealName() const;

	/**
	* Sets the real name.
	*
	* @param realName
	*            the new real name
	*/
	void setRealName(const QString&);

	/**
	* Gets the Hauptnummer or an other preferred number.
	*
	* @return the number
	*/
	ContactNumber getMainNumber() const;

private:
	static const int CATEGORY_WICHTIG = 1;

	int mCategory;
	QString mRealName;
	QList<ContactNumber> *mNumbers;
	QList<ContactEmail> *mEmails;
};
