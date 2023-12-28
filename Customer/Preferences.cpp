// Preferences.cpp
#include "Preferences.h"
#include <iostream>
using namespace std;

Preferences::Preferences() {}

Preferences::Preferences(const vector<string>& settings) : settings(settings) {}

// 克隆方法的实现
ICloneable* Preferences::clone() const {
    return new Preferences(*this);
}

// 打印用户偏好设置
void Preferences::printPreferences() const {
    for (const auto& setting : settings) {
        cout << setting << endl;
    }
}
