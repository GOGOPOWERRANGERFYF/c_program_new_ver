/*
    词法分析
    语法分析
    语义分析
    中间表示(中间代码生成)
    这些都属于编译器前端的部分
*/
/*
    第5章  语义分析

    编译器的语义分析(semantic analysis)阶段的任务是:
    将变量的定义与它们各个使用联系起来,检查每一个表达式是否有正确的类型,
    并将抽象语法转换成更简单的、适合于生成机器代码的表示。

    5.1 符号表

        语义分析阶段一个主要的工作是符号表的管理,
        符号表(symbol table)也称为环境(environment),
        其作用是将标识符映射到它们的类型和存储位置。
        在处理类型、变量和函数的声明时,这些标识符便与其在符号表中的"含义"相绑定。
        每当发现标识符的使用(即非声明性出现)时,便在符号表中查看它们的含义。

        程序中的每一个局部变量都有一个作用域(scope),该变量的此作用域中是可见的。
        作用域中声明的变量、类型和函数在作用域范围内都是可见的。
        当语义分析到每一个作用域的结束时,所有此作用域的标识符都将被抛弃。
        ==> (网络资料:C的变量作用域通常只是编译器前端里的概念,
        如果不考虑输出调试符号信息的需求的话,变量作用域在编译器后端是不需要的。
        到符号表在代码生成过程中的作用是将局部变量映射到寄存器或着调用栈上，将全局变量映射到全局地址.
        在代码生成后符号表就消失了,生成出来的代码里就不再带有局部变量的符号信息,
        对局部变量的“作用域”概念也就随之消失.)

        环境是由一些绑定(binding)构成的集合,所谓绑定指的是标识符与其含义之间的一种映射关系。

        ...

    5.1.1 多个符号表
        在有些语言中,可以同时存在若干种活跃的环境：
        程序中每一个模块、类或者记录都有它自己的符号表。

        ...

    5.1.2 高效的命令式风格符号表
        大型程序可能含有数千个不同的标识符,因此符号表的组织必须能够进行高效的查找。
        命令式风格的环境通常采用散列表来实现,散列表的效率很高。

        ...(待回看)

    5.1.3 高效的函数式符号表
        ...
        (大概:由散列表的问题==>到采用二叉搜索树)
        ...待后续回看阅读补充...

    ...

    ...
    
    环境
        Symbol模块中的类型table提供从符号到其绑定的映射。
        ==>注意:这个只是书本中编译器示例中的例子,提供的是思路,不是说一定要是这样子
        这样,我们将有一个类型环境(type environment)和一个值环境(value environment)。
    
    ...

    ...

    5.3 表达式类型检查
    
*/