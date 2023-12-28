// ShoppingCart.cpp
#include "ShoppingCart.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart() {}

ShoppingCart::ShoppingCart(const vector<string>& items) : items(items) {}

// 克隆方法的实现
ICloneable* ShoppingCart::clone() const {
    return new ShoppingCart(*this);
}

// 打印购物车内容
void ShoppingCart::printShoppingCart() const {
    for (const auto& item : items) {
        cout << item << endl;
    }
}
