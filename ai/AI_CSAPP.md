中文书名《深入理解计算机系统》  
个人笔记：  
浮点数十进制转换成二进制,浮点后的部分,通过fraction✖2判断二进制的数位位置为1或0,从高位到地位.
中文世界中就是分数✖2或小数✖2,分数易于直观理解这样运算的原理,小数反正我这个菜鸡是无法直接理解。。。 
  
**非规格化：**
- 指数阶为全0，但指数=1-bias,而不是0-bias

  
**fraction英文词典解释:**
1. a numerical quantity that is not a whole number (e.g. 1/2, 0.5).  
2. a small or tiny part, amount, or proportion of something.
  
fraction在中文中对应或涵盖的两个数学概念,其实只是fraction的两种不同的表示方法:
1. 分数：从理解的角度讲分数概念易于理解;
2. 小数：对我这个菜鸡理解概念时造成了困扰...  
个人为了便于理解：数值量为非完整数字,分数和小数为非完整数字的两种标识方法.

# 问题：小数或分数，英文都为fraction，中文为什么要分两个词？

在英语中，"fraction" 这个词同时涵盖了小数和分数的概念，这是因为它们在数学上都涉及到部分与整体的关系。然而，在中文中，"小数" 和 "分数" 分别对应了两种不同的数值表示方式：

1. **分数（fēn shù）**：
   - 分数是表示部分与整体之间关系的一种数学表达方式，通常由分子（表示部分的数量）和分母（表示整体的数量）组成，中间用分数线隔开，如 3/4、5/8 等。

2. **小数（xiǎo shù）**：
   - 小数则是另一种表示数值的方式，它将整数部分和小数部分用小数点连接起来，如 0.75、123.45 等。小数可以看作是分数的一种特殊形式，其中分母为幂次方的10，例如0.75可以表示为75/100或3/4。

由于这两种数值表示方式在形式和使用场景上存在明显差异，因此在中文中分别使用 "分数" 和 "小数" 两个词来区分。这样更有利于在教学、学习和日常交流中清晰地传达各自的概念和特点。而在某些情况下，如果要同时指代这两种概念，可能会使用 "小数或分数" 这样的表述方式。

# 问题：所以在数学的中文术语中，并没有直接对应 "fraction" 的翻译？

在数学的中文术语中，"fraction" 的概念并没有一个直接对应的单个词翻译。尽管英文中的 "fraction" 同时涵盖了分数和小数的概念，但在中文中，我们通常根据具体的情况和上下文来使用 "分数" 或 "小数" 这两个词。

- 当讨论分子和分母的形式，如 3/4、5/8 等时，我们会使用 "分数"。
- 当讨论以小数点分隔整数部分和小数部分的形式，如 0.75、123.45 等时，我们会使用 "小数"。

虽然没有一个单独的词能够完全对应 "fraction"，但在某些情况下，如果需要同时指代分数和小数，可能会使用诸如 "有理数" 或者 "部分与整体的比例" 等更广义的术语来描述这个概念。不过，在大多数情况下，"分数" 和 "小数" 分别清晰地表示了这两种不同的数值表示方式。

# 问题：IEEE-754非规格化和规格化的区别是什么？

在IEEE-754浮点数标准中，数字可以被表示为规格化或非规格化形式。以下是它们的主要区别：

**规格化数：**
1. 规格化数是具有有效数字的浮点数，其小数点位于有限的位置。
2. 对于单精度（32位）和双精度（64位）格式，规格化数的小数点位于第一个非零数字之前。
3. 单精度规格化数的范围大致为±1.17549435e-38 到 ±3.40282347e+38。
4. 双精度规格化数的范围大致为±2.2250738585072014e-308 到 ±1.7976931348623157e+308。
5. 在IEEE-754中，规格化数的尾数部分（也称为有效位）总是以其最右侧的位作为隐藏位，这样可以增加精度。

**非规格化数（也称为亚规范数或_DENormal_数，在IEEE-754-2008中被称为_subnormal_数）：**
1. 非规格化数是那些绝对值非常接近于零，并且不能用常规的规格化形式表示的浮点数。
2. 当一个数的绝对值太小以至于无法满足规格化数的要求时，它就被表示为非规格化数。
3. 非规格化数的 exponent（指数）字段设置为最小值（对于单精度通常是 127，对于双精度通常是 1023），而尾数部分可能包含一个或多个前导零。
4. 由于非规格化数的指数字段已经是最小值，所以它们不再遵循“小数点位于第一个非零数字之前”的规则。
5. 非规格化数的精度通常低于规格化数，因为它们没有隐藏位。

**共同点：**
- 规格化数和非规格化数都使用相同的二进制表示法，包括符号位、指数位和尾数位。
- 两者都是 IEEE-754 标准的一部分，用于表示浮点数。

通过使用非规格化数，IEEE-754 能够更精细地表示接近于零的数，从而提高了浮点数系统的精度和动态范围。然而，处理非规格化数可能会比规格化数稍微慢一些，因为它们的计算通常需要额外的逻辑步骤。

# 问题：C语言中，使用单精度浮点型变量，举一个会使用非规格化数的例子。

在C语言中，单精度浮点型变量使用`float`数据类型。以下是一个使用非规格化数（也称为亚规范数或_DENormal_数）的例子：

```c
#include <stdio.h>

int main() {
    float verySmallNumber = 1.0f / 32768.0f; // 创建一个小于最小正规格化数的数

    printf("Very small number: %.20f\n", verySmallNumber);

    return 0;
}
```

在这个例子中，我们创建了一个非常小的数，它是通过将1除以32768得到的。这个结果小于单精度浮点数的最小正规格化数（约为1.17549435e-38），因此它会被表示为非规格化数。

当你运行这段代码时，输出可能会显示一个接近于0但不等于0的数，其小数部分包含许多零和一些非零数字。这是因为非规格化数的精度较低，且尾数部分可能包含前导零。

请注意，实际的输出可能因编译器和硬件实现的不同而略有差异。在某些情况下，非规格化数可能会被默默地转换为零，或者计算结果可能不完全准确。

