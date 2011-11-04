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

class TamInfo {

public:
	/*
	* NewIndex In Int index in list (0 <= index < count) NewName Out String
	* user friendly name NewEnable Out Boolean is TAM enabled?
	*/
	TamInfo(int);

	int getIndex() const;

	const QString& getName() const;
	void setName(const QString&);

	bool isEnable() const;
	void setEnable(bool);

	bool isDisplay() const;
	void setDisplay(bool );

private:
	int mIndex;
	QString mName;
	bool mEnable;
	bool mDisplay;
};
