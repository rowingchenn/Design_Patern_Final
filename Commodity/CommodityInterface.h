// Created by xzw on 2023/12/25.

#ifndef DESIGNPATTERN_2021_COMMODITYINTERFACE_H
#define DESIGNPATTERN_2021_COMMODITYINTERFACE_H

#include "Commodity.h"
#include "CommodityFactory.h"
#include "../Shop/shopInterface.h"

using namespace std;

class CommodityInterface {
private:
    CommodityFactory commodityFactory;
public:
    void Initialize(shopInterface &shopInterface);

    void MainInterface(shopInterface &shopInterface);
};


#endif 
