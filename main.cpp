#include <iostream>
#include "Vec2D.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
    Vec2D v1, v2{ 3, 4 }, v3{ 5, 12 };
    cin >> v1;
    cout << "v1 = " << v1 << endl;
    cout << "v2++ = " << v2++ << endl;
    cout << "v2 = " << v2 << endl;
    cout << "++v3 = " << ++v3 << endl;
    cout << "v3 = " << v3 << endl;
    cout << "v2-- = " << v2-- << endl;
    cout << "v2 = " << v2 << endl;
    cout << "--v3 = " << --v3 << endl;
    cout << "v3 = " << v3 << endl;
    cout << "v2 + v3 =" << (Vec2D)v2 + (Vec2D)v3 << endl;
    cout << "v3 - v2 =" << (Vec2D)v3 - (Vec2D)v2 << endl;
    //写测试数据累死了，不写了（咽气）
    //呃啊
    return 0;
}
