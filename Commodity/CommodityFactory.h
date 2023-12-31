// Created by xzw on 2023/12/25.

#ifndef DESIGNPATTERN_2021_COMMODITYFACTORY_H
#define DESIGNPATTERN_2021_COMMODITYFACTORY_H

#include "Commodity.h"
#include<map>

using namespace std;

class CommodityFactory {
public:
    map<CommodityInformation*, int> _existingCommodityList;
    CommodityInformationReader reader;
    CommodityInformation * getSingleCommodity(int ID, string name, int price, int shopID, int amount);
};

#endif 
