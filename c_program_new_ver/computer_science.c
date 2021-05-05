// 一组门锁存器组成寄存器,寄存器能存一个数字,这个数字有多少位,叫位宽(width)
// 寄存器,允许输入线为1,门锁存器存储的值全部重置为0
//
// 线路复用器/数据选择器/multiplexer/MUX:
//  不需要重置,直接用就是了,花样怎么变都是n位二进制那2^n个组合(各个组合的顺序变而已)      
//
//《计算机科学速成课》P3
// 计算机基础知识:
//   半导体,常温条件下导电性能介于导体和绝缘体之间的材料
//   晶体管,它是一个开关,可以用控制线路来控制开或关
//                                电极(可当成输入)
//                                  |
//                                 /
//      控制线control wire --------|   <---- "|"为半导体,是一个门电极gate electode
//                                 \           通过控制线改变门的电荷electrical charge of the gate
//                                  |          来控制半导体材料的导电性
//                                 电极(可当成输出)
//   布尔代数(boolean)
// 1.NOT Gate 非门:
//                                电极
//                                  |_____  output输出
//                                 /
//               input输入 --------|   
//                                 \           
//                                  |         
//                                __|__
//                                 ___    "接地"
//   input off, output on  电流往output方向流动
//   input on , output off 电流往接地方向流动
//   logic table for Not:
//       ____________________
//      | input   |   output |
//      | true  1 |  false 0 |
//      | false 0 |  true  1 |
//       --------------------
// 2.AND Gate 与门:
//     _____  ____  _____  output
//          \/    \/
//         ----  ----
//          |     |
//      inputA  inputB 
//  logic table for And:
//       ________________________________
//      | input A | output B |  output   |
//      | true  1 |  true  1 |  true  1  |
//      | true  1 |  false 0 |  false 0  |
//      | false 0 |  true  1 |  false 0  |
//      | false 0 |  false 0 |  false 0  |
//       --------------------------------
// 3.OR Gate 或门:
//   current电流
//             __________     ___
//            |          \___/   |
// current ---|            |     |-- output
//            |__     ____/-\____|
//               \___/     |
//                 |       |
//              inputA   inputB  (transistor晶体管)
//       ________________________________
//      | input A | output B |  output   |
//      | true  1 |  true  1 |  true  1  |
//      | true  1 |  false 0 |  true  1  |
//      | false 0 |  true  1 |  true  1  |
//      | false 0 |  false 0 |  false 0  |
//       --------------------------------
// 4.XOR Gate 异或门:
// 
//  =|=AND-Not-|
//   |=OR------|=AND--
//
//            _______      NOT
//  ---+------|      \     |\
//     |      | AND   )----| >----+
//  ---|--+---|______/     |/     |
//     |  |                       |   _______
//     |  |   _______             |___|      \
//     |__|___\      \            ____| AND   )----
//        |    | OR   \___________|   |______/
//        |___ |      /               
//            /______/
//
//       ________________________________
//      | input A | output B |  output   |
//      | true  1 |  true  1 |  false 0  |
//      | true  1 |  false 0 |  true  1  |
//      | false 0 |  true  1 |  true  1  |
//      | false 0 |  false 0 |  false 0  |
//       --------------------------------
//-----------------------------------------------------
//P5
// ALU: arithmetic logic unit
//        an arithmetic unit and a logic unit
//-----------------------------------------------------
// 5.half adder 半加法器:
//       _______________________
//      |   input   |  output   |
//      ------------------------
//      |  A  |  B  |carry| sum |
//      ------------------------
//      |  0  |  0  |  0  |  0  |
//      |  0  |  1  |  0  |  1  |
//      |  1  |  0  |  0  |  1  |
//      |  1  |  1  |  1  |  0  |
//      ------------------------
//                 _______             
//               \ \      \           
//   A---+-------|  | XOR  \______SUM
//   B---|--+----|  |      /              
//       |  |    / /______/
//       |  |       ______
//       |  |______|      \
//       |_________| AND   )------CARRY
//                 |______/
//
//   抽象(封装成一个单独组件):
//         _____________
//     A--|  half adder |-- SUM
//     B--|_____________|-- CARRY
//
// 6.full adder 全加器:
//     注: 这里的C是指低位的进位
//       _____________________________
//      |     input       |   output  |
//      -------------------------------
//      |  A  |  B  |  C  |carry| sum |
//      -------------------------------
//      |  0  |  0  |  0  |  0  |  0  |
//      |  0  |  1  |  0  |  0  |  1  |
//      |  1  |  0  |  0  |  0  |  1  |
//      |  1  |  1  |  0  |  1  |  0  |
//      -------------------------------
//      |  0  |  0  |  1  |  0  |  1  |
//      |  0  |  1  |  1  |  1  |  0  |
//      |  1  |  0  |  1  |  1  |  0  |
//      |  1  |  1  |  1  |  1  |  1  |
//      -------------------------------
//     111      CARRY
//      101     A
//  +   111     B
//  -------------------
//     1100     SUM
//  从第2位起,A+B+CARRY[前一位]=SUM
//  然后根据A+B的CARRY[当前位] 与 CARRY[前一位] 经过 OR门 --> 得到CARRY[下一位]的信号
//
//  这里的半加器,你把上面半加器里的AND门放在XOR门上就行了...
//         _____________
//     A--| half adder 2|-- CARRY -------------------------------- OR ------ C[i+1]
//     B--|_____________|-- SUM---|                                 |
//                                |        _____________            |
//                                |----A--|half adder 1 |-- CARRY---|
//     C[i]--------------------------- B--|_____________|-- SUM ------------ SUM[i] (i>=0)
//  C[i+1]会发生进位CARRY的必要条件:
//     1. 全加器2只有A和B都为1时才会进位,它的SUM为0,所以全加器2最大只能为1,不会进位CARRY
//     2. 全加器1只有A(half adder2 SUM)和B都为1时才会进位
//            2.1 全加器1 A(全加器2 SUM)为1的情况,只有全加器2 A和B中其中一个为1,一个为0,全0或全1 SUM都为0
//            2.2 全加器1 B(低一位的进位C为1)
//   总结：半加器1和半加器2不会发生同时进位CARRY的情况
//
//   全加器抽象:
//                 ___________
//           A----| full      |----C[i+1]
//           B----| adder     |
//        C[i]----|___________|----SUM[i]
//
// 7.8bit ripple carry adder(8位行波进位加法器):
//       _____________
//   A--|  half adder |-- SUM ----------------------------------------------- SUM[0]
//   B--|_____________|-- CARRY--|
//                               |         ___________
//                               |--C[i]--| full      |--SUM[i]---------------SUM[1]
//                                     A--| adder     |
//                                     B--|___________|--C[i+1]---后面继续堆全加法器就行了
//
//  最高位的全加器如果发生进位carry,就会发生溢出overflow,超过8bit所能表示的数据
// * 现代的计算机用的加法电路有点不同,叫"超前进位加法器" carry-look-ahead adder
//   简单的CPU做乘法运算只是多做几次加法
//   现在的计算机和手机有专门的加法器,比较复杂,但本质也只是堆逻辑门
// 
// 8. arithmetic & logic unit 算术逻辑单元
//    里面很多逻辑门,我们不必关心这些细节,抽象化:
//                         8bit       8bit
//                        inputA     inputB
//          4bit            __|__    __|__        flags(常用的,还有很多其他标志,输出0/1-->假/真):
//      operation code -->  \    \  /    /   --> overflow  (用一条线连接加法器最高位carry输出即可)               
//                           \    \/    /    --> zero      (可用于两个数是否相等)
//                            \________/     --> negative  (可用于比较连个数的大小)
//                                |
//                              output
//                               8bit
//   logic unit:
//   zero flag(只要有1个1输入,输出结果就会为0假)
//     =OR--|
//          |==OR--|
//     =OR--|      |
//          |      |==OR--NOT--output
//     =OR--|      |
//          |==OR--|
//     =OR--|
//
//  注意: 各种门电路是一种抽象,我们只考虑输入和输出就好,不要太纠结于真实电路
//


// RAM random access memory
// *理解寄存器和内存 看懂网课《计算机科学速成课》P6
// 1.保存1的电路
//                 ____
//           A-----\   \ 
//                  |OR >------+----- output
//           B--+--/___/       |
//              |______________|
//
//   A输入1,B输入0,OR输出1 
//   output线上回路给B线
//   相当于B输入1
//   A停止输入1
//   B --> OR --> B 形成回路,电路记录了"1"
//   A再输入或停止,也无法改变这个回路的状态
//    
// 2.保存0的电路
//                ____
//          A-----|   \ 
//                |AND )------+----- output
//          B--+--|___/       |
//             |______________|
//
//   A,B输入1,则output为1,回路为1
//   B停止输入,output还是为1
//   A停止输入(则回路也停止)
//   A无论再设什么值,电路始终输出0
//
// 3.and-or latch (and-or 锁存器)
//   latch:弹簧锁,插销
//               _________________________________
//              |  ____                           |
//              +--\   \               ___        |
//                  |OR >-------------|   \       |
//   input set-----/___/    |\        |AND )------+----- output
//       reset--------------| >-------|___/                         
//                          |/
//                         NOT
//     第一步:
//       input set设置1
//       reset设置0,经过NOT门变1
//       AND门相当于输入了两个1,output1,回路1
//       input set设置0后,回路1 加 NOT门,AND还是保持output1
//     第二步:
//       reset设置1,经过NOT门变0         
//       AND门output0,回路变0
//     总结:
//     input set设置1,ouput1,保存1
//     reset设置1,ouput0,保存0
// 
// 4.gated latch (门锁存器)
//  4.1先看抽象化后的gated latch门锁,看它所要完成的操作,就更容易理解里面的逻辑门为什么那样设计   
//
//   数据输入           ________
//  data input   -----| gated  |      数据输出
//                    | latch  |----- data out
//  write enable -----|________|
//   允许写入线
//  数据输入和允许写入都从0开始
//  第一步,写入并保存1:
//    允许写入线1,数据输入1,数据输出1
//    允许写入线0,数据输入线不管是1或0,数据输出都为1,值被存起来了
//  第二步,写入0:
//    再次设置允许输入线为1,数据线输入0,数据输出为0
//    设置允许输入线为0,数据输入线不管是1或0,数据输出都为0
//  --> 只保存1bit没啥用,因此用一组门锁存器组成寄存器
//
//  设计成这样是为了逻辑上更容易理解,比 输入设置 和 复位 更好理解吧...
//  4.2 gated latch 抽象化前:
//    
//                                                  _________________________________
//                                                 |  ____                           |
//                                         ___     +--\   \                          |
//     data input --------+---------------|   \        |OR >--+                      |
//                        |               |AND )------/___/   |                      |
//                 +-------)--------------|___/               |                      |
//                 |      |                                   |        ___           |
//                 |      |    |\           ___               +-------|   \          |
//                 |      +----| >---------|   \      |\              |AND )---------+----- output
//                 |           |/ NOT      |AND )-----| >-------------|___/
//  write enable --+-----------------------|___/      |/
//                                                   NOT
// *4.3 理解下面这个过程:                                                   
//   实现output 0 --> 1:
//    write enable --> 1
//    data input --> 1
//    output 1
//    write enable --> 0
//    (这个只是说明:data input --> 1或0,output都为1)
//    output保存1
//   实现output 1 --> 0:
//    write enable --> 1
//    data input --> 0
//    output --> 0
//    write enable --> 0
//    output保存0
//
//  4.3.1 write enable --> 1
//                                                  _________________________________
//                                                 |  ____                           |
//                                         ___     +--\   \                          |
//     data input ---0----+---------------|   \        |OR >--+                      |
//                        |               |AND )---0--/___/   |                      |
//                 +---1---)--------------|___/               |                      |
//                 |      |                                   |        ___           |
//                 |      |    |\           ___               +-------|   \          |
//                 |      +----| >---1-----|   \      |\              |AND )---------+--0-- output
//                 |           |/ NOT      |AND )--1--| >------0------|___/
//  write enable --+----1------------------|___/      |/
//                                                   NOT
//
//  4.3.2 data input --> 1    回路1
//                                                  _________________________________
//                                                 |  ____                           |
//                                         ___     +--\   \                          |
//     data input ---1----+---------------|   \        |OR >--+                      |
//                        |               |AND )---1--/___/   |                      |
//                 +---1---)--------------|___/               |                      |
//                 |      |                                   |        ___           |
//                 |      |    |\           ___               +-------|   \          |
//                 |      +----| >---0-----|   \      |\              |AND )---------+--1-- output
//                 |           |/ NOT      |AND )--0--| >-------------|___/
//  write enable --+----1------------------|___/      |/
//                                                   NOT
//
//  4.3.3 write enable --> 0   回路1
//                                                  _________________________________
//                                                 |  ____                           |
//                                         ___     +--\   \                          |
//     data input ---1----+---------------|   \        |OR >--+                      |
//                        |               |AND )---0--/___/   |                      |
//                 +---0---)--------------|___/               |                      |
//                 |      |                                   |        ___           |
//                 |      |    |\           ___               +-------|   \          |
//                 |      +----| >---0-----|   \      |\              |AND )---------+--1-- output
//                 |           |/ NOT      |AND )--0--| >-------------|___/
//  write enable --+----0------------------|___/      |/
//                                                   NOT
//
//  4.3.4 write enable --> 1   回路1
//                                                  _________________________________
//                                                 |  ____                           |
//                                         ___     +--\   \                          |
//     data input ---1----+---------------|   \        |OR >--+                      |
//                        |               |AND )---1--/___/   |                      |
//                 +---1---)--------------|___/               |                      |
//                 |      |                                   |        ___           |
//                 |      |    |\           ___               +-------|   \          |
//                 |      +----| >---0-----|   \      |\              |AND )---------+--1-- output
//                 |           |/ NOT      |AND )--0--| >-------------|___/
//  write enable --+----1------------------|___/      |/
//                                                   NOT
//
//  4.3.5 data input --> 0    回路0
//                                                  _________________________________
//                                                 |  ____                           |
//                                         ___     +--\   \                          |
//     data input ---0----+---------------|   \        |OR >--+                      |
//                        |               |AND )---0--/___/   |                      |
//                 +---1---)--------------|___/               |                      |
//                 |      |                                   |        ___           |
//                 |      |    |\           ___               +-------|   \          |
//                 |      +----| >---1-----|   \      |\              |AND )---------+--0-- output
//                 |           |/ NOT      |AND )--1--| >-------------|___/
//  write enable --+----1------------------|___/      |/
//                                                   NOT
//
//  4.3.6 write enable --> 0    回路0
//                                                  _________________________________
//                                                 |  ____                           |
//                                         ___     +--\   \                          |
//     data input ---0----+---------------|   \        |OR >--+                      |
//                        |               |AND )---0--/___/   |                      |
//                 +---0---)--------------|___/               |                      |
//                 |      |                                   |        ___           |
//                 |      |    |\           ___               +-------|   \          |
//                 |      +----| >---1-----|   \      |\              |AND )---------+--0-- output
//                 |           |/ NOT      |AND )--0--| >-------------|___/
//  write enable --+----0------------------|___/      |/
//                                                   NOT
// 看一下理解就好,直接记抽象化的门锁存器(这个容易记--')...
//
// 5. 8-bit register(8bit寄存器):
//    现在的CPU一般都是64bit寄存器啦~原理是一样的,位宽更大而已
//        一根线连接所有允许写入线
//                  |
//                  |     ________
//  data input  -----)---| gated  |      
//                  |    | latch  |----- data out
//  write enable    |----|________|
//                  |     ________
//  data input  -----)---| gated  |      
//                  |    | latch  |----- data out
//  write enable    |----|________|
//                  |     ________
//  data input  -----)---| gated  |      
//                  |    | latch  |----- data out
//  write enable    |----|________|
//                  |     ________
//  data input  -----)---| gated  |      
//                  |    | latch  |----- data out
//  write enable    |----|________|
//                  |     ________
//  data input  -----)---| gated  |      
//                  |    | latch  |----- data out
//  write enable    |----|________|
//                  |     ________
//  data input  -----)---| gated  |      
//                  |    | latch  |----- data out
//  write enable    |----|________|
//                  |     ________
//  data input  -----)---| gated  |      
//                  |    | latch  |----- data out
//  write enable    |----|________|
//                  |     ________
//  data input  -----)---| gated  |      
//                  |    | latch  |----- data out
//  write enable    +----|________|
//
//  存入8bit数据:
//      连接所有允许输入线的线设置1
//      然后每根数据写入线输入数据(正规讲法就是高电平就是1,低电平就是0咯...)
//      数据写入后,允许输入线设置为0,数据保存成功
//      (允许输入线设置1,数据全部重置为0,这里有待验证,应该是对的啦,只是我现在脑袋疼不想再走一边门锁存器)
//
//  8bit register(8bit寄存器):
//    8条数据输入线
//    8条数据输出线
//    1条允许写入线
//  *我觉得记住门锁存器这个概念很重要,承上启下...数字电路就是一层层封装抽象...要记住每一层是不可能的...
//   今天记住了明天也会忘记...
//
// 6.内存跟寄存器的锁存器排列方式不同,如果跟寄存器一样,要用的线就太多了,因此内存采用矩阵排列锁存器(网格)
//   行线和列线都为1,确定门锁存器,通过AND门来判断,输出--> [行+列选择测试线]
//   (记住,一个门锁存器储存一个bit位数据)
//   [行+列选择测试线通过AND门,门锁存器矩阵定位]与允许写入线(一条允许写入线连接所有门锁存器) 信号再通过一个 AND门
//   [行+列选择测试线通过AND门,门锁存器矩阵定位]与数据线(一条数据输入线连接所有门锁存器,用于读写) 信号再通过一个 AND门
//   [行+列选择测试线通过AND门,门锁存器矩阵定位]与允许读取线(一条允许读取线连接所有门锁存器) 信号再通过一个 AND门
//
//   一个256bit内存,需要16根行线,16根列线,1根允许写入线,1根数据输入线,1根数据读取线
//   这三根线都分别连接所有门锁存器,分别靠和[行+列选择测试线]一起通过AND门来判断操作
// 理解到这个层次差不多了...再深究下去头发要没了
//
// 7. 数据选择器(data selector),也叫多路复用器(multiplexer,简称MUX)
// 一个多路复用器处理行row
// 一个多路复用器处理列column
//  
//  *线路复用器的设计(终于搞懂啦!!!好开心...)
//  用到 非门 和 与门
//  设计思路:
//    第一步 输出每个数位的所有位值
//    第二步 列举出n位二进制数的所有组合  
//
//  A1 A2两个地址信号(address singals)
//  A0 -----+------------ A0
//          |    |\  NOT   
//          +----| >----- !A0  
//               |/
//    
//  A1 -----+------------ A1
//          |    |\  NOT   
//          +----| >----- !A1  
//               |/
//
// 穷举法(数学原理:两个二进制位)
// 数位1和0,每个数位只有0,1两种位值
// A0和!A0为相反的位值 
// A1和!A1为相反的位值
//  默认A1=0,A2=0
// 穷举两位二进制数的所有组合
//  A1  A0
//  A1 !A0
// !A1  A0
// !A1 !A0
//  只有!A1!A0经过 与门(AND门) 为真(1)
//  *前置条件:0.默认值 A0=0 A1=0
//  *核心思想:1.需要哪个"与门"输出,就把哪个"与门"的输入转换成!A1!A0
//           2.通过取反A1和A0的值实现!A1!A0的组合  
//           3.取反通过改变地址信号线的 信号 实现(A1取反成!A的同时,!A1会取反成A1)
//  A1=0 A0=0
//  0   0   
//  0   1   
//  1   0
//  1   1   =AND=> enable
//
//  A1=0 A0=1
//  0   1    
//  0   0  
//  1   1   =AND=> enable
//  1   0  
//  
//  A1=1 A0=0
//  1   0   
//  1   1   =AND=> enable
//  0   0
//  0   1   
//
//  A1=1 A0=1
//  1   1   =AND=> enable   
//  1   0
//  0   1
//  0   0  
//           ____
//   A0-----|    \ 
//          |AND  )-----
//   A1-----|____/
//           ____
//   A0-----|    \ 
//          |AND  )-----
//  !A1-----|____/
//           ____
//  !A0-----|    \ 
//          |AND  )-----
//   A1-----|____/
//           ____
//  !A0-----|    \ 
//          |AND  )-----
//  !A1-----|____/
//
// 上面的理解不够直观,还是直接举个栗子吧~  
//  二进制
//  A2=0  A1=0  A0=0
//  数位    2   1   0
//         A2  A1  A0
//         A2  A1 !A0
//         A2 !A1  A0
//         A2 !A1 !A0
//        !A2  A1  A0
//        !A2  A1 !A0
//        !A2 !A1  A0
//        !A2 !A1 !A0   ==> enable
//  
//  enable要向上移动一位,要将A0变成!A0,    
//  0位的地址线输入信号就要变为!A0,输出A0变成!A0,!A0变成了A0  
//  如下所示:
//         A2  A1 !A0
//         A2  A1  A0
//         A2 !A1 !A0
//         A2 !A1  A0
//        !A2  A1 !A0
//        !A2  A1  A0
//        !A2 !A1 !A0   ==> enable
//        !A2 !A1  A0   
//
//  数学理论层面:
//  *再进行深入理解(以下的理解对我而言是理解线路复用器的数学理论核心啊!!!)
//  从位置记数法的本质:各 数位 位值的排列组合(不重复的组合数量)来记数
//  这里讨论的是二进制(位置记数法的其中一种),n为位数(从0开始),组合数=2^n
//  看下面的例子:
//  数位    1   0
//  只有1位的二进制
//              0
//              1
//  然后这个二进制数加多一位,两位的二进制
//          0   0
//          0   1
//          1   0
//          1   1
//  两位的二进制的组合数是没加之前的两倍 
//  在1位二进制的组合前加个0,是一组新组合
//  在1位二进制的组合前加个1,又是一组新组合   
//  
//  **理解本质的奥妙之处(啊...我悟了...打通了任督二脉的感觉...):
//  这个规律延伸到多位二进制,多加的数位可以是任意位置,
//  反正就是让组合数量翻一倍,
//  一倍的组合是带新插入数位的数值0的(这个数位的位值为0时所有组合)
//  另一倍的组合是带新插入数位的值1的(这个数位的位值为1时所有组合)
//  然后你删除新插入的0和1,你会发现,你得到了两组完全一样的克隆组合
//  所以你就会发现,你在multiplexer修改输入信号,本质不过就是
//  新插入数位的位值0和1在两组相同的组合 互相调换了个位置而已...
//  
//  当然了,如果一定要找学术的正规的理解,布尔代数可能是比较正确的一个方向
//  但我总不能又跑去啃一门 布尔代数 吧...头发掉不起,人生耗不起啊...
//  
//  况且我现在的理解不是更接近原始的本质吗~~~
//
//  ***通过改变地址信号,把需要通过的与门的编码全变成1就选择成功了,
//  需要改多位编码的就重复上面的过程就好了
//  修改1位编码的快速记忆思路:
//  5位编码,先去掉需要修改的位,剩下的为两个2^4的相同组合
//  从新插入要修改的为,填0的组合和填1的组合把0和1对调以下,就实现了修改
//  有下一位需要修改的编码重复上一步即可
//
//  电路设计层面:
//  1.前面的地址信号为数位
//  后面两个输出为每个数位的两个数值
//  A0 -----+------------ A0
//          |    |\  NOT   
//          +----| >----- !A0  
//               |/
//  2.然后就是排列出n位二进制的所有组合,最大组合数位2^n
//
//
//  再记录一点最新心得:
//  线路复用器,就是n位二进制的2^n个排列组合,只是各组合之间的先后顺序的改变
//  地址信号线再怎么变(输出的位值还是0和1),
//  然后思维转到新插入位的位值全部0和1转换(0和1填充到两个相同的2^(n-1)组合)
//  还是这2^n各组合,只不过顺序变了而已
//
//  RAM结构体系的个人抽象理解:
//  矩阵通过行列选择器(多路复用器)访问1bit存储空间(门锁存器)
//  把8个矩阵并排,然后通过相同8位总线分别并排连接,  
//  ==> 一个bank为一个二维矩阵 ==> 8个bank合成一个chip(三维矩阵)
//  ==> 把下面的一堆描述,在转换以下,平铺的8个二维矩阵,堆叠成三维矩阵就行了
//  8个矩阵读取相同的8bit地址编码,实现相同的地址访问8个不同矩阵的门锁存器
//  也就是访问一个字节Byte的数据/存储空间(门锁存器)
//  每个矩阵有n条地址线,1条数据线(输入和输出),1条允许输入线,1条允许输出线
//  然后1条允许输入总线连接8个矩阵的允许输入先
//  1条允许输出总线连接8个矩阵的允许输出线
//  这8bit/1Byte数据就能输入,储存,输出了(当然还有允许输入线设置为1时,8位数据会清零)  
//  为什么是8位数据清零,因为一个地址编码一次只能访问矩阵的一个门锁存器
//  附加内容:4个可以一次输入储存和输出的内存芯片,连接芯片的地址总线的最低3位不连接芯片
//          8个连续地址读取到的其实是相同的64位数据
//          数据跨越两个不同的64位存储空间,就需要读取两次才能读取完整数据
//          编译器会处理内存对齐问题
//          能访问单个字节的cpu实际上还做了很多处理
//  重点:一个内存地址(物理地址)对应一个字节Byte的数据
//          
//  专业的内存参考书:《Memory systems Cache DRAM Disk》
//
//  更详细的去看《深入理解计算机系统》
//  SRAM 高速缓存用(晶体管储存)
//  DRAM 内存用(电容储存)
//
//  内存chip芯片的width一般位4bit,8bit或者16bit
//  所以要凑够数据带宽的话:
//      4bit * 16个chip
//      8bit * 8个chip
//     16bit * 4个chip
//  64bit width 一个 rank
//  (个人的一点领悟:8个连续地址读取的是相同的64位数据,
//  0xff000
//  0xff001 
//  0xff010
//  0xff011
//  0xff100
//  0xff101
//  0xff110
//  0xff111 八个连续地址,
//  发送地址编码0xff000时,cpu读取8字节中的哪个字节,
//  那个字节不就是所谓存储在0xff000地址上的字节了吗...突然间悟了...
//  再然后低序字节存放在所谓的低地址不就是小端序了吗...
//  其实也就是发送低地址编码信号时,cpu截取8字节编码中的高序字节还是低序字节)
//
//  channel dimm rank chip bank (row column)



// 草稿(临时的笔记):.....................................................................
// 64位计算机,字长64位
// DRAM organization
// channel DIMM rank chip bank row && column
//  油管课程:
//  bank ==> 2D array of cells: row * columns
//  
//  (暂时的笔记,以后会修改或删除
//  以下为个人对内存电路的实际设计理解得很粗浅甚至可能有误得情况下,脑袋里构建的内存结构体系
//  8个矩阵1个bank(这不是绝对的,矩阵个数是可多可少的,具体情况却决于设计)
//  8个矩阵输入/输出8位数据,8个矩阵的row和column多路复用器接收相同的地址编码
//  1字节数据就是这么来的
//  )
// 草稿(临时的笔记):.....................................................................



//《计算机科学速成课》P7
// 中央处理器 CPU central proccessing unit
// 算术逻辑单元 ALU arithmetic logic unit
// 寄存器 register
// 随机访问存储器 RAM random access memory
//
// 
// [指令寄存器   instruction register
//  指令地址寄存器   instruction address register
//  指令译码器 ] ==> 简化打包成 控制单元 control unit 
//
//  取指令==>解码==>执行
//  指令地址寄存器+1
//  循环...
//
//  解码,其实很简单,思路就是,比如指令0010,
//  把指令变成全1,3个非门,一个直连,然后四个信号在通过两个与门
//  两条信号线再通过一个与门,信号为1就是指令0010,不是就输出0
//
//  时钟clock负责管理CPU的节奏,时钟以精确的时间间隔触发电信号
//  控制单元会用这个信号来推进CPU的内部操作
//  CPU "取指令==>解码==>执行"的速度叫 时钟速度,速度越快,单位时间越短,频率越高
//  时钟速度clock speed,单位赫兹Hz(赫兹是用来表示频率的单位,1Hz代表1秒一个周期)
//
//  CPU和RAM用"地址线","数据线","允许输入和允许输出线"进行通信
//
//  插点个人心得(洗澡的时候突然开窍了...想通CPU怎么决定大小端序):
//  64条数据线传入CPU,这里暂时忽略CPU缓存
//  ------------
//  ------------
//  ... ...
//  ------------
//  ------------
//            | 数据线
//  寄存器     你想要输入寄存器的数据怎么排列,那不就是你CPU说了算了吗~~~
//  啊!我悟了!!!但睡觉前又有了新疑问...
//  哎,睡醒了继续寻找答案... 20210418
//  《计算机组成原理(第2版)唐朔飞》7.2.2 P305
//  字地址,字节地址
//
