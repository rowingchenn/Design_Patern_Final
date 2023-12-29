//
// 本文件用于责任链不同节点进行等级处理
//
#include "ChainOfResponsibility.h"

void NormalLogger::writeLog(int level) {
    if (level == 1) // 如果日志等级为1，则当前日志处理者处理
        cout << "日志: 目前系统正常运行。" << endl;
    else
        _nextLogger->writeLog(level); // 否则将请求传递给下一个处理者
}

void SuccessLogger::writeLog(int level) {
    if (level == 2) // 如果日志等级为2，则当前日志处理者处理
        cout << "系统日志: 用户操作成功。" << endl;
    else
        _nextLogger->writeLog(level); // 否则将请求传递给下一个处理者
}

void ErrorLogger::writeLog(int level) {
    if (level == 3) // 如果日志等级为3，则当前日志处理者处理
        cout << "系统日志: 用户输入命令错误。" << endl;
    else
        _nextLogger->writeLog(level); // 否则将请求传递给下一个处理者
}
