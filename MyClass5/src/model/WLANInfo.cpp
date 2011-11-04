#include "WLANInfo.h"

WLANInfo::WLANInfo() {
	mIndex = -1;
	mAuthState = false;
	mSpeed = 0;
	mSignalStrength = 0;
}

int WLANInfo::getIndex() const {
	return mIndex;
}

void WLANInfo::setIndex(int index) {
	mIndex = index;
}

const QString& WLANInfo::getMacAdress() const {
	return mMacAdress;
}

void WLANInfo::setMacAdress(const QString& macAdress) {
	mMacAdress = macAdress;
}

const QString& WLANInfo::getIpAdress() const {
	return mIpAdress;
}

void WLANInfo::setIpAdress(const QString& ipAdress) {
	mIpAdress = ipAdress;
}

bool WLANInfo::isAuthState() const {
	return mAuthState;
}

void WLANInfo::setAuthState(bool authState) {
	mAuthState = authState;
}

int WLANInfo::getBandwidth() const {
	return mSpeed;
}

void WLANInfo::setBandwidth(int bandwidth) {
	mSpeed = bandwidth;
}

int WLANInfo::getSignalStrength() const {
	return mSignalStrength;
}

void WLANInfo::setSignalStrength(int signalStrength) {
	mSignalStrength = signalStrength;
}

const QString& WLANInfo::getSsid() const {
	return mSsid;
}

void WLANInfo::setSsid(const QString& ssid) {
	mSsid = ssid;
}
