//  第6章 指针
//  (变量名属于标识符,但标识符定义的范围>变量名,个人觉得数组
//  的元素名也是变量,a[2] = 5,元素a[2]是左值)
//  高级语言提供的特性之一就是通过名字而不是通过地址
//  来访问内存的位置
//  当然,这些名字就是我们所称的变量
//  名字与内存位置之间的关联并不是由硬件提供的,
//  它是由编译器实现的
//  变量给我们一种更方便的方法记住地址
//  硬件仍通过地址访问内存位置
//  (变量名直接访问与其关联的内存地址,访问地址上存储的值\数据,
//  要知道与变量关联的地址则通过&变量名取得)

//  6.6 NULL指针
//  标准定义了NULL指针,它作为一个特殊的指针变量,表示不指向任何东西.
//  要使一个指针变量为NULL,可以给它赋一个零值
//  测试一个指针变量是否为NULL,可以将它与零值进行比较
//  重点:选择零值只是一种源代码约定,在机器内部,NULL指针的实际值可能与此不同
//       编译器负责零值和内部值之间的翻译转换
//  如果对一个NULL指针进行间接访问,它的结果因编译器而异.