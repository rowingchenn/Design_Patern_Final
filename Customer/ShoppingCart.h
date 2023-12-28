// ShoppingCart.h
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ICloneable.h"
#include <vector>
#include <string>
#include<iostream>
using namespace std;

// 购物车类
class ShoppingCart : public ICloneable {
private:
    vector<string> items; // 存储购物车中的商品

public:
    ShoppingCart();
    ShoppingCart(const vector<string>& items);

    // 实现 ICloneable 接口的克隆方法
    ICloneable* clone() const override;

    // 打印购物车内容的方法
    void printShoppingCart() const;
};

#endif // SHOPPINGCART_H
