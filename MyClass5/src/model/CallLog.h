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

#include "Call.h"

class CallLog {

public:
	/**
	* Instantiates a new call log.
	*/
	CallLog();

	/**
	* Instantiates a new call log.
	*
	* @param xmlStream
	*            the xml stream
	*/
	CallLog(const QString&);

	/**
	* Gets the calls.
	*
	* @return the calls
	*/
	const QList<Call>& getCalls() const;

	/**
	* Adds the call.
	*
	* @param call
	*            the call
	*/
	void addCall(const Call&);

private:
	QList<Call> *calls;
};
