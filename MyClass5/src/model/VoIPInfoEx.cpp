#include "VoIPInfoEx.h"

VoIPInfoEx::VoIPInfoEx() {
	mPasswordMinChar = 3;
	mPasswordMaxChar = 64;
}

void VoIPInfoEx::setPasswordMinChar(int min) {
	mPasswordMinChar = min;
}

int VoIPInfoEx::getPasswordMinChar() const {
	return mPasswordMinChar;
}

void VoIPInfoEx::setPasswordMaxChar(int max) {
	mPasswordMaxChar = max;
}

int VoIPInfoEx::getPasswordMaxChar() const {
	return mPasswordMaxChar;
}

void VoIPInfoEx::setPasswordAllowedChar(const QString& allowed) {
	mPasswordAllowedChar = allowed;
}

const QString& VoIPInfoEx::getPasswordAllowedChar() const {
	return mPasswordAllowedChar;
}
