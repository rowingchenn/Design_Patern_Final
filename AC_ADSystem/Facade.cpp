#include "Facade.h"

#include "ActivitySystem.h"
#include "AdvertisingSystem.h"
#include "AdVisitor.h"
#include "AcVisitor.h"
#include "Interpreter.h"

Facade::Facade()
{
    AdSystemInstance = AdvertisingSystem::GetAdSystemInstance();
    AcSystemInstance = ActivitySystem::GetAcSystemInstance();
    ActivityInterpreter = new Interpreter();

    AddAd(1, "2023双十一美食节，每日限时秒杀，健康好味等你来！");
	AddAd(2, "双十一倒计时！今晚特惠盛宴，预付定金抢先享，错过再等一年！");
	AddAd(3, "购物狂欢季！双十一限时优惠券，11月11日特惠疯抢，只此一天！");
	AddAd(4, "今夜零点，双十一超级特卖，全年最低价，抢完即止！");
	AddAd(5, "预售狂欢！双十一付尾款，享受超额返利，今晚不留遗憾！");
	AddAd(6, "双十一狂欢不止购！全场满额送惊喜，购越多得越多！");
	AddAd(7, "今晚20点，双十一预付狂欢，定金立减，抢完即赚！");
	AddAd(8, "双十一疯狂抢购夜，首单立享超额优惠，今晚不睡觉！");
	AddAd(9, "品牌盛典，双十一5折起！奢侈品也疯狂，限时抢购！");
	AddAd(10, "天猫双十一提前享，大牌折扣独家放送，让每一分钱都花得值！");



    vector<int> vect1;//商品列表
    vect1.push_back(10);
    vect1.push_back(11);
    vect1.push_back(12);
    vect1.push_back(13);
    vect1.push_back(14);
    vect1.push_back(15);
    vect1.push_back(16);
    vect1.push_back(17);
    vect1.push_back(18);
    vect1.push_back(19);
    AddAcD(1, "食品商品全场八折！", vect1, 0.8);//添加打折类活动
    vector<int> vect2;//商品列表
    vect2.push_back(20);
    vect2.push_back(21);
    vect2.push_back(22);
    vect2.push_back(23);
    vect2.push_back(24);
    vect2.push_back(25);
    vect2.push_back(26);
    vect2.push_back(27);
    vect2.push_back(28);
    vect2.push_back(29);
    AddAcD(2, "饮料全场七五折！", vect2, 0.75);//添加打折类活动
    vector<int> vect3;//商品列表
    vect3.push_back(30);
    vect3.push_back(31);
    vect3.push_back(32);
    vect3.push_back(33);
    vect3.push_back(34);
    vect3.push_back(35);
    vect3.push_back(36);
    vect3.push_back(37);
    vect3.push_back(38);
    vect3.push_back(39);
    AddAcD(3, "电子产品全场九五折！", vect3, 0.95);//添加打折类活动
    vector<int> vect4;//商品列表
    vect4.push_back(40);
    vect4.push_back(41);
    vect4.push_back(42);
    vect4.push_back(43);
    vect4.push_back(44);
    vect4.push_back(45);
    vect4.push_back(46);
    vect4.push_back(47);
    vect4.push_back(48);
    vect4.push_back(49);
    AddAcD(4, "图书全场七折！", vect4, 0.7);//添加打折类活动
    vector<int> vect5;//商品列表
    vect5.push_back(50);
    vect5.push_back(51);
    vect5.push_back(52);
    vect5.push_back(53);
    vect5.push_back(54);
    vect5.push_back(55);
    vect5.push_back(56);
    vect5.push_back(57);
    vect5.push_back(58);
    vect5.push_back(59);
    AddAcD(5, "日用品全场五折！", vect5, 0.5);//添加打折类活动
    vector<int> vect6;//商品列表
    vect6.push_back(60);
    vect6.push_back(61);
    vect6.push_back(62);
    vect6.push_back(63);
    vect6.push_back(64);
    vect6.push_back(65);
    vect6.push_back(66);
    vect6.push_back(67);
    vect6.push_back(68);
    vect6.push_back(69);
    AddAcD(6, "家用电器全场八折！", vect6, 0.8);//添加打折类活动
    vector<int> vect7;//商品列表
    vect7.push_back(70);
    vect7.push_back(71);
    vect7.push_back(72);
    vect7.push_back(73);
    vect7.push_back(74);
    vect7.push_back(75);
    vect7.push_back(76);
    vect7.push_back(77);
    vect7.push_back(78);
    vect7.push_back(79);
    AddAcD(7, "服饰全场六折！", vect7, 0.6);//添加打折类活动
    vector<int> vect8;//商品列表
    vect8.push_back(80);
    vect8.push_back(81);
    vect8.push_back(82);
    vect8.push_back(83);
    vect8.push_back(84);
    vect8.push_back(85);
    vect8.push_back(86);
    vect8.push_back(87);
    vect8.push_back(88);
    vect8.push_back(89);
    AddAcD(8, "文具全场五折！", vect8, 0.5);//添加打折类活动
    vector<int> vect9;//商品列表
    vect9.push_back(90);
    vect9.push_back(91);
    vect9.push_back(92);
    vect9.push_back(93);
    vect9.push_back(94);
    vect9.push_back(95);
    vect9.push_back(96);
    vect9.push_back(97);
    vect9.push_back(98);
    vect9.push_back(99);
    AddAcD(9, "运动器材全场九折！", vect9, 0.9);//添加打折类活动
    AddAcF(10, "全场满200减30", 200, 30);//添加满减类活动
    AddAcF(11, "全场满300减50", 300, 500);//添加满减类活动
    AddAcF(12, "全场满1000减250", 1000, 250);//添加满减类活动

}

void Facade::BrowseAd()
{
    AdVisitor_Browse* AdBrowse = new AdVisitor_Browse();
    AdSystemInstance->Accept(AdBrowse);

    delete AdBrowse;
}

void Facade::BrowseAd(int BrowseAdID)
{
    AdVisitor_Browse* AdBrowse = new AdVisitor_Browse(BrowseAdID);
    AdSystemInstance->Accept(AdBrowse);

    delete AdBrowse;
}

void Facade::AddAd(int ID, string Cont)
{
    AdVisitor_Add* AddAdVisit = new AdVisitor_Add(ID, Cont);
    AdSystemInstance->Accept(AddAdVisit);
    delete AddAdVisit;
}

void Facade::BrowseAc()
{
    AcVisitor_Browse* AcBrowse = new AcVisitor_Browse();
    AcSystemInstance->Accept(AcBrowse);

    delete AcBrowse;
}

void Facade::BrowseAc(int BrowseAcID)
{
    AcVisitor_Browse* AcBrowse = new AcVisitor_Browse(BrowseAcID);
    AcSystemInstance->Accept(AcBrowse);

    delete AcBrowse;
}

void Facade::AddAcD(int ID, string Cont, vector<int>& CommodityInformationList, float DisRate)
{
    AcVisitor_Add* AddAcVisit = new AcVisitor_Add(ID, Cont, CommodityInformationList, DisRate);
    AcSystemInstance->Accept(AddAcVisit);
    delete AddAcVisit;
}

void Facade::AddAcF(int ID, string Cont, float Thd, float RedAmount)
{
    AcVisitor_Add* AddAcVisit = new AcVisitor_Add(ID, Cont, Thd, RedAmount);
    AcSystemInstance->Accept(AddAcVisit);
    delete AddAcVisit;
}

float Facade::CalOptimalDecision(map<CommodityInformation*, int>& BuyCommodityInformationMap) // 策略模式
{
    AcVisitor_CalPrice* CalPriceVisitor;
    CalPriceVisitor = new AcVisitor_CP_Discount(BuyCommodityInformationMap);// 策略1，使用打折活动
    AcSystemInstance->Accept(CalPriceVisitor);
    float OptimalPrice = CalPriceVisitor->OptimalPrice;
    string OptimalDecisionCode = CalPriceVisitor->OptimalDecisionCode;

    delete CalPriceVisitor;

    CalPriceVisitor = new AcVisitor_CP_FullRedu(BuyCommodityInformationMap); // 策略2，使用满减活动
    AcSystemInstance->Accept(CalPriceVisitor);
    if (CalPriceVisitor->OptimalPrice < OptimalPrice)
    {
        OptimalPrice = CalPriceVisitor->OptimalPrice;
        OptimalDecisionCode = CalPriceVisitor->OptimalDecisionCode;
    }
    ActivityInterpreter->MakeInterpretation(OptimalDecisionCode); // 进行解释

    cout << "###最优价格为： " << OptimalPrice << endl;
    return OptimalPrice;
}

void Facade::RecommendActivity(vector<CommodityInformation*>& RelatedCommodityInformationList)
{
    AcVisitor_Recommend* RecommendVisitor = new AcVisitor_Recommend(RelatedCommodityInformationList); // 寻找相关活动

    AcSystemInstance->Accept(RecommendVisitor);
    ActivityInterpreter->MakeInterpretation(RecommendVisitor->RecommendActivityCode); // 进行解释

    delete RecommendVisitor;
}

void Facade::RecommendActivity(map<CommodityInformation*, int>& RelatedCommodityInformationMap)
{
    vector<CommodityInformation*> RelatedCommodityInformationList;
    for (auto it = RelatedCommodityInformationMap.begin(); it != RelatedCommodityInformationMap.end(); it++)
    {
        RelatedCommodityInformationList.push_back((*it).first);
    }
    RecommendActivity(RelatedCommodityInformationList);
}
