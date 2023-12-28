// Order.h
#include "OrderState.h"

// Order 类，表示一个订单
class Order {
private:
    OrderState *state; // 当前状态

public:
    Order() : state(nullptr) {}
    ~Order() { delete state; }

    // 设置订单的当前状态
    void setState(OrderState *state) {
        delete this->state;
        this->state = state;
    }

    // 转移到下一个状态
    void nextState() {
        if (state) {
            state->handleRequest(this);
        }
    }

    // 获取当前状态的名称
    std::string getStateName() const {
        return state ? state->getStateName() : "No State";
    }
    
};
