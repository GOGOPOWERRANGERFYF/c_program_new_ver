/*
    namespace 名称空间
*/
/*
    第2章 开始学习c++

    2.1.5 名称空间
        如果使用iostream,而不是iostream.h,则应使用下面的名称空间编译指令
        来使iostream中的定义对程序可用:
        using namesapce std; (备注:其实这个在实际工作中不推荐使用...)
        cout << "string" << endl;
        这叫using编译指令(directive)。

        名称空间是c++中一项较新的特性(与C++11之前对比...)
        它是为了让编写将多个厂商已有的代码组合起来的程序更简单而设计的。

        std::cout << "string" << std::endl;

        using std::cout;
        using std::endl;
        cout << "string" << endl;

        c++编译器的标准组件类、函数和变量,都被放置在名称空间std中。
        仅当头文件没有扩展名h时,情况才是如此。(个人猜想:为了兼容C?因为C并没有名称空间)
        (个人理解:名称空间是为了区分不同的库)

    2.1.6 使用cout进行c++输出 P18
        cout << "string"
        cout是一个预定义的对象,
        <<为插入操作符(插入到输出流中)
        cout对象处理插入到输出流中的字符串。

        操作符重载
        插入操作符<<与按位左移操作符<<  符号相同.
        这是一个操作符重载的例子,通过重载,同一个操作符将有不同的含义。
        编译器通过上下文来确定操作符的含义,C本身也有一些操作符重载的情况,
        例如,&符号即表示地址操作符,又表示按位与AND操作符。
        *符号即表示乘法、又表示对指针的解引用。
        编译器可以根据上下文来确定其含义,C++扩展了操作符重载的概念,允许用户定义的类型(类)
        重新定义操作符的含义。

        1. 控制符(manipulator) endl
            endl和cout一样,都是在iostream中定义的,位于名称空间std中。
            (网络资料:endl是一个函数模板...暂时不懂这玩意...)

        2. 换行符
            '\n' 转义序列

*/

/*
    第4章 复合类型

    4.7 指针和自由存储空间
        ...
    4.7.4 使用new来分配内存
    对指针的工作方式有一定的了解后,来看一看它如何实现重要的OOP技术--在程序运行时分配
    内存。
    前面,我们将指针初始化为变量的地址,变量是在编译时分配、有名称的内存,而指针只是为可以通过
    名称直接访问的内存提供了一个别名。(个人理解:直接寻址和间接寻址,计算机组成原理的知识)
    指针真正的用武之地在于,在运行阶段分配未命名的内存以存值。在这种情况下,只能通过指针来访问内存。
    在C标准库中,可以用函数malloc()来分配内存;在C++中仍然可以这样做,但C++有更好的方法--new操作符。

    int * p = new int;

    ==>这一段务必要理解透...让人茅塞顿开~



    4.7.5 使用delete来释放内存
        ...
    4.7.6 使用new来创建动态数组
        ...
*/