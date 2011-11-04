#include "VoIPClientInfo.h"

VoIPClientInfo::VoIPClientInfo(int index) {
	mIndex = index;
}

int VoIPClientInfo::getIndex() const{
	return mIndex;
}

void VoIPClientInfo::setUsername(const QString& username) {
	mUsername = username;
}

const QString& VoIPClientInfo::getUsername() const {
	return mUsername;
}

void VoIPClientInfo::setRegistrar(const QString& registrar) {
	mRegistrar = registrar;
}

const QString& VoIPClientInfo::getRegistrar() const {
	return mRegistrar;
}

void VoIPClientInfo::setName(const QString& name) {
	mName = name;
}

const QString& VoIPClientInfo::getName() const {
	return mName;
}

void VoIPClientInfo::setOutgoingNumber(const QString& outgoingNumber) {
	mOutgoingNumber = outgoingNumber;
}

const QString& VoIPClientInfo::getOutgoingNumber() const {
	return mOutgoingNumber;
}

void VoIPClientInfo::setId(const QString& id) {
	mId = id;
}

const QString& VoIPClientInfo::getId() const{
	return mId;
}
