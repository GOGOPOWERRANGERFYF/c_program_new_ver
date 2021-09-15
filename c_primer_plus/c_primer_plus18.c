#include <stdio.h>
#include <stdbool.h>
#define RATE1 1.0
#define RATE2 2.0
#define RATE3 3.0
#define STEP1 kwh_a * RATE1
#define STEP2 (kwh_b - kwh_a) * RATE2
#define STEP3 (kwh_c - kwh_b) * RATE3
int step_rate(void);
int division(void);
int prime_number(void);

int main(void)
{
    //step_rate();
    //division();
    prime_number();
    return 0;
}

int step_rate(void)
{
    const double kwh_a = 10.0, kwh_b = 20.0, kwh_c = 50.0;
    double kwh;

    printf("input kwh:\n");    
    // 11 --> 11.0  int --> double promotion升级
    // 11.0 --> 11  double --> int demotion降级
    // 输出为映射真值,与升级降级不同,不要弄混
    while (scanf("%lf", &kwh) == 1){
        if (kwh < 0){
            printf("wrong data!\n");
        }
        else if (kwh <= kwh_a){
            printf("count: %.3f\n", kwh * RATE1);
        }
        else if (kwh <= kwh_b){
            printf("count: %.3f\n", STEP1 + (kwh - kwh_a) * RATE2);
        }
        else if (kwh <= kwh_c){
            printf("count: %.3f\n", STEP1 + STEP2 + (kwh - kwh_b) * RATE3);
        }
        else {
            printf("count: %.3f\n", STEP1 + STEP2 + STEP3 + (kwh - kwh_c) * RATE3);
        }
    }
    // <c primer plus第六版> P424 
    // if else嵌套形式也可以实现,效果一样,但还是上面的else if清晰明了
    // if else嵌套形式有兴趣可以了解
    // 
    // if (expression)
    //     statement;
    // else
    //    if (expression)
    //         statement;
    //    else
    //         statement; 
    // 嵌套的if else语句被视为一条语句,因此可以不用花括号括起来,但括起来让代码更加清晰
    // 好了,说了这么多if else嵌套语句,总结,else if语句真香...
    printf("game over!\n");
    return 0;
}

// C99标准要求编译器至少支持127层嵌套
// nested if 嵌套if

// if与else的匹配(先if后else,else if不在这里的讨论范围)
// else与离它最近的if语句(包括有括号和无括号的if语句)匹配
// 反正就是与最近的if语句相匹配呗...
// *找else相匹配的if要向前找
// *编译器是忽略缩进的,因此不能通过缩进来判断if与else的匹配
//
// if (expression)
//     statement;
// if (expression)  -- if
//     statement;       |  匹配
// else             -- else
//     statement;
//
// if (expression){       -- if
//     statement;             |
//     if (expression)        | 匹配
//         statement;         |
// }                          |
// else                   -- else
//     statement;
//

// 100^2 = 100 * 100     100^1 = 100       
// 100^2 * 100^1 = 100 * 100 * 100 = 100^(2+1) = 100^3
// 100^0.5等于100的平方根
// 100^0.5 * 100^0.5 = 100^(0.5+0.5) = 100^1
int division(void)
{
    int div, num;
    for (div = 2, scanf("%d", &num); div < num; div++){
        // num % div 
        // num模除div,余数为0的就是能整除的
        if (num % div == 0){
            printf("num / div = %d, div = %d\n", num / div, div);
        }
    }
    // optimize 优化
    return 0;
}

// 数学知识点:
//   自然数: 0和正整数
//   素数(质数prime number):  大于1的自然数,且除了1和自身,不能被其它自然数整除
int prime_number(void)
{
    long unsigned int div, num;
    // bool为_Bool的别名,在stdbool.h头文件中定义
    bool is_prime_number;
    while (scanf("%lu", &num) == 1)
    {
        // for 计数循环(counting loop)
        // 根据素数的定义,除了1和数本身,依次循环2至少数的前一位数
        // for循环开始前div,is_prime_number初始化,且仅初始化一次
        for (div = 2, is_prime_number = true; div < num; div++)
        {
            // 如果数能被其它自然数整除,这个数就不是素数,标记flag设置为假false
            if (num % div == 0){
                printf("Not prime number, %lu is divisible by %lu.\n"
                , num, div);
                is_prime_number = false;
            }
        }
        // is_prime_number为真,说明数不能被除1和本身之外的自然数整除,是素数(质数)
        if (is_prime_number == true){
            printf("Yes, %lu is prime number!\n", num);
        }
    }
    return 0;
}
// 2也是素数(比较特殊的素数),但在程序中,for测试条件为假,is_prime_number为真,
// 没经过if测试语句验证,经过if测试语句的话is_prime_number就为假了,所以for测试条件为假算是歪打正着吧...
// 这段程序还是有个缺陷,会把0,1(可通过while测试条件验证)当成素数,学到后面的逻辑运算符再完善

// 逻辑运算符
// && 与
// || 或
// !  非

// if else
//
// if (expression)
//     statement
//
// if (expression)
//     statement1
// else
//     statement2
//
// if (expression1)
//     statement1
// else if (expression2)
//     statement2
// else
//     statement3
//
// statement可以是一条简单语句或复合语句




