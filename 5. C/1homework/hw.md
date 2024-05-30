# Упражнение 7. Язык C

## Справка

Минимальная программа на C (программа ничего не делает):

    int main() {
        return 0;
    }

Минимальная программа на C, печатающая один символ:

    #include <stdio.h>

    int main() {
        putchar('h');
        return 0;
    }

Функция `putchar` - входит в стандартную библиотеку C, её разрабатывать не нужно.

Конструкции `if`, `while`, `for` требуют скобки `()` вокруг условий.

Точки с запятой `;` - обазательны.

Тип пишется перед именем переменной:

    int x = 0;

Основные типы: `bool`, `char`, `int`, `float`.

Строка в языке C - это указатель на первый символ строки. Строки в C автоматически заканчиваются специальным символом '\0'.

Синтаксис во многом похож на Go, за деталям обращайтесь пожалуйста в интернет, документацию и так далее, или обсудим на занятии.

Ограничение для всех заданий - нельза использовать `printf`. Только `putchar`.

## Задание 1

Портировать следующую функцию на язык C:

    abs:
        mov rax, [rsp + 8]
        cmp rax, 0
        jge .l1
        jmp .l2
    .l1:
        ret 1 * 8
    .l2:
        neg rax
        ret 1 * 8

Желательно портировать максимально близко к исходнику.

---

Решение (`1.c`):

```c
#include <stdio.h>

int abs(int n)
{
    if (n >= 0)
    {
        return n;
    }
    return n * (-1);
}

int my_abs(int n)
{
    if (n < 0)
    {
        n *= -1;
    }
    return n;
}

int main(void)
{
    printf("%d\n", abs(-123));
    printf("%d\n", abs(123));

    printf("%d\n", my_abs(-456));
    printf("%d\n", my_abs(456));
    return 0;
}
```

## Задание 2

Портировать следующую функцию на язык C:

    relation_sign:
        mov rax, [rsp + 1 * 8]
        mov rbx, [rsp + 2 * 8]
        cmp rax, rbx
        jl .l1
        je .l2
        jg .l3
    .l1:
        push '<'
        call putchar
        jmp .compare_end
    .l2:
        push '='
        call putchar
        jmp .compare_end
    .l3:
        push '>'
        call putchar
        jmp .compare_end
    .compare_end:
        ret

Вопрос: Что делает данная функция? Какую задачу она решает?

Ответ: Функция принимает 2 числовых аргумента, сравнивает их, вызывает функцию `putchar`, которая выводит знак равенства (`<`, `=`, `>`).

---

Решение:

```c
#include <stdio.h>

void relation_sign(int a, int b)
{
    if (a < b)
    {
        putchar('<');
    }
    else if (a == b)
    {
        putchar('=');
    }
    else if (a > b)
    {
        putchar('>');
    }
    return;
}

void my_relation_sign(int a, int b)
{
    char c = '=';
    if (a < b)
    {
        c = '<';
    }
    else if (a > b)
    {
        c = '>';
    }
    putchar(c);
    return;
}

int main(void)
{
    relation_sign(1, 2);
    relation_sign(1, 1);
    relation_sign(2, 1);

    putchar('\n');
    
    my_relation_sign(1, 2);
    my_relation_sign(1, 1);
    my_relation_sign(2, 1);
    return 0;
}
```

## Задание 3

Портировать следующую функцию на язык C:

    is_zero:
        n equ qword[rbp + 2 * 8]

        push rbp
        mov rbp, rsp
        push rbx rcx rdx

        cmp n, 0
        je .t1
        jne .t2

    .t1:
        mov rax, 1
        jmp .end

    .t2:
        mov rax, 0

    .end:
        pop rdx rcx rbx
        pop rbp
        ret 8

Вопрос: Что делает данная функция? Какую задачу она решает?

Ответ: Функция `is_zero` проверяет равен ли `0` переданный параметр, если да, то отдает `1`, иначе `0`.

---

Решение:

```c
#include <stdio.h>

int is_zero(long a)
{
    long n = a;
    if (n == 0)
    {
        return 1;
    }
    else if (n != 0)
    {
        return 0;
    }
}

int my_is_zero(int a)
{
    return a == 0;
}

int main(void)
{
    printf("%d %d\n", is_zero(123), is_zero(0));

    printf("%d %d\n", my_is_zero(123), my_is_zero(0));
    return 0;
}
```

## Задание 4

Портировать следующую функцию на язык C:

    print_hex_byte:
        mov rax, [rsp + 8]
        mov rcx, 16
        xor rdx, rdx
        div rcx

        push rdx
        add rax, '0'
        cmp rax, 9 + '0'
        jle .p1
    .alpha1:
        add rax, 'a' - 10 - '0'     ; ':'
    .p1:
        push rax
        call putchar

        pop rdx
        cmp rdx, 9
        jg .alpha2
        add rdx, '0'
        jmp .p2
    .alpha2:
        add rdx, 'a' - 10
    .p2:
        push rdx
        call putchar

        ret 8

---

Решение:

```c
#include <stdio.h>

void print_hex_byte(int n)
{
    char d1 = (n / 16) + '0';
    char d2 = (n % 16) + '0';

    if (d1 > '9')
    {
        d1 += 'a' - 10 - '0';
    }
    putchar(d1);

    if (d2 > '9')
    {
        d2 += 'a' - 10 - '0';
    }
    putchar(d2);
}

int main(void)
{
    print_hex_byte(0);
    putchar('\n');
    print_hex_byte(1);
    putchar('\n');
    print_hex_byte(16);
    putchar('\n');
    print_hex_byte(200);
    putchar('\n');
    print_hex_byte(255);
    putchar('\n');
    return 0;
}
```

## Задание 5

Портировать следующую функцию на язык C:

    convert_char:
        mov rax, [rsp + 8]
        sub rax, '0'
        cmp rax, 10
        jl .done
        add rax, '0'
        sub rax, 'A' - 10
        cmp rax, 16
        jl .done
        add rax, 'A'
        sub rax, 'a'
        ret
    .done:
        ret

Вопрос: Что делает данная функция? Какую задачу она решает?

## Задание 6

Портировать следующую функцию на язык C:

    check_char:
        mov rax, [rsp + 8]
        sub rax, '0'
        cmp rax, 0
        jl .done
        add rax, '0'
        sub rax, 'A'
        cmp rax, 0
        jl done
        add rax, 'A'
        sub rax, 'a'
        cmp rax, 0
        jl done
        cmp rax, 15
        jg done
        mov rax, 1
        ret 8
    .done:
        mov rax, 0
        ret 8

Вопрос: Что делает данная функция? Какую задачу она решает?

## Задание 7

Разработать функцию `max2(int, int)`, находящую наибольшее среди двух чисел и возвращающую это число.

А затем:

Портировать следующую функцию на язык C:

    max3:
        push rbx rcx rdx

        mov rax, [rsp + 8 * 6] ; a
        mov rbx, [rsp + 8 * 5] ; b
        mov rcx, [rsp + 8 * 4] ; c

        push rax rbx
        call max2

        push rax rcx
        call max2

        pop rdx rcx rbx
        ret 3 * 8

Вопрос: Что делает данная функция? Какую задачу она решает?

## Задание 8

Портировать следующую функцию на язык C:

    max4:
        push rbx rcx rdx

        mov rax, [rsp + 8 * 4]
        mov rbx, [rsp + 8 * 5]
        mov rcx, [rsp + 8 * 6]
        mov rdx, [rsp + 8 * 7]

        sub rsp, 2 * 8

        push rax
        push rbx
        call max2

        mov [rsp + 8 * 0], rax

        push rcx
        push rdx
        call max2

        mov [rsp + 8 * 1], rax

        mov rax, [rsp + 8 * 0]
        mov rbx, [rsp + 8 * 1]

        push rax
        push rbx
        call max2

        add rsp, 8 * 2

        pop rdx rcx rbx
        ret 4 * 8

Желательно портировать максимально близко к исходнику.

## Задание 9

Портировать следующую функцию на язык C:

    print_string:
        mov rsi, [rsp + 8]
        cmp rsi, 0
        je .exit

        movzx rax, byte[rsi]
        cmp rax, 0
        je .exit
        push rsi
        push rax
        call putchar
        pop rsi
        add rsi, 1

        mov [rsp + 8], rsi
        jmp print_string
    .exit:
        ret 8

## Задание 10

Портировать следующую функцию на язык C:

    print_bool:
        mov rax, [rsp + 8]
        cmp rax, 0
        je .false
    .true:
        push t
        call print_string
        ret 8
    .false:
        push f
        call print_string
        ret 8

где `t` и `f` - глобальные строковые переменные, желательно максимально близко выразить это.

## Рекомендуемая литература

* Charles Petzold. Code. The Hidden Language of Computer Hardware and Software
(Чарльз Петцольд. Код: тайный язык информатики)
