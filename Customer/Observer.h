// Observer.h
#ifndef CUSTOMER_OBSERVER_M
#define CUSTOMER_OBSERVER_M


#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Observer {
public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() {}
};

class ConcreteObserver : public Observer {
private:
    string name; // 存储用户姓名

public:
    explicit ConcreteObserver(const string& name) : name(name) {}

    void update(const string& message) override {
        cout << "[" << name << "] " << message << endl;
    }
};


class Subject {
private:
    vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void notify(const string& message) {
        for (auto* observer : observers) {
            cout<<endl<<"[系统通知]:"<<message<<endl;
            observer->update(message);
            cout<<endl;
        }
    }
};

class ConcreteSubject : public Subject {
private:
    string productStatus;

public:
    void setProductStatus(const string& status) {
        productStatus = status;
        notify(productStatus); // 当产品状态改变时，通知所有观察者
    }
};

#endif // CUSTOMER_MOMENTO_M