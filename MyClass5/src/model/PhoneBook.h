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

#include "Contact.h"

class PhoneBook {

public:
	/**
	* Instantiates a new phone book.
	*/
	PhoneBook();

	/**
	* Destroys a phone book.
	*/
	~PhoneBook();

	/**
	* Instantiates a new phone book.
	*
	* @param xmlStream
	*            the xml stream
	*/
	PhoneBook(const QString&);

	/**
	* Adds the contact.
	*
	* @param contact
	*            the contact
	*/
	void addContact(const Contact&);

	/**
	* Gets the contacts.
	*
	* @return the contacts
	*/
	const QList<Contact>& getContacts() const;

	/**
	* Gets the id.
	*
	* @return the id
	*/
	const QString& getId() const;

	/**
	* Sets the id.
	*
	* @param id
	*            the new id
	*/
	void setId(const QString&);

	/**
	* Gets the name.
	*
	* @return the name
	*/
	const QString& getName() const;

	/**
	* Sets the name.
	*
	* @param name
	*            the new name
	*/
	void setName(const QString& name);

private:
	QString mId;
	QString mName;
	QList<Contact> *mContacts;
};
