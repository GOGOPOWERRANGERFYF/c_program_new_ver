#include <iostream>
/**
 * 目前没有任何计划系统学习c++,只是了解其中一些我认为有必要知道的知识点
 * 对学习其他语言有帮助.
*/
class Animal {
    public:
        // 虚函数
        virtual void info(void);
};

void Animal::info(void) {
    std::cout << "animal" << std::endl;
}

class Dog: Animal {
    public:
        void info(void) {
            std::cout << "animal -> dog" << std::endl;
        }
};

int main(void) {
    // c++中可以直接实例化对象;
    // java因为隐藏了指针，使用的是引用，所以实例化为Dog dog1 = new Dog();
    // java中dog1为引用;
    // 学c++可知引用为对象的一个别名,和对象的标识符代表的是同一个指针
    //Animal animal1;
    //animal1.info();
    Dog dog1;
    Animal * animal_p1 = (Animal *)&dog1;
    animal_p1->info();
    Animal & animal_r2 = (Animal &)dog1;
    animal_r2.info();

    double d1 = 1.0;
    d1 = 1.0 - 0.1 - 0.1 - 0.1 - 0.1 - 0.1;
    std::cout << d1 << std::endl;

    return 0;
}



