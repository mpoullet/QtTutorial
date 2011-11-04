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
#include <QDate>

#include "ContactNumber.h"

/* Represents a call in the calllist */
class Call
{
public:

	/**
	 * Instantiates a new call.
	 */
	Call();
	
	enum CALL_TYPE
	{
		MISSED, INCOMING, OUTGOING, UNSPECIFIED_CALL
	};

	enum EXTERN_PORT_TYPE
	{
		FIXEDLINE, SIP, MOBILE, UNSPECIFIED_PORT
	};

	static const char TAG_SEPARATOR;
	static const QString TAG_SIP;
	static const QString TAG_MOBILE;

	/**
	 * Gets the call type for key. Mapping from FRITZ!Box-key
	 * 
	 * @param aString
	 *            the a string
	 * 
	 * @return the call type for key
	 */
	static CALL_TYPE getCallTypeForKey(const QString&);

	void setCalledNumber(const QString&);
	const QString& getCalledNumber() const;

	void setCallerNumber(const QString&);
	const QString& getCallerNumber() const;

	const QDate& getTimeStamp() const;
	void setTimeStamp(const QDate&);

	const QString& getPartnerName() const;

	/**
	 * Gets the partner name or if that is empty the number.
	 * 
	 * @return the partner name if empty number
	 */
	const QString& getPartnerNameIfEmptyNumber() const;

	/**
	 * Checks if the partner name is empty.
	 * 
	 * @return true, if is partner name empty
	 */
	bool isPartnerNameEmpty() const;

	void setPartnerName(const QString&);

	CALL_TYPE getType() const;
	void setType(CALL_TYPE type);

	/**
	 * Gets the partner number.
	 * 
	 * @return the partner number
	 */
	const QString& getPartnerNumber() const;

	/**
	 * Gets the external port.
	 * Only available for outgoing calls
	 * 
	 * @return the external port or empty
	 */
	EXTERN_PORT_TYPE getExternPort() const;

	/**
	 * Gets the intern port.
	 * 
	 * @return the intern port
	 */
	const QString& getInternPort() const;

	/**
	 * Sets the intern port.
	 * 
	 * @param internPort
	 *            the new intern port
	 */
	void setInternPort(const QString&);

	/**
	 * Gets the intern number.
	 * 
	 * @return the intern number
	 */
	const QString& getInternNumber() const;

	/**
	 * Gets the duration.
	 * 
	 * @return the duration
	 */
	int getDuration() const;

	/**
	 * Sets the duration.
	 * 
	 * @param duration
	 *            the new duration
	 */
	void setDuration(int duration);

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
	 * Gets the count.
	 * 
	 * @return the count
	 */
	int getCount() const;

	/**
	 * Sets the count.
	 * 
	 * @param count
	 *            the new count
	 */
	void setCount(int count);

	/**
	 * Gets the number type.
	 * 
	 * @return the number type
	 */
	ContactNumber::NUMBER_TYPE getNumberType() const;

	/**
	 * Sets the number type.
	 * 
	 * @param numberType
	 *            the new number type
	 */
	void setNumberType(ContactNumber::NUMBER_TYPE);

private:
	CALL_TYPE mType;
	QDate mTimeStamp;
	QString mCalledNumber;
	QString mCallerNumber;
	QString mPartnerName;
	QString mInternPort;
	QString mId;
	int mCount;
	ContactNumber::NUMBER_TYPE mNumberType;
	int mDuration; // in minutes
};
