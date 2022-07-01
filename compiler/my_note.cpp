#include <iostream>
class stack;
class stackFrame;
union stackElement {
        char m_char_stack_element;
        short m_short_stack_element;
        int m_int_stack_element;
        long m_long_stack_element;
        void * m_void_pointer;
};
class stack {
    public:
        stackElement * m_stackBottom_element;
        stack * m_stack_pointer;
        stackFrame * m_stackFrame_pointer;

};
class stackFrame {
    public:
        stackElement m_stackFrame_element;
        stackFrame * m_stackFrame_pointer;
};
stack * stackInit(stackElement *);
stack * stackPush(stack *);
stack * stackPop(stack *);

stack * stackInit(stackElement * sep) {
    stack stack_temp;
    stack * stack_pointer = &stack_temp;
    stack_temp.m_stackBottom_element = sep;
    stack_temp.m_stack_pointer = &stack_temp;
    stack_temp.m_stackFrame_pointer = NULL;
    return stack_pointer;
}
stack * stackPush(stack * stack_p) {

    return stack_p;
}

int main(void) {
    using namespace std;
    stackElement se;
    se.m_int_stack_element = 666;
    stackElement * sep = &se;
    stack stack_my;
    stack_my = *stackInit(sep);
    cout << stack_my.m_stackBottom_element->m_int_stack_element << endl;
    cout << oct << stack_my.m_stackBottom_element->m_int_stack_element << endl;
    cout << hex << stack_my.m_stackBottom_element->m_int_stack_element << endl;
    return 0;
}


/*
class fyf {
    public:
        std::string m_name;
        //std::string myName() {
        //    fyf me;
        //    std::cout << me.m_name << std::endl;
        //    return me.m_name;
        //}
};

int main(void) {
    std::cout << "my note ===>" << std::endl;
    std::string name = "name";
    std::cout << name << std::endl;
    std::cout << &(std::cout) << std::endl;

    fyf me;
    me.m_name = "fyf";
    std::cout << me.m_name << std::endl;
    std::cout << sizeof(me.m_name) << std::endl;
    std::cout << &me.m_name << std::endl;
    std::cout << &me.m_name[0] << std::endl;

    fyf xx;
    xx.m_name = "xxxxxxxx";
    std::cout << xx.m_name << std::endl;
    std::cout << sizeof(xx.m_name) << std::endl;
    std::cout << &xx.m_name << std::endl;

    return 0;
}
*/

