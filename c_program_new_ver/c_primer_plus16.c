// *重要知识点:
//  C标准库:
//    函数原型声明放在头文件 xxx.h (编译系统预处理阶段,读取并插入头文件文本)
//    函数定义放在其它源文件 xxx.c (已经提前编译好,编译系统链接阶段就是链接这些文件)
#include <stdio.h>
#include <stdbool.h>
// 符号常量/明示常量(manifest constant)
#define NAME "fyf"
// C99新增_Bool类型   
// 表示真或假的变量称为布尔变量(boolean variable)
// _Bool类型变量只能储存1(真)或0(假)
// 把非零值赋给_Bool类型变量是,该变量会被设置为1(这反映C把所有非零值视为真)
int bool_variable(void);
int for_loop(void);
int for_loop_nine_methods(void);
int for_example(void);
int comma_operator(void);
int exit_condition_loop(void);
int nested_loop(void);
int nested_loop_other(void);
int array(void);
int for_array_average(void);
// 函数原型声明 function prototype declaration
// 1.函数名; 2.返回值类型; 3.传入参数
// 不写函数原型声明其实编译系统编译时会进行隐式函数原型声明,不过编译时会有警告 -w选项忽略警告
// 还是不要偷懒,即使编译过了,也可以运行,但可能有预料不到的错误(而且C99标准已经删除了隐式函数声明法则)
double power(double n, int limit_e);
//double power(double, int); 这样声明也可以
// 让编译系统知道函数返回值的类型,知道返回值有多少字节数据
// 函数声明有参数的话可以让编译系统知道传入参数的类型和个数
// C编译系统只会从头到尾编译一遍,函数调用需要知道函数返回值(和参数类型个数,如果有的话)
// 编译到函数调用语句,还没有到函数定义,所以编译系统只能通过函数原型声明知道这些信息
// (C编译器太古老了,较新的语言基本没有函数声明了)

// encounter 遇到,遭遇
// <c primer plus第六版> P388 对函数声明和使用带返回值的函数有比较详细的解释(很值得看的知识点)
//1.编译器遇到调用函数语句时,还没有遭遇到函数定义,不知道函数的返回值类型
//  通过前置声明(forward declaration)可让编译器知道函数的返回值类型,函数定义在别处
//  (函数定义如果在main函数前,函数原型声明可以省略,但这不是C的标准风格)
//  附:通常函数定义(function definition)放在在其它文件中
//2.printf(),scanf()这些函数的原型声明(function prototype declaration)包含在stdio.h头文件里,
//  #include <stdio.h>预处理指令,读取并插入头文件里的文本 

// 这段main()程序是一个驱动(driver)示例,这段程序用来测试其它函数(function)
int main(void)
{
    _Bool a = 1, b = 'a', c = 0, d = 88
    , e = "abcd";
    int input_limit_e;
    double power_return_value, input_n;
    printf("a = 1: %3d\n", a);
    printf("b = 'a': %d\n", b);
    printf("c = 0: %3d\n", c);
    printf("d = 88: %2d\n", d);
    printf("e = \"abcd\": %2d\n", d);

    // 函数调用,读取函数返回值
    // 函数的返回值存放在寄存器或内存(stack栈)
    // 函数原型声明的返回值类型(必须,也是需要使用函数原型声明的原因):
    //   编译系统编译到函数调用代码的时候,需要知道函数调用要读取的返回值的类型,知道数据类型才能知道要读取多长位宽的数据
    //   但还没有编译到函数定义,所以需要通过函数原型声明知道返回值类型
    // 函数原型声明的参数(非必须):
    //   让函数调用可以传入正确的实参类型和个数   
    // 1.隐式函数声明,c99标准后已淘汰
    // 2.函数类型声明 function type declaration
    //      int xxx();
    //   缺点: 编译器检查不到函数调用时传入实参的类型和个数错误
    // 3.函数定义声明,把函数定义放主函数前
    //   缺点: 不利于代码的组织
    // 4.函数原型声明 function prototype declaration
    //      int xxx(int xxx, float xxx);
    //      int xxx(void);
    //   直接用函数原型声明就完事了...
    // * C编译器很古老,有历史包袱...只会从头到尾编译一遍,所以有以上这些问题,比较新的语言就不会有这些声明的问题
    bool_variable();
    for_loop();
    for_loop_nine_methods();
    for_example();
    comma_operator();
    exit_condition_loop();
    nested_loop();
    nested_loop_other();
    array();
    for_array_average();

    // scanf函数返回值为成功读取输入项个数,读取成功几个项返回值就为几,读取成功0个就为0
    // EOF,end of file,文件终止符
    // EOF在windows,linux,mac中有区别,具体上网查去,老子现在没心情也没空...
    printf("input number and exponent:\n");
    // 函数原型里n为double类型,输入整数类型也没关系,double类型等级比所有证书类型高,
    // 整数类型会被自动转换(隐式转换)成double类型
    // 函数原型power函数底数的变量用double类型是因为double类型能表示的范围更大更全面
    //
    // 输入 10 文本(ascii码),编译系统把它转换成 10.0 文本,再转换成double类型的binary储存
    // (编译器具体怎么实现不清楚,但这个思路和结果应该是对的...
    //  至少结果是对的,目前水平有限,这个思路让我能理解,未必精准或正确)
    // 输入 a 文本或符号文本(这些转换成表示double类型的文本想想就过分啊...),所以当然输入错误咯...
    while (scanf(" %lf %d", &input_n, &input_limit_e) == 2){
        // 函数调用,把函数返回值返回给主函数
        power_return_value = power(input_n, input_limit_e);
        printf("number^exponent = %.2f\n", power_return_value);
    }
    printf("Game over! Bye~");
    return 0;
}

int bool_variable(void)
{
    // C99提供老stdbool.h头文件,该头文件定义了_Bool的别名bool,
    // 把true和false定义为1和0的符号常量
    // 包含了该头文件后,代码可以与C++兼容,true和false,bool为c++的关键字
    bool a;
    int b;
    char c;
    printf("input decimal number:\n");
    // 1. 精简写法:
    while (scanf("%d", &b)){
        printf("true\n");
    }
    // 2. 非常啰嗦写法...
    // 不用小括号, ==运算符优先级也比=高
    //a = (scanf("%d", &b) == 1);
    //while (a){
    //    printf("true\n");
    //    a = scanf("%d", &b) == 1;
    //}
    // 3. 很啰嗦写法...
    //a = scanf("%d", &b) == 1;
    //while (a){
    //    printf("true\n");
    //    a = scanf("%d", &b) == 1;
    //}
    // 4. 啰嗦写法...
    //a = scanf("%d", &b);
    //while (a){
    //    printf("true\n");
    //    a = scanf("%d", &b);
    //}
    //越啰嗦,可读性越高,但写起来确实啰嗦啊...
    scanf("%c", &c);
    printf("false! %d\n", c);
    return 0;
}

// 知识点总结:
// precedence of relational operators(关系运算符优先级)
// 关系运算符优先级比算术(arithmetic)运算符低,比赋值运算符高
// 优先级高的先结合
// 关系运算符之间的优先级:
// 高优先级组: < <= > >=
// 低优先级组: == !=
// 与其他大多数运算符一样,关系运算符的结合律也是从左到右 
// <c primer plus> P340 表6.2 运算符优先级

// while语句是一种入口条件循环
// while (test expression/test condition)
//      statement                         
// statement可以是简单语句,也可以是复合语句(花括号括起来)
// expression部分为假或0前,重复执行statement部分

// <c primer plus> P343
// 1.不确定循环(indefinite loop) while测试表达式为假0之前,不确定要循环多少次
//
// 2.计数循环(counting loop) 循环之前就知道要循环多少次
//  (1) 计数器初始化
//  (2) 测试条件(与有限值比较)
//  (3) 计数器递增(更新)
// 计数循环我们用for循环,虽然while循环(计数循环)也能实现 

//for循环可以把上述3个行为(初始化,测试,递增[更新])组合在一起
int for_loop(void)
{
    // a. 计数器初始化
    // b. 循环一次(测试表达式为真);测试条件为假,终止循环,跳过计数器更新,执行后面的代码
    // c. 计数器更新(递增)
    int a;
    // a = 1; 初始化只执行一次(once),循环开始前
    // for循环圆括号中的表达式也叫控制表达式,它们都是完整表达式
    // a++循环结束时求值
    for (a = 1; a <= 5; a++){
        printf("for loop: %d\n", a);
    }
    // 由此可看出,a <= 5表达式为假0,循环结束,后面的a++表达式不执行
    printf("out of for loop, a: %d\n", a);
    return 0;
}

int for_loop_nine_methods(void)
{
    int n, m = 2;
    //int n, m;
    char c;
    double f;
    // for循环 控制表达式   n--,n=n-2,n=n-10也可以,根据需求
    for (n = 5; n >= 0; n--){
        printf("decrement counter n-- : %d\n", n);
    } 
    // for循环 控制表达式   n++,n=n+2,n=n+10也可以,根据需求
    for (n = 5; n <= 10; n = n + 2){
        printf("increment counter n = n + 2 : %d\n", n);
    }
    // 可以用字符代替数字计数,(该程序能正常运行,是因为字符在计算机内部跟数字一样以二进制数存储)
    for (c = 'a'; c <= 'z'; c++){
        printf("character: %c, ASCII(decimal): %d\n", c, c);
    }
    // 上面三条测试条件都是测试 迭代(iteration)次数(控制循环次数) 
    // 还可以测试其他条件,例如 n * n < 100,测试限制n的平方的大小
    // 递增的量可以算术增长,也可以几何增长
    for (f = 1.0; f <= 10.0; f = f * 1.2){
        printf("f * 1.2 : %.13f %a\n", f, f);
    }
    // 第三个表达式可以使用任何合法的表达式,无论是什么表达式,每次迭代都会更新该表达式的值
    // int y = 10;
    // for (x = 1; y <= 50; y = ++x * 2 + 5)
    // 这里可以这么理解,计数器x的代数计算的值赋值给y,对y作测试
    // 可以正常运行,但编程风格不好
    for (n = 1; n <= 5;){
        // 计数器更新部分也可以放进循环体内
        n = n + 2;
    }
    printf("%d\n", n);
    // for循环的控制表达式,三个表达式可以使用不同的变量
    for (n = 1, f = 1.0; f <= 5.0; f = 2 * n * f){
        printf("OK_1!\n");
    }

    //clang编译器,m没有初始化,测试表达式的值为假0
    //for (; m <= 5;){
    //for循环控制表达式三个表达式可以省略,但两个分号不能省略
    //测试条件为空语句,值为真,程序无限循环
    //for (;;){
    //语法上虽然可以省略三个表达式,但这样代码貌似没有任何实际意义啊...
    for (m = 1; m <= 5;){
        m++;
        printf("%d\n", m);
    }
    printf("%d\n", m);

    return 0;
}
// *** for循环控制表达式总结(核心知识点,遵循一下三点原则):
// 1. 计数器初始化
//      1.1 第一个表达式也可以是其他表达式(即使函数表达式也可以)
//      1.2 只在循环开始前执行一次(once)
// 2. 测试条件(测试表达式) 
//      2.1 如果测试条件为空语句,则值一直为真,程序无限循环
// 3. 计数器更新(递增:算术递增,几何递增都可以;可以把这个表达式放入循环体内)
//      3.1 放在控制表达式,循环结束一次,执行一次
//      3.2 放在循环体内,循环一次,执行一次
// 注: 可以省略三个表达式,但两个分号不能省略(其它随便你折腾...)
//     1表达式 可以放在for语句前进行初始化
//     2表达式 空语句值一直为真
//     3表达式 可以放循环体内

// 个人总结(while和for的区别):
//      while (测试条件test condition)
//      for (控制表达式,三个表达式) 
//      while和for都是入口条件循环(entry condition loop)
//
//  while: 1.不确定循环; (程序运行完成前无法确定循环迭代次数)
//         2.计数循环;   (程序运行前就可知循环迭代次数,计数循环一般用for)

// for循环只需记住几个重点就好:
//  三个控制表达式,三个表达式都可以省略,两个分号不能省略
//  计数器初始化可以在for语句前,只在for循环前执行一次
//  计数器更新可以在循环体内,迭代一次,执行一次;在控制表达式,循环迭代结束一次,执行一行
//  测试条件为空语句,值为真

// 形式:
//  for (initialize; test; update)
//      statement
//
//  initialize 初始化    (计数器初始化)
//  initialize表达式在for循环迭代之前值执行一次
//  test       测试      (测试条件)
//  update     更新      (计数器更新)
int for_example(void)
{
    int x;
    //三个控制表达式
    for (x = 1; x < 1; x++){
       printf("OK");
    }
    printf("%d\n", x);
    return 0;
}

// 其他赋值运算符
// 可修改的左值,右值(常量,变量,可求值的表达式)
// y += 2       y = y + 2
// y -= 2       y = y - 2
// y *= 2       y = y * 2
// y /= 2       y = y / 2
// y %= 2       y = y % 2
// y += x       y = y + x
// y *= x + 2   y = y * (x + 2)
// 1.组合形式的赋值运算符让代码更紧凑
// 2.与一般形式相比,这些组合形式的赋值运算符生成的机器代码更高效

// 逗号运算符(comma): ,
// 逗号运算符并不局限于for循环使用
// 逗号运算符的两个性质:
//  1.保证了被它分隔的表达式从左到右求值
//    (换言之,逗号是一个序列点sequence point,左侧项的所有副作用side effect在执行右侧项之前发生)
//    n++, n * 2;    左侧子表达式,右侧子表达式
//  2.整个逗号表达式的值是右侧项的值
int comma_operator(void)
{
    int a, x, y, z;
    //逗号comma表达式的值是右侧(项/表达式)的值
    a = (5,6);
    printf("%d\n", a);
    //先执行赋值表达式,右侧子表达式什么也没做(实际在计算机内部有没有做还要看汇编代码)
    a = 5,6;
    printf("%d\n", a);

    //逗号运算符,保证被分隔的表达式从左至右求值
    //逗号运算符,整个逗号表达式的值是右侧项的值 (逗号运算符运算求值)
    //圆括号,先对逗号表达式(comma expression)求值
    x = (y = 3, (z = ++y + 2) + 5);
//       ------------------------   --> 逗号表达式
    printf("x = (y = 3, (z = ++y + 2) + 5); ");
    printf("x: %d\n", x);
    //逗号运算符,整个逗号表达式,两个子表达式(subexpression)
    //整个逗号表达式的值等于逗号右边的子表达式的值
    x = y = 3, (z = ++y + 2) + 5;
//  ----------------------------    --> 逗号表达式
    printf("x = y = 3, (z = ++y + 2) + 5; ");
    printf("x: %d\n", x);
    return 0;
    //逗号运算符(comma operator),当作一个序列点(sequence point)
    //逗号运算符的运算符优先级是C所有运算符里最低的(google查的...)
}
// *逗号也可用作分隔符,不是逗号运算符,例如在变量声明和函数参数列表中的逗号就是分隔符

// <c primer plus第六版> P259 表5.1
// 组合赋值运算符 与 赋值运算符 优先级 相同
// x *= y + 5 与 x = x * (y + 2) 相同
//            运算符优先级
//   运算符             结合律 
//    ()              从左到右
//   + - (一元)        从右到左
//   * /              从左到右
//   + - (二元)        从左到右
//   =                从右到左
//

// *逗号运算符把两个表达式连接成一个表达式(逗号表达式),并保证左边的子表达式先求值
//  整个逗号表达式的值是逗号运算符右侧子表达式的值

// 入口条件循环 entry condition loop   
// while for
// 循环每次迭代前检查(执行)测试条件 

// 出口条件循环 exit condition loop
// 出口条件循环 do while
// 循环的每次迭代之后检查(执行)测试条件
// do
// {
//    statement  
// } while ( expression );

int exit_condition_loop(void)
{
    int a = 1;
    do
    {
        printf("exit condition loop: %d\n", a);
        a++;
    } while (a <= 5);
    printf("exit loop: %d\n", a);
    return 0;
}

//入口条件循环用for或while都可以:
// 让for像while一样
// for ( ;test; ) 与 while (test) 效果相同
//
// 让while像for一样
// 计数器初始化;
// while (测试条件) {
//  循环体;
//  计数器更新;
// }
// 与 for (计数器初始化;测试条件;计数器更新) 循环效果相同
// 具体看<c primer plus第六版> P372,觉得有点啰嗦,懒得做笔记...
// 我个人总结的话: while适合不确定循环,for适合计数循环
// do while 适合先执行一次循环的迭代,再执行测试条件

// nested loop 嵌套循环
// 指在一个循环内包含另一个循环
int nested_loop(void)
{
    int m;
    char c;
    // outer loop 外层循环
    for (m = 0; m <= 5; m++){
        // loop body
        printf("row %d: ", m);
        // inner loop 内层循环
        for(c = 'a'; c <= 'z'; c++){
            // nested loop body
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}
// 嵌套循环(nested loop)中,外层循环(outer loop)每迭代一次,内层循环(inner loop)迭代到测试条件为假0为止

int nested_loop_other(void)
{
    int m;
    char c;
    // 三个控制表达式
    for (m = 0; m <= 5; m++){
        //函数的核心,外层循环每迭代一次,内层循环计数器初始化的值递增
        //当然,还可以把递增扩展到内层循环测试条件(测试表达式),这里就不展开了
        for (c = 'A' + m; c <= 'F'; c++ ){
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}

// array数组,是按顺序存储的一系列类型相同的值
// 整个数组有一个数组名,下标(subscript)必须是整数,下标从0开始计数,数组的元素依次存储在内存中相邻的位置
// 通过整数下标(subscript)访问单独的项(item)或元素(element)
// 编译器不会检测数组下标的错误
// 《c primer plus》 P378 图6.6 字符数组与字符串的区别 末尾月有没有/0空字符
// 空字符/0的ascii码:0
// int a[10];   声明可储存10个int类型值的数组
// a[0] = 10;   数组下标(subscript)从0开始
// a[15] = 10;  数据还是会被存放,有可能会导致程序异常中断
// 数组的类型可以是任意数据类型
int array(void)
{
    // 声明int类型数组
    int a[9];
    // 声明char类型数组
    char c[9];
    a[0] = 15;
    printf("%d\n", a[0]);
    return 0;
}

int for_array_average(void)
{
    int subscript, score[5];
    double sum = 0;
    
    printf("input 5 scores:\n");
    for (subscript = 0; subscript < 5; subscript++){
        scanf("%d", &score[subscript]);
        //隐式转换 int --> double 类型级别低的转换为类型级别高的
        sum += score[subscript];
    }
    
    printf("scores: ");
    for (subscript = 0; subscript < 5; subscript++){
        printf("%d ", score[subscript]);
    }
    printf("\n");
    printf("average: %.2f\n", sum/5.0);
    return 0;
}
// 键入enter键后程序开始读取输入缓冲区的数据

// 函数返回值的循环示例
// 幂power
// n^e     n为底数,e为指数
double power(double n, int limit_e)
{
    int e;
    //从算法理解,先把power的结果(幂的值)初始化为1.0
    double pow = 1.0;
    //幂的指数e在for循环三个控制表达式的第一个表达式计数器初始化中初始化
    for (e = 1; e <= limit_e; e++){
        // 指数为1,幂的值为底数n本身
        // 指数为2,幂的值为n * n,再赋给左侧的项
        // 指数为3,幂的值为n * n * n,再赋给左侧的项
        // ......
        pow *= n;
        // 左侧的项乘以右侧的项,再把乘积付给左侧的项
    }
    //返回值类型已在函数头声明,为double类型
    //可以返回 常量,变量,表达式
    //返回值为 常量的值,变量的值,表达式的值
    return pow;
}





