// PaymentMethod.h
#ifndef PAYMENT_METHOD_H
#define PAYMENT_METHOD_H

#include <iostream>
#include <stdexcept>

// 抽象基类
class PaymentMethod {
public:
    virtual void pay(int amount) = 0; // 纯虚函数
    virtual ~PaymentMethod() {} // 虚析构函数
};

// CreditCardPayment 类声明
class CreditCardPayment : public PaymentMethod {
public:
    void pay(int amount) override;
};

// AlipayPayment 类声明
class AlipayPayment : public PaymentMethod {
public:
    void pay(int amount) override;
};

// ApplePayPayment 类声明
class WechatPayment : public PaymentMethod {
public:
    void pay(int amount) override;
};

// PaymentMethodFactory 类声明
class PaymentMethodFactory {
public:
    enum PaymentType {
        CREDIT_CARD,
        ALIPAY,
        WXPAY
    };

    static PaymentMethod* createPaymentMethod(PaymentType type);
};

#endif // PAYMENT_METHOD_H
