#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    element A[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s)         //스택 초기화 함수
{
    s->top = -1;
}

int is_empty(StackType* s)
{
    return (s->top == -1);
}

int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화상태");
        return;
    }
    else s->A[++(s->top)] = item;
}

element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백에러");
        return 0;
    }
    else return s->A[(s->top)--];
}

element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백에러");
        return 0;
    }
    else return s->A[(s->top)];
}

int checking(const char* in)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);

    init_stack(&s);

    for (i = 0; i < n; i++) {
        ch = in[i];
        switch (ch)
        {
        case'(':case'{':case'[':
            push(&s, ch);
            break;

        case')':case'}':case']':
            if (is_empty(&s)) return 0;
            else {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '{' && ch != '}') ||
                    (open_ch == '[' && ch != ']'))

                    return 0;
            }
            break;
        }
    }
    if (!is_empty(&s)) return 0;

    return 1;
}

int main()
{
    int j, C;
    scanf("%d", &C);

    for (j = 0; j < C; j++) {


        char p[MAX_STACK_SIZE];
        char q[MAX_STACK_SIZE];
        char r[MAX_STACK_SIZE];

        scanf("%s", &p);
        scanf("%s", &q);
        scanf("%s", &r);

        if (checking(p) == 1)
            printf("YES\n");
        else
            printf("NO\n");

        if (checking(q) == 1)
            printf("YES\n");
        else
            printf("NO\n");

        if (checking(r) == 1)
            printf("YES\n");
        else
            printf("NO\n");
        return 0;

    }
}
