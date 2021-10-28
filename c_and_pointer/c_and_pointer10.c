#include <stdio.h>
int dot_operator(void);
int arch_operator(void);
struct x {
    char        c;
    char        array_c[10];
};
struct full_struct {
    //menber 标量变量
    char        char_a;
    short int   short_int_a;
    int         int_a;
    long int    long_int_a;
    float       float_a;
    double      double_a;
    //menber 数组
    char        char_array_a[10];
    short int   short_int_array_a[10];
    int         int_array_a[10];
    long int    long_int_array_a[10];
    float       float_array_a[10];
    double      double_array_a[10];
    //menber 结构
    struct x    sx_a;
};

int main(void){
    //dot_operator();
    //arch_operator();
    return 0;
}

int dot_operator(void){
    // nil: null pointer to c-object(指针为空)
    struct x * struct_x_pointer;
    struct full_struct full_struct_a;
    struct full_struct * full_struct_pointer;
    char * char_pointer;
    full_struct_a.sx_a.c = 'a';

    //结构访问数组成员的表达式,结果为成员数组的(首元素)指针  
    printf("full_struct_a.sx_a.array_c: %p\n", full_struct_a.sx_a.array_c);
    
    //结构变量指针的值等于结构变量首个成员的指针的值
    struct_x_pointer = &full_struct_a.sx_a;
    char_pointer = full_struct_a.sx_a.array_c;
    //访问结构变量的成员(这里的成员也是一个结构变量)
    //打印结构变量成员的第一个字节,以字符格式输出
    //这个结构变量的第一个字节刚好与它的第一个成员是一致的
    //第二个成员就不一定了,因为结构跟数组不一样,并不是一定连续储存的
    //结构成员不连续储存才是常态...
    //重点:访问一个结构变量跟访问一个标量变量的操作是一样的
    //     但并没有一个打印结构的格式说明符,所以下面的代码通
    //     过打印一部分从侧面推理得到结论
    //     访问变量就是访问给变量分配的内存块
    //     数组的话就有所不同,数组名是一个指针常量
    printf("full_struct_a.sx_a(%%c): %c\n", full_struct_a.sx_a);
    printf("&full_struct_a.sx_a(%%p): %p\n", &full_struct_a.sx_a);
    printf("&full_struct_a.sx_a(%%lx): %lx\n", &full_struct_a.sx_a);
    printf("struct_x_pointer: %p\n", struct_x_pointer);
    printf("full_struct_pointer: %p\n\n", full_struct_pointer);
    
    printf("char_pointer: %p\n", char_pointer);

    return 0;
}

int arch_operator(void){
    char * char_pointer_a;
    struct x * sx_pointer_a;
    struct x sxa;

    char_pointer_a = &sxa.c;
    sx_pointer_a = &sxa;
    sxa.c = 'A';

    //直接访问结构变量的成员c
    printf("sxa.c = %c\n", sxa.c);
    printf("&(sxa.c): %p\n", &(sxa.c));
    //.点运算符的优先级高于&地址运算符

    printf("&sxa.c: %p\n", &sxa.c);
    //间接访问结构变量的成员c,sx_pointer_a->c
    //sx_pointer_a->c间接访问成员c的值,通过成员c的指针
    printf("sx_pointer_a->c = %c\n", sx_pointer_a->c);
    //&sx_pointer_a->c取成员c的指针, ->的优先级高于&,所以无需括号
    printf("&sx_pointer_a->c: %p\n", &sx_pointer_a->c);
    //指向结构变量的指针,间接运算符优先级比点运算符低
    //指向结构变量的指针和指向结构变量第一个成员的指针 指针的值相等
    //但指针的类型是不同的,指针+1,指针加上所指向数据类型的一个存储长度
    printf("(*sx_pointer_a).c: %c\n", (*sx_pointer_a).c);

    printf("&sxa.c: %p\n", &sxa.c);
    printf("char_pointer_a: %p\n", char_pointer_a);
    return 0;
}

// struct
// 结构变量
// 结构成员变量
// union
// 联合变量
// 联合成员变量

// 谷哥搜索到的一些说法:
// 结构和联合是用户定义数据类型 user defined data types
// 数组和结构是聚合数据类型aggregate data types 
// (聚合数据类型:能同时储存一个以上的单独数据)
// union是一种特殊数据类型...

//  附加(小笔记)：
//      从本质上看,结构声明创建了一个名为struct name的新类型
//      与C内置数据类型一样,声明相关数据类型的变量会为变量分配存储空间
//      数据类型本身并不会分配存储空间
//      要理解一点机器级码本身没有数据类型的信息,只有数据+操作
//      由编译器来解决
//  《c和指针》p195
//  第10章 结构和联合
//  10.1 结构基础知识
//      聚合数据类型(aggregate data type)能够同时存储超过一个的单独数据
//  C提供了两种类型的聚合数据类型,数组和结构(struct)
//  数组是相同类型元素的集合,每个元素通过下标引用或指针来间接访问
//  结构也是一些值的集合,这些值成为它的成员(member)
//  但一个结构的各个成员可能具有不同的类型
//  * 附加个人理解:实例化的数组和结构,数组和结构的实例
//      由于一个结构的成员长度可能不同,所以不能像数组一样用下标来访问它们  
//  结构的每个成员都有自己的名字,可以通过名字访问
    
//  书本上:结构变量属于标量?谷哥之后,还是没啥确定的说法...
//  确定的是按照c标准,数组和结构属于aggregate data types(聚合数据类型)
//  这一part跳过,直接按照下面*语句的说法也说得通(可以避免构建的知识体系的崩塌)...  
  
//  scalar data types标量数据类型
//  *(结构变量)可以像对待其他标量类型那样执行相同类型的操作:
//      1.结构也可以作为函数的参数
//      2.结构也可以作为函数的返回值
//      3.相同类型的结构变量相互之间可以赋值
//      4.可以声明指向结构的指针,取一个结构变量的地址
//      5.也可以声明结构数组
// 个人心得:可以对结构变量进行和对标量变量一样的操作
//         像数组就不行

//  个人理解:
//      像标量变量一样,编译器给结构变量分配一块存储区域
//      相同类型的结构变量,编译器分配的内存区域大小时相等的
//      结构变量内的成员存储未必是连续的,有"缝隙"
//      不连续才是常态...

//  10.1.1 结构声明
//  在声明结构时,必须列出结构包含的所有成员
//  struct tag{ member-list } variable-list;
//        标签   成员列表      结构变量列表
//  struct  {
//      int     a;
//      char    b;
//      float   c;
//  } x;
//  
//  struct  {
//      int     a;
//      char    b;
//      float   c;
//  } y[10], * z;
//  结构变量x,一个名叫x的变量,它包含三个成员:一个整数,一个字符,一个浮点数;
//  结构(数据类型)数组y[10],它包含了20个结构;
//  指针z,它指向这个类型的结构
//  注意:这两个结构声明被编译器当作两种截然不同的类型,即使它们的成员列表相同.
//  变量x 和 变量y,变量z 的类型不同: z = &x是非法的[不同的(结构类型)],编译器会警告.
//  个人理解:数组和结构都是聚合类型,数组有int(数据类型)数组,char(数据类型)数组
//           不同类型的数组;
//           类似的,结构也有不同的类型,以结构来声明区分不同类型的结构(不能凭成员区分)
//  
//  使用tag标签字段,这样结构声明就可以在后续的声明中使用
//  使用标签创建同一种类型的结构
//  struct simple {
//      int     a;
//      char    b;
//      float   c;
//  };
//  个人理解(课本上的说法不便于我理解):
//  它(带标签的结构声明)本身并未创建任何变量
//  标签标识了一种类型的结构,用于声明未来的该类型的结构变量
//  struct simple x;
//  struct simple y[10], * z;
//  这些声明使用标签来创建(结构)变量
//  x,y,z都是同一种类型的结构变量
//
//  网上资料:typedef为一种数据类型定义一个新名字
//  
//  声明结构时可以使用另一种良好的技巧,
//  用typedef创建一种新的类型(名),例子所示:
//  typedef struct {
//      int     a;
//      char    b;
//      float   c;
//  } simple;
//  用这个技巧的结构声明和用标签的结构声明效果几乎相同
//  区别是这里的simple是这种类型的结构的数据类型别名,
//  而不是这种类型的结构的标签
//  所以后续的声明如下例所示:
//  simple x;
//  simple y[10], * z;
//  提示:如果想在多个源文件中使用同一类型的结构,应把带标签的结构声明或
//       typedef形式的结构声明放在一个头文件中,源文件需要使用这个类型的
//      结构声明时可以使用#include指令把头文件包含进来

//  注意:这里比较容易搞混的地方
//  a. 带tag标签的结构声明形式,后续的结构变量声明:
//     struct 标签名 结构变量名 
//  b. typedef为结构类型创建别名的结构声明形式,后续的结构变量声明:
//     结构类型别名 结构变量名 

//  10.1.2  结构成员
//  可以在结构外部声明的任何变量都可以作为结构的成员
//  结构成员可以是标量(变量),数组(变量),指针(变量)甚至是其他结构.
//  struct complex {
//      float f; 
//      int a[20];
//      long * lp;
        // simple要结合上下文来看,才能确定是结构的标签或别名
//      struct simple s;
//      struct simple sa[10];
//      struct simple * sp;
//  };      
//  一个结构的成员名字可以与其他结构的成员名字相同,它们之间并不会冲突

//  10.1.3 结构成员的直接访问
//  结构变量的成员通过.点操作符访问
//  点操作符接受两个操作数,二元运算符咯...
//  左操作数是结构变量的名字,右操作数是需要访问的成员的名字
//  这个表达式的结果就是指定的成员
//  struct complex comp;
//  成员a是一个数组,comp.a选择这个成员,这个表达式的结果是个数组名^(1)
//  成员s是个结构,所以表达式comp.s的结果是个结构名^(1)
//  我们可以把这个表达式用作另一个点操作符的左操作数,如(comp.s).a
//  选择结构comp的成员s(一个结构)的成员a
//  *点操作符的结合律:从左往右,所以可以省略括号,表达式comp.s.a表示相同的意思
//                  
//  ^(1): 结果是数组名的话,表达式结果为数组(首元素)指针 -- 已经过验证
//        结果是结构名的话  -- 目前还没结果,只能先按书上的结构名记了...
//                  
//  成员sa是一个结构数组,所以comp.sa是一个(结构)数组名^(1),它的值是一个指针常量
//  对这个表达式使用下标引用操作,如(comp.sa)[5]将选择一个数组元素,但这个元素本身
//  是一个结构,所以可以使用点操作符取得它的成员之一,例如
//  ((comp.sa)[5]).c
//  下标引用和点操作符优先级相同,结合律都是从左往右,所以可以省略括号,如下
//  comp.sa[5].c
//  上面两个表达式时等效的
//
//  10.1.4 结构成员的间接访问
//   -> 箭头运算符
//  .点操作符优先级高于间接(访问)操作符/间接运算符*
//  结构变量(标识符).成员 直接访问
//  (*结构指针).成员 间接访问
//  结构指针->成员 间接访问
//  拥有一个指向结构(变量)的指针,访问这个结构(变量)的成员
//      a.首先用间接运算符对结构(变量)指针进行间接运算,得到/找到这个结构(变量)在内存中
//        本质:间接寻址
//      b.然后用点操作符访问结构(变量)的成员
//  假设一个函数的参数是一个指向结构(变量)的指针,函数原型如下:
//  void func(struct complex * cp);
//  函数可以使用下面的表达式访问这个指针变量所指向的结构(变量)
//  再用点操作符访问结构(变量)的成员f
//  (*cp).f   (点运算符的优先级高于间接运算符)
//  c语言提供了一个更方便的操作符,箭头操作符->
//  箭头操作符接受两个操作数,左操作数必须是一个指向结构(变量)的指针
//  间接访问操作内置于箭头操作符中(箭头操作符对左操作数执行间接访问
//  取得指针所指向的结构变量,然后和点操作符一样,根据右操作数访问一个
//  指定的结构变量成员)
//  所以我们不需要显式地执行间接访问和使用括号
//  cp->f   访问一个float类型变量成员
//  cp->a   访问一个数组名
//  cp->s   访问一个结构
//
//  添加知识点:机器码中并没有数据类型的信息,操作码+操作数
//  个人理解:
//  这里先假设成员类型为int数据类型
//  结构成员的直接访问:
//      结构变量.成员
//      &结构变量.成员          取成员变量指针
//  结构成员的间接访问:
//      结构变量指针->成员
//      &结构变量指针->成员     取成员变量指针
//  上面两个表达式的本质是一个int变量,所以可通过&取该变量的指针
//  (常量为什么无指针,查看c_notebook.c立即数的概念)

//  10.1.5 结构自引用
//  链表和树,都用这种技巧实现
//  self reference 自引用
//  结构成员的类型为自身结构类型  
//  struct self_reference {
//       int                     a;
//       struct self_reference   b;
//       int                     c;
//  };
//  这种类型自引用是非法的
//  成员b是一个完整的结构变量,你会发现
//  成员结构变量b的成员也有一个结构变量b,无限套娃...
//  (简单理解就是结构变量包含结构变量,无限包含结构变量)
//  它是无限递归的... 
//  你可以想象一下这类型的结构变量占用的存储空间无限增大
//  所以上面的结构声明是非法的
//  编译时编译器会报错
//
//  struct self_reference2 {
//       int                        a;
//       struct self_reference2   * b;
//       int                        c;
//  };
//  这个结构声明则是合法的
//  成员b为结构(变量)指针,指向的是同一类型的不同结构(变量)
//  这是更高级的数据结构...如链表和树,都是用这种技巧实现的
//  每个结构(变量)指向链表的下一个元素或树的下一个分枝
//  指针(变量)的长度是固定的,通过间接运算符访问下一个同一类型
//  的结构变量
//
//  警告:
//  在结构声明内部用结构类型别名声明结构指针变量(成员)
//  typedef struct {
//       int                 a;
//       self_reference3   * b;
//       int                 c;
//  } self_reference3;
//  编译器编译时报错:未知类型self_reference3
//  这个结构声明的目的是创建结构类型别名self_reference3,
//  但类型名直到声明的末尾才定义,在结构声明的内部它尚未
//  定义,所以编译到指针变量b是报错未知类型.
//
//  解决方法为添加一个结构标签,
//  在结构声明内部用结构标签声明结构指针变量(成员)
//  typedef struct self_reference3 {
//       int                        a;
//       struct self_reference3   * b;
//       int                        c;
//  } self_reference3;
//  但有啥要整这么复杂...目前个人水平太低,不太理解干嘛要这样做...

// 10.1.6 不完整的声明
//  struct b;   不完整的结构声明
//  struct a {
//      struct b * pointer;
//  };
//
//  struct b {
//      struct a * pointer;
//  };
//  
//  结构声明a的成员列表中需要结构b的不完整声明(incomplete declaration)

//  10.1.7 结构的初始化
//  结构的初始化方式和数组很相似
//  一个位于花括号内部,由逗号分隔的初始值列表
//  用于结构各成员的初始化
//  这些值根据结构成员列表的顺序写出
//  如果初始值列表的值不够,剩余的结构成员将使用缺省值进行初始化
//  struct init_ex {
//      int     a;
//      short   b[10];
//      simple  c;          // 10.1.1 struct simple
//  } x = {
//          10,
//          {1, 2, 3, 4, 5},    //数组的初始值表,不足的初始化为0
//          {25, 'x', 1.9}
//  };

//  10.2 结构、指针和成员
//  例子:  
//  为结构类型创建别名
//  typedef struct {
//      int     a;
//      short   b[2];
//  } ex2;
//  为带标签的结构类型创建别名
//  typedef struct ex {
//      int         a;
//      char        b[3];
//      ex2         c;
//      struct ex * d;
//  } ex;
//  图示:《c和指针》第二版 P200 个人解释:ex结构类型的模板template
//  *编译器只要有可能就会设法避免成员之间的空间浪费
//
//  声明结构变量
//  ex  x = {10, "Hi", {5, {-1, 25}}, 0};
//  ex结构(数据)类型指针px
//  ex  * px = &x;
//  图示:《c和指针》第二版 P200 
//  结构变量声明创建的如图所示,一个指针变量,一个结构变量
//  px | | --> | (a:10) ('H','i',0) |(a:5) (b[1]:-1,b[2]:25)| (d:0) |  
//  还是直接看书本的图示吧...
//
//  10.2.1 访问指针
//  表达式px的右值是(注意:由于还没找到英文原版书籍,我感觉
//  正确的理解应该是表达式px作为右值,下面的也应这样理解,
//  我就不在下面一一说明了,太麻烦了...人生苦短,我要偷懒...
//  访问指针和访问结构这两小节我都是按书本的说法记的笔记,
//  表达式px作为右值,访问指针变量px的内存位置,取内存位置
//  上的值;表达式作为左值,访问px的内存位置,内存位置接受新值
//  插入一点计算机组成知识点(寻址方式):
//  a.立即方式:操作数在指令中明确地给出
//  b.直接方式:在指令中直接给出这个单元的地址
//  c.间接方式:操作数的有效地址是存储单元中的内容,这个存储单元
//    的地址在指令中给出
//  详细的请看《计算机组成》第5版 P34)
//
//
//  px是一个指针变量,且不存在间接运算符,所以表达式的值
//  就是指针变量px的值(内容)
//  这个表达式的左值是变量px(标识符)
//  (附加知识点:任何时候都要记住,机器代码=操作码+操作数)
//
//  表达式px+1,这个表达式不是一个合法的左值
//  它的值并不存储于任何可标识的内存位置
//  这个表达式的右值很有趣,如果px指向一个结构数组,
//  则这个表达式将指向该数组的下一个结构
//  (px+1等于加上一个该结构变量的存储长度)
//  编译器无法检测到这类错误,必须自己判断这样的指针运算
//  是否右意义

//  10.2.2 访问结构
//  我们可以使用*间接运算符对指针进行操作,间接访问指针指向的变量
//  (直接访问就是访问指针变量的位置)
//  表达式*px的右值是px所指向的结构
//  *px表达式的结果是整个结构
//  (个人理解: *结构指针 与 结构变量标识符 表达式的结果都是访问整个结构)
//  可以把表达式赋值给另一个结构类型相同的结构变量
//  你也可以把*px作为.点操作符的左操作数,访问结构变量的指定成员(.优先级高于*)
//  *px也可以作为函数的参数(个人心得:形参为左值,实参为右值),或作为函数返回值(不
//  过整个结构变量作为参数或返回值占用空间大,程序效率低)
//  表达式*px的左值是一个结构变量,将接收一个新值(更精确地说,将接受所有成员的新值)
//  可修改的左值(例如变量),重要的是位置,而不是这个位置所保存的值
//  
//  10.2.3 访问结构成员
//  表达式px->a的右值是:  
//  访问结构变量的成员a,取成员a(变量a)的值(数据)
//  ->操作符(箭头操作符)间接访问结构,然后访问成员a
//  知道指向结构的指针不知道结构变量名,便可以使用表达式px->a
//  如果知道结构变量名,可以使用功能相同的表达式x.a
//  
//  *px表达式和px->a表达式
//  结构变量的指针值与结构变量第一个成员的指针值相等
//  它们具有相同的地址,但指针类型不相同
//  px->a访问结构变量的成员a,就是访问变量a
//  表达式&px->a用&操作符取变量a的地址(指针)
//  (箭头操作符优先级比&地址操作符高)
//
//  为了便于理解,我自己添加的例子:
//      struct test {
//          int a;
//          char b[5];
//      };
//      int main(void)
//      {
//          struct test st = {10, {1, 2, 3, 4, 5}};
//          struct test * pst;
//          int * pi;
//          pst = &st;
//          //编译报错,指针类型不同
//          //pst = st.a;
//          //表达式st.a和pst->a本质都是访问变量a
//          //这里把两个表达式作为右值,
//          //作为右值时,访问变量a标识的内存位置,取位置上的值(数据)
//          pi = &st.a;
//          pi = &pst->a;
//          
//          //访问数组就是访问指向数组的指针常量
//          //对数组进行取地址操作,也是得到指向数组的指针常量
//          //我个人的推论(有言在先,错了别怪我...):这个指针常量
//          //应该是在操作码中直接给出的...像其他常量一样,没有指针
//          //&&数组名-->&数组指针(常量)和&10(常量)一样编译会报错
//          printf("%p\n", pst->b);
//          printf("%p\n", &pst->b);
//          //访问数组得到的是数组的指针(指针常量)
//          printf("%p, %ld\n", pst->b, pst->b);
//
//          //数组首元素的地址与数组的地址(指针)相同
//          //因此下面这一句代码可以输出成员数组第一个元素
//          printf("%d\n", *pst->b);
//          //访问成员数组的第二个元素
//          //编译器编译后的机器码其实没有这一句的执行过程
//          //个人猜测:应该跟编译器的优化有关,编译时应该可以
//          //通过优化选项让生成的机器码有执行这个访问过程的指令
//          //仅为猜测,看完之后概不负责...
//          pst->b[1];
//          return 0;
//      }
//  根据汇编代码,表达式&st.a和&pst->a在计算机中的执行
//  都是取变量a的指针的值mov到寄存器
//  (因为两个表达式本质最后都是访问变量a)
//  *pst访问整个结构,*pi访问结构成员int变量a
//  如果结构成员是数组的话,表达式pst->b的结果为指针常量(数组名是指针常量)
//  数组名可以做右值,不可以作为左值,它是一个常量
//  
//
//  10.2.4 访问嵌套的结构  
//  (例子在10.2)
//  访问本身也是结构的成员c,使用表达式px->c
//  作为左值:整个结构(个人理解,间接访问结构变量成员c(成员c本身也是结构变量)
//  作为左值时,重点在内存位置,而不是内存位置上的值/数据)
//  
//  使用.点操作符访问c的特定成员,px->c.a作为右值,
//  访问成员c的成员a
//  
//  *px->c.b
//  个人理解版本:
//  (优先级:箭头操作符>点操作符>间接操作符
//  间接访问成员c,访问结构变量c,再直接访问结构变量c的成员b(数组)
//  访问数组等于访问指向数组的指针(常量),在机器码的操作码中直接给
//  出该指针常量的地址,访问该指针常量,再通过该指针常量(地址),访问
//  整个数组,《计算机组成》间接寻址方式的知识点)
//  
//  10.2.5 访问指针成员
//  
//  10.3 结构的存储分配
//  (附加网上资料,然后的个人理解:
//  1.结构的每个成员都以为内存存储空间是以它自己的存储长度来划分的,
//    因此成员储存的位置一定在自己宽度的倍数上-->这一句是精髓啊~
//    结构成员之间的存储不能重叠,按成员列表的顺序存储
//  2.结构存储的总长度为成员中存储长度最长的长度的倍数,不足的补足
//    -->按最宽/长(存储空间最长)成员进行内存补齐
//  (这个应该是最精准的版本了,就暂时这样了)
//      
//  struct align {
//      char    a;
//      int     b;
//      char    c;
//  };  
//  8c 8d 8e 8f 90 91 92 93 94 95 96 97
// a--
//             b-- -- -- --
//                         c--
//  -- -- -- -- -- -- -- -- -- -- -- --  b长度的3倍补齐
//  结构储存总长(成员中储存长度最长的长度倍数补齐,这个例子中是12个字节)

// 10.6 联合
// union
// 联合的所有成员引用的是内存的相同位置
// 在不同时刻不同的东西存在同一内存位置,使用联合