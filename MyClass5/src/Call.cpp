#include "Call.h"

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
	if (!called.isEmpty()) {
		mCalledNumber = called;
	}
}

const QString& Call::getCalledNumber() const
{
	return mCalledNumber;
}

void Call::setCallerNumber(const QString& caller)
{
	mCallerNumber = (caller.isNull()) ? "" : caller;
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
	if (isPartnerNameEmpty())
		return getPartnerNumber();
	return getPartnerName();
}

/**
* Checks if the partner name is empty.
* 
* @return true, if is partner name empty
*/
bool Call::isPartnerNameEmpty() const
{
	return getPartnerName().length() == 0;
}

void Call::setPartnerName(const QString& partnerName)
{
	mPartnerName = (partnerName.isNull()) ? "" : partnerName;
}

Call::CALL_TYPE Call::getType() const
{
	return mType;
}

void Call::setType(CALL_TYPE type)
{
	mType = (type.isNull()) ? Call::UNSPECIFIED : type;
}

/**
* Gets the partner number.
* 
* @return the partner number
*/
const QString& Call::getPartnerNumber() const
{
	switch(getType())
	{
	case OUTGOING:
		return mCalledNumber;

	case INCOMING:
	case MISSED:
		return mCallerNumber;
	}

	return "";
}

/**
* Gets the external port.
* Only available for outgoing calls
* 
* @return the external port or empty
*/
Call::EXTERN_PORT_TYPE Call::getExternPort() const
{
	QString number = NULL;
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

	if (number != NULL)
	{
		int separator = number.indexOf(Call::TAG_SEPARATOR);
		if (separator < 1) return Call::FIXEDLINE;

		if (number.substring(0, separator)
			.equalsIgnoreCase(Call::TAG_SIP))
			return Call::SIP;
		else if (number.substring(0, separator)
			.equalsIgnoreCase(Call::TAG_MOBILE))
			return Call::MOBILE;
	}

	return Call::UNSPECIFIED_CALL;
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
	mInternPort = (internPort.isNull()) ? "" : internPort;
}

/**
* Gets the intern number.
* 
* @return the intern number
*/
const QString& Call::getInternNumber() const
{
	QString number = NULL;
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

	if (number != NULL)
	{
		int separator = number.indexOf(Call::TAG_SEPARATOR);
		if (separator < 0) return number;
		return number.substring(separator + 1).trim();
	}
	return "";
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
	mId = (id.isNull()) ? "" : id;
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
void Call::setNumberType(ContactNumber.NUMBER_TYPE numberType)
{
	mNumberType = (numberType.isNull()) ?
		ContactNumber.NUMBER_TYPE.OTHER : numberType;
}

/**
* Gibt Zeit und Datum des Anrufes "schön" formatiert zurück. Format:
* <VollesDatum_MonatAlsText> <Uhrzeit_StundeMinute>
* 
* @param c
*            a valid context
* 
* @return the pretty date full
*/
const QString& Call::getPrettyDateFull() const
{
	return DateFormat.getMediumDateFormat(c).format(getTimeStamp()) + " "
		+ DateFormat.getTimeFormat(c).format(getTimeStamp());
}

/**
* Gets user friendly formatted call duration
* 
* @param c
*            a valid context
* @return the pretty duration string
*/
const QString& Call::getPrettyDuration() const
{
	return QString.format(c.getQString(R.string.call_log_duration_fmt),
		getDuration());
}

/**
* Gets user friendly formatted call count
* (to be used for getCount()>1)
* 
* @param c
*            a valid context
* @return the pretty count string
*/
const QString& Call::getPrettyCount() const
{
	return QString.format(c.getQString(R.string.call_log_count_fmt),
		getCount());
}


bool Call::equals(QObject o)
{
	if (o != NULL) return hashCode() == o.hashCode();
	return false;
}


int Call::hashCode()
{
	int result = 17;
	result = 31 * result + mType.hashCode();
	result = 31 * result + mTimeStamp.hashCode();
	result = 31 * result + mCalledNumber.hashCode();
	result = 31 * result + mCallerNumber.hashCode();
	result = 31 * result + mInternPort.hashCode();
	result = 31 * result + mCount;
	result = 31 * result + mId.hashCode();
	return result;
}

