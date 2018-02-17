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

>`Sales_data::Sales_data(Sales_data rhs);`

参数类型应该是引用类型

## exercise 13.3
>What happens when we copy a `StrBlob`? What about `StrBlobPtr`?

当我们拷贝 StrBlob 时，会使 shared_ptr 的引用计数加1，当我们拷贝 StrBlobPtr 时，
引用计数不会变化

## exercise 13.4
>Assuming Point is a class type with a public copy constructor, identify each use
of the copy constructor in this program fragment


