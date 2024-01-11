### 还原装饰器语法糖的本质
```python
def print_decorator(ret_arg):
    print("print_decorator start, ret_arg={} >>>\n".format(ret_arg))
    def my_print(func_arg):
        print("my_print start >>")
        print("call {}".format(func_arg))
        func_arg(ret_arg)
        print("my_print before return >>\n")
        return func_arg
    return my_print

obj = type("obj", (object,), {})

@print_decorator(ret_arg=obj.__bases__)
@print_decorator(ret_arg=obj.__mro__)
def ret(want_to_print_ret):
    print("ret start >")
    print(" => ret {}".format(want_to_print_ret))
    print("ret end >")

'''
装饰器语法糖还原:
为了代码"美观",代码更抽象了,增加了理解的成本
'''
ret1 = print_decorator(ret_arg=obj.__bases__)
ret2 = print_decorator(ret_arg=obj.__mro__)
# 这是理解为何return func_arg修改为其它返回值报错的原因,不返回func_arg,
# ret变量就不再是ret函数的引用了。第二次传入ret(被修改为其它值)时就无法正确调用原本的ret函数.
ret = ret1(ret)
ret = ret2(ret)
```