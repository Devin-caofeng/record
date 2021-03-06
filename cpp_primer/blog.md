默认情况下，this 的类型是指向非常量类对象的常量指针

class Test {

};

例如在 Test 的成员函数中，this 的类型是 Test **const。尽管 this 是隐式的，但是
它仍然需要遵循初始化规则，默认情况下我们不能将 this 绑定到一个常量对象上，也就使
得我们不能用常量对象调用其普通的成员函数（因为常量不允许被被修改，而普通的成员函
数无法保证这一点，所以编译器常量对象调用非 const 成员函数）。

那这样的话，常量类对象岂不是无法调用其成员函数了吗？这样的话类的作用可能就会被大
大缩减了，c++ 肯定要有解决办法，还记得大一当时学 c++ 时看到函数的参数列表后跟了一
个 const 感觉很奇怪的样子，又对 c++ 的复杂性多了一点认识......现在想来这也是合情理
的做法，因为 this 是隐式存在的不能出现在参数列表中，所以无法向我们平常那样声明为
const Test **const 的形式，c++ 给出的做法是在函数的参数列表后加上 const 来表示
this 是一个指向常量的指针，这样的函数可以保证常量对象不被随意修改(具体见 effective c++
条款3，什么叫做不可修改，这里又可以体会到一些细节问题)，又被称为常成员函数
(const member function)

在我们编写的没有用到类的程序中，名字查找(name lookup)寻找与所用名字最匹配的声明的过程比较直接。
首先，在名字所在的块中寻找其声明语句，在当前位置之前出现的声明。
如果没有找到，继续查找外层作用域。
重复上述步骤，如果最终都未找到匹配的声明，则程序出错。

对于定义在类中的成员来说，首先编译器会先编译所有的成员的声明，直到类全部可见后才编译函数体。
按照这种方式处理类可以简化类代码的组织方式。因为成员函数体直到整个类可见后才会被处理,
所以它能够使用类中定义的任何名字。如果函数的定义和成员的声明同时被处理，那么我们就无法使用
声明在函数函数定义体之后的那些名字。

类型名要特殊处理
    一般来说，内层作用域可以重新定义外层作用域中的名字，即使该名字已经在内层作用中
    使用过
