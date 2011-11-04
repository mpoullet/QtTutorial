#include "Call.h"

const char Call::TAG_SEPARATOR = ':';
const QString Call::TAG_SIP = "SIP";
const QString Call::TAG_MOBILE = "Mobilfunk";

/**
* Instantiates a new call.
*/
Call::Call() {
	mType = Call::UNSPECIFIED_CALL;
	mCount = 0;
	mNumberType = ContactNumber::OTHER;
	mDuration = 0; // in minutes
}

/**
* Gets the call type for key. Mapping from FRITZ!Box-key
* 
* @param aQString
*            the a string
* 
* @return the call type for key
*/
Call::CALL_TYPE Call::getCallTypeForKey(const QString& aQString)
{
	switch (aQString.toInt())
	{
	case 1: return Call::INCOMING;
	case 2: return Call::MISSED;
	case 3: return Call::OUTGOING;
	default:
		return Call::UNSPECIFIED_CALL;
	}
}

void Call::setCalledNumber(const QString& called)
{
	if (called.isEmpty()) {
		mCalledNumber.clear();
	} else {
		mCalledNumber = called;
	}
}

const QString& Call::getCalledNumber() const
{
	return mCalledNumber;
}

void Call::setCallerNumber(const QString& caller)
{
	if (caller.isEmpty()) {
		mCallerNumber.clear();
	} else {
		mCallerNumber = caller;
	}
}

const QString& Call::getCallerNumber() const
{
	return mCallerNumber;
}

const QDate& Call::getTimeStamp() const
{
	return mTimeStamp;
}

void Call::setTimeStamp(const QDate& date)
{
	if (date.isValid()) {
		mTimeStamp = date;
	}
}

const QString& Call::getPartnerName() const
{
	return mPartnerName;
}

/**
* Gets the partner name or if that is empty the number.
* 
* @return the partner name if empty number
*/
const QString& Call::getPartnerNameIfEmptyNumber() const
{
	if (isPartnerNameEmpty()) {
		return getPartnerNumber();
	} else {
		return getPartnerName();
	}
}

/**
* Checks if the partner name is empty.
* 
* @return true, if is partner name empty
*/
bool Call::isPartnerNameEmpty() const
{
	return getPartnerName().isEmpty();
}

void Call::setPartnerName(const QString& partnerName)
{
	if (partnerName.isEmpty()) {
		mPartnerName.clear();
	} else {
		mPartnerName = partnerName;
	}
}

Call::CALL_TYPE Call::getType() const
{
	return mType;
}

void Call::setType(CALL_TYPE type)
{
	if (type >= Call::MISSED && type <= Call::UNSPECIFIED_CALL) {
		mType = type;
	} else {
		mType = Call::UNSPECIFIED_CALL;
	}
}

/**
* Gets the partner number.
* 
* @return the partner number
*/
const QString& Call::getPartnerNumber() const
{
	// TODO: find a better workaround
	static const QString null;

	switch(getType())
	{
	case OUTGOING:
		return mCalledNumber;

	case INCOMING:
	case MISSED:
		return mCallerNumber;
	}

	return null;
}

/**
* Gets the external port.
* Only available for outgoing calls
* 
* @return the external port or empty
*/
Call::EXTERN_PORT_TYPE Call::getExternPort() const
{
	QString number;
	switch(getType())
	{
	case OUTGOING:
		number = mCallerNumber;
		break;

	case INCOMING:
	case MISSED:
		number = mCalledNumber;
		break;
	}

	if (!number.isEmpty())
	{
		int separator = number.indexOf(Call::TAG_SEPARATOR);
		if (separator < 1) return Call::FIXEDLINE;

		if (number.mid(0, separator)
			.compare(Call::TAG_SIP, Qt::CaseInsensitive))
			return Call::SIP;
		else if (number.mid(0, separator)
			.compare(Call::TAG_MOBILE, Qt::CaseInsensitive))
			return Call::MOBILE;
	}

	return Call::UNSPECIFIED_PORT;
}

/**
* Gets the intern port.
* 
* @return the intern port
*/
const QString& Call::getInternPort() const
{
	return mInternPort;
}

/**
* Sets the intern port.
* 
* @param internPort
*            the new intern port
*/
void Call::setInternPort(const QString& internPort)
{
	if (internPort.isEmpty()) {
		mInternPort.clear();
	} else {
		mInternPort = internPort;
	}
}

/**
* Gets the intern number.
* 
* @return the intern number
*/
const QString& Call::getInternNumber() const
{
	// TODO: find a better workaround
	static const QString null;

	QString number;
	switch(getType())
	{
	case OUTGOING:
		number = mCallerNumber;
		break;

	case INCOMING:
	case MISSED:
		number = mCalledNumber;
		break;
	}

	if (!number.isEmpty())
	{
		int separator = number.indexOf(Call::TAG_SEPARATOR);
		if (separator < 0) return number;
		return number.left(separator + 1).trimmed();
	}
	return null;
}

/**
* Gets the duration.
* 
* @return the duration
*/
int Call::getDuration() const
{
	return mDuration;
}

/**
* Sets the duration.
* 
* @param duration
*            the new duration
*/
void Call::setDuration(int duration)
{
	mDuration = (duration < 0) ? 0 : duration;
}

/**
* Gets the id.
* 
* @return the id
*/
const QString& Call::getId() const
{
	return mId;
}

/**
* Sets the id.
* 
* @param id
*            the new id
*/
void Call::setId(const QString& id)
{
	if (id.isEmpty()) {
		mId.clear();
	} else {
		mId = id;
	}
}

/**
* Gets the count.
* 
* @return the count
*/
int Call::getCount() const
{
	return mCount;
}

/**
* Sets the count.
* 
* @param count
*            the new count
*/
void Call::setCount(int count)
{
	mCount = (count < 0) ? 0 : count;
}

/**
* Gets the number type.
* 
* @return the number type
*/
ContactNumber::NUMBER_TYPE Call::getNumberType() const
{
	return mNumberType;
}

/**
* Sets the number type.
* 
* @param numberType
*            the new number type
*/
void Call::setNumberType(ContactNumber::NUMBER_TYPE numberType)
{
	if ((numberType >= ContactNumber::HOME) && (numberType <= ContactNumber::OTHER)) {
		mNumberType = numberType;
	} else {
		mNumberType = ContactNumber::OTHER;
	}
}
