#include "order.h"
#include "OrderInterface.h"
#include <iomanip>
#include <iostream>

using namespace std;

//新建一个订单
void OrderInterface::CreateOrder(int customerID, map<CommodityInformation *, int> Items, float price) {
    Order *p = new Order(customerID, Items, price);
    orderlist.push_back(p);
}

//根据id删除一个订单
void OrderInterface::RemoveOrder(string orderno)//从订单列表中移除订单
{
    vector<Order*>::iterator it;
    for (it = orderlist.begin(); it != orderlist.end(); ++it) {
        if ((*it)->getID() == orderno) {
            orderlist.erase(it);
            return;
        }
    }
}

//在list里加一个订单
void OrderInterface::AddOrder(Order *order) {
    orderlist.push_back(order);
}



//支付某一订单
void OrderInterface::pay() {
    int paidOrderNum = 0;
    for (auto _order:orderlist) {
        if (_order->getPayState() == 1) {
            _order->pay();
            paidOrderNum++;
        } else
            continue;
    }
    printf("支付成功，共支付了%d笔订单\n", paidOrderNum);
}

//根据用户id展示所有订单
void OrderInterface::display(int id)
{
    CommodityInformationReader reader;
    cout << "您的订单列表包含的订单有: " << endl;
    for (auto order : this->orderlist) {
        if (order->getcustomerid() == id) {
            cout << "起始" << endl;
            cout << "订单号: " << order->getID() << endl;
            for (auto item : order->getItems()) {
                reader.setCommodityInformation(item.first);
                cout << "商品名: " << reader.getName() << endl;
                cout << "商品ID: " << reader.getID() << endl;
                cout << "数量: " << item.second << endl;
            }
            order->Request();
            cout << "结束" << endl;
        }
    }
}

//根据用户id展示所有未支付订单
void OrderInterface::displayUnpaid(int id) {
    CommodityInformationReader reader;
    for (auto order:orderlist) {
        if (order->getcustomerid() == id && order->getPayState() == 1) {
            cout << "起始" << endl;
            cout << "订单号: " << order->getID() << endl;
            for (auto item:order->getItems()) {
                reader.setCommodityInformation(item.first);
                cout << "商品名称: " << reader.getName() << endl;
                cout << "商品ID: " << reader.getID() << endl;
                cout << "数量: " << item.second << endl;
            }
            order->Request();
            cout << "结束" << endl;
        } else continue;
    }

}

//选择操作
void OrderInterface::MainInterface(Customer *customer) {
    int choice_status, ID;
    showUserOrderCmds showUserOrderCmds;
    VirtualCustomerInformationReader *reader = new VirtualCustomerInformationReader(customer->getInfo());
    while (true) {
        showUserOrderCmds.showUserCmds();
        cin >> choice_status;
        if (choice_status == 0)
            break;
        switch (choice_status) {
            case 1: {
                cout << "进行中的订单列表如下: " << endl;
                display(reader->getID());
                break;
            }
            case 2: {
                pay();
                break;
            }
            case 3: {
                cout << "您的订单列表如下: " << endl;
                display(reader->getID());
                break;
            }
            default:
                cout << "输入错误，请重新输入！" << endl;
                break;
        }
    }
}

