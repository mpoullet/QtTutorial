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

class ContactEmail {

public:
	enum EMAIL_TYPE
	{
		PRIVATE, BUSINESS, OTHER
	};

	/**
	* Instantiates a new contact email.
	*/
	ContactEmail();

	/**
	* Sets the type.
	*
	* @param type
	*            the new type
	*/
	void setType(EMAIL_TYPE);

	/**
	* Sets the type to custom type.
	*
	* @param type
	*            the custom type
	*/
	void setType(const QString&);

	/**
	* Gets the email address.
	*
	* @return the email address
	*/
	const QString& getEmail() const;

	/**
	* Sets the email address.
	*
	* @param email
	*            the new email address
	*/
	void setEmail(const QString&);

private:
	EMAIL_TYPE mType;
	QString mCustomType;
	QString mEmail;
};
