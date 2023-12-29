#include "shop.h"

// 店铺类成员函数：展示店铺的详细信息
void Shop::showShopInformation() {
    cout << "店铺ID: " << _shopID << endl;
    cout << "店铺名称: " + _shopName << endl;
    cout << "开店日期: " + _shopDate << endl;
    cout << "店铺库存: " << _shopStorage << endl;
    cout << "店铺评分: " << this->getTotalRemarkScore() << endl;
    cout << "--以下是评价--" << endl;
    for (ShopRemark *shopRemark:_shopRemarks) {
        cout << "*" << endl;
        cout << "评价日期: " << shopRemark->getRemarkDate() << endl;
        cout << "评价用户: " << shopRemark->getRemarkUser() << endl;
        cout << "评价内容: " << shopRemark->getRemarkBody() << endl;
        cout << "*" << endl << endl;
    }
    cout << "--评价到底了--" << endl;
    cout << endl;
}

/*
 * 以下是各派生类的accept函数以及构造函数的具体实现
 * 按.h文件所述共有10个，内容基本与其中相同，后续不再赘述
 */
void restaurantShop::accept(Visitor &v) {
    return v.visit(this);
}

restaurantShop::restaurantShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                   double shopScore, const list<ShopRemark *> &shopRemarks,
                   const map<CommodityInformation *, int> &itemList) : Shop(
        shopName, shopId, shopType, shopDate, shopStorage, shopScore, shopRemarks, itemList) {}


void drinksShop::accept(Visitor &v) {
    return v.visit(this);
}

drinksShop::drinksShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                     int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                     const map<CommodityInformation *, int> &itemList) : Shop(shopName, shopId, shopType, shopDate,
                                                                              shopStorage,
                                                                              shopScore, shopRemarks, itemList) {}


void digitalShop::accept(Visitor &v) {
    return v.visit(this);
}

digitalShop::digitalShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                         int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                         const map<CommodityInformation *, int> &itemList) : Shop(shopName, shopId, shopType, shopDate,
                                                                                  shopStorage,
                                                                                  shopScore, shopRemarks, itemList) {}


void booksShop::accept(Visitor &v) {
    return v.visit(this);
}

booksShop::booksShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                   double shopScore, const list<ShopRemark *> &shopRemarks,
                   const map<CommodityInformation *, int> &itemList) : Shop(
        shopName, shopId, shopType, shopDate, shopStorage, shopScore, shopRemarks, itemList) {}


void groceryShop::accept(Visitor &v) {
    return v.visit(this);
}

groceryShop::groceryShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                     int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                     const map<CommodityInformation *, int> &itemList) : Shop(shopName, shopId, shopType, shopDate,
                                                                              shopStorage,
                                                                              shopScore, shopRemarks, itemList) {}


void furnitureShop::accept(Visitor &v) {
    return v.visit(this);
}

furnitureShop::furnitureShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                             int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                             const map<CommodityInformation *, int> &itemList) : Shop(shopName, shopId, shopType,
                                                                                      shopDate, shopStorage,
                                                                                      shopScore, shopRemarks,
                                                                                      itemList) {}


void clothesShop::accept(Visitor &v) {
    v.visit(this);
}

clothesShop::clothesShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                         int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                         const map<CommodityInformation *, int> &itemList) : Shop(shopName, shopId, shopType, shopDate,
                                                                                  shopStorage,
                                                                                  shopScore, shopRemarks, itemList) {}


void stationeryShop::accept(Visitor &v) {
    return v.visit(this);
}

stationeryShop::stationeryShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                               int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                               const map<CommodityInformation *, int> &itemList) : Shop(shopName, shopId, shopType,
                                                                                        shopDate,
                                                                                        shopStorage, shopScore,
                                                                                        shopRemarks,
                                                                                        itemList) {}


void sportsShop::accept(Visitor &v) {
    return v.visit(this);
}

sportsShop::sportsShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                     int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                     const map<CommodityInformation *, int> &itemList) : Shop(shopName, shopId, shopType, shopDate,
                                                                              shopStorage,
                                                                              shopScore, shopRemarks, itemList) {}


void nullShop::accept(Visitor &v) {
    return v.visit(this);
}

//初始化nullShop对象的属性。接收一系列参数，包括店铺名称、店铺ID、店铺类型、店铺日期、店铺库存、店铺评分、店铺备注列表和商品清单等。
nullShop::nullShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                   double shopScore, const list<ShopRemark *> &shopRemarks,
                   const map<CommodityInformation *, int> &itemList) : Shop(
        shopName, shopId, shopType, shopDate, shopStorage, shopScore, shopRemarks, itemList) {}

void proxyShop::accept(Visitor &v) {
    return v.visit(this);
}

proxyShop::proxyShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                     int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                     const map<CommodityInformation *, int> &itemList, Shop *shop) : Shop(shopName, shopId, shopType,
                                                                                          shopDate, shopStorage,
                                                                                          shopScore, shopRemarks,
                                                                                          itemList), shop(shop) {}


void proxyShop::display() {
    // 创建代理对象
    if (shop == nullptr) {
        shop = new nullShop("unknown", rand() % 10000 + 10, "unknown", "2023-12-28", 0, 0, list<ShopRemark *>(),
                            map<CommodityInformation *, int>());
    }
    shop->showShopInformation();
}

shopDecorator::shopDecorator(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                             int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                             const map<CommodityInformation *, int> &itemList, Shop *decoratedShop) 
                               :Shop(shopName,shopId,shopType,shopDate,
                                    shopStorage,shopScore,shopRemarks,
                                    itemList),
                                decoratedShop(decoratedShop) {}

void shopDecorator::accept(Visitor &v) {
    return v.visit(this);
}

AddStarShopDecorator::AddStarShopDecorator(const string &shopName, int shopId, const string &shopType,
                                           const string &shopDate, int shopStorage, double shopScore,
                                           const list<ShopRemark *> &shopRemarks,
                                           const map<CommodityInformation *, int> &itemList, Shop *decoratedShop)
                                           : shopDecorator(shopName, shopId, shopType, shopDate, 
                                                           shopStorage, shopScore, shopRemarks, itemList,
                                                           decoratedShop) {}

void AddStarShopDecorator::accept(Visitor &v) {
    setRemarkScore(10.00);
    //return v.visit(this);
}


