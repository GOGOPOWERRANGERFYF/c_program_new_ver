/*
第4章 类型和声明

4.1 类型
    ...

4.9 声明
    一个名字（标识符）能够在C++程序里使用之前必须首先声明。
    Before a name(identifier) can be used in a  C++ program, it must be declared. That is, its type must
be specified to inform the compiler what kind of entity the name refers. ...
    ...




4.9.1 声明的结构
    一个声明由四个部分组成：一个可选的 “说明符”，一个基础类型，一个声明符，还有一
个可选的初始式。
    A declaration consists of four parts: an optional “specifier”, a basic type, a declarator, and an
optional initializer.

    ...

4.9.4 作用域

4.9.6 对象和左值
    ... 因此，对一个名字的某种需求就是它应该表示“存储器里的什么东
    西”。这也就是最简单最基本的对象概念。这样，一个对象就是存储中一片连续的区域；左值
    就是引用某个对象的表达式。术语左值原本是想说 “某个可以放在赋值左边的东西”。然而，
    并不是每个左值都能够被用在赋值的左边，左值也可以是引用某个常量(5.5节)。没有被
    声明为常量的左值常常被称做是可修改的左值。不要将对象的这种简单和低级的概念与类对
    象和多态性类型(15.4.3节)的对象概念弄混淆了。

*/