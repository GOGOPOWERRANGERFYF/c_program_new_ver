/*
    第3章 符号表结构
    本章探讨有关符号表构造的问题,包括如何设计反映现代程序设计语言特征的符号表。
    我们首先讨论符号可能属于的存储类、以及支配符号在程序各个部分中可见性的规则,也
    即作用域规则。

    3.1 存储类、可见性和生命期
    多数程序设计语言允许给变量指定存储类(storage classes).存储类规定了
    变量的作用域、可见性和生命期等特征。   
    (个人批注:例如C语言的auto和static关键字)

    作用域(scope)是其内说明一个以上变量的静态程序结构单元。
    在许多语言中,作用域可以嵌套。
    与作用域密切相连的一个概念是变量的可见性(visibility),可见性指出
    变量名引用的特性实例(个人批注:内存块)处在什么作用域内。
    内层作用域的变量使得外层作用域的同名变量暂时变为不可见,称为
    内层 变量遮盖(shadows) 了外层变量。

    变量的生命期(lifetime)是声明此变量的程序的一段执行期,它从变量第一次
    可见时开始,到最后一次可见时结束。
    (个人批注:函数调用栈出栈后,函数的局部变量生命期结束;
             C的文件作用域变量,生命期从程序载入到程序执行完,
             C的static块作用域变量,生命期在块作用域中变量声明开始到程序执行完结束)

    几乎所有语言都有全局的(global)存储类。
    全局存储类赋予变量的生命期为程序的整个生命期(全局作用域),即,它使得
    整个程序都能见到改变量。或者,在可见性规则允许一个变量遮盖另一个变量的语言中,
    它使得该变量在未被遮盖的地方处处可见。

    如C语言,具有文件作用域存储类,这种存储类使得变量只在某个文件可见,
    但生命期为程序的整个执行期。

    大多数语言支持自动存储类或栈存储类。这种存储类将变量的作用域指定为它的程序
    单元,生命期是该程序单元的特定活跃期。
    (个人批注:其实就是代码的块吧)

    有些语言允许这种存储类,它们由限定前面所述的存储类为静态而来。
    例如,C允许将变量声明成static,这使得在程序的整个执行期间内都保存分配
    给该变量的存储空间,即使它们的声明在某个函数之内。这些变量只能在该函数内
    被访问。

    动态作用域（dynamic scopint),即作用域可以按照调用关系嵌套而不是静态嵌套。
    在动态嵌套的情况下...目前还不太了解...(闭包,JS的作用域链???)
    ... 待完善知识点:动态作用域

    3.2 符号属性和符号表项
    程序中的每一个符号都有一系列相关联的属性,这些属性既来源于源语言的语法和语义,也来源于
    程序对符号的具体声明和使用。
    典型的属性中有一些是很明显的,如符号的名字、类型、作用域和大小;
    其他一些属性,如符号的寻址方法,则不是很明显。

    本节试图枚举出各种可能的属性,并对那些不太明显的属性进行解释。    
    我们也用这种方式来讲述符号表的内容,即符号表项。
    符号表项(symbol-table entry)以一种便于设置和查找的方式集中了具体符号的各种属性。
    (个人批注:符号属性存储在符号表内,成为符号表项...)

    表3-1 符号表项中典型的域(直接看书上的就好..)
    ...

    类型引用(type referent)或者是一个指向表示构造类型结构的指针,或者是表示一个构造
    类型结构的名字。

    符号表记录最复杂的方面通常是type属性的值。一般来说,源语言类型由预定义的类型(int,char,float)
    和构造类型(对象的类型???)

    ...Pascal语言看不太懂,跳过...

    3.3 局部符号表管理
        讨论如何管理特定过程的局部符号表,这是任何代码生成方法都会遇到的一个基本问题。
        下面是一组创建、释放和管理符号表及其表项的过程接口
        (书本的示例中,SymTab是表示符号表的类型,Symbol是符号的类型)
        ...
        ...
        这里就不抄了,暂时跳过...

        设计符号表时主要的考虑是要能使符号和属性的插入和提取都尽可能地快。
        符号表构造成由表项组成的一维数组会使得查找相当慢。
        另外两种选择,即平衡二叉树和散列表,二者都能提供快速的插入、查找和提取。
        但在保持树的平衡和计算散列值上会有一些代价。
        如后面3.4节将讨论的,一般更好的方法时采用对每一个散列值带有一系列项的散列表。
        对于面向对象语言,最适合于处理作用域规则的符号表实现方法是将散列于数组结合起来使用
        ...
        图3-2 每一个散列值具有散列桶链的局部符号散列表
        这里也是暂时不太懂...
    
    3.4 全局符号表结构

    ==> 从3.2后都要待以后重新开始学习.因为不咋理解...
        暂时学到这里...主要讲的还是用怎样的数据结构实现各作用域的符号表?

    3.5 存储绑定和符号寄存器 (这个值得重复阅读,深入理解)
        存储绑定(storage binding)讲变量名转换为地址,即给变量分配地址。
        这是代码生成之中或之前必须进行的处理过程。
        在我们的中间语言层次系统中(书中示例编译器?),存储绑定是MIR至LIR转换过程
        的一部分(参见第4章),还将MIR的赋值展开为取数,运算和存储指令,并且展开调用
        为一系列的指令。

        每一个变量都被指定一个适合于其存储类的地址,更确切地说,是指定一种寻址方法。

        我们采用后一个术语。因为，给过程内的局部变量指定的不是固定的机器地址(或相对于一个
        模块的基址的固定地址),而是相对于某个寄存器的偏移来访问的一个栈地址,这个寄存器的值
        通常随着过程调用而改变。

        对于存储绑定,变量分为四种主要的类别:全局变量,全局栈变量(暂时找不到例子...)???,栈变量和栈静态变量。
        在那些允许导入变量或导入整个作用域的语言中,我们还必须考虑导入变量或导入作用域的情况。

        全局变量和具有静态存储类的变量通常分配的是固定的可重定位地址,或是相对一个基址寄存器的偏移,
        这个基址寄存器称为全局指针。

        栈变量分配的是相对栈指针或帧指针的偏移地址,因此它们可以随过程的调用而出现或消失,而且
        它们的位置也会随调用不同而改变。

        在许多语言中,堆对象的空间是动态分配的,并通过存储分配子程序设置的指针来访问,

        另一种处理栈变量(在有些情况下也用于全局变量)的方法是给它们分配寄存器而不是存储单元,
        当然,存放在寄存器中的变量通常不能通过索引来寻址,因此这种方法不能用于数组.同样,在代码
        生成之前或代码生成过程中,一般也不能给很多变量分配寄存器,因此只有数量有限的可用寄存器.

        但是我们可以给标量变量(网络资料:标量变量用于表示各个大小固定的数据对象)指定符号寄存器,
        这种符号寄存器没有个数的限制,它只是一个名字。然后,在编译过程的较后阶段再为这个名字分配
        真实的寄存器或存储单元。(这个现在看不懂,以后再看...)

        符号表管理子程序来给变量绑定存储单元。
        给每个静态变量指定一个位移(个人批注:通过全局指针?),
        给每个分配在栈中的变量指定一个位移,并用帧指针作为其基址寄存器。
        对于记录,则从第一个元素到最后一个元素,依次给每个元素指定位移和基址寄存器.(啥是记录???...)


    3.6 生成取数和存数指令的方法
        下面的过程生成取值到寄存器的取指令和将计算好的值存储到存储器适当位置的存指令。
        它们也可能会修改对应的符号表向,以反映每一个值得位置,即这个值是否在寄存器中以及
        在哪一个寄存器,并在需要时生成整数寄存器与浮点寄存器之间的传送指令,以便当使用这些
        值时它们已经在所需要类型的寄存器中。
        ===>先缓一缓,开始懵逼了... 缓过劲来再继续 
*/