#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

class RGBA {
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;

public:
    RGBA(uint8_t m_r, uint8_t m_g, uint8_t m_b, uint8_t m_a) : m_red(m_r), m_green(m_g), m_blue(m_b), m_alpha(m_a) {}

    void print() {
        cout << "m_red = " << unsigned(m_red) << endl;
        cout << "m_green = " << unsigned(m_green) << endl;
        cout << "m_blue = " << unsigned(m_blue) << endl;
        cout << "m_alpha = " << unsigned(m_alpha) << endl;
    }
};

class Power {
private:
    double numberA = 2;
    double numberB = 3;

public:
    void set(double a, double b) {
        numberA = a;
        numberB = b;
    }

    void calculate() {
        cout << pow(numberA, numberB) << endl;
    }
};

class Stack {
private:
    int array[10];
    int index;
public:
    void reset() {
        for (int i = 0; i < 10; i++) {
            array[i] = 0;
        }

        index = -1;
    }

    bool push(int a) {
        if (index == 9)
            return false;

        index++;
        array[index] = a;
        return true;
    }

    int pop() {
        int result;
        if (index >= 0) {
            result = array[index];
            index--;
            return result;
        }
        else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    void print() {
        cout << "(";
        for (int i = 0; i < index + 1; i++) {
            if (i < index)
                cout << array[i] << " ";
            else
                cout << array[i];
        }
        cout << ")" << endl;
    }
};

int main()
{
    cout << "Задача 1" << endl;
    Power power;
    power.calculate();
    power.set(2, 4);
    power.calculate();
    cout << endl;

    cout << "Задача 2" << endl;
    RGBA rgba(10, 20, 30, 40);
    rgba.print();
    cout << endl;

    cout << "Задача 3" << endl;
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(5);
    stack.push(7);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    stack.push(2);
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}
