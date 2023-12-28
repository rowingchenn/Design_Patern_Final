// CustomerBuilder.h
#ifndef CUSTOMER_BUILDER_M
#define CUSTOMER_BUILDER_M


#include<string>
#include<iostream>
using namespace std;
class Customer {
private:
    string identity;  // 用户身份：游客、普通用户、PLUS用户
    string name;      // 用户姓名
    string email;     // 用户邮箱
public:
    

    void showIdentity() {
        cout << "用户身份: " << identity << endl;
    }
    void setName(const string& name) { this->name = name; }
    void setEmail(const string& email) { this->email = email; }
    void setIdentity(const string& identity) { this->identity = identity; }
    string getIdentity() const { return identity; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    


};

class CustomerBuilder {
public:
    virtual void buildIdentity() = 0;
    virtual Customer* getCustomer() = 0;
    virtual ~CustomerBuilder() {}
};

class GuestCustomerBuilder : public CustomerBuilder {
private:
    Customer* customer;

public:
    GuestCustomerBuilder() {
        customer = new Customer();
    }

    void buildIdentity() override {
        customer->setIdentity("游客");
    }

    Customer* getCustomer() override {
        return customer;
    }
};


class CommonCustomerBuilder : public CustomerBuilder {
private:
    Customer* customer;

public:
    CommonCustomerBuilder() {
        customer = new Customer();
    }

    void buildIdentity() override {
        customer->setIdentity("普通用户");
    }

    Customer* getCustomer() override {
        return customer;
    }
};

class PlusCustomerBuilder : public CustomerBuilder {
private:
    Customer* customer;

public:
    PlusCustomerBuilder() {
        customer = new Customer();
    }

    void buildIdentity() override {
        customer->setIdentity("尊贵的PLUS用户");;
    }

    Customer* getCustomer() override {
        return customer;
    }
};

class CustomerDirector {
public:
    static void construct(CustomerBuilder* builder) {
        builder->buildIdentity();
    }
};

#endif // CUSTOMER_BUILDER_M