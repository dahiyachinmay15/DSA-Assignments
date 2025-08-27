//ques1
#include<iostream>
using namespace std;

#define n 5
int stack[n];
int top=-1;

void push(int x){
    if (top == n-1){
        cout<<"Stack overflow\n";
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        top--;
    }
}

void peek(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Top element is "<<stack[top]<<endl;
    }
}

void isEmpty(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
}

void isFull(){
    if(top==n-1)
    cout<<"Stack if full"<<endl;
    else
    cout<<"Stack is not full"<<endl;
}

void display(){
    cout<<"Stack elements are ";
    for(int i=n;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int choice,x;
    while(1){
cout<<"Enter your choice "<<endl;
        cout<<"1.Push 2.Pop 3.isEmpty 4.isFull 5.Peek 6.Display"<<endl;

    cin>>choice;
    
switch(choice){
    case 1:
    cout<<"Enter value ";
    cin>>x;
    push(x);
    break;

    case 2:
    pop();
    break;

    case 3:
    isEmpty();
    break;
    
    case 4:
    isFull();
    break;

    case 5:
    peek();
    break;

    case 6:
    display();
    break;

    default:
    cout<<"Invalid choice choose again";
    
    


}
        
    }
}

//ques 2
#include<iostream>
#include<cstring>
#include<string>
using namespace std;


#define N 100

char stack[N];
int top = -1;

void push(char c) {
    if (top < N - 1) {
        top++;
        stack[top] = c;
    }
}

char Pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';  
}

int main() {
    char str[N];
    int i;

  
    cout<<"Enter a string: ";
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    
    cout<<"Reversed string: ";
    while (top != -1) {
        cout<<Pop();
    }

   cout<<endl;
    return 0;
}

//ques 3
#include<iostream>
#include<cstring>

using namespace std;

#define N 1000

char stack[N];
int top = -1;

void push(char ch)
{
  if (top >= N - 1)
  {
    cout<<"Stack Overflow"<<endl;;
    exit(1);
  }
  stack[++top] = ch;
}

char pop()
{
  if (top == -1)
  {
    return '\0';
  }
  return stack[top--];
}

int isMatchingPair(char opening, char closing)
{
  return (opening == '(' && closing == ')') ||
         (opening == '{' && closing == '}') ||
         (opening == '[' && closing == ']');
}

int isBalanced(char expr[100])
{
  for (int i = 0; expr[i] != '\0'; i++)
  {
    char ch = expr[i];

    if (ch == '(' || ch == '{' || ch == '[')
    {
      push(ch);
    }
    else if (ch == ')' || ch == '}' || ch == ']')
    {
      char topChar = pop();
      if (!isMatchingPair(topChar, ch))
      {
        return 0;
      }
    }
  }

  return (top == -1);
}

int main()
{
  char expr[N];

  printf("Enter an expression: ");
  fgets(expr, sizeof(expr), stdin);

  if (isBalanced(expr))
    printf("The expression has balanced parentheses.\n");
  else
    printf("The expression does NOT have balanced parentheses.\n");

  return 0;
}

//ques 4
#include<iostream>
#include<cstring>
using namespace std;

#define n 100
char st[n];
int top=-1;

void push(char c) {
    top++;
    st[top] = c;
}

char pop() {
    return st[top--];
}

int priority(char op){
    if(op=='^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

char intopost(char infix[], char postfix[]){
    int i=0,j=0;
    char ch;
   while ((ch = infix[i++]) != '\0'){
       if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        postfix[j++]=ch;
       }

       else if(ch=='('){
        push(ch);
       }
       else if (ch==')'){
        while(top != -1 && st[top]!='(')
        postfix[j++]=pop();
        pop();
       }
       else {
        while(top!= -1 && priority(st[top])>=priority(ch))
        postfix[j++]=pop();
        push(ch);
       }

   }
   while (top!=-1)
   {
    postfix[j++]=pop();
    postfix[j]='\0';
   }
   
}
int main(){
    char infix[n],postfix[n];
    cout << "Enter Infix Expression: ";
    cin >> infix;

    intopost(infix, postfix);

    cout << "Postfix Expression: " << postfix << endl;

}

//ques 5
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
  if (top == MAX - 1)
  {
    cout<<"Stack overflow\n";
    exit(1);
  }
  stack[++top] = val;
}

int pop()
{
  if (top == -1)
  {
    cout<<"Stack underflow\n";
    exit(1);
  }
  return stack[top--];
}

int isOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int evaluatePostfix(char postfix[100])
{
  int i;
  int val1, val2;
  int result;
  int length = strlen(postfix);

  for (i = 0; i < length; i++)
  {
    char c = postfix[i];

    if (isspace(c))
    {
    
      continue;
    }

    if (isdigit(c))
    {
     
      push(c - '0');
    }
    else if (isOperator(c))
    {
      val2 = pop();
      val1 = pop();

      switch (c)
      {
      case '+':
        result = val1 + val2;
        break;
      case '-':
        result = val1 - val2;
        break;
      case '*':
        result = val1 * val2;
        break;
      case '/':
        if (val2 == 0)
        {
          cout<<"Division by zero error!\n";
          exit(1);
        }
        result = val1 / val2;
        break;
      case '^':
        result = (int)pow(val1, val2);
        break;
      default:
        cout<<"Unknown operator"<<c<<endl;
        exit(1);
      }
      push(result);
    }
    else
    {
      cout<<"Invalid character in expression: "<< c;
      exit(1);
    }
  }

  return pop();
}

int main()
{
  char postfix[MAX];

  cout<<"Enter a postfix expression (single-digit operands):" ;
  fgets(postfix, MAX, stdin);

  int result = evaluatePostfix(postfix);

  cout<<"Result of postfix evaluation: "<< result<<endl;

  return 0;
}
