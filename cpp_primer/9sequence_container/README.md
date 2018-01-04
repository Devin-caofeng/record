#练习9.1
- (a)list 因为需要频繁的进行插入操作

- (b)deque 总是在头尾进行插入，删除操作

- (c)vector 不需要进行额外的进行插入删除操作

#练习9.2
  std::list<std::deque<int>> lst;

#练习9.3
两个迭代器 begin 和 end 需满足以下条件：
- 它们指向同一个容器中的元素，或是容器最后一个元素之后的位置。
- 我们可以通过反复递增 begin 来达到 end。end 不能在 begin 之前。

#练习9.4
```
bool Find(std::vector<int>::const_iterator begin,
          std::vector<int>::const_iterator end,
          int num) {
    while (begin++ != end) {
        if (*begin == num) return true;
    }

    return false;
}
```
