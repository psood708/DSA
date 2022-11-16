 #include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct stack
{
    int tos;
};
void push(char a[], struct stack *st, int ele)
{
    st->tos = st->tos + 1;
    a[st->tos] = ele;
}
char poped(char a[], struct stack *st)
{
    char item = a[st->tos];
    a[st->tos] = '\0';
    st->tos = st->tos - 1;
    return item;
}
bool isEmpty(struct stack *st)
{
    if (st->tos == -1)
        return true;
    else
        return false;
}
char stackTop(char a[], struct stack *st)
{
    return a[st->tos];
}
bool prcd(char a, char b)
{
    if ((a == '+' || a == '-') && (b == '-' || b == '+'))
        return true;
    else if (a == '+' || a == '-')
        return false;
    else if (a == '-' && (b == '+' || b == '-'))
        return true;
    else if ((a == '/' || a == '*' || a == '%') && (b == '(' || b == '$' || b == '^'))
        return false;
    else if ((a == '/' || a == '*' || a == '%'))
        return true;
    else if ((a == '^' || a == '$') && b == '(')
        return false;
    else if ((a == '^' || a == '$'))
        return true;
    else if (a == '(')
        return false;
    else
        return false;
}
int main()
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->tos = -1;
    char s[50];
    printf("Enter infix Expression");
    gets(s);
    printf("Postfix Expression: ");
    char a[strlen(s)];
    for (int i = 0; i < strlen(s); i++)
    {
        char symb = s[i];
        if (isalnum(symb))
        {
            printf("%c", symb);
        }
        else
        {
            if (symb == ')')
            {
                //here we need to put some value ffor ch;
                char ch = '2';
                while (ch != '(')
                {
                    ch = poped(a, st);
                    if (ch == '(')
                    {
                        continue;
                    }
                    printf("%c", ch);
                }
            }
            else
            {
                while (!isEmpty(st) && prcd(stackTop(a, st), symb))
                {
                    char mb = poped(a, st);
                    printf("%c", mb);
                }
                push(a, st, symb);
            }
        }
    }
    while (!isEmpty(st))
    {
        char cd = poped(a, st);
        printf("%c", cd);
    }
}

