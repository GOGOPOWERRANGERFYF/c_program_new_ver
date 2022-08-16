#include <iostream>
#include <pthread.h>
#include <unistd.h>
void * task1(void * p);
void * task2(void * p);
inline int add(int, int);
int sum = 0;
pthread_mutex_t mutex_lock;

int main(void) {
    // using 编译指令; ::作用域运算符
    using namespace std;

    // 引用
    int a = 5;
    int &ra = a;
    int result = add(a, ra);
    cout << result << endl;

    /*  
        << 左移; 这里的<<为运算符重载,流插入
        cout ostream类对象(输出);
        另外当然还有还有cin对象(输入)
        endl为控制符 
    */
    //cout << ra << " "<< &ra << endl;
    //cout << a << " " << &a << endl;
    //cout << (a == ra) << endl;

    // 本质是inline内联函数?
    //cout << "hex = " << hex << 123456 << endl;
    //cout << "dec = " << dec << 123456 << endl;
    //cout << "oct = " << oct << 123456 << endl;

    pthread_t pt1, pt2;
    // arg2: 线程属性; arg4: 传入task函数参数;
    pthread_create(&pt1, NULL, task1, &pt1);
    pthread_create(&pt2, NULL, task1, &pt2);
    // arg2: 
    pthread_join(pt1, NULL);
    pthread_join(pt2, NULL);
    cout << "mutex_lock yes ==> " << dec << sum << endl;

    sum = 0;
    pthread_t pt3, pt4;
    pthread_create(&pt3, NULL, task2, &pt3);
    pthread_create(&pt4, NULL, task2, &pt4);
    pthread_join(pt3, NULL);
    pthread_join(pt4, NULL);
    cout << "mutex_lock no =========> " << dec << sum << endl;
    return 0;
}

void * task1(void * p) {
    using namespace std;
    // 一点经验:不加锁的情况下,循环次数太少的时候,会出现程序运行很多次也没有出现问题(很有隐蔽性),
    //         直接增加循环次数,出现问题的几率大增.
    for (int i = 0; i < 15000; i++) {
        pthread_mutex_lock(&mutex_lock);
        sum++;
        //cout << "tread<" << p << "> " << dec << sum << endl;
        pthread_mutex_unlock(&mutex_lock);
        // 不加锁不能保证上面两句代码执行完了才进行线程上下文切换

        // 挂起?or阻塞?线程???
        //usleep(5000);
    };
    //cout << "task(sum)" << "(" << p << ")" << ": " << dec << sum << endl;
    return NULL;
}

void * task2(void * p) {
    using namespace std;
    for (int i = 0; i < 15000; i++) {
        sum++;
        //usleep(5000);
    };
    //cout << "task(sum)" << "(" << p << ")" << ": " << dec << sum << endl;
    return NULL;
}

// 内联函数,内联函数的代码指令直接内联至主调函数的代码指令中(个人非官方概述)
inline int add(int x, int y) {
    return x + y;
}

