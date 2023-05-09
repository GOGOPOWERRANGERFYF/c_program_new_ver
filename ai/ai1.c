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