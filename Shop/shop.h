#pragma once

#ifndef SOFTWAREARC_SHOP_H
#define SOFTWAREARC_SHOP_H

#include <iostream>
#include <list>
#include <string>
#include <map>
#include "../Commodity/Commodity.h"

using namespace std;

//这个头文件主要说明了和店铺有关的一切属性和方法。

class Visitor;//声明使用访问者模式
class ShopRemark;//声明使用商家评论类

/*
 * 商家评论类
 * 属性：评价日期、评价用户、评价内容、评价分数
 * 该类为商家评论的构造类，在店铺类的实际使用过程中会用到，其会根据评论分数和的平均值来参与过滤器模式，故予以介绍。
 */
class ShopRemark {
private:
    // 评论日期、评论用户、评论内容、评价分数
    string _remarkDate;
    string _remarkUser;
    string _remarkBody;
    double _remarkScore;
public:

    //构造函数，里面的参数为上述4个属性
    ShopRemark(const string &remarkDate, const string &remarkUser, const string &remarkBody, double remarkScore)
            : _remarkDate(remarkDate), _remarkUser(remarkUser), _remarkBody(remarkBody), _remarkScore(remarkScore) {}

    //获取评论日期
    const string &getRemarkDate() const {
        return _remarkDate;
    }

    //获取评论用户
    const string &getRemarkUser() const {
        return _remarkUser;
    }

    //获取评论内容
    const string &getRemarkBody() const {
        return _remarkBody;
    }

    //获取评论分数
    double getRemarkScore() const {
        return _remarkScore;
    }

};

/*
 * 店铺类
 * 介绍：为店铺的基类，内含各种属性和等待模板方法Template Method实现的虚函数
 * 函数：
 *      各个属性的getters and setters
 *      店铺类的构造函数
 * 虚函数将在派生类中具体说明。
 */
class Shop {
private:
    // 店铺的各个属性
    string _shopName;
    int _shopID;
    string _shopType;
    string _shopDate;
    int _shopStorage;
    double _shopScore;
    list<ShopRemark *> _shopRemarks;
    map<CommodityInformation *, int> _itemList;

public:
    // 店铺中要用到的方法
    //展示信息
    void showShopInformation();

    //visitor模式的accept函数
    virtual void accept(Visitor &v) = 0;

    //基类构造函数
    Shop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
         double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation *, int> &itemList)
            : _shopName(
            shopName), _shopID(shopId), _shopType(shopType), _shopDate(shopDate), _shopStorage(shopStorage), _shopScore(
            shopScore), _shopRemarks(shopRemarks), _itemList(itemList) {}

            // 获取店铺名称
    const string &getShopName() const {
        return _shopName;
    }
    //获取店铺ID
    int getShopId() const {
        return _shopID;
    }

    // 获取店铺类型
    const string &getShopType() const {
        return _shopType;
    }

    // 获取店铺日期
    const string &getShopDate() const {
        return _shopDate;
    }

    // 获取店铺库存
    int getShopStorage() const {
        return _shopStorage;
    }

    // 获取店铺评论
    const list<ShopRemark *> &getShopRemarks() const {
        return _shopRemarks;
    }

    // 设置店铺名称
    void setShopName(const string &shopName) {
        _shopName = shopName;
    }

    // 设置店铺ID
    void setShopId(int shopId) {
        _shopID = shopId;
    }

    // 设置店铺类型
    void setShopType(const string &shopType) {
        _shopType = shopType;
    }

    // 设置店铺日期
    void setShopDate(const string &shopDate) {
        _shopDate = shopDate;
    }

    // 设置店铺库存
    void setShopStorage(int shopStorage) {
        _shopStorage = shopStorage;
    }

    // 添加评论
    void
    addShopRemarks(const string &remarkDate, const string &remarkUser, const string &remarkBody, double remarkScore) {
        _shopRemarks.push_back(new ShopRemark(remarkDate, remarkUser, remarkBody, remarkScore));
    }

    // 获取商品目录
    const map<CommodityInformation *, int> &getItemList() const {
        return _itemList;
    }

    // 设置商品目录
    void setItemList(const map<CommodityInformation *, int> &itemList) {
        _itemList = itemList;
    }

    //获取店铺评分
    double getTotalRemarkScore() const {
        double totalScore = 0.00;
        for (auto _remark:_shopRemarks) {
            totalScore = totalScore + _remark->getRemarkScore();
        }
        int len = _shopRemarks.size();
        if (_shopRemarks.empty())
            return 0.00;
        else
            return totalScore / len;
    }

    // 设置店铺评分
    void setRemarkScore(double shopScore) {
        _shopScore = shopScore;
    }
};

/*
 * 以下为访问者模式 Visitor Pattern
 * 通过访问者模式，可以在不改变对象结构的前提下，对对象中的元素进行新的操作。
 */

//抽象访问者
class Visitor {
public:
    virtual void visit(Shop *shop) = 0;
};

//具体访问者，展示店铺信息
class infoVisitor : public Visitor {
public:
    void visit(Shop *shop) {
        shop->showShopInformation();
    }
};

//具体访问者，展示过滤后的店铺信息
class filterVisitor : public Visitor {
public:
    void visit(Shop *shop) {
        cout << shop->getShopId() << " - 店铺名称: " << shop->getShopName() << endl;
    }
};

/*
  以下为模板方法 Template Method
  是一种行为型设计模式，用于定义一个算法的骨架，将算法中的某些步骤延迟到子类中实现。
  它通过将不变的部分封装在父类中，将可变的部分留给子类来实现，从而实现代码的复用和扩展。
  子类仅会根据用户所输入的信息来从Shop基类派生
  所有派生的子类均在下文中进行声明，在实际进行使用的时候会根据类型来生成店铺。
  每个子类包含3个函数：
       showShopInformation(): 输出店铺的详细信息
       accept(): 与访问者模式Visitor共同使用，用来执行参数为Visitor时其中的调用函数
       构造函数：生成对应的派生子类
  店铺类型: restaurant, drinks, digital, books, grocery, furniture, clothes, stationery, sportss, null.
 */
// restaurant Shop子类与构造函数
class restaurantShop : public Shop {
public:
    void accept(Visitor &v);

    restaurantShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
             double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation *, int> &itemList);
};

// clothesShop子类与构造函数
class clothesShop : public Shop {
public:
    void accept(Visitor &v);

    clothesShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                double shopScore, const list<ShopRemark *> &shopRemarks,
                const map<CommodityInformation *, int> &itemList);
};

// drinksShop子类与构造函数
class drinksShop : public Shop {
public:
    void accept(Visitor &v);

    drinksShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
              double shopScore, const list<ShopRemark *> &shopRemarks,
              const map<CommodityInformation *, int> &itemList);
};

// digitalShop子类与构造函数
class digitalShop : public Shop {
public:

    void accept(Visitor &v);

    digitalShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                double shopScore, const list<ShopRemark *> &shopRemarks,
                const map<CommodityInformation *, int> &itemList);
};

// booksShop子类与构造函数
class booksShop : public Shop {
public:

    void accept(Visitor &v);

    booksShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
             double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation *, int> &itemList);
};

// groceryShop子类与构造函数
class groceryShop : public Shop {
public:

    void accept(Visitor &v);

    groceryShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
              double shopScore, const list<ShopRemark *> &shopRemarks,
              const map<CommodityInformation *, int> &itemList);
};

// furnitureShop子类与构造函数
class furnitureShop : public Shop {
public:

    void accept(Visitor &v);

    furnitureShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                  double shopScore, const list<ShopRemark *> &shopRemarks,
                  const map<CommodityInformation *, int> &itemList);
};

// stationery子类与构造函数
class stationeryShop : public Shop {
public:

    void accept(Visitor &v);

    stationeryShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                   double shopScore, const list<ShopRemark *> &shopRemarks,
                   const map<CommodityInformation *, int> &itemList);
};

// sportsShop子类与构造函数
class sportsShop : public Shop {
public:

    void accept(Visitor &v);

    sportsShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
              double shopScore, const list<ShopRemark *> &shopRemarks,
              const map<CommodityInformation *, int> &itemList);
};

/* 设计模式-空项目模式 Null Object Mode
 主要思想是在程序中使用一个“空对象”来替代空值。
 通过使用空对象模式，程序可以在处理空值时不会出现异常或错误，并且可以保持程序的健壮性和功能完整性。
 当程序检测到参数为空或null时，可以创建一个空对象并将其作为参数传递给函数，空对象中的值都是没有意义的值，
 但程序可以按照生成对象的标准化来处理。
 使用空对象模式的好处在于，它可以减少代码中的if-else语句，使代码更加简洁和易于维护。
 同时，它还可以让程序更加灵活，因为空对象可以模拟任何其他对象，从而使程序更容易扩展和修改。
 在函数运行中预先对参数为空或null做判断，如果为真则也生成一个对象，但是对象中的值都是没有意义的值。而非给用户只输出错误信息。
  这样做无论什么情况都可以按照生成对象的标准化来处理。
  */
// nullShop与构造函数
class nullShop : public Shop {
public:

    void accept(Visitor &v);

    nullShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
             double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation *, int> &itemList);
};

/*
 * 设计模式-代理模式 Proxy Mode
 * 通过创建一个代理对象来控制对原始对象的访问。
 * 对代理对象进行的操作可以等效于直接对被代理对象进行操作。
 */
//代理对象
class proxyShop : public Shop {
private:
    Shop *shop;
public:
    proxyShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
              double shopScore, const list<ShopRemark *> &shopRemarks, 
              const map<CommodityInformation *, int> &itemList,
              Shop *shop);

    void accept(Visitor &v);

    //展示商店
    void display();
};

// 商店装饰器基类
class shopDecorator : public Shop {
protected:
    Shop *decoratedShop;
public:
    virtual void accept(Visitor &v);

    shopDecorator(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                  double shopScore, const list<ShopRemark *> &shopRemarks,
                  const map<CommodityInformation *, int> &itemList, Shop *decoratedShop);
};

// 商店装饰器基类的子类 - 修改评论分数
class AddStarShopDecorator : public shopDecorator {
public:

    void accept(Visitor &v);

    void execute() {
        decoratedShop->setRemarkScore(10.00);
    }

    AddStarShopDecorator(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                         int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                         const map<CommodityInformation *, int> &itemList, Shop *decoratedShop);
};

#endif //SOFTWAREARC_SHOP_H