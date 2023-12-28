// ConcreteStates.cpp
#include<iostream>
#include "ConcreteStates.h"
#include "Order.h"

// 下单状态下的行为实现
void OrderedState::handleRequest(Order *order) {
    cout << "Setting state to Paid"<<endl;
    order->setState(new PaidState());
}

// 支付 状态下的行为实现
void PaidState::handleRequest(Order *order) {
    cout << "Setting state to Shipped"<<endl;
    order->setState(new ShippedState());
}

// 发货 状态下的行为实现
void ShippedState::handleRequest(Order *order) {
    cout << "Setting state to Completed"<<endl;
    order->setState(new CompletedState());
}

// 完成 状态下的行为实现
void CompletedState::handleRequest(Order *order) {
    cout << "Order is already in completed state"<<endl;
}
