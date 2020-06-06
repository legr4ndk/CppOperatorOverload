//
// Created by Legrandk on 2020.4.22.
//
#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#ifndef VEC2D__VEC2D_H
#define VEC2D__VEC2D_H

class Vec2D
{
private:
    double x;
    double y;
public:
    //类方法
    Vec2D();                                    //默认构造函数
    Vec2D(double, double);                      //有参构造函数
    Vec2D add(double);                          //加法函数，有数字加法与向量加法两种重载
    Vec2D add(const Vec2D&);
    double& at(int);                            //获取向量的x或者y
    int compareTo(Vec2D);                       //比较向量的模的大小
    Vec2D& decrease();                          //自减函数
    double direction();                         //求向量的方向（斜率）
    double dot(const Vec2D&);                   //向量间的点乘
    bool equal(const Vec2D&);                   //判断向量是否相等
    Vec2D& increase();                          //自增函数
    double magnitude();                         //求向量的模
    Vec2D multiply(double);                     //向量的数乘
    friend Vec2D operator*(double, Vec2D&);     //数字前置的友元函数乘法运算符重载
    Vec2D negative();                           //向量取负
    Vec2D subtract(double);                     //减法函数，有数字减法与向量减法两种重载
    Vec2D subtract(const Vec2D&);
    std::string toString() const;               //向量转化成字符串

    //运算符重载
    Vec2D& operator++();                        //重载前缀自增运算符
    Vec2D operator++(int dummy);                //重载后置自增运算符
    Vec2D operator+(double);                    //重载加法运算符，有数字加法与向量加法两种重载
    Vec2D operator+(const Vec2D&);
    friend Vec2D operator+(double, Vec2D&);     //数字前置的友元函数加法运算符重载
    Vec2D& operator+=(const Vec2D&);            //重载加法赋值运算符
    Vec2D& operator--();                        //重载前缀自减运算符
    Vec2D operator--(int dummy);                //重载后置自减运算符
    Vec2D operator-();                          //重载取负运算符
    Vec2D operator-(double);                    //重载减法法运算符，有数字加法与向量加法两种重载
    Vec2D operator-(const Vec2D&);
    friend Vec2D operator-(double, Vec2D&);     //数字前置的友元函数减法运算符重载
    Vec2D& operator-=(const Vec2D&);            //重载减法赋值运算符
    double operator*(const Vec2D&);             //重载乘法运算符-点乘运算
    Vec2D operator*(double);                    //重载乘法运算符-数乘运算
    double& operator[](int);                    //重载索引运算符（下标）
    //重载流插入运算符和流提取运算符
    friend std::ostream& operator<<(std::ostream& os, const Vec2D& v);
    friend std::istream& operator>>(std::istream& is, Vec2D& v);
    operator double();                          //重载类型转换运算符（函数原型不写返回值类型）
    Vec2D& operator=(const Vec2D&);             //重载赋值运算符（规避浅拷贝）
    bool operator==(const Vec2D&);              //重载等号运算符
    bool operator!=(const Vec2D&);              //重载不等号运算符
    bool operator>(const Vec2D&);               //重载关系运算符
    bool operator>=(const Vec2D&);
    bool operator<(const Vec2D&);
    bool operator<=(const Vec2D&);
};

#endif //VEC2D__VEC2D_H
