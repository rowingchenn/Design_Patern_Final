// PaymentMethod.cpp
#include "PaymentMethod.h"
#include<iostream>
using namespace std;

void CreditCardPayment::pay(int amount) {
    cout<<"正在利用信用卡进行支付"<<endl;
    cout<<"支付来源：银行卡"<<endl;
    cout<<"支付金额："<< amount <<endl;
}

void AlipayPayment::pay(int amount) {
    cout<<"正在利用支付宝进行支付"<<endl;
    cout<<"支付来源：支付宝（余额宝）"<<endl;
    cout<<"支付金额："<< amount <<endl;
}

void WechatPayment::pay(int amount) {
    cout<<"正在利用微信进行支付"<<endl;
    cout<<"支付来源：微信零钱"<<endl;
    cout<<"支付金额："<< amount <<endl;
}

PaymentMethod* PaymentMethodFactory::createPaymentMethod(PaymentMethodFactory::PaymentType type) {
    switch (type) {
        case CREDIT_CARD: return new CreditCardPayment();
        case ALIPAY: return new AlipayPayment();
        case WXPAY: return new WechatPayment();
        default: throw std::invalid_argument("无效支付方式");
    }
}
