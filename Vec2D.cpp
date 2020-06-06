//
// Created by Legrandk on 2020.4.22.
//

#include "Vec2D.h"

//默认构造函数
Vec2D::Vec2D()
{
    x = 0.0;
    y = 0.0;
}

//有参构造函数
Vec2D::Vec2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

//加法，有数值和向量加法两种重构
Vec2D Vec2D::add(double numeral)
{
    return Vec2D{ this->x + numeral, this->y + numeral };
}
Vec2D Vec2D::add(const Vec2D& secondVec2D)
{
    return Vec2D{ this->x + secondVec2D.x,
                  this->y + secondVec2D.y };
}

//重载加法运算符
Vec2D Vec2D::operator+(const double numeral)
{
    return this->add(numeral);
}
Vec2D Vec2D::operator+(const Vec2D& secondVec2D)
{
    return this->add(secondVec2D);
}
Vec2D operator+(double numeral, Vec2D& vec2d)
{
    return vec2d.add(numeral);
}

//重载加法赋值运算符
Vec2D& Vec2D::operator+=(const Vec2D& secondVec2D)
{
    *this = this->add(secondVec2D);
    return *this;
}
//获取元素
double& Vec2D::at(int index)
{
    if (index == 0)
        return this->x;
    else if (index == 1)
        return this->y;
    else //输入数据不合法，抛出异常
    {
        std::cout << "Index out of bound" << std::endl;
        //You can throw out an error here
        exit(0);
    }
}

//重载索引运算符
double& Vec2D::operator[](int index)
{
    return this->at(index);
}

//比较大小
int Vec2D::compareTo(Vec2D secondVec2D)
{
    if (this->magnitude() > secondVec2D.magnitude()) //大于
        return 1;
    else if (this->magnitude() < secondVec2D.magnitude()) //小于
        return -1;
    else //等于
        return 0;
}

//重载关系运算符
bool Vec2D::operator>(const Vec2D& v)
{
    return this->compareTo(v) == 1;
}
bool Vec2D::operator>=(const Vec2D& v)
{
    return this->compareTo(v) != -1;
}
bool Vec2D::operator<(const Vec2D& v)
{
    return this->compareTo(v) == -1;
}
bool Vec2D::operator<=(const Vec2D& v)
{
    return this->compareTo(v) != 1;
}

//自减
Vec2D& Vec2D::decrease()
{
    (this->x)--;
    (this->y)--;
    return *this;
}

//重载自减运算符
Vec2D& Vec2D::operator--()
{
    return this->decrease();
}
Vec2D Vec2D::operator--(int dummy)
{
    Vec2D temp{ this->x, this->y };
    (this->x)--;
    (this->y)--;
    return temp;
}
//方向
double Vec2D::direction()
{
    return atan(this->x / this->y);
}

//点乘
double Vec2D::dot(const Vec2D& secondVec2D)
{
    return (this->x * secondVec2D.x +
        this->y + secondVec2D.y);
}

//重载乘法运算符-点乘
double Vec2D::operator*(const Vec2D& secondVec2D)
{
    return this->dot(secondVec2D);
}

//判断是否相等
bool Vec2D::equal(const Vec2D& secondVec2D)
{
    return (this->x == secondVec2D.x &&
        this->y == secondVec2D.y);
}

//重载等号运算符
bool Vec2D::operator==(const Vec2D& v)
{
    return this->equal(v);
}

//重载不等号运算符
bool Vec2D::operator!=(const Vec2D& v)
{
    return !this->equal(v);
}

//自增
Vec2D& Vec2D::increase()
{
    (this->x)++;
    (this->y)++;
    return *this;
}

//重载自增运算符
Vec2D& Vec2D::operator++()
{
    return this->increase();
}
Vec2D Vec2D::operator++(int dummy)
{
    Vec2D temp{ this->x, this->y };
    (this->x)++;
    (this->y)++;
    return temp;
}
//求模
double Vec2D::magnitude()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

//重载类型转换运算符
Vec2D::operator double()
{
    return this->magnitude();
}

//数乘
Vec2D Vec2D::multiply(double numeral)
{
    return Vec2D{ this->x * numeral,
                  this->y * numeral };
}

//重载乘法运算符-数乘
Vec2D Vec2D::operator*(double numeral)
{
    return this->multiply(numeral);
}
Vec2D operator*(double numeral, Vec2D& vec2d)
{
    return vec2d.multiply(numeral);
}

//求反
Vec2D Vec2D::negative()
{
    return Vec2D{ -this->x, -this->y };
}

Vec2D Vec2D::operator-()
{
    return this->negative();
}
//减法，有数值和向量减法两种重构
Vec2D Vec2D::subtract(double numeral)
{
    return Vec2D{ this->x - numeral, this->y - numeral };
}
Vec2D Vec2D::subtract(const Vec2D& secondVec2D)
{
    return Vec2D{ this->x - secondVec2D.x,
                  this->y - secondVec2D.y };
}

//重载减法运算符
Vec2D Vec2D::operator-(double numeral)
{
    return this->subtract(numeral);
}
Vec2D Vec2D::operator-(const Vec2D& secondVec2D)
{
    return this->subtract(secondVec2D);
}
Vec2D operator-(double numeral, Vec2D& vec2d)
{
    //return vec2d.negative() + numeral;
    return vec2d.negative().add(numeral);
}
//重载减法赋值运算符
Vec2D& Vec2D::operator-=(const Vec2D& secondVec2D)
{
    *this = this->subtract(secondVec2D);
    return *this;
}

//生成字符串
std::string Vec2D::toString() const
{
    return std::string{ "(" + std::to_string(this->x) + ", "
                            + std::to_string(this->y) + ")" };
}

//重载流插入运算符与流提取运算符
std::ostream& operator<<(std::ostream& os, const Vec2D& v)
{
    os << v.toString();
    return os;
}
std::istream& operator>>(std::istream& is, Vec2D& v)
{
    is >> v.x >> v.y;
    return is;
}

//重载赋值运算符
Vec2D& Vec2D::operator=(const Vec2D& v)
{
    this->x = v.x;
    this->y = v.y;
    return *this;
}

