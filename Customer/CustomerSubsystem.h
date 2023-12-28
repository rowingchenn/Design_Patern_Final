#ifndef CUSTOMER_SUBSYSTEM_H
#define CUSTOMER_SUBSYSTEM_H


#include"CustomerBuilder.h"

// 这里定义运行顾客子系统需要的函数

// UI
// 菜单
void showMenu();
// 原型模式
void showPrototype();
// 状态模式
void showState();
// 工厂模式
void showPayment();
// 备忘录模式
void Case_Momento(Customer* customer);
// 观察者模式
void Case_Observer(Customer* customer);

// 子系统运行函数
void runCustomerSubsystem();

#endif // CUSTOMER_SUBSYSTEM_H
