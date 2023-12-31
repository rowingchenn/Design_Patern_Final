#include <iostream>
#include <ctime>
#include <unordered_map>
#include "order.h"
#include<vector>

using namespace std;

//订单类
//用户、状态、时间等等
Order::Order(int customerID, map<CommodityInformation *, int> Items, float price) : Customerid(customerID),items(Items), Price(price) {
    time_t t = time(0);
    char ch[64];
    strftime(ch, sizeof(ch), "%Y%m%d%H%M%S", localtime(&t));
    orderid.assign(ch + 2);
    State *pStateA = new ConcreteStateA();
    m_pState = new ConcreteStateA();
}

//支付，实际上就是修改订单状态
void Order::pay()
{
    //如果是未支付
    if (m_pState->value() == 1) {
        State* pStateB = new ConcreteStateB();
        m_pState = pStateB;
        cout << "成功支付" << endl;
        //如果已支付，提示勿重复支付
    }
    else {
        cout << "已成功支付，请勿重复支付。";
    }
}

//打印订单状态
void Order::Request()
{
    if (m_pState!=NULL) {
        m_pState->Handle(this);
    }
}



