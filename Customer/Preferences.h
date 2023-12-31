// Preferences.h
#ifndef PREFERENCES_H
#define PREFERENCES_H

#include "ICloneable.h"
#include <vector>
#include <string>
#include<iostream>
using namespace std;

// 用户偏好设置类
class Preferences : public ICloneable {
private:
    vector<string> settings; // 存储用户偏好设置

public:
    Preferences();
    Preferences(const vector<string>& settings);

    // 实现 ICloneable 接口的克隆方法
    ICloneable* clone() const override;

    // 打印偏好设置的方法
    void printPreferences() const;
};

#endif // PREFERENCES_H
