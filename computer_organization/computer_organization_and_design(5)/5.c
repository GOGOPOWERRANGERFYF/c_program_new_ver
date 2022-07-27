/*
    大容量和高速度:开发存储期层次结构
    5.1 引言
        ...

    5.2 存储期计数    
        ...

    5.3 cache的基本原理
        ...

    由于cache中每个位置可能对应于主存中多个不同的地址,我们如何知道cache中的数据
    项是否是所请求得字呢?即如何知道所请求得字是否在cache中?我们可以在cache中增加
    一组标记(tag),标记中包含了地址信息,这些地址信息可以用来判断cache中得字是否就是
    所请求的字.标记只需包含地址的高位,也就是没有用来检索cache的那些位.
    (标记位只需使用高m位,地址低n位的索引域则用来选择cache中的块)
    标记:表中的一个字段,包含了地址信息,这些地址信息可以用来判断cache中的字是否就是
    所请求的字.

    我们还需要一种方法来判断cache块中确实没有包含有效信息.例如,当一个处理器启动时,
    cache中没有数据,标记域中的值没有意义.甚至在执行了一些指令后,cache中的一些块
    依然为空,因此,在cache中,这些块的标记应该被忽略.最常用的方法就是增加一个有效位(valid bit)
    来标识一个块是否含有一个有效地址.如果该位没有被设置,则不能使用改块中的内容.
    有效位:表中的一个字段,用来标识一个块是否含有一个有效数据.

    本节的剩余部分,我们将重点说明如何在cache中进行读操作.通常来说,由于读操作不会改变cache中的内容,
    因此处理时比写操作要简单一些.在探讨了读操作和cache缺失如何处理的基本原理后,我们讲介绍实际计算机
    中cache的设计以及cache如何让处理写操作.

    重点:cache可能时预测计数中最重要的例子.它依赖于局部性原理尽可能在存储期层次结构的更高一层中
    寻找需要的数据,并且预测错误时提供能够从存储器层次的更低一层中找到并获取正确数据的机制.现代
    计算机中cache预测命中率通常高于95%.
    [扩展] 
        温习:
        对学软件的来说《计算机科学速成课》讲的硬件深度对我这种菜鸡也够用了...
        (门)锁存器构成/组成寄存器(储存数据bit,而且有输出out,允许写入线输入0后,input无法输入门锁存器);
        缓存(允许写入线,允许输出线,数据线,[行地址线,列地址线->线路复用器]等...);
        内存(允许写入线,允许输出线,数据线,[行地址线,列地址线->线路复用器]等...);
        在数字电路中,移位寄存器（shift register）

        扩展内容(温习部分不严谨甚至有错误,以这里的为准):
        现代的设计都采取了存储器阵列
        1. Memory Array (存储器阵列) -- register file(寄存器组)
            file 计算机的文件,档案;排成一行的人或物;
            从cpu发出的地址会被输入进 行解码器(row decoder)和 列解码器(col decoder);行解码器
            会根据指令的读和写来选择 写字线(write word line,WWL) 或者 读字线(read word line,RWL),
            列解码器也会根据地址来选择 写位线(write bit line) 和 读位线(read bit line,RBL).
            好比坐标系,我们知道了Y轴坐标和X轴坐标,我们就能定位到对应的bit-cell(位单元),从而来进行
            读写操作.
            (个人注解:字线和位线还挺形象...选中行,选中一行bit,选中一列,确定一bit,当然,这只一bit,
            多个阵列层叠,就可以选择跟寄存器位宽相同的bit了...跟之前学的内存的这部分原理是相通的,
            接着看下面的缓存和主存/内存)
            
        2. Memory Array (存储器阵列) -- SRAM and DRAM
            通常用于制造cache(缓存器)的一种存储器技术:SRAM - static random access memory
            静态随机存储器,SRAM只要一直通着电,数据就会一直存在里面,所以名字中带有"静态"二字;
            如果电没有了,数据就会消失,SRAM属于易失性存储器(volatile memory)中的一种.
            由于每个单元里塞了六个晶体管,所以SRAM的造价并不便宜,而且面积功耗很大,因此SRAM并不是
            制造main memory(主存/内存)的最佳选择.制造容量更大的内存需要另一种存储技术:DRAM --
            dynamic random access memory动态随机存储器.

            SRAM和DRAM都可以用memory array的技术设计.
            相比SRAM,DRAM中的每个单元就简单了许多,由一个晶体管和一个电容构成.这也赋予了DRAM一个
            相当大的优点:对比SRAM,在相同的面积下,DRAM可以储存更多的数据,因为每个单元需要的晶体管
            非常的少,这也使得DRAM可以做成大容量的相对便宜的存储器.
            因为内部存在了电容，所以 DRAM 不是纯逻辑电路，一般的 CMOS 制程不能用于制造 DRAM，所以 
            DRAM 的制程和普通的都是区分开来了的。DRAM 的另一个特点就是需要经常刷新（Refresh），因
            为电容会持续漏电荷从而损失数据状态，所以每过几毫秒，都会重新刷新电荷，不过刷新也需要时间，
            这也导致了DRAM的速度比SRAM稍慢一些。

    5.3.1 cache访问
    ...
*/