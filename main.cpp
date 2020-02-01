#include <iostream>
#include <memory>

class Stack
        {
            size_t * stack_pointer;
            size_t size;
            size_t index;
    public:
            Stack()
            {
                size = 1;
                stack_pointer = new size_t[size];
                index = 0;
            }
            ~Stack()
            {
                delete [] stack_pointer;
            }
            void push(int value)
            {
                index++;
                stack_pointer[index]=value;
            }
            void pop()
            {
                if(index>0)
                {
                stack_pointer[index]=0;
                index--;
                } else
                {
                    std::cout<<"Stack is empty!\n";
                }
            }
         /*   const size_t &operator[](size_t index)
            {
                return stack_pointer[index];
            } */
         size_t getValue() const
         {
                return stack_pointer[index];
         }
         friend std::ostream& operator <<(std::ostream& out, const Stack& s);

        };
std::ostream& operator <<(std::ostream& out, const Stack& s)
{
    return out<<s.getValue();
}

int main() {
    Stack s1;
    s1.push(3);
    s1.push(5);
    std::cout<<s1.getValue();
    std::cout<<s1;
    s1.pop();
    s1.pop();
    s1.pop();
    int a;
    std::cin>>a;
    s1.push(a);
    std::cout<<s1;
    return 0;
}
