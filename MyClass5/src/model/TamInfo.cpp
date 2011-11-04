#include "TamInfo.h"

TamInfo::TamInfo(int index) {
	mIndex = index;
	mEnable = false;
	mDisplay = false;
}

int TamInfo::getIndex() const {
	return mIndex;
}

const QString& TamInfo::getName() const {
	return mName;
}

void TamInfo::setName(const QString& name) {
	mName = name;
}

bool TamInfo::isEnable() const {
	return mEnable;
}

void TamInfo::setEnable(bool enable) {
	mEnable = enable;
}

bool TamInfo::isDisplay() const {
	return mDisplay;
}

void TamInfo::setDisplay(bool display) {
	mDisplay = display;
}
