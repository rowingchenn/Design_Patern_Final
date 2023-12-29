#include <iostream>

using namespace std;

class AbstractLogger {
protected:
    AbstractLogger *_nextLogger;  // 下一个处理者的指针
public:
    AbstractLogger() { _nextLogger = nullptr; }

    virtual ~AbstractLogger() {}

    void SetNextLogger(AbstractLogger *logger) { _nextLogger = logger;} // 设置下一个处理者的方法

    //在主程序中，通过调用SetNextLogger方法来设置各个处理者之间的关系，形成责任链。
    //当调用责任链的顶端处理者进行日志记录时，日志记录会根据自身的等级进行分发，并由适当的处理者进行处理。
    //如果责任链中没有处理该等级的处理者，日志记录将不会被处理。

    virtual void writeLog(int level) = 0; // 抽象方法，用于写入日志
};

class NormalLogger : public AbstractLogger {
    virtual void writeLog(int level);
};

class ErrorLogger : public AbstractLogger {
    virtual void writeLog(int level);
};

class SuccessLogger : public AbstractLogger {
    virtual void writeLog(int level);
};

