- 1.标准库算法对迭代器而不是容器进行操作。因此，算法不能（直接）添加或删除容器中的元素。
为了删除或添加元素，我们必须使用容器操作。

- 四种可调用的对象，分别是函数，函数指针，重载了 () 的类，以及 lambda 表达式。

- lambda 表达式形式 [capture list](parameter list) -> return type { function body }
capture list 是一个 lambda 所在函数中定义的局部变量的列表（通常为空）。return type，
parameter list 和 function body 与普通函数相同。但是 lambda 表达式必须使用尾置返回
来指定返回类型。
-- 我们可以忽略参数列表和返回类型，但是必须包含 capture 和 function body。
-- 一个 lambda 表达式只有在其捕获列表中捕获一个它所在函数中的局部变量，才能在其函数体中使用该变量。
