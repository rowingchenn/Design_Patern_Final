#include<iostream>
#include <iomanip>
// 顾客子系统头文件
#include "CustomerSubsystem.h"
// 支付模块
#include "PaymentMethod.h"
// 订单模块
#include "Order.h"
#include "ConcreteStates.h"
// 信息模块
#include "Preferences.h"
#include "ShoppingCart.h"
// 用户个人信息模块
#include "CustomerFacade.h"
// 回滚备份
#include "Memento.h"
// 降价提醒
#include "Observer.h"

using namespace std;

void showMenu(){
    cout<< "选择您想体验的服务："<<endl;
    cout<<"1.支付模块(工厂模式)"<<endl;
    cout<<"2.订单模块(状态模式)"<<endl;
    cout<<"3.信息模块(原型模式)"<<endl;
    cout<<"4.更新个人信息(备忘录模式可回滚)"<<endl;
    cout<<"5.接受商家通知(观察者模式)"<<endl;
    return ;
}

// 原型模式
void showPrototype(){
    // 创建原始的 Preferences 和 ShoppingCart 对象
    Preferences originalPreferences({"暗黑模式", "中文", "免打扰"});
    ShoppingCart originalCart({"iPhone15 Pro", "苹果干", "面膜"});

    // 克隆这些对象
    Preferences* clonedPreferences = static_cast<Preferences*>(originalPreferences.clone());
    ShoppingCart* clonedCart = static_cast<ShoppingCart*>(originalCart.clone());
    
    // 使用原始和克隆的对象
    cout << "原始偏好设置:" << endl;
    originalPreferences.printPreferences();
    cout << "克隆偏好设置:" << endl;
    clonedPreferences->printPreferences();

    cout << "原始购物车:" << endl;
    originalCart.printShoppingCart();
    cout << "克隆购物车:" << endl;
    clonedCart->printShoppingCart();

    char input;
    do{
        cout << "  [q] 退出"<<endl;
        cin>>input;
    }while(input != 'q' && input != 'Q');

    return;
}

// 状态模式
void showState() {
    Order order;
    order.setState(new OrderedState()); // 设置初始状态为已下单

    char input;
    do {
        cout << "当前订单状态: " << order.getStateName() << endl;
        cout << "选项: "<<endl;;
        cout << "  [n] 下一个状态"<<endl;
        cout << "  [q] 退出"<<endl;
        cout << "请选择一个选项: ";
        cin >> input;

        switch (input) {
            case 'n':
                order.nextState();
                break;
            case 'q':
                return;
            default:
                cout << "无效选项，请重试。"<<endl;
        }
    } while (input != 'q');
}

// 工厂模式
void showPayment(){

    cout<< "请选择您的支付方式："<<endl;
    cout << "1.银行卡支付" <<endl;
    cout << "2.支付宝支付"<<endl;
    cout <<"3.微信支付"<<endl;

    int input;
    cin>>input;

    PaymentMethodFactory::PaymentType type;

    switch(input){
        case 1: type = PaymentMethodFactory::CREDIT_CARD; break;
        case 2: type = PaymentMethodFactory::ALIPAY; break;
        case 3: type = PaymentMethodFactory::WXPAY; break;
        default: 
            cout << "无效支付方式"<<endl;
            break;
    }
    PaymentMethod* paymentMethod = PaymentMethodFactory::createPaymentMethod(type);
    cout<<"请输入支付金额:"<<endl;
    int amount = 0;
    cin >> amount;
    paymentMethod->pay(amount);

    char a;
    cout<<"按q退出支付模块"<<endl;
    cin>>a;
    if (a == 'q' || a == 'Q'){
        delete paymentMethod;
        return ;
    }
}

// 观察者模式
void Case_Observer(Customer* customer){
    ConcreteSubject subject;
    ConcreteObserver observer1(customer->getName());
    subject.attach(&observer1);
    subject.setProductStatus("您喜欢的商品降价啦，快来看看吧！");
    return;
}

// 备忘录模式
void Case_Momento(Customer* customer){
    CustomerAccountFacade accountFacade(customer);  // 备份用户信息
    accountFacade.backupAccountInfo();
    accountFacade.updateAccountInfo();
    accountFacade.showAccountInfo();
    // 回滚到之前的状态
    string opt="";
    cout << "是否需要回滚？(y/n)" ;
    cin >> opt;
    if(opt=="y"){
        cout << "正在回滚到上一个状态..." << endl;
        accountFacade.rollbackAccountInfo(0);
        accountFacade.showAccountInfo();
    }
    return;
}

void runCustomerSubsystem(){
    char option;
    cout << setfill('=') << setw(50) << "=" << endl;
    cout << setfill(' ') << setw(30) << right << "Welcome to" << endl;
    cout << setw(34) << right << "E-Commerce Platform" << endl;
    cout << setfill('=') << setw(50) << "=" << endl;
    cout << "请选择用户身份："<<endl;
    cout << "1. 游客\n2. 普通用户\n3. PLUS用户" << endl;
    int choice;
    cin >> choice;

    CustomerBuilder* builder;
    switch(choice) {
        case 1:
            builder = new GuestCustomerBuilder();
            break;
        case 2:
            builder = new CommonCustomerBuilder();
            break;
        case 3:
            builder = new PlusCustomerBuilder();
            break;
        default:
            cout << "无效选择，程序退出。" << endl;
            return ;
    }
    CustomerDirector::construct(builder);
    Customer* customer = builder->getCustomer();
    CustomerAccountFacade accountFacade(customer);

    if (choice == 1) {
        cout << "游客身份无法享受后续操作。" << endl;
        delete builder;
        return ;
    }

    accountFacade.updateAccountInfo();
    accountFacade.showAccountInfo();
    do {
        showMenu();
        cin >> option;

        switch (option) {
            case '1':
                showPayment();
                break;
            case '2':
                showState();
                break;
            case '3':
                showPrototype();
                break;
            case '4':
                Case_Momento(customer);
                break;
            case '5':
                Case_Observer(customer);
                break;
            case '0':
                cout << "退出顾客子系统，谢谢！"<<endl;
                break;
            default:
                cout << "无效输入，请再次输入"<<endl;
        }
    } while (option != '0');

    return ;
}

int main(){
    runCustomerSubsystem();
    return 0;
}