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

class WLANInfo {

	WLANInfo();

	int getIndex() const;
	void setIndex(int index);

	const QString& getMacAdress() const;
	void setMacAdress(const QString&);

	const QString& getIpAdress() const;
	void setIpAdress(const QString&);

	bool isAuthState() const;
	void setAuthState(bool);

	int getBandwidth() const;
	void setBandwidth(int);

	int getSignalStrength() const;
	void setSignalStrength(int);

	const QString& getSsid() const;
	void setSsid(const QString& ssid);

private:
	/*
	* NewAssociatedDeviceIndex In Int Index in der Liste (0 <= index < Anzahl)
	* NewAssociatedDeviceMACAddress Out QString MAC-Adresse des Gerätes
	* NewAssociatedDeviceIPAddress Out QString IP-Adresse des Gerätes
	* NewAssociatedDeviceAuthState Out Bool Gerät angemeldet NewX_AVM-DE_Speed
	* Out Int Datenrate (0 ... 300) NewX_AVM-DE_SignalStrength Out Int
	* Signalstärke (0 … 70)
	*/

	int mIndex;
	QString mMacAdress;
	QString mIpAdress;
	bool mAuthState;
	int mSpeed;
	int mSignalStrength;
	QString mSsid;
};
