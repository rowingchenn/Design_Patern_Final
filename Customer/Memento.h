// Memento.h
#ifndef CUSTOMER_MOMENTO_M
#define CUSTOMER_MOMENTO_M


#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Memento {
private:
    string state;

public:
    Memento(const string& state) : state(state) {}
    string getState() const { return state; }
};

class Originator {
private:
    string state;

public:
    void setState(const string& state) {
        this->state = state;
    }

    string getState() const {
        return state;
    }

    Memento saveStateToMemento() {
        return Memento(state);
    }

    void getStateFromMemento(const Memento& memento) {
        state = memento.getState();
    }
};

class CareTaker {
private:
    vector<Memento> mementoList;

public:
    void add(const Memento& state) {
        mementoList.push_back(state);
    }

    Memento get(int index) {
        return mementoList.at(index);
    }
};

#endif // CUSTOMER_MOMENTO_M