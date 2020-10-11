#include<stdio.h>
#include<stdlib.h>
char stack[10];
int top=-1;
void push(char ch)
{
    top++;
    stack[top]=ch;
}
char pop()
{
    return stack[top--];
}
void convert(char in[],char post[])
{
    int i=0,j=0;
    char ch,x;
    for(int i=0;in[i]!='\0';i++)
    {
        ch=in[i];
        switch(ch)
        {
            case '(':push(ch);
            break;
            case ')':while(stack[top]!='(')
            post[j++]=pop();
            x=pop();
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':while(stpri(stack[top])>inpri(ch))
            post[j++]=pop();
            push(ch);
            break;
            default:post[j++]=ch;
        }
    }
    while(stack[top]!='#')
    post[j++]=pop();
    post[j]='\0';
}
int stpri(char ch)
{
    switch(ch)
    {
            case '+': return 2;
            case '-':return 2;
            case '*':return 4;
            case '/':return 4;
            case '%':return 4;
            case '^':return 5;
            case '(':return 0;
            case '#':return -1;

    }
    return 8;
}
int inpri(char ch)
{
    switch(ch)
    {
            case '+': return 1;
            case '-':return 1;
            case '*':return 3;
            case '/':return 3;
            case '%':return 3;
            case '^':return 6;
            case '(':return 9;
            case ')':return 0;

    }
    return 7;
}
int main()
{
    char postfix[20],infix[20];
    push('#');
    printf("Enter the infix expression \n");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("The postfix expression is %s \n",postfix);
    return 0;
}
