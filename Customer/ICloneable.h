// ICloneable.h
#ifndef ICLONEABLE_H
#define ICLONEABLE_H

// 原型接口类
class ICloneable {
public:
    virtual ~ICloneable() {}

    // 纯虚函数，用于克隆对象
    virtual ICloneable* clone() const = 0;
};

#endif // ICLONEABLE_H
