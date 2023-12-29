#pragma once

using namespace std;

#ifndef SOFTWAREARC_SHOPMANAGER_H
#define SOFTWAREARC_SHOPMANAGER_H

#include <iostream>
#include <list>
#include <utility>
#include <string>
#include "shop.h"
#include "shopFilter.h"
#include "../Welcome/welcome.h"
#include "../Customer/Customer.h"
#include "../Commodity/Commodity.h"

/* 抽象工厂模式（Abstract Factory Pattern）
 提供了一种方式来创建一系列相关或依赖对象的家族，而无需指定具体的类。
 在抽象工厂模式中，抽象工厂作为所有工厂的基类，负责定义创建对象的接口，而具体的工厂则派生自抽象工厂，实现了创建具体对象的方法。

 抽象工厂模式通过将具体的类实例化操作委托给工厂类，使得客户端代码与具体类解耦。
 客户端只需要与抽象工厂及其创建接口进行交互，而不需要直接调用具体的类。
 这样，当需要更换具体实现时，只需要更改具体工厂的实例，而不需要修改客户端代码。

 抽象工厂是比工厂更高级的存在，从面向对象的角度来说工厂继承了抽象工厂，是抽象工厂的派生子类和具体实现。

 所以抽象工厂设置为所有工厂的基类，获取对象的函数声明为虚函数，具体使用工厂时从抽象工厂中派生。
*/
class AbstractFactory {
public:
    virtual Shop *createShop(string type) = 0;
};
/* 工厂模式（Factory Pattern）
 用于根据特定的条件或参数创建对象。它通过将对象的创建逻辑封装在一个工厂类中，使得客户端代码与具体对象的实例化过程解耦。
 在工厂模式中，通常会定义一个抽象工厂接口或基类，其中包含用于创建对象的方法。
 具体的工厂类会实现这个接口或继承这个基类，并根据不同的条件或参数来实例化对应的对象。
 该工厂只有一个函数，参数为店铺的类型，根据用户提供的类型来生产对应的店铺对象。
 可以根据不同的店铺类型，通过调用工厂的函数来获取相应的店铺对象。

 工厂模式的优点是可以隐藏实例化对象的具体过程，使得客户端代码更加简洁和可读。
*/
class ShopFactory : public AbstractFactory {
public:
    Shop *createShop(string type);
};
/*
 * 店铺子系统和整体系统进行耦合的接口类
 * 里面有对子系统内操作所用的临时数据，以及对上述临时数据进行操作的方法。
 * 详细介绍将在内部进行。
 */
class shopInterface {

private:
    // 店铺列表、货物列表、用来生产的工厂
    list<Shop *> _shopList;
    map<CommodityInformation *, int> _commodityList;
    ShopFactory _shopFactory; // Factory Mode. In order to create some shops by users or admins.

public:
    //获取所有货物列表
    map<CommodityInformation *, int> &getCommodityList() { return _commodityList; }

    //展示所有货物列表
    void showCommodityList(map<CommodityInformation *, int> List);

    //更新指定货物列表
    void setCommodityList(const map<CommodityInformation *, int> &commodityList) { _commodityList = commodityList; }

    //获取所有店铺列表
    const list<Shop *> &getShopList() const { return _shopList; };

    //展示所有店铺
    void showAllShops();

    //生产店铺
    Shop *createShop(string type);

    // 用户为指定ID的店铺添加评价
    void addRemark(int, Customer *customer);

    // 查看指定ID店铺的详细信息
    void checkShop(int ID);

    // 初始化接口类中的相关信息
    void initialize();

    // 展示给用户以进行操作的主界面
    void mainInterface(Customer *customer);

    // 根据店铺评分筛选店铺
    void filterShopByScore();

    // 将货物列表按所属商店ID同步到对应商店
    void prepareGoods(int ID);

    // 展示所有商店的所有货物
    void showAllGoodsInShops();

    // 查看指定ID商店中的所有货物
    void checkGoods(int ID);

    // 将指定ID的商品加入购物车
    CommodityInformation *addCart(int ID);
};
/*
 * 原型模式 Prototype
 */
class shopCache{
private:
    map<Shop*,int> _shopMap; //  原型模式所需的商店数据缓存库
public:
    Shop* cloneShop(int shopID);//  根据ID获取数据缓存库中的店铺
    void loadCache();// 预先设置缓存的函数
};
#endif //SOFTWAREARC_SHOPMANAGER_H