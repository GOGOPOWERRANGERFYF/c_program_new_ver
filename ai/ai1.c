/**
 * 问题：主调函数给被调函数传入的参数保存在哪？
 * POE回答：
 * 在大多数编程语言中，主调函数给被调函数传入的参数通常是通过栈（stack）来传递的。栈是一种用于管理函数调用的数据结构，
 * 它在内存中以一种特定的方式组织数据。
 * 当主调函数调用一个函数时，它会将函数的参数值压入栈中。被调函数可以通过访问栈中相应的位置来获取这些参数值。在函数执
 * 行完毕后，这些参数值会从栈中弹出。
 * 具体来说，当主调函数调用被调函数时，以下步骤通常会发生：
 * 1.主调函数将被调函数的参数按照特定的调用约定（calling convention）压入栈中，或者将参数存储在寄存器中（某些参数可
 * 能会通过寄存器传递）。
 * 2.主调函数调用被调函数，控制权转移到被调函数。
 * 3.被调函数通过栈指针（stack pointer）或寄存器等方式访问栈中的参数值，以获取传入的参数。
 * 4.被调函数在执行期间使用这些参数进行计算或操作。
 * 5.当被调函数执行完毕后，它会将返回值（如果有的话）放入指定的位置（如寄存器或栈），然后控制权返回给主调函数。
 * 6.主调函数从栈中清除被调函数的参数，并继续执行后续的指令。
 * 需要注意的是，具体的参数传递和调用约定可能因编程语言、编译器、操作系统或硬件平台而有所不同。有些语言（如C）使用栈
 * 作为主要的参数传递方式，而其他语言（如寄存器传递）可能使用不同的机制。因此，在不同的环境中，参数存储的位置和传递方
 * 式可能会有所差异。
 * 
*/
/**
 * 问题：转义空格字符的作用
 * 转义空格字符的作用是在字符串中使用特殊的字符序列来表示空格。在许多编程语言和标记语言中，空格通常被视为分隔符，
 * 用于分隔关键字、标识符和其他语法元素。但是，有时候需要在字符串中包含实际的空格字符，而不是作为分隔符。 
 * 为了在字符串中表示空格字符，可以使用转义字符来转义空格。在许多编程语言中，通常使用反斜杠（\）作为转义字符的前缀，
 * 后跟特定的字符来表示特殊的含义。对于空格字符，通常使用转义序列"\ "来表示。 
 * 例如，在C语言中，如果想在字符串中插入一个空格字符，可以使用以下转义序列：
 * c
 * char* str = "Hello\ World";
 * 在上述示例中，"\ "表示一个空格字符，而不是字符串的结束符。这样，字符串中的内容将被解释为"Hello World"，其中包含一个空格字符。 
 * 转义空格字符的作用是确保空格字符在字符串中得到正确的解释和处理，而不会被视为分隔符或其他特殊含义。
*/

/**
 * 问题：CPU中断，是由CPU控制器这个硬件决定的吗？
 * AI回答：
 * 是的，CPU中断是由CPU控制器这个硬件来决定的。当硬件检测到一个中断信号时，它会立即将控制权转移到中断处理程序，并在处理程序执行
 * 完毕后，将控制权返回到中断发生前的程序。CPU控制器还负责保存和恢复中断处理程序和被中断程序的上下文信息，以确保中断处理程序能够
 * 正确地执行并返回到被中断程序。中断是操作系统中非常重要的一部分，它允许CPU在执行任务时及时响应外部事件，从而提高系统的可靠性和
 * 响应性。
 * 
 * 问题：CPU控制器检测到中断信号，是不是相当于读取到一条指令，但这条指令不是在指令寄存器中的指令？
 * AI回答：
 * 是的，CPU控制器检测到中断信号时，可以将其视为一条特殊的指令。当中断信号发生时，CPU控制器会暂停当前正在执行的指令，将当前程序
 * 的上下文信息保存到栈中，并将控制权转移到中断处理程序。中断处理程序会执行特定的任务，例如响应用户输入、处理硬件错误等。在中断处
 * 理程序执行完毕后，CPU控制器会从栈中恢复之前保存的上下文信息，并将控制权返回到之前被中断的程序。因此，中断处理程序可以被视为一
 * 种特殊的指令，它不是存储在指令寄存器中的指令，而是由中断控制器触发执行的一段程序。
 * 
 */

/**
 * 上面的回答才能解答我的疑惑，下面的回答已经没啥意义了，而且还会让我困惑。。。
 * 问题：硬件隐式保存用户寄存器的CPU详细处理过程 —— 阅读《操作系统导论》P43 时的疑问。
 * 个人附加：对于PC(程序计数器)和IR(指令寄存器)两个不同的寄存器的基本事实，我居然脑子瓦特了。。。剩下的就参看下面的回答.
 * AI回答：
 * 当计算机发生中断时，硬件会根据中断向量号找到对应的中断处理程序，并将当前运行进程的寄存器状态保存到内核栈中。这一过程涉及到CPU的中
 * 断响应和堆栈操作。
 * 具体的处理过程如下：
 * 1. CPU检测到中断信号，将当前的指令地址（也就是程序计数器PC）保存到内部的中断向量寄存器中。
 * 2. CPU根据中断向量寄存器中的中断向量号，在中断向量表中查找对应的中断处理程序入口地址。
 * 3. CPU将当前运行进程的寄存器状态保存到内核栈中。这个过程涉及到堆栈操作，包括：
 *    - 将堆栈指针SP的当前值减去一定的偏移量，使得堆栈指针指向内核栈的空闲位置。
 *    - 将CPU寄存器中的值逐个压入内核栈中，包括通用寄存器、指令寄存器、程序计数器、程序状态寄存器等。
 * 4. CPU跳转到中断处理程序的入口地址开始执行中断处理程序。
 * 5. 中断处理程序在内核栈中保存相关的上下文信息，执行完后，再从内核栈中恢复运行进程的寄存器状态，执行iret（或reti）指令返回原进程。
 * 6. CPU根据返回地址恢复现场，执行iret指令返回到原进程的下一条指令，CPU继续执行。
 *    需要注意的是，中断处理过程中，不仅需要保存当前运行进程的寄存器状态，还需要对现场进行保护，防止被恶意程序篡改。因此，操作系统会为每
 *    一个进程分配独立的内核栈，以保证中断处理程序的上下文信息不被其他进程篡改。
 * 
 * 问题：上面回答的第1至4点操作过程是通过什么指令实现的？
 * 在x86架构中，上述的第1至4点操作过程可以通过以下指令来实现：
 * 1. 将当前的指令地址保存到内部的中断向量寄存器中
 * 在x86架构中，可以使用  `INT`  指令来产生中断信号并将中断向量号保存到中断向量寄存器中。
 * 2. 根据中断向量寄存器中的中断向量号，在中断向量表中查找对应的中断处理程序入口地址
 * 中断向量表是一个256项的数组，每一项都保存了对应中断号的中断处理程序入口地址。在x86架构中，可以使用  `LIDT`  指令将IDT表
 * 的基地址和限长写入到中断描述符表寄存器（IDTR）中，并使用  `INT`  或  `INTO`  指令产生中断信号，使得CPU能够正确地查找到
 * 中断处理程序入口地址。
 * 3. 将当前运行进程的寄存器状态保存到内核栈中
 * 在x86架构中，可以使用  `PUSH`  指令将CPU寄存器中的值压入堆栈中，使用  `POP`  指令从堆栈中弹出值，并使用  `MOV`  指令将
 * 值直接从寄存器中存入内存中。对于堆栈指针SP的修改，可以使用  `ADD`  或  `SUB`  指令来实现。
 * 4. 跳转到中断处理程序的入口地址开始执行中断处理程序
 * 在x86架构中，可以使用  `JMP`  指令来跳转到中断处理程序的入口地址开始执行。另外，在中断处理程序结尾处需要使用  `IRET`  指令
 * 来返回原进程并恢复现场。
 * 
 * 问题：这些指令需要载入指令寄存器吗？—— 硬件真的不熟，才会有这个问题，但真的解开了困惑...
 * 在x86架构中，CPU在执行指令时需要将指令加载到指令寄存器（Instruction Pointer，IP）中，然后执行指令。因此，执行上述
 * 指令时，也需要先将指令加载到IP中，然后CPU才能执行相应的操作。对于中断处理程序，CPU会使用中断向量表中的中断向量号作为
 * 索引，从中断向量表中获取中断处理程序入口地址并加载到IP中，然后跳转到该地址开始执行中断处理程序。在执行完中断处理程序后，
 * 使用  `IRET`  指令从中断返回并将控制权交还给原进程，同样也需要将指令加载到IP中，并执行相应的操作。
 * 个人附加：可中断的“无情地执行指令”的机器...
 * 
 * 问题：硬件隐形保存用户寄存器的操作指令是硬件还是操作系统提供的？->对这个回答有疑问。。。
 * 这个操作通常是由操作系统提供的。在一些架构中，例如x86架构，CPU拥有一个特殊的寄存器CR3，它存储着页目录表的基地址，通过
 * 更改CR3的值可以切换不同的页目录表，从而实现虚拟内存管理。当发生进程切换时，操作系统会更新CR3的值，以切换到新的页目录表，
 * 从而实现进程间的虚拟内存隔离。在更新CR3的同时，操作系统通常也会保存当前进程的寄存器状态。这个过程通常是在操作系统内核态
 * 中完成的，因为只有在内核态中才能够进行这样的操作。因此，可以说操作系统提供了这个功能。
 * 
 * 个人小结(不保证一定正确啊)：
 *    CPU检测到中断信号,PC(程序计数器:指令地址)的值保存到中断向量寄存器中,载入中断向量号对应的程序入口地址到PC,继续执行指令,
 *    执行时钟中断处理例程,保存被中断进程的CPU上下文到系统栈(每个进程都分配有用户栈和系统栈),继续根据异常号执行系统调用例程,
 *    保存CPU上下文的"实际值"(非结构体的指针,而是结构体成员)到PCB(进程控制块),然后根据调度器判断是否继续进行该任务(进程/线程)或切换。
 *    
*/

/**
 * 问题：C语言的作用域有几种，分别举例说明。 
 * C语言中，主要有以下四种作用域：
 * 1. 全局作用域：
 * 全局变量定义在程序的外部，在整个程序中都是可见的，可以被所有函数访问。例如：
 * #include <stdio.h>
 * int global_variable = 10; 定义全局变量
 * void fun(void);
 * int main() {
 *     printf("全局变量 global_variable = %d\n", global_variable);
 *     fun();
 *     return 0;
 * }
 * void fun() {
 *     printf("在函数 fun 中，全局变量 global_variable = %d\n", global_variable);
 * }
 *
 * 2. 函数作用域：
 * 函数内定义的变量只能在该函数内使用，函数外部无法访问。函数作用域内的变量称为局部变量。例如：
 * #include <stdio.h>
 * void fun(void);
 * int main() {
 *     fun();
 *     return 0;
 * }
 * void fun() {
 *     int num = 10; 定义局部变量
 *     printf("在函数 fun 中，局部变量 num = %d\n", num);
 * }
 * 
 * 3. 块作用域：
 * 块作用域与函数作用域类似，不同之处在于变量定义在代码块中，只能在该块中使用。例如：
 * #include <stdio.h>
 * int main() {
 *     int i;
 *     {
 *         int inner = 10; 定义块作用域变量
 *         i = inner;
 *     }
 *     printf("i = %d\n", i);
 *     return 0;
 * }
 * 
 * 4. 文件作用域：
 * 文件作用域是在函数外定义的变量，只能在文件中使用。例如：
 * #include <stdio.h>
 * static int num = 10; 定义文件作用域变量 <-static为个人添加,ai回答并不保证完全正确...
 * void fun(void);
 * int main() {
 *     printf("全局变量 num = %d\n", num);
 *     fun();
 *     return 0;
 * }
 * void fun() {
 *     printf("在函数 fun 中，文件作用域变量 num = %d\n", num);
 * }
 * 总的来说，C语言中有四种作用域，分别是全局作用域、函数作用域、块作用域和文件作用域，每种作用域都有其特定的作用和用途。
 * 个人补充：函数原型作用域对于现代C语言并不是必须的，一些旧版本的C编译器中仍然必须(所以这个就懒得管了...c primer plus最新的还是C11标准的,目前最新为C18)
 * 全局作用域和文件作用域可通过(gcc a.c b.c)自己编译验证。->可温习一些翻译单元的概念。
 * 
*/

// C语言事件循环
#include <stdio.h>
#include <stdlib.h>
 // 定义事件处理回调函数类型
typedef void (*event_handler_t)(void);
 // 定义事件结构体
typedef struct {
    event_handler_t handler;
} event_t;
 // 定义事件循环结构体
typedef struct {
    event_t *events;
    int num_events;
} event_loop_t;
 // 初始化事件循环
void event_loop_init(event_loop_t *loop, int num_events) {
    loop->events = (event_t *) malloc(sizeof(event_t) * num_events);
    if (loop->events == NULL) {
        printf("Error: Failed to allocate memory for event loop.\n");
        exit(1);
    }
    loop->num_events = num_events;
}
 // 注册事件
int event_loop_add_event(event_loop_t *loop, event_handler_t handler) {
    // 找到第一个空闲的事件槽位
    for (int i = 0; i < loop->num_events; i++) {
        if (loop->events[i].handler == NULL) {
            // 找到了空闲的槽位，注册事件
            loop->events[i].handler = handler;
            return 0;
        }
    }
    // 没有空闲的槽位了，返回错误
    return -1;
}
 // 执行事件循环
void event_loop_run(event_loop_t *loop) {
    // 不断循环处理事件
    while (1) {
        for (int i = 0; i < loop->num_events; i++) {
            event_t *event = &loop->events[i];
            if (event->handler != NULL) {
                // 调用事件处理回调函数
                event->handler();
                // 处理完事件后将槽位清空
                event->handler = NULL;
            }
        }
    }
}
 // 示例的事件处理回调函数
void event_handler_example(void) {
    printf("Event handled.\n");
}
 // 程序入口
int main(int argc, char **argv) {
    // 初始化事件循环
    event_loop_t loop;
    event_loop_init(&loop, 10);
     // 注册事件
    event_loop_add_event(&loop, event_handler_example);
     // 执行事件循环
    event_loop_run(&loop);
     return 0;
}