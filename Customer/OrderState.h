#ifndef ORDER_STATE_H  // 头文件保护开始
#define ORDER_STATE_H

#include<iostream>
using namespace std;

class Order;

class OrderState {
public:
    virtual ~OrderState() {}

    // 纯虚函数
    virtual void handleRequest(Order *order) = 0;

    // 获取当前状态的名称
    virtual string getStateName() const = 0;
};

#endif // ORDER_STATE_H  // 头文件保护结束
