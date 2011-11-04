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

class VoIPInfoEx {

public:
	VoIPInfoEx();

	void setPasswordMinChar(int);
	int getPasswordMinChar() const;

	void setPasswordMaxChar(int);
	int getPasswordMaxChar() const;

	void setPasswordAllowedChar(const QString&);
	const QString& getPasswordAllowedChar() const ;

private:
	/*
	* NewVoIPPasswordMinChars Out Int min. length of password
	* NewVoIPPasswordMaxChars Out Int max. length of password
	* NewVoIPPasswordAllowedChars Out QString chars allowed in passwords
	*/

	int mPasswordMinChar;
	int mPasswordMaxChar;
	QString mPasswordAllowedChar;
};
