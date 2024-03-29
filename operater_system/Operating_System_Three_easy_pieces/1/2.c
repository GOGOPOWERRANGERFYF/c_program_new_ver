/**
 * 第2章 操作系统介绍
 * 
 *  ...
 * 
 *     程序运行时会发生什么？
 *     一个正在运行的程序会做一件非常简单的事情：执行指令。处理器从内存中获取（fetch）
 * 一条指令，对其进行解码（decode）（弄清楚这是哪条指令），然后执行（execute）它（做它
 * 应该做的事情，如两个数相加、访问内存、检查条件、跳转到函数等）。完成这条指令后，
 * 处理器继续执行下一条指令，依此类推，直到程序最终完成。
 *     这样，我们就描述了冯•诺依曼（Von Neumann）计算模型的基本概念。听起来很简
 * 单，对吧？但在这门课中，我们将了解到在一个程序运行的同时，还有很多其他疯狂的事
 * 情也在同步进行——主要是为了让系统易于使用。
 *     实际上，有一类软件负责让程序运行变得容易（甚至允许你同时运行多个程序），允许
 * 程序共享内存，让程序能够与设备交互，以及其他类似的有趣的工作。这些软件称为操作
 * 系统（Operating System，OS），因此它们负责确保系统既易于使用又正确高效地运行。
 * 
 *                          关键问题：如何将资源虚拟化
 *     我们将在本书中回答一个核心问题：操作系统如何将资源虚拟化？这是关键问题。...
 * ...
 * 
 *     要做到这一点，操作系统主要利用一种通用的技术，我们称之为虚拟化（virtualization）。
 * 也就是说，操作系统将物理（physical）资源（如处理器、内存或磁盘）转换为更通用、更
 * 强大且更易于使用的虚拟形式。因此，我们有时候将操作系统称为虚拟机（virtual machine）。
 *     当然，为了让用户可以告诉操作系统做什么，从而利用虚拟机的功能（如运行程序、
 * 分配内存或访问文件），操作系统还提供了一些接口（API），供你调用。实际上，典型的操
 * 作系统会提供几百个系统调用（system call），让应用程序调用。由于操作系统提供这些调用
 * 来运行程序、访问内存和设备，并进行其他相关操作，我们有时也会说操作系统为应用程序提供了
 * 一个标准库（standard library）。
 *     最后，因为
 * 
 * 2.1 虚拟化CPU
 *     （书本的例程很值得学习，对我这个菜鸡很有帮助。。。）
 *      ...
 * 
 * 
 * 
 * 2.2 虚拟化内存
 *     现在让我们考虑一下内存。现代机器提供的物理内存（physical memory）模型非常简单。
 * 内存就是一个字节数组。要读取（read）内存，必须指定一个地址（address），才能访问存储
 * 在那里的数据。要写入（write）或更新（update）内存，还必须指定要写入给定地址的数据。
 *     程序运行时，一直要访问内存。程序将所有数据结构保存在内存中，并通过各种指令
 * 来访问它们，例如加载和保存，或利用其他明确的指令，在工作时访问内存。不要忘记，
 * 程序的每个指令都在内存中，因此每次读取指令都会访问内存。
 *     ...
 *     
 *     实际上，这正是操作系统虚拟化内存（virtualizing memory）时发生的情况。每个进程
 * 访问自己的私有虚拟地址空间（virtual address space）（有时称为地址空间，address space），
 * 操作系统以某种方式映射到机器的物理内存上。
 * 
 * 
*/