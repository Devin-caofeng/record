## exercise 13.1
>What is a copy construct? When is it used?

如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，则此
构造函数是拷贝构造函数。
当拷贝初始化发生时，会调用拷贝构造函数
- 使用 = 定义变量
- 将一个对象作为实参传递给一个非引用类型的形参
- 从一个返回类型为非引用类型的函数返回一个对象
- 用花括号列表初始化一个数组中的元素或一个聚合类中的成员

## exercise 13.2
>Explain why the following declaration is illegal
`Sales_data::Sales_data(Sales_data rhs);`

参数类型应该是引用类型

## exercise 13.3
>What happens when we copy a `StrBlob`? What about `StrBlobPtr`?

当我们拷贝 StrBlob 时，会使 shared_ptr 的引用计数加1，当我们拷贝 StrBlobPtr 时，
引用计数不会变化

## exercise 13.4
>Assuming Point is a class type with a public copy constructor, identify each use
of the copy constructor in this program fragment

```c++
Point global;
Point foo_bar(Point arg)  // 1
{
    Point local = arg, *heap = new Point(global);  // 2, 3
    *heap = local;
    Point pa[ 4 ] = { local, *heap };  // 4, 5
    return *heap;  // 6
}
```

## exercise 13.5
>Given the following sketch of a class, write a copy constructor that copies all
the members. Your constructor should dynamically allocate a new string and copy
the object to which ps points, rather than copying ps itself.

`HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }`

## exercise 13.6
拷贝赋值运算符是一个名为 operator= 的函数，当复制运算发生时就会用到它1.合成拷贝赋值运算符
可以用来禁止该类型对象的赋值。如果一个类未定义自己的拷贝赋值运算符，编译器会为它生成一个
合成拷贝赋值运算符

## exercise 13.7
都会发生浅层拷贝，所有的指针将指向相同的地址

## [exercise 13.8](ex13_8.cpp)

## exercise 13.9
析构函数是类的一个成员函数，其名字由波浪号接类名组成。它没有返回值，也不接受参数。
合成析构函数可被用来阻止该类型的对象呗销毁，当一个类未定义自己的析构函数时，编译器
会为它生成一个合成析构函数

## exercise 13.10
当一个 StrBlob 对象被销毁时，shared_ptr 的引用计数会减少。当 StrBlobPtr 对象被
销毁时，不影响引用计数

## [exercise 13.11](ex13_8.cpp)

## exercise 13.12
三次，分别是 accum，item1 和 item2

## [exercise 13.13](ex13_13.cpp)

## exercise 13.14
输出三个相同的序号

## exercise 13.15
会，因为新定义的拷贝构造函数会为每一个对象生成新的序号，所以会输出三个不同的序号
输出结果视具体的程序而定

## exercise 13.16
会改变，原因同上题，新的输出结果视具体的程序而定
会输出 a, b, c 的序号

## exercise 13.17
[13.14](ex13_14.cpp)|[13.15](ex13_15.cpp)|[13.16](ex13_16.cpp)

## [exercise 13.18](ex13_18.cpp)

## [exercise 13.19](ex13_19.cpp)
不需要，因为在现实中雇员是不可以拷贝的

## exercise 13.20
类的数据成员将会被拷贝和销毁

## exercise 13.21
编译器合成的版本满足目前的需求，因此不需要自定义拷贝控制操作

## [exercise 13.22](ex13_22.cpp)

## exercise 13.23
见 exercise 13.22

## exercise 13.24
如果未定义析构函数，将会发生内训泄露。如果未定义拷贝构造函数，将会使得多个类对象
中的指针指向同一块内存，导致内存重复释放，程序出错

## exercise 13.25
拷贝构造函数和拷贝赋值运算符都需要重新分配内存。因为 StrBlob 使用了智能指针，当
智能指针的引用计数为0时会自动释放对象，所以不需要析构函数

## exercise 13.26[hpp](ex13_26.hpp)|[cpp](ex13_26.cpp)

## [exercise 13.27](ex13_27.cpp)

## [exercise 13.28](ex13_28.cpp)

## exercise 13.29
这其实是三个不同的函数，参数类型不同，所以不会导致递归循环

## [exercise 13.30](ex13_30.hpp)

## [exercise 13.31](ex13_31.cpp)

## exercise 13.32
不会，类值的版本利用 swap 交换指针不用进行内存分配，因此得到了性能上的提升。类指针
的版本原本就没有进行内存重新分配，所以性能不会得到提升

## exercise 13.33
因为 save 和 remove 操作需要更新指定 Folder

## exercise 13.34[hpp](ex13_34.hpp)[cpp](ex13_34.cpp)

## exercise 13.35
在赋值后，一些已经存在的 Folders 将会与 Message 不同步
