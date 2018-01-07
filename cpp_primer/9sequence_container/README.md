## ex9.1
- (a)list 因为需要频繁的进行插入操作

- (b)deque 总是在头尾进行插入，删除操作

- (c)vector 不需要进行额外的进行插入删除操作

## ex9.2
    std::list<std::deque<int>> lst;

## ex9.3
两个迭代器 begin 和 end 需满足以下条件：
- 它们指向同一个容器中的元素，或是容器最后一个元素之后的位置。
- 我们可以通过反复递增 begin 来达到 end。end 不能在 begin 之前。

## ex9.4
```c++
bool Find(std::vector<int>::const_iterator begin,
          std::vector<int>::const_iterator end,
          int value) {
    while (begin++ != end) {
        if (*begin == value) return true;
    }

    return false;
}
```

## ex9.5
```c++
auto Find(std::vector<int>::const_iterator begin,
          std::vector<int>::const_iterator end,
          int value) {
    for (; begin != end; ++begin) {
        if (*begin == value) return begin;
    }
    return end;
}
```

## ex9.6
    while (iter1 != iter2)
list 容器的迭代器不支持 < 运算符，因为其元素在内存中分配的空间不一定是连续的。

## ex9.7
    std::vector<int>::size_type

## ex9.8
    std::list<std::string>::const_iterator
    std::list<std::string>::iterator

## ex9.9
- cbegin 返回的是常量迭代器
- begin 返回的是普通迭代器

## ex9.10
- 题目有错误，auto 后定义的变量必须为同一类型
- 应该改为
```
    auto it1 = v1.begin();
    auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```
- it1 - std::vector<int>::iterator
- it2, it3, it4 - std::vector<int>::const_iterator

## ex9.11
```c++
std::vector<int> vec;               // 0
std::vector<int> vec(1);            // 0
std::vector<int> vec(10, 1);        // 1
std::vector<int> vec{ 1, 2, 3 };    // 1, 2, 3
std::vector<int> vec(other_vec);    // 和 other_vec 相同
std::vector<int> vec(other_vec.begin(), other_vec.end());  // 和 other_vec 相同
```

## ex9.12
- 接受一个容器来创建拷贝的构造函数，接受的容器和本容器的类型，元素必须都相同
- 接受两个迭代器创建拷贝的构造函数，只要接受的容器元素可以转换为本容器的元素类型即可

## ex9.13
```c++
std::list<int> lst{ 1, 2, 3 };
std::vector<int> vec0{ 1, 2, 3 };

std::vector<double> vec1(lst.cbegin(), lst.cend());
std::vector<double> vec2(vec0.cbegin(), vec1.cend());
```

## ex9.14
```c++
std::list<char *> lst{ "one", "two", "three" };
std::vector<std::string> vec;
vec.assign(lst.cbegin(), lst.cend());
```

## ex9.15
```c++
std::vector<int> vec1{ 1, 2, 3 };
std::vector<int> vec2{ 1, 2, 3 };
std::vector<int> vec3{ 1, 2, 3, 4 };

std::cout << (vec1 == vec2) ? "true" : "false" << std::endl;
std::cout << (vec1 == vec3) ? "true" : "false" << std::endl;
```

## ex9.16
```c++
std::vector<int> vec{ 1, 2, 3 };
std::list<int> lst1{ 1, 2, 3 };
std::list<int> lst2{ 1, 2, 3, 4 };

std::cout << (std::vector<int>(lst1.cbegin(), lst1.cend()) == vec)
             ? "true" : "false" << std::endl

std::cout << (std::vector<int>(lst2.cbegin(), lst2.cend()) == vec)
             ? "true" : "false" << std::endl
```

## ex9.17
- 两个容器的类型要一致，且容器中的元素类型也要一致
- 容器中的元素类型要支持 < 运算符

## [ex9.18](ex9.18.cpp)

## ex9.19
- 把deque 改为 list

## [ex9.20](ex9.20.cpp)

## ex9.22
- 循环无法终止
- 迭代器失效

## ex9.23
- 都是相同的值

## [ex9.24](ex9.24.cpp)

## ex9.25
- elem1 与 elem2 相等时不会删除任何元素，什么事也不会发生
- 如果 elem2 是尾后迭代器，则会删除从 elem1 开始的所有元素
- 如果 elem1 和 elem2 都是尾后迭代器同样什么事也不会发生

## [ex9.26](ex9.26.cpp)

## ex9.27
```c++
std::forward_list<int> flst{ 1, 2, 3, 4, 5 };
auto prev = flst.before_begin();
auto curr = flst.begin();

while (curr != flst.end()) {
    if (*curr & 0x1) {
        curr = flst.erase(prev);    // 要删除单链表中的一个节点，必须知道其前一个节点
    }
    else {
        prev = curr;
        ++curr;
    }
}
```
## [ex9.28](ex9.28.cpp)

## ex9.29
- 在容器末尾添加75个值为0的元素
- 从容器末尾删除90个元素

## ex9.30
>接受单个参数的 resize 版本对元素类型什么限制（如果有的话）？
- 如果容器包含类类型的元素并增大容量的话，元素对应的类必须提供默认构造函数

## ex9.31

## ex9.32
- 不合法，因为两个参数的求值顺序是未指定的，而此语句是假设参数一先求值。

## ex9.33
- begin 会失效，程序将会崩溃。

## ex9.34 [test](ex9.34.cpp)
- 这段程序的原本意图是把为奇数的元素拷贝一份，但是循环无法结束，++iter 被放到了
循环外, 且迭代器缺少向前移动的行为。

## ex9.35
- capacity 表示在不重新分配内存的情况下，容器最大可容纳的元素数目
- size 表示容器当前所存储的元素数目

## ex9.36
不可能，capaticy 一定要大于等于 size

## ex9.37
- list 中的 size 和 capacity 的结果时是相同的，list 是动态分配内存的，提供
capacity 没有实际意义，size 完全可以完成 capacity 的功能, 并且逻辑上也更合理。
- array 的大小是固定的，也不需要提供 capacity。

## [ex9.38](ex9.38.cpp)

## ex9.39
定义了一个元素类型为 string 的 vector，给其分配了可容纳 1024 个 string 的内存
空间，然后从标准输入不断获取输入的 stirng 并将其 push_back 到容器中，直到输入结束。
最后将容器中的元素数量(size)扩大到原来的 1.5 倍，新添加的元素使用值初始化。如果容器
大小超过 1024 还要进行扩容。

## ex9.40
- 输入 256 个词，capacity 为 1024
- 输入 512 个词，capacity 为 1024
- 输入 1000 或 1048 个词，capacity 会扩大，具体视不同实现而定

## ex9.41
```c++
std::vector<char> vec{ 'a', 'b', 'c' };
std::string str(vec.cbegin(), vec.cend());
std::cout << str << '\n';
```
