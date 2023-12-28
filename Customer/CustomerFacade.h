// CustomerFacade.h
#ifndef CUSTOMER_FACADE_M
#define CUSTOMER_FACADE_M


#include<iostream>
#include<string>
#include"CustomerBuilder.h"
#include"Memento.h"
class CustomerAccountFacade {
private:
    Customer* customer;
    CareTaker careTaker;
    Originator originator;

public:
    explicit CustomerAccountFacade(Customer* customer) : customer(customer) {}

    // 提供简单的接口来处理用户账户信息
     void backupAccountInfo() {
        originator.setState(customer->getName() + ";" + customer->getEmail()); // 将状态设为name;email
        careTaker.add(originator.saveStateToMemento());
    }

    void rollbackAccountInfo(int index) {
        originator.getStateFromMemento(careTaker.get(index));
        auto state = originator.getState();
        auto delimiterPos = state.find(';');
        customer->setName(state.substr(0, delimiterPos));
        customer->setEmail(state.substr(delimiterPos + 1));
    }
    void showAccountInfo() {
        cout<<endl<<"显示个人信息："<<endl;
        cout << "姓名: " << customer->getName() << endl;
        cout << "邮箱: " << customer->getEmail() << endl;
        customer->showIdentity();
        cout<<endl;
    }

    void updateAccountInfo() {
        string name,email;
        cout<<endl<<"编辑个人信息,如跳过请输入skip"<<endl;
        cout<<"请输入用户姓名:";
        cin>>name;
        if(name!="skip")
            customer->setName(name);
        cout<<"请输入用户邮箱:";
        cin>>email;
        if(email!="skip")
            customer->setEmail(email);
        if(name=="skip"&&email=="skip")
            cout<<"退出编辑，个人信息未修改~"<<endl;
        cout<<"退出编辑，已成功保存个人信息！"<<endl<<endl;
        backupAccountInfo();
    }
};

#endif // CUSTOMER_FACADE_M