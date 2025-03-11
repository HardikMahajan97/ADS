#include<bits/stdc++.h>
using namespace std;

class charStack{
    int* arr;
    int top;
    int size;
    public:
    charStack(int size)
    {
        arr = new int[size];
        size = size;
        top = -1;
    }

    void push(char element){
        // Base case: if the stack is full
        if(top == size){
            cout << "Cannot push, the stack is full! " << endl;
            return;
        }
        // Add the element to the stack.
        arr[++top] = element;
    }

    char pop(){
        //Base case: if the stack is empty.
        if(top == -1){
            cout << "Stack is empty! " << endl;
            return '\0';
        }

        //Pop the top element form the stack.
        return arr[top--];
    }

    char peek(){
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }
};
int priority(char element){
    if(element == '^') return 3;
    if(element == '*' || element == '/') return 2;
    if(element == '+' || element == '-') return 1;
    
    return -1;
}
void infixToPostfix(char* str, char* postfix){
    charStack s(strlen(str));
    int j = 0;
    for(int i = 0; i < strlen(str); i++){
        char element = str[i];
        //If the element is not an operator.
        if(element >= '0' && element <= '9' 
        || element >= 'a' && element <= 'z' 
        || element >= 'A' && element <= 'Z')
        {
            postfix[j++] = element;
        }

        //If the element is an opening bracket, push it directly.
        else if(element == '(') s.push(element);

        //If the element is a closing bracket, pop all the elements until you find the opening bracket.
        else if(element == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                postfix[j++] = s.peek();
                s.pop();
            }
            //Just pop out the bracket but don't add it in postfis expression.
            s.pop();
        }

        //If the element is an operator, check the priority and then push it accordingly.
        else{
            while( !s.isEmpty() && priority(s.peek()) >= priority(element) ){
                postfix[j++] = s.pop();
            }
            s.push(element);
        }
    }

    while(!s.isEmpty()){
            postfix[j++] = s.pop();
    }

    postfix[j] = '\0';
}
int main(){

    cout << "Enter the size of your expression: " << endl;
    int size;
    cin >> size;
    char str[size];
    char postfix[size];
    charStack s(size);

    cout << "Enter the infix expression: " << endl;
    cin >> str;

    infixToPostfix(str, postfix);

    cout << "Conversion to postfix: " << endl;
    cout << postfix << endl;

    return 0;
}