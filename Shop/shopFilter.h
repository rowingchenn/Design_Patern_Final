#ifndef TEST_SHOPFILTER_H
#define TEST_SHOPFILTER_H

#include<iostream>
#include<list>
#include "shop.h"

/*
 * 设计模式：过滤器模式
 * 评分标准为：
 *      若score>=7.5, 将之加入高分过滤器的列表中；
 *      若5<=score<7.5，将之加入中分过滤器的列表中；
 *      若2.5<=score<5，将之加入低分过滤器的列表中
 */

//抽象过滤器
class ShopFilter {
public:
    virtual list<Shop *> selectShop(list<Shop *> ShopList) = 0;
};

//三个具体过滤器
class HighShopFilter:public ShopFilter{
public:
    list<Shop *> selectShop(list<Shop *> ShopList);
};

class MidShopFilter:public ShopFilter{
public:
    list<Shop *> selectShop(list<Shop *> ShopList);
};

class LowShopFilter:public ShopFilter{
public:
    list<Shop *> selectShop(list<Shop *> ShopList);
};
#endif 
