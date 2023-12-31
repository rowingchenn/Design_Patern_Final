// ConcreteStates.h
#include "OrderState.h"
#include <iostream>

// OrderedState 类，表示订单已下单状态
class OrderedState : public OrderState {
public:
    void handleRequest(Order *order) override;
    std::string getStateName() const override { return "已下单"; }
};

// PaidState 类，表示订单已支付状态
class PaidState : public OrderState {
public:
    void handleRequest(Order *order) override;
    std::string getStateName() const override { return "已支付"; }
};

// ShippedState 类，表示订单已发货状态
class ShippedState : public OrderState {
public:
    void handleRequest(Order *order) override;
    std::string getStateName() const override { return "已发货"; }
};

// CompletedState 类，表示订单已完成状态
class CompletedState : public OrderState {
public:
    void handleRequest(Order *order) override;
    std::string getStateName() const override { return "已完成"; }
};
