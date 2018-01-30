## ex11_1
map 是关联容器，vector 是顺序容器

## ex11_2
- list   双向链表，当需要频繁插入删除元素时推荐使用
- vector 向量，当需要随机访问，向末尾插入删除时推荐使用
- duque  双端队列，当需要频繁在头尾插入删除元素时推荐使用
- map    字典，需要类似于字典的功能时推荐使用
- set    集合，需要存储有序不重复的元素时推荐使用

## ex11_3
```c++
void CountWords(const std::vector<std::string> &words) {
    map<std::string, size_t> words_count;
    for (const auot &i : words) ++words_count[i];

    for (const auto &kv : words_count) {
        std::cout << kv.first << ":" << kv.second << '\n';
    }
}
```

## ex11_4
```c++
void Strip(std::string &str) {
    for (auto &c : str) c = tolower(c);
    str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
}

void CountWords(const std::vector<std::string> &words) {
    map<std::string, size_t> words_count;
    for (const auto &i : words) ++words_count[i];

    for (const auto &kv : words_count) {
        std::cout << kv.first << ":" << kv.second << '\n';
    }
}
```

## ex10_7
```c++
inline
void AddToFamily(std::map<std::string, std::vector<std::string>> &record,
         const std::string &family,
         const std::string &child) {
    record[family].push_back(child);
}
```

## ex10_8
```cpp
void Test(std::vector<std::string> &vec) {
    std::string str;
    while (std::cin >> str) {
        if (vec.find(vec.cbegin(), vec.cend(), str) != vec.end()) {
            vec.push_back(str);
        }
    }
}
```

## ex10_9
    std::map<std::string, std::list<size_t>> m;

## ex10_10
可以定义 vector<int>::iterator 到 int 的 map，但不可以定义 list<int>::iterator 到 int 的 map
因为 map 的 key 必须支持 < 运算符，vector<int>::iterator 支持 < 运算符，故可以，list<int>::iterator 不支持 < 运算符
不可以

## ex10_11
```c++
using Less = bool (*)(const Sales_data &, const Sales_data &);
std::multistd<Sales_data, Less> book_store(Less);
```

## [ex10_12](ex10_12.cpp)


## [ex10_13](ex10_13.cpp)


## [ex10_14](ex10_14.cpp)

## ex10_15
- mapped_type 是 vector<int>
- key_type    是 int
- value_type  是 pair<const int, vector<int>>

## ex10_16
```c++
std::map<int, std::string> map;
map[6] = "666";
auto iter = map.begin();
iter->second = "2333";
```

## ex10_17
第二个调用不合法，set 没有 push_back 方法，其他都合法。

## ex10_18
    std::map<std::string, size_t>::const_iterator;

## ex10_19
    std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>::iterator;

## ex10_20
```c++
std::map<stf::string, size_t> map;
for (std::string word; std::cin >> word; ) {
    auto result = map.insert({ word, 1 });
    if (result->second) ++(result.first->second); // result.first 为指向插入 pair 的迭代器
}
```
使用 insert 更容器阅读和编写，insert 有返回值，可以明确插入的结果。

## ex10_21
若 insert 成功；先添加一个元素，然后返回一个 pair，pair 的 first 是一个迭代器，此迭代器指向新添加的元素，
这个元素是一个 pair，然后递增 pair 的 second。若 insert 失败，递增相应元素的 second 成员。

## ex10_22
- 参数类型 std::pair<std::string, std::vector<int>>
- 返回值类型 std::pair<std::map<std::string, std::vector<int>>::iterator, bool>

## ex10_23
```c++
inline
void AddToFamily(std::multimap<std::string, std::vector<std::string>> &record,
                 const std::string &family,
                 const std::string &child) {
    record[family].push_back(child);
}
```

## ex11_24
向 m 中添加了一个 key 为 0，value 为 1 的 pair。

## ex11_25
越界访问，未定义行为。

## ex11_26
```c++
std::map<int, std::string> m = { { 1, "a" }, { 2, "bb" } };
using KeyType = std::map<int, std::string>::key_type;
using ReturnType = std::map<int, std::string>::mapped_type;
```

## ex11_27
对于允许重复关键出现的容器，应该使用 count，对于不允许重复关键字的容器，应该使用 find

## ex11_28
    std::map<std::string, std::vector<int>>::iteraotr;

## ex11_29
如果给定的关键字不在容器中，则 upper_bound 和 lower_bound 返回相等的迭代器，指向一个
不影响排序的关键字插入位置，equal_range 会返回一个 pair，其 first 和 second 都是迭代器，
都指向关键字可以插入的位置。

## ex11_30
- pos 为一个 pair
- pos.first 为一个迭代器，指向匹配关键字的元素
- pos.first->second 为此元素的 second

## [ex11_31](ex11_31.cpp)

## [ex11_32](ex11_32.cpp)
