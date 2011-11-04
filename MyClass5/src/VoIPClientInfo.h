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

class VoIPClientInfo {

	VoIPClientInfo(int);

	int getIndex() const;

	void setUsername(const QString&);
	const QString& getUsername() const;

	void setRegistrar(const QString&);
	const QString& getRegistrar() const;

	void setName(const QString&);
	const QString& getName() const;

	void setOutgoingNumber(const QString&);
	const QString& getOutgoingNumber() const;

	void setId(const QString& id);
	const QString& getId() const;

private:
	/*
	* NewX_AVM-DE_ClientIndex In Int index in list (0 <= index < count)
	* NewX_AVM-DE_ClientUsername Out QString user name
	* NewX_AVM-DE_ClientRegistrar Out QString registrar NewX_AVM-DE_PhoneName
	* Out QString user friendly name NewX_AVM-DE_OutGoingNumber Out QString
	* external phone number optional (extended, not supported by all box'
	* versions) NewX_AVM-DE_ClientId Out QString additional ID
	*/

	int mIndex;
	QString mUsername;
	QString mRegistrar;
	QString mName;
	QString mOutgoingNumber;
	QString mId;
};
