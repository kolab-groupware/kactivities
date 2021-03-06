#include <iostream>

class A {
    public:
        virtual int fn(int arg) {
            return 10 * arg;
        };

};

class B: public A {
    public:
        virtual int fn(int arg) override {
            return 20 * arg;
        };

};

int main()
{
    A * a = new A();
    A * b = new B();

    int result = a->fn(2) - b->fn(1);

    return 0;
}
