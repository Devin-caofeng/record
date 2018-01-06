## ex1
- (a)list 因为需要频繁的进行插入操作

- (b)deque 总是在头尾进行插入，删除操作

- (c)vector 不需要进行额外的进行插入删除操作


## ex2
  std::list<std::deque<int>> lst;


## ex3
两个迭代器 begin 和 end 需满足以下条件：
- 它们指向同一个容器中的元素，或是容器最后一个元素之后的位置。
- 我们可以通过反复递增 begin 来达到 end。end 不能在 begin 之前。


## ex4
```
bool Find(std::vector<int>::const_iterator begin,
          std::vector<int>::const_iterator end,
          int value) {
    while (begin++ != end) {
        if (*begin == value) return true;
    }

    return false;
}
```

## ex5
```
auto Find(std::vector<int>::const_iterator begin,
          std::vector<int>::const_iterator end,
          int value) {
    for (; begin != end; ++begin) {
        if (*begin == value) return begin;
    }
    return end;
}
```

## ex6
  while (iter1 != iter2)
list 容器的迭代器不支持 < 运算符，因为其元素在内存中分配的空间不一定是连续的。


## ex7
  std::vector<int>::size_type


## ex8
  std::list<std::string>::const_iterator
  std::list<std::string>::iterator


## ex9
- cbegin 返回的是常量迭代器
- begin 返回的是普通迭代器


## ex10
- 题目有错误，auto 后定义的变量必须为同一类型
- 应该改为
```
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```
- it1 - std::vector<int>::iterator
- it2, it3, it4 - std::vector<int>::const_iterator


## ex11
```
std::vector<int> vec;               // 0
std::vector<int> vec(1);            // 0
std::vector<int> vec(10, 1);        // 1
std::vector<int> vec{ 1, 2, 3 };    // 1, 2, 3
std::vector<int> vec(other_vec);    // 和 other_vec 相同
std::vector<int> vec(other_vec.begin(), other_vec.end());  // 和 other_vec 相同
```

## ex12
- 接受一个容器来创建拷贝的构造函数，接受的容器和本容器的类型，元素必须都相同
- 接受两个迭代器创建拷贝的构造函数，只要接受的容器元素可以转换为本容器的元素类型即可


## ex13
```
std::list<int> lst{ 1, 2, 3 };
std::vector<int> vec0{ 1, 2, 3 };

std::vector<double> vec1(lst.cbegin(), lst.cend());
std::vector<double> vec2(vec0.cbegin(), vec1.cend());
```

## ex14
```
std::list<char *> lst{ "one", "two", "three" };
std::vector<std::string> vec;
vec.assign(lst.cbegin(), lst.cend());
```


## ex15
```
std::vector<int> vec1{ 1, 2, 3 };
std::vector<int> vec2{ 1, 2, 3 };
std::vector<int> vec3{ 1, 2, 3, 4 };

std::cout << (vec1 == vec2) ? "true" : "false" << std::endl;
std::cout << (vec1 == vec3) ? "true" : "false" << std::endl;
```


## ex16
```
std::vector<int> vec{ 1, 2, 3 };
std::list<int> lst1{ 1, 2, 3 };
std::list<int> lst2{ 1, 2, 3, 4 };

std::cout << (std::vector<int>(lst1.cbegin(), lst1.cend()) == vec)
             ? "true" : "false" << std::endl

std::cout << (std::vector<int>(lst2.cbegin(), lst2.cend()) == vec)
             ? "true" : "false" << std::endl
```


## ex17
- 两个容器的类型要一致，且容器中的元素类型也要一致
- 容器中的元素类型要支持 < 运算符

## [ex18](ex18.cpp)

## ex19
- 把deque 改为 list


## ex22
- 循环无法终止
- 迭代器失效


## ex23
- 都是相同的值


## ex25
- elem1 与 elem2 相等时不会删除任何元素，什么事也不会发生
- 如果 elem2 是尾后迭代器，则会删除从 elem1 开始的所有元素
- 如果 elem1 和 elem2 都是尾后迭代器同样什么事也不会发生


## ex27
```
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

## ex29
- 在容器末尾添加75个值为0的元素
- 从容器末尾删除90个元素
