## ex10_1
>头文件 algorithm 中定义了一个名为 count 的函数，它类似于 find，接受一堆迭代器和一个值作为参数。count 返回
给定值在序列中出现的次数。编写程序，读取 int 序列存入 vector 中，打印有多少个元素的值等于给定值。
```c++
int CountOfValue(const std::vector<int> &vec, int to_find) {
    return std::count(vec.cbegin(), vec.cend(), to_find);
}
```

## ex10_2
```c++
int CountOfValue(const std::list<std::string> &lst, std::string to_find) {
    return std::count(lst.cbegin(), lst.cend(), to_find);
}
```

## ex10_3
```c++
int GetSum(const std::vector<int> &vec) {
    return std::accumulate(vec.cbegin(), vec,cend(), 0);
}
```

## ex10_4
结果是 int 类型，vector 中的元素会先被转换为 int 类型然后再进行累加。

## ex10_5
两个容器中的元素都为 C 风格字符串，则无法进行比较，因为原生 C 风格字符串之间用 == 判断
的两者的地址值是否相等，而没有比较字符串内容。

## ex10_6
```c++
void FillValue(std::vector<int> &v, int value) {
    std::fill_n(v.begin(), v.size(), 0);
}
```

## ex10_7
- (a) 有错误
    copy(lst.cbegin(), lst.cend(), vec.begin());
改为
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
- (b) 没有错误
    vec.reserve(10);
改为
    vec.resize(10);
或
    fill_n(back_inserter(vec), 10, 0);

## ex10_8
back_inserter 是插入迭代器，在头文件 iterator 中声明，不属于标准库算法 algorithm

## [ex10_9](ex10_9.cpp)

## ex10_10
- 为了分离算法和成员函数提供的操作。
- 算法通过迭代器而不是容器访问容器中的元素，因此算法不能（直接）改变容器的大小。

## [ex10_11](ex10_11.cpp)

## ex10_12

## [ex10_13](ex10_13.cpp)

## ex10_14
```c++
auto Add = [](int n1, int n2) { return n1 + n2; };
```

## ex10_15
```c++
int value = 1;
auto Add = [value](int n) { return value + n; };
```

## [ex10_16](ex10_16.cpp)

## [ex 10_18 and 10_19](ex10_18_19.cpp)

## ex10_20
```c++
size_t LengthBigetThan6(std::vector<str::string> &words, size_t len) {
    return std::count_if(words.cbegin(), words.cend(),
        [len](const std::string str]) {
            return str.size() > len;
    });
}
```

## ex10_21
```c++
int num = 6;
auto CheckAndDecrement = [&num] { return num > 0 ? !--num : !num; };
while (!CheckAndDecrement()) std::cout << num << ' ';
std::cout << '\n';
```

## ex_10_22
```c++
bool IsShorter(const std::string &str, const std::string::size_type len) {
    return str.size() <= 6;
}

int main() {

    ...
    auto conut = std::count_if(words.cbegin(), words.cend(),
                               std::bind(IsShorter, _1, 6));

    return 0;
}
```

## ex10_23
如果被绑定的函数接受n个参数，那么 bind 函数接受n+1个参数，多出来的一个为要绑定函数的函数名

## [ex10_24](ex10_24.cpp)

## [ex10_25](ex10_25.cpp)

## ex10_26
- back_inserter 使用 push_back
- front_inserter 使用 push_front
- inserter 使用 insert，此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。
元素将被插入到给定迭代器所表示的元素之前。

## ex10_27
```c++
std::vector<int> vec{ 1, 2, 2, 3, 3, 4 };
std::list<int> lst;
std::unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst));

for (const auto &i : lst) std::cout << i << ' ';
std::cout << '\n';
```

## ex10_28
```c++
std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
std::vector<int> v1, v2, v3;
std::copy(vec.cbegin(), vec.cend(), front_inserter(v1));
std::copy(vec.cbegin(), vec.cend(), back_inserter(v2));
std::copy(vec.cbegin(), vec.cend(), inserter(v3, v3.begin()));
```

## [ex10_29](ex10_29.cpp)
