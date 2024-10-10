/*
    ECMAScript规范(规范原文只有英文，这里的中文均为：AI翻译 或 个人添加的注解)：

    ...

    9  Executable Code and Execution Contexts 可执行代码和执行上下文
    9.1 Environment Records 环境记录
    环境记录是一种规范类型，用于根据ECMAScript代码的词法嵌套结构定义标识符与特定变量和函数的关联。
    通常，环境记录与ECMAScript代码的某些特定语法结构相关联，如函数声明、块语句或Try语句的Catch子句。
    每次评估此类代码时，都会创建一个新的环境记录，以记录由该代码创建的标识符绑定。

    每个环境记录都有一个[[OuterEnv]]字段，该字段要么是null，要么是对外部环境记录的引用。这用于模拟环境记录值的逻辑嵌套。
    内部环境记录的外部引用是对逻辑上包围内部环境记录的环境记录的引用。外部环境记录当然可能有它自己的外部环境记录。
    一个环境记录可以作为多个内部环境记录的外部环境。例如，如果一个函数声明包含两个嵌套的函数声明，那么每个嵌套函数的环境记录
    将把当前评估的周围函数的环境记录作为它们的外部环境记录。

    环境记录纯粹是规范机制，不必对应于任何ECMAScript实现的具体工件。ECMAScript程序无法直接访问或操作这些值。

    9.1.1 环境记录类型层次结构 The Environment Record Type Hierarchy

    环境记录可以被看作是存在于一个简单的面向对象层次结构中，其中环境记录是一个抽象类，
    有三个具体的子类：声明性环境记录、对象环境记录和全局环境记录。
    函数环境记录和模块环境记录是声明性环境记录的子类。

    环境记录（抽象）
        1.声明性环境记录用于定义ECMAScript语言语法元素（如函数声明、变量声明和Catch子句）的效果，
          这些元素直接将标识符绑定与ECMAScript语言值关联起来。

            1.1 函数环境记录对应于ECMAScript函数对象的调用，包含该函数内顶级声明的绑定。它可能建立一个新的this绑定。
            它还捕获了支持super方法调用所需的状态。

            1.2 模块环境记录包含模块的顶级声明的绑定。它还包含模块显式导入的绑定。它的[[OuterEnv]]是一个全局环境记录。

        2.对象环境记录用于定义ECMAScript元素（如With语句）的效果，这些元素将标识符绑定与某个对象的属性关联起来。

        3.全局环境记录用于脚本全局声明。它没有外部环境；它的[[OuterEnv]]是null。它可能预先填充了标识符绑定，并且包括一个关联的全局对象，
          该对象的属性提供了全局环境的一些标识符绑定。随着ECMAScript代码的执行，可能会向全局对象添加其他属性，并且初始属性可能会被修改。

    环境记录抽象类包括表16中定义的抽象规范方法。这些抽象方法对于每个具体的子类都有不同的具体算法。

    ...


    9.4 Execution Contexts 执行上下文
    执行上下文是一种规范设备，用于跟踪ECMAScript实现运行代码时的评估。在任何给定时间点，每个代理最多有一个正在执行代码的执行上下文。
    这被称为代理的运行执行上下文。本规范中对运行执行上下文的所有引用都指的是周围代理的运行执行上下文。

    执行上下文栈用于跟踪执行上下文。运行执行上下文始终是这个栈的顶部元素。每当控制权从当前运行执行上下文关联的可执行代码转移到与之不关联的
    可执行代码时，就会创建一个新的执行上下文。新创建的执行上下文被推入栈中，并成为运行执行上下文。

    执行上下文包含跟踪其关联代码执行进度所需的任何实现特定状态。每个执行上下文至少包含表25中列出的状态组件。

            表25：所有执行上下文的状态组件
        组件	        目的
        代码评估状态	执行、挂起和恢复与此执行上下文关联的代码评估所需的任何状态。
        函数	       如果此执行上下文正在评估函数对象的代码，则此组件的值就是该函数对象。如果上下文正在评估脚本或模块的代码，则值为null。
        领域	       领域记录，关联代码从该记录访问ECMAScript资源。
        脚本或模块	    模块记录或脚本记录，关联代码起源于此。如果没有起源脚本或模块，如在InitializeHostDefinedRealm中创建的原始执行上下文的
                       情况，则值为null。

    运行执行上下文的代码评估可能在本规范内定义的多个点被挂起。一旦运行执行上下文被挂起，不同的执行上下文可能成为运行执行上下文并开始评估其代码。
    在稍后的时间，挂起的执行上下文可能再次成为运行执行上下文，并在之前挂起的点继续评估其代码。运行执行上下文状态在执行上下文之间的转换通常以类似
    栈的后进先出方式进行。然而，一些ECMAScript特性需要非LIFO的运行执行上下文转换。

    运行执行上下文的领域组件的值也称为当前领域记录。运行执行上下文的函数组件的值也称为活动函数对象。

    ECMAScript代码执行上下文还包含表26中列出的额外状态组件。

            表26：ECMAScript代码执行上下文的额外状态组件
        组件	    目的
        词法环境	标识用于解析此执行上下文中代码所做标识符引用的环境记录。
        变量环境	标识持有此执行上下文中VariableStatements创建的绑定的环境记录。
        私有环境	标识持有最近包含类中ClassElements创建的私有名称的PrivateEnvironment记录。如果没有包含类，则为null。

    执行上下文的词法环境和变量环境组件始终是环境记录。

    表示生成器评估的执行上下文包含表27中列出的额外状态组件。

            表27：生成器执行上下文的额外状态组件
        组件	目的
        生成器	此执行上下文正在评估的生成器。

    在大多数情况下，只有运行执行上下文（执行上下文栈的顶部）直接被本规范内的算法操作。因此，当使用“词法环境”和“变量环境”这些术语时，
    如果没有特别说明，它们指的是运行执行上下文的这些组件。

    执行上下文纯粹是一种规范机制，不必对应于ECMAScript实现的任何特定工件。ECMAScript代码无法直接访问或观察执行上下文。


*/

/*
    调用函数 --> 创建执行上下文 --> 压入调用栈 --> 执行上下文 --> 弹出调用栈

    每当我们加载一个脚本或调用一个函数，一个新的执行上下文就会被创建。
    ...


    执行上下文可在 ES规范 9 > 9.4 Exection Contexts 查看：
        [Execution Context(执行上下文)]:
            [Code Evaluation State]:
            [Realm]:
                [Intrinsics]
                [Global Object]
                [Global Environment Record]
            [ScriptOrModule]
            [Function]
        -------------------------------- 所有执行上下文的状态组件
            [LexicalEnvironment]:
                [Enviroment Record]
            [VariableEnvironment]:
                [Enviroment Record]
            [PrivateEnvironment]:
                [Enviroment Record]
        -------------------------------- ECMAScript代码执行上下文的额外状态组件
            [Generator]
        -------------------------------- 生成器执行上下文的额外状态组件



        执行上下文本质上定义了我们的代码执行的环境。它包含了许多引擎用来保持跟踪代码片段的执行流的内部组件,
    执行上下文用环境记录来保持跟踪和保持标识符绑定已创建的变量声明，函数声明，所有在上下文的值。

    脚本，首先加载已经创建的全局执行上下文，每个执行上下文经过两个阶段:
        1.创建阶段
            为在上下文内的变量声明,函数声明等设置(分配)内存空间
        2.执行阶段
            执行上下文在调用栈，代码实际上被执行

        全局执行上下文有许多组件,但是目前我们关注realm,lexicalEnvironment和variableEnvironment。
    一个realm(n.领域)指向a realm record，realm本质上是一个我们代码运行的独立环境，例如，当我们
    在浏览器打开一个新的标签(tab)，刷新一个页面，服务worker，web worker，iframe等等，一个新的realm被创建，
    所以它本质上是一个独立的环境。

    [Realm] 由几个组件组成，主要包括Intrinsics(内在/内置)，Global Object, Global Environment Record等。
        1. [Intrinsics] 内置？
            提供所有标准内置对象和函数，本质上是执行JavaScript的基础/基建(foundational)。
            像数组，函数，语法错误等。
        2. [全局对象] Global Object
            全局对象包含几种类型的属性：
                a. specification defined properties(规范属性:ECMAScript规范中明确定义的属性)：
                    本质只是暴露内置(intrinsics)的,Array函数等所有JavaScript的这些东西都
                    在全局对象(global object)中。
                b. host defined properties(宿主定义属性)：
                    浏览器中像fetch，setTimeout，document等也是有全局对象提供的。
                c. user defined properties(用户定义属性)：
                    作为开发者我们可以明白地添加属性到全局对象或毫无疑问地声明一个函数在全局作用域，不论何时我们
                    有一个带var关键字的变量在全局作用域，它也会被添加到全局对象中，且贯穿整个脚本都是可用的。
        3. [全局环境记录] Global Environment Record
            environment record管理上下文的标识符绑定。


    脚本 walk through：
        [全局环境记录] global environment record:
            [Object record] 对象记录: --> 全局对象 global object；
                1.在全局作用域用 var 声明的变量，绑定到全局对象；
                ...
                2.在全局作用域声明的函数，绑定到全局对象；
                [function object] 函数对象：
                    [Environment]：--> 全局环境记录 global environment record
                    [Call]：援引函数的方法
            [Declarative record] 声明性记录?:
                绑定和存储(初始化)全局作用域中用 const 或 let 关键字声明的变量，
                上下文创建阶段 绑定(binding)，在执行阶段初始化；

        
        [全局执行上下文]:
            [realm]: --> realm (intrinsics、全局对象和全局环境记录，例如一个浏览器标签)
            [LexicalEnvironment]词法环境: --> 全局环境记录 global environment record
            [VariableEnvironment]变量环境: --> 全局环境记录 global environment record

            <创建阶段>:
                变量和函数绑定 到 环境记录 -> 对象记录 或 Declarative record；
                var声明的变量会绑定到全局对象，且初始化赋值为undefined；
                let或const声明的变量会绑定到Declarative record，不会初始化赋值；
            <执行阶段>:
                var声明的变量赋值。
                let或const声明的变量初始化赋值。
                函数绑定时已在内存中初始化。

        [函数执行上下文] Function Execution Context:
            [Rleam]：-> ...
            [LexicalEnvironment]词法环境: --> 函数执行上下文环境记录
                [(函数)环境记录] Function Environment Record:
                    管理：
                        <创建阶段>：形参变量的标识符绑定，在函数执行上下文创建阶段直接绑定和初始化；

                        <创建阶段>：标识符绑定用 let 和 const 声明的变量，未初始化；
                        <执行阶段>：绑定的变量初始化。

                        <创建阶段>：在该函数作用域内的函数声明直接绑定并初始化？
                    [外部环境] OuterEnv:
                        如果该函数在全局作用域中声明，则 -> 全局环境记录 global environment record；
            [VariableEnvironment]变量环境: 在全局作用域声明时 --> [全局环境记录] global environment record
                [(函数)环境记录] Function Environment Record: ...
                    ...
                    [外部环境] OuterEnv: ...

            概括：
            <创建阶段>:
                变量和函数绑定 到 环境记录 -> 对象记录 或 Declarative record；
            <执行阶段>:
                变量初始化赋值。
                函数绑定时已在内存中初始化。

        
        补充：执行阶段，执行上下文压入调用栈。
        作用域是语言级别的概念，环境是运行时层级的概念，环境 是 运行时 管理 作用域规则 具体实现的 数据结构。
        作用域链 由 环境链([环境记录]的[外部环境:OuterEnv]的引用实现) 管理实现。


    hoisting
        变量提升发生在执行上下文的创建阶段，

    scope chain

    closure
        ...
        [[Environment]] 和 






*/

/*
    注意：
        ES规范并没有规定具体实现，词法环境记录和变量环境记录是两个独立概念，但V8引擎通常把它们合并到同一个数据结构中。


        使用ESM模块时，模块的顶级作用域为模块作用域，声明的全局变量和函数不会绑定到全局环境记录的对象记录->window对象(浏览器环境中)。
        js的模块是通过http(s)工作的。(震惊。。。)
*/

/*
    个人理解：
    js native code是编译成机器码的；
    js 函数对象是运行时创建的；
    所以console.log和console.dir输出的是两个不同的对象。
*/