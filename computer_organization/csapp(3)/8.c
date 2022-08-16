/*
    第二部分 在系统上运行程序
*/

/*
    第7章 链接
        ...
*/

/*
    第8章 异常控制流

    从给处理器加电开始,直到你断电为止,程序计数器假设一个值的序列
        a0,a1,...,an-1
    其中,每个ak是某个相应的指令Ik的地址.每次从ak到ak+1的过渡称为控制转移(control transfer).
    这样的控制转移序列叫做处理器的控制流(flow of control或control flow).

    最简单的一个控制流是一个"平滑的"序列,其中每个Ik和Ik+1在内存中都是相邻的.这种平滑流的突变(也就是Ik+1与Ik不相邻)
    通常是由诸如跳转、调用和返回这样一些熟悉的程序指令造成的.这样一些指令都是必要的机制,使得程序能够对由程序变量表示
    的内部程序状态中的变化做出反应.

    但是系统也必须能够对系统状态的变化做出反应,这些系统状态不是被内部程序变量捕获的,而且也不一定要和程序的执行相关.
    比如,一个硬件定时器定期产生信号,这个事件必须得到处理.包到达网络适配器后,必须存放在内存.程序向磁盘请求数据,然后休眠,
    直到被通知说数据已就绪.当子进程终止时,创造这些子进程的父进程必须得到通知.

    现代系统通过使控制流发生突变来对这些情况做出反应.一般而言,我们把这些突变称为异常控制流(exceptional control flow, ECF).
    异常控制流发生在计算机系统的各个层次,内核通过上下文切换将控制从一个用户进程转移到异常处理程序.在操作系统层,内核通过上下文
    切换将控制从一个用户进程转移到另一个用户进程.在应用层,一个进程可以发送信号到另一个进程,而接收者会将控制突然转移到它的一个信号
    处理程序.一个程序可以通过回避通常的栈规则,并执行到其他函数中任意位置的非本地跳转来对错误做出反应.

    作为程序员,理解ECF很重要,这有很多原因:
        理解ECF将帮助你理解重要的系统概念.ECF是操作系统用来实现I/O、进程和虚拟内存的基本机制.在能够真正理解这些重要概念之前,你
        必须理解ECF.

        理解ECF将帮助你理解应用程序是如何与操作系统交互的.应用程序通过使用一个叫做陷阱(trap)或者系统调用(system call)的ECF形式,
        向操作系统请求服务.比如,向磁盘写数据、从网络读取数据、创建一个新进程,以及终止当前进程,都是通过应用程序调用系统调用来实现的.
        理解基本的系统调用机制将帮助你理解这些服务是如何提供给应用的.

        理解ECF将帮助你编写有趣的新应用程序.操作系统为应用程序提供了强大的ECF机制,用来创建新进程、等待进程终止、通知其他进程系统
        中的异常事件,以及检测和响应这些事件.如果理解了这些ECF机制,那么你就能用它们来编写诸如Unix shell和web服务器之类的有趣程序了.

        理解ECF将帮助你理解并发.ECF是计算机系统中实现并发的基本机制.在运行中的并发例子有:中断应用程序执行的异常处理程序,在时间上
        重叠执行的进程和线程,以及中断应用程序执行的信号处理程序.理解ECF是理解并发的第一步.我们会在第12章中更详细地研究并发.

        理解ECF将帮助你理解软件异常如何工作.向C++和Java这样的语言通过try、catch以及throw语句来提供软件异常机制.软件异常允许
        程序进行非本地跳转(即违反通常的调用/返回栈规则的跳转)来响应错误情况.非本地跳转是一种应用层ECF,在C中是通过setjmp和
        longjmp函数提供的.理解这些低级函数将帮助你理解高级软件异常如何得以实现.

    对系统的学习,到目前为止你已经了解了应用是如何与硬件交互的.本章的重要性在于你将开始学习应用是如何与操作系统交互的.有趣的是,
    这些交互都是围绕着ECF的.我们将描述存在于一个计算机系统中所有层次上的各种形式的ECF.从异常开始,异常位于硬件与操作系统交界的部分.
    我们还会讨论系统调用,它们是为应用程序提供到操作系统的入口点的异常.然后,我们将提升抽象的层次,描述进程和信号,它们位于应用和操作
    系统的交界之处.最后讨论非本地跳转,这是ECF的一种应用层形式.

    个人总结: 
        pc program counter寄存器,控制转移(control transfer),控制流(control flow),异常控制流(exception control flow, ECF)

    8.1 异常
    异常是异常控制流的一种形式,它一部分由硬件实现,一部分由操作系统实现.因为它们有一部分是由硬件实现的,所以具体细节将随系统的不同
    而有所不同.然而,对于每个系统而言,基本的思想都是相同的.在这一节中我们的目的是让你对异常和异常处理有一个一般性的了解,并且向你
    揭示现代计算机系统的一个经常令人感到迷惑的方面.
    异常(exception)就是控制流中的突变,用来响应处理器状态中的某些变化.
    图8-1展示了基本的思想.
                           应用程序                    异常处理程序
                              |                           
                              |
                              |         异常
    事件在这里发生-----> I curr V ------------------------->+ 
                       I next | <---+                     | 异常
                              |      \                    | 处理
                              |       +-------------------V
                              |          异常返回(可选)
                              |
    图8-1 异常的剖析.处理器状态中的变化(事件)触发从应用程序到异常处理程序的突发的控制转移(异常).
    在异常处理程序完成处理后,它将控制返回给被中断的程序或者终止.
    在图中,当处理器状态中发生一个重要的变化时,处理器正在执行某个当前指令I curr.在处理器中,状态被编码为不同的位和信号.
    状态变化称为事件(event).事件可能和当前指令的执行直接相关.比如,发生虚拟内存缺页、算术溢出,或者一条指令试图除以零.
    另一方面,事件也可能和当前指令的执行没有关系.比如,一个系统定时器产生信号或者一个I/O请求完成.
    在任何情况下,当处理器检测到有事件发生时,它就会通过一张叫做异常表(exception table)的跳转表,进行一个间接过程调用(异常),
    到一个专门设计用来处理这类事件的操作系统子程序(异常处理程序(exception handler)).当异常处理程序完成处理后,根据引起异常
    的事件的类型,会发生一下3种情况中的一种:
    1) 处理程序将控制返回给当前指令I curr,即当前事件发生时正在执行的指令.
    2) 处理程序将控制返回给I next,如果没有发生异常将会执行的下一条指令.
    3) 处理程序终止被中断的程序.
    8.1.2节将讲述关于这些可能性的更多内容.
    旁注 硬件异常与软甲异常
    C++和Java的程序员会注意到术语"异常"也用来描述C++和Java以catch,throw和try语句形式提供的应用及ECF.如果想严格清晰,
    我们必须区别"硬件"和"软件"异常,但这通常是不必要的,因为从上下文种就能够很清楚地知道是那种含义.

    8.1.1 异常处理
    异常可能会难以理解,因为处理异常需要硬件和软件紧密结合.很容易搞混哪个部分执行哪个任务.让我们更详细地来看看硬件和软件
    的分工吧.
    系统中可能的每种类型的异常都分配了一个唯一的非负整数的异常号(exception number),其中一些号码是由处理器的设计者分配的,
    其他号码是由操作系统内核(操作系统常驻内存的部分)的设计者分配的.前者的示例包括被零除、缺页、内存访问违例、断点以及算术
    运算溢出.后者的示例包括系统调用和来自外部I/O设备的信号.
    在系统启动时(当计算机重启或者加电时),操作系统分配和初始化一张称为异常表的跳转表,使得表目k包含异常k的处理程序的地址.
    图8-2展示了异常表的格式.(直接去书上看,其实也不用,下图8-3的异常表部分我已经把8-2的内容结合上去了...)
    图8-2 异常表.异常表是一张跳转表,其中表目K包含异常k的处理程序代码的地址.
    在运行时(当系统在执行某个程序时),处理器检测到发生了一个事件,并且确定了相应的异常号k.随后,处理器触发异常,方式是执行
    间接过程调用,通过异常表的表目k,转到相应的处理程序.图8-3展示了处理器如何使用异常表来形成适当的异常处理程序的地址.异
    常号是到异常表中的索引,异常表的起始地址放在一个叫做异常表基址寄存器(exception table base register)的特殊CPU寄
    存器里.
                                                         异常表
                        异常号                         0  [    ] (异常处理程序0的代码的地址)
                        (x84)                         1  [    ] (异常处理程序1的代码的地址)
                          |                  +------> 2  [    ] (异常处理程序2的代码的地址)
                          V 异常k的条目的地址  |             ...        ...
     [异常表基址寄存器]--->(+)-----------------+       n-1 [    ] (异常处理程序n-1的代码的地址)
        图8-3 生成异常处理程序的地址(注解:异常号,基址偏移地址).(*重点)异常号是到异常表中的索引.
    异常类似于过程调用,但是有一些重要的不同之处:
    * 过程调用时,在跳转到处理程序之前,处理器将返回地址压入栈中.然而,根据异常的类型,返回地址要么是当前指令(当事件
      发生时正在执行的指令),要么是下一条指令(如果事件不发生,将会在当前指令后执行的指令).
    * 处理器也把一些额外的处理器状态压到栈里,在处理程序返回时,重新开始执行被中断的程序会需要这些状态.比如,x86-64系统会将
      包含当前条件码的EFLAGS寄存器和其他内容压入栈中.(附加:EFLAGS register:program status and control,主要用于提供
      程序的状态及进行相应的控制.)
    * 如果控制从用户程序转移到内核,所有这些项目都被压到内核栈中,而不是压到用户栈中.
    * 异常处理程序运行在内核模式下(见8.2.4节),这意味着它们对所有的系统资源都有完全的访问权限.
    一旦硬件触发了异常,剩下的工作就是由异常处理程序在软件中完成.在处理程序处理完事件之后,它通过执行一条特殊的"从中断返回"
    指令,可选地返回到被中断的程序,该指令将适当的状态弹回到处理器的控制和数据寄存器中,如果异常中断的是一个用户程序,就将状
    态恢复为用户模式(见8.2.4节:控制寄存器,模式位),然后将控制返回给被中断的程序.

    8.1.2 异常的类别
    异常可以分为四类:中断(interrupt)、陷阱(trap)、故障(fault)和终止(abort).图8.4中的表对这些类别的属性做了小结.
     类别          原因           异步/同步             返回行为
     中断   来自I/O设备的信号         异步           总是返回到下一条指令
     陷阱   有意的异常               同步           总是返回到下一条指令
     故障   潜在可恢复的错误          同步           可能返回到当前指令
     终止   不可恢复的错误            同步           不会返回
    图8-4 异常的类别,异步异常是由处理器外部的I/O设备中的事件产生的,同步异常是执行一条指令的直接产物.
    1. 中断
    中断是异步发生的,是来自处理器外部的I/O设备的信号的结果.硬件中断不是由任意一条专门的指令造成的,从这个意义上来说它是异步的.
    硬件中断的异常处理程序常常称为中断处理程序(interrupt handler).
    图8-5概述了一个中断的处理.I/O设备,例如网络适配器、磁盘控制器和定时器芯片,通过向处理器芯片上的一个引脚发信号,并将异常号
    放到系统总线上,来触发中断,这个异常号标识了引起中断的设备.
                                         |
                                         |    (2)在当前指令完成后,控制传递给处理程序
        (1)在当前指令的执行过程中,中 I curr V-------------------------------------->
        断引脚电压变高了            I next | <----+                               |  (3)中断处理程序运行
                                         |      \                               |
                                         |       +------------------------------V
                                         |  (4)处理程序返回到下一条指令
                                         V
        图8-5 中断处理,中断处理程序将控制返回给应用程序控制流中的下一条指令
    在当前指令完成执行之后,处理器注意到中断引脚的电压变高了,就从系统总线读取异常号,然后调用适当的中断处理程序.当处理程序返回
    时,它就将控制返回给下一条指令(也即如果没有发生中断,在控制流中会在当前指令之后的那条指令).结果是程序继续执行,就好像没有发
    生过中断一样.
    剩下的异常类型(陷阱、故障和终止)是同步发生的,是执行当前指令的结果.我们把这类指令叫做故障指令(faulting instruction).
    2. 陷阱和系统调用
    陷阱是有意的异常,是执行一条指令的结果.就像中断处理程序一样,陷阱处理程序将控制返回到下一条指令.陷阱最重要的用途是在用户程序
    和内核之间提供一个像过程一样的接口,叫做系统调用.
    (个人理解:用户进程通过异常这个"接口:方法/函数"[系统调用]控制转移到异常处理程序[内核态进程]? 
    陷阱:"异常"指令:系统调用指令,执行到/踩到陷阱,触发异常?)
    用户程序经常需要向内核请求服务,比如读一个文件(read)、创建一个新的进程(fork)、加载一个新的程序(execve),或者终止当前进程(exit).
    为了允许对这些内核服务的受控访问,处理器提供了一条特殊的"syscall n"指令,当用户程序想要请求服务n时,可以执行这条指令.执行syscall
    指令会导致一个到异常处理程序的陷阱,这个处理程序解析参数,并调用适当的内核程序.图8-6概述了一个系统调用的处理.
                                         |
                                         |    (2)控制传递给处理程序
        (1)应用程序               syscall V-------------------------------------->
        执行一次系统调用            I next | <----+                                |  (3)陷阱处理程序运行
                                         |       \                               |
                                         |        +------------------------------V
                                         |  (4)处理程序返回到syscall之后的指令
                                         V
        图8-6 陷阱处理.陷阱处理程序将控制返回给应用程序控制流中的下一条指令
    从程序员的角度来看,系统调用和普通的函数调用是一样的.然而,它们的实现非常不同.普通的函数运行在用户模式中,用户模式限制了函数可以
    执行的指令的类型,而且它们只能访问与调用函数相同的栈.系统调用运行在内核模式中,内核模式允许系统调用执行特权指令,并访问定义在内核
    中的栈.8.2.4节会更详细地讨论用户模式和内核模式.
    3. 故障
    故障由错误情况引起,它可能能够被故障处理程序修正.当故障发生时,处理器将控制转移给故障处理程序(个人理解:实际是进程?).如果处理程序
    能够修正这个错误情况,它就将控制返回到引起故障的指令,从而重新执行它.否则,处理程序返回到内核中的abort例程,abort例程会终止引起故障
    的应用程序.图8-7概述了一个故障的处理.
                                         |
                                         |    (2)控制传递给处理程序
        (1)当前指令            I curr <---+-------------------------------------->
        导致了一个故障                     +------+                                |  (3)故障处理程序运行
                                         |       \                               |
                                         |        +------------------------------V----------> abort
                                         |                  (4)处理程序要么重新执行当前指令,要么终止
                                         V
        图8-7 故障处理.根据故障是否能够被修复,故障处理程序要么重新执行引起故障的指令,要么终止
    一个经典的故障实例是缺页异常,当指令引用一个虚拟地址,而与该地址相对应的物理页面不在内存中,因此必须从磁盘中取出时,就会发生故障.
    就像我们将在第9章中看到的那样,一个页面就是虚拟内存的一个连续的块(典型的是4KB).缺页处理程序从磁盘加载适当的页面,然后将控制返回
    给引起故障的指令.当指令再次执行时,相应的物理页面已经驻留在内存中了,指令就可以没有故障地运行完成了.
    4. 终止
    终止是不可恢复的致命错误造成的结果,通常是一些硬件错误,比如DRAM或者SRAM位被损坏时发生的奇偶错误.终止处理程序从不将控制返回给
    应用程序.如图8-8所示,处理程序将控制返回给一个abort例程,该例程会终止这个应用程序(释放进程的内存空间?).

    8.1.3 Linux/x86-64系统中的异常
    为了使描述更具体,...(暂时忽略)

    8.2 进程
    异常是允许操作系统内核提供进程(process)概念的基本构造块,进程是计算机科学中最深刻、最成功
    的概念之一.
    在现代系统上运行一个程序时,我们会得到一个假象,就好像我们的程序是系统中当前运行的唯一的程序一样.我们的程序好像是
    独占地使用处理器和内存.处理器就好像是无间断地一条接一条地执行我们程序中的指令.最后,我们程序中的代码和数据好像是
    系统内存中唯一的对象.这些假象都是通过进程的概念提供给我们的.
    <进程的经典定义就是一个执行中程序的实例>.系统中的每个程序都运行在某个进程的上下文(context)中.上下文是由程序正确运行
    所需的状态组成的.这个状态包括存放在内存中的程序的代码和数据,它的栈、通用目的寄存器的内容、程序计数器、环境变量以及
    打开文件描述符的集合.
    (个人暂时的理解:是否可简单具象化为程序存储在硬盘,进程、进程的上下文(程序的状态)在内存呢,待验证...)
    每次用户通过shell输入一个可执行目标文件的名字,运行程序时,shell就会创建一个新的进程,然后在这个新进程的上下文中运行
    这个可执行目标文件.应用程序也能够创建新进程,并且在这个新进程的上下文中运行它们自己的代码或其他应用程序.

    关于操作系统如何实现进程的细节的讨论超出了本书的范围,反之,我们将关注进程提供给应用程序的关键抽象:
        一个独立的逻辑控制流,它提供一个假象,好像我们的程序独占地使用处理器.
        一个私有的地址空间(address space),它提供一个假象,好像我们的程序独占地使用内存系统,让我们更深入地看看这些抽象.

    8.2.1 逻辑控制流
    即使在系统中通常有许多其他程序在运行,进程也可以向每个程序提供一种假象,好像它在独占地使用处理器.如果想用调试器单步执行
    程序,我们会看到一系列的程序计数器(PC)的值,这些值唯一地对应于包含在程序的可执行目标文件中的指令,或是包含在运行时动态
    链接到程序的共享对象中的指令.这个PC值得序列叫做逻辑控制流,或者简称逻辑流.
    考虑一个运行着三个进程的系统,如图8-12所示.处理器的一个物理控制流被分成了三个逻辑流,每个进程一个.每个竖直的条表示一个
    进程的逻辑流的一部分.在这个例子中,三个逻辑流的执行是交错的.进程A运行了一会儿,然后是进程B开始运行到完成.然后,进程C运
    行了一会儿,进程A接着运行直到完成.最后,进程C可以运行到结束了.
       时间        进程A         进程B         进程C
        |           |
        |                        |
        |                        |
        |                                     |
        |           |
        |           |
        |                                     |
        V
        图8-12 逻辑控制流.进程为每个程序提供了一种假象,好像程序在独占地使用处理器.
        每个竖直的条表示一个进程的逻辑控制流的一部分
    图8-12的关键点在于进程是轮流使用处理器的.每个进程执行它的流的一部分,然后被抢占(preempted)(暂时挂起),然后轮到其他进程.
    对于一个运行在这些进程之一的上下文中的程序,它看上去就像是在独占地使用处理器.唯一的反面例证是,如果我们精确地测量每条指令
    使用的时间,会发现在程序中一些指令的执行之间,CPU好像会周期性地停顿.然而,每次处理器停顿,它随后会继续执行我们的程序,并不
    改变程序内存位置或寄存器的内容.

    8.2.2 并发流
    计算机系统中逻辑流有许多不同的形式.异常处理程序、进程、信号处理程序、线程和Java进程都是逻辑流的例子.
    一个逻辑流的执行在时间上与另一个流重叠,称为并发流(concurrent flow),这两个流被称为并发地运行.更准
    确地说,流X和Y互相并发,当且仅当X在Y开始之后和Y结束之前开始,或者Y在X开始之后和X结束之前开始.例如,图
    8-12中,进程A和B并发地运行,A和C也一样,另一方面,B和C没有并发地运行,因为B的最后一条指令在C的第一条
    指令之前执行.
    多个流并发地执行的一般现象被称为并发(concurrency),一个进程和其他进程轮流运行的概念称为多任务(multitasking),
    一个进程执行它的控制流的一部分的每一时间段叫做时间片(time slice).因此,多任务也叫做时间分片(time slicing).
    例如,图8-12中,进程A的流由两个时间片组成.
    注意,并发流的思想与流运行的处理器核心数或者计算机数无关.如果两个流在时间上重叠,那么它们就是并发的,即使它们是运行
    在同一个处理器上.不过,有时我们会发现确认并行流是很有帮助的,它是并发流的一个真子集.如果两个流并发地运行在不同的处
    理器核或者计算机上,那么我们称它们为并行流(parallel flow),它们并行地运行(running in parallel),且并行地执行(
    parallel execution).
    (个人注解:<*重点:两个流在时间上重叠,就是并发>注意:单个核心,并发的进程在核心中是错开轮流执行的,称为多任务;
    多个核心或计算机上,为并发流的子集并行流)

    8.2.3 私有地址空间
    进程也为每个程序提供一种假象,好像它独占地使用系统地址空间.在一台n位地址的机器上,地址空间是2^n个可能地址的集合,
    0,1,...,2^n-1.进程为每个程序提供它自己的私有地址空间.一般而言,和这个空间中某个地址相关联的那个内存字节是不能被
    其他进程读或者写的,从这个意义上说,这个地址空间是私有的.
    尽管和每个私有地址空间相关联的内存的内容一般是不同的,但是每个这样的空间都有相同的通用结构.比如,图8-13展示了一个
    x86-64 Linux进程的地址空间的组织结构.
    地址空间底部都是保留给用户程序的,包括通常的代码、数据、堆和栈段.代码总是从地址0x400000开始.地址空间顶部保留给内核
    (操作系统常驻内存的部分).地址空间的这个部分包含内核在代表进程执行指令时(比如当应用程序执行系统调用时)使用的代码、
    数据和栈.
                (...图去书本上看)
                图8-13 进程的地址空间

    8.2.4 用户模式和内核模式
    为了使操作系统内核提供一个无懈可击的进程抽象,处理器必须提供一种机制,限制一个应用可以执行的指令以及它可以访问的
    地址空间范围.
    处理器通常是用某个控制寄存器中的一个模式位(mode bit)来提供这种功能的,该寄存器描述了进程当前享有的特权.但设置
    了模式位时,进程就运行在内核模式中(有时叫做超级用户模式).一个运行在内核模式的进程可以执行指令集中的任何指令,并且
    可以访问系统中的任何内存位置.
    没有设置模式位时,进程就运行在用户模式中.用户模式中的进程不允许执行特权指令(privileged instruction),比如停止
    处理器、改变模式位,或者发起一个I/O操作.也不允许用户模式中的进程直接引用地址空间中内核区的代码和数据.任何这样的
    尝试都会导致致命的保护故障.反之,用户程序必须通过系统调用接口间接地访问内核代码和数据.
    运行应用程序代码的进程初始时是在用户模式中的.进程从用户模式变为内核模式的唯一方法是通过诸如中断、故障或者陷入系统
    调用这样的异常(标注:温习一下上面的异常控制流知识点).当异常发生时,控制传递到异常处理程序、处理器将模式从用户模式变为
    内核模式.处理程序运行在内核模式中,当它返回到应用程序代码时,处理器就把模式从内核模式该回到用户模式.
    Linux提供了一种聪明的机制,叫做/proc文件系统,它允许用户模式进程访问内核数据结构的内容,/proc文件系统将许多内核数据
    结构的内容输出为一个用户程序可以读的文本文件的层次结构.比如,你可以使用/proc文件系统找出一般的系统属性,比如CPU类型
    (/proc/cpuinfo),或者某个特殊的进程使用的内存段(/proc/<process-id>/maps).2.6版本的Linux内核引入/sys文件系统,
    它输出关于系统总线和设备的额外的低层信息.==>个人总结:linux提供了/proc和/sys可以用用户模式进程访问内核的数据.

    8.2.5 上下文切换
    操作系统内核使用一种称为上下文切换(context switch)的较高层形式的异常控制流来实现多任务.上下文切换机制在8.1节中
    已经讨论过的那些较低层异常机制之上的.
    内核为每个进程维持一个上下文(context).
    ...(待完善)

    8.3 系统调用错误处理
    ...

    8.4 进程控制
    Unix提供了大量从C程序中操作进程的系统调用.这一节将描述这些重要的函数,并举例说明如何使用它们.
    8.4.1 获取进程ID
    每个进程都有一个唯一的整数(非零)进程ID(PID).getpid函数返回调用进程的PID.getppid函数返回它的父进程的PID(创建
    调用进程的进程).
    #include <sys/types.h>
    // C头文件目录/usr/include/, 本例中头文件sys文件夹路径/usr/include/x86_64-linux-gnu/sys
    #include <unistd.h>
    pid_t getpid(void);
    pid_t getppid(void);    // 返回,调用者或其父进程的PID
    getpid和getppid函数返回一个类型为pid_t的整数值,在linux系统上它在types.h中被定义为int.

    8.4.2 创建和终止进程
    从程序员的角度,我们可以认为进程总是处于下面三种状态之一:
    *运行.进程要么在CPU上执行,要么在等待被执行且最终会被内核调度.
    *停止.进程的执行被挂起(suspended),且不会被调度.当收到SIGSTOP、SIGTSTP、SIGTTIN或者SIGTTOU信号时,进程就停止,并且
     保持停止直到它收到一个SIGCONT信号,在这个时刻,进程再次开始运行.(信号是一种软件中断的形式,将在8.5节中详细描述.)
    *终止.进程永远地停止了.进程会因为三种原因终止:1)收到一个信号,该信号的默认行为是终止进程,2)从主程序返回,3)调用exit函数
    #include <stdlib.h>
    void exit(int status); // 该函数不返回
    exit函数以status退出状态来终止进程(另一种设置退出状态的方法是从主程序中返回一个整数值).
    父进程通过调用fork函数创建一个新的运行的子进程.
    (fork 分叉; branch 分支;)
    #include <sys/types.h>
    #include <unistd.h>
    pid_t fork(void);   // 返回:子进程返回0,父进程返回子进程的PID,如果出错,则为-1.
    
*/
