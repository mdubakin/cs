# Упражнение 3

## ? Задание 1. Логические схемы

Ещё раз раз попробовать решить задание 2.18 про 3-битный NEG с учётом превращения нуля обратно в ноль.

## Задание 2. Постфискная (обратная) польская нотация

2.1. Дана формула в обычной (инфиксной) нотации, составить соответствующую ей RPN-формулу:

    1 + 2 + 3

Ответ: `12+3+`

Note: RPN -- это reversed Polish notation.

## Задание 3. Кодирование информации

Пусть дана шахматная доска и на ней где-то стоит шашка.

3.1. Как можно закодировать положение одной этой шашки? Т.е. то, где, в какой клетке она сейчас находится.

![](https://shitpoet.cc/sshots/2018-10-20--160323--206295684.png)

Ответ: Мы можем договориться о том, что значение **0** - это поле **1a**, а последнее поле **8h** - имеет значение **111111** (63 в дес.). Тогда поле **5f** будет можно закодировать как 5 * 6 = 30 = **11110**.

---

3.2. Сколько минимально бит потребуется, чтобы закодировать положение одной шашки?

Ответ: На шахматной доске **8 * 8 = 64** полей. Нам потребуется **6** бит, чтобы закодировать положение одной шашки.

## Задание 4. Постфискная (обратная) польская нотация

4.1. Дана формула в обычной (инфиксной) нотации, составить соответствующую ей RPN-формулу:

    1 + (3 * 4) / 5

Ответ: `134*5/+`

## Задание 5. Логические схемы

5.1. Разработать схему, которая имеет на выходе четыре лампочки, и работает так, что:

 1) в первый момент времени светится только первая лампочка,
 2) во второй момент времени светится только вторая лампоча,
 3) в третий момент времени светится только третья лампочка.

Однако имеет исключение для четвёртого момента времени:

  4) в четвёртый момент времени светятся все лампочки.

После 4 тактов работы весь процесс повторяется снова.

В схеме необходимо взять источник прямоугольного импульса (осциллятор). Возможно, есть смысл использовать один или несколько счётчиков или декодеров.

### Решение

![](https://i.ibb.co/bJvSsVN/image.png)

### Справка. Декодеры

Пример поведения 2-битного декодера:

    x y    a b c d
    --------------
    0 0    1 0 0 0
    0 1    0 1 0 0
    1 0    0 0 1 0
    1 1    0 0 0 1

Декодер на схеме можно обозначить как прямоугольник и просто подписать `decoder` или `dc`. Это не принципиально.

По сути, декодер является 4-канальным 1-битным демультиплексером, на вход которого всегда подана единица.

### Справка. Счётчики

Счётчик - это набор делителей частоты, соединённых последовательно. На вход счётчика можно подать колеблющийся сигнал 0 1 0 1 0 1 и т.д., и тогда счётчик будет выдавать набор бит, которые можно интерпретировать как число 0 до числа, соответствующего разрядности счётчика. Например, 3-битный счётчик:

    c   x y z
    ---------
    0   0 0 0
    1   0 0 1
    0   0 1 0
    1   0 1 1
    0   1 0 0
    1   1 0 1
    0   1 1 0
    1   1 1 1

где `c` - от. англ. "clock" (часы) - некоторый внешний колеблющийся сигнал 0, 1, 0, 1 и т.д.

В таблице можно заметить, что младший бит (`z`) - совпадает со входом `c`, средний бит `y` колеблится с половинной частотой относительно входа `c`, а `x` движется с ещё раз уполовиненной часотой. В итоге образуется код числа от `0` (`000`) до `7` (`111`).

## Задание 6. Постфискная (обратная) польская нотация

6.1. Дана формула в обычной (инфиксной) нотации, составить соответствующую ей RPN-формулу:

    (1 + 2) * (3 - 4)

Ответ: `12+34-*`

## Задание 7. Синхронизированные логические схемы

7.1. Дана схема с четырьмя регистрами и двумя входами управления `s` и `w`:

![](https://sshots.shitpoet.cc/2023-10-10--221820--1658525632.png)

Дополнить данную схему, чтобы она делала:

1) сложение чисел из регистров `A` и `C`, если на входе `s` подан `0`
2) сложение чисел из регистров `B` и `C`, если на входе `s` подан `1`

Схема должна записать результат сложения в регистр `R`, когда на входе `w` появится `1`.

Т.е. схема делает программируемое сложение `A/B` с `C` с дальнешим сохранением результата в регистре.

### Решение

![](https://i.ibb.co/X4SpHXH/image.png)

## Задание 8. Постфискная польская нотация

8.1. Дана формула в обычной (инфиксной) нотации, составить соответствующую ей RPN-формулу:

    ((((1 - 2) - 3) - 4) - 5) * 6

Ответ: `12-3-4-5-6*`

## Задание 9. Синхронизированные логические схемы

9.1. Дана схема с четырьмя регистрами.

![](https://sshots.shitpoet.cc/2023-10-10--220419--1252212964.png)

Пусть регистры `R0` и `R1` содержат некоторые числа.

Завершить данную схему, чтобы после некоторого времени значения в регистрах `R0` и `R1` поменялись местами.

Например, если исходно в `R0` хранится число 3, а в регистре `R1` хранится число 7, то после какого-то времени необхоидмо, чтобы теперь в `R0` стало храниться 7, а в `R1`, наоборот, 3.

В схеме есть два дополнительных регистра, которые можно, но не обязательно использовать. Другие регистры, триггеры и модули памяти в схему добавлять нельзя.

В данной схеме необходимо использовать генератор прямоугольного импульса (clock) + счётчик, чтобы организовать перемещение данных между регистрами без потери информации.

Note: Нельзя просто соединить выход одного регистра ко входу другого и подать 1 на входы записи, так как это может привести к нестабильной работе схемы, так как скорость срабатывания разных компонентов всегда немного отличается, что может привести к потере или искажению информации.

Упрощение: Если строить решение, используя счётчик, то в какой-то момент в будущем обмен может повториться (и значения вернутся к исходным), а через ещё какое-то время значения могут опять обменяться. В данной задаче этим можно пренебречь. Главное, чтобы в какой-то момент времени значения обменялись и держались в таком состоянии хотя бы один такт счётчика.

### Решение

![](https://i.ibb.co/sVBB3hG/image.png)

## Задание 10. Постфискная польская нотация

10.1. Дана формула в обычной (инфиксной) нотации, составить соответствующую ей RPN-формулу:

    1 - (2 - (3 - (4 - 5 * 6)))

Ответ: `123456*----`

## ? Задание 11. Синхронизированные логические схемы

11.1. Дана схема с двумя регистрами, генератором прямоугольного импульса, 2-битным счётчиком и декодером с 4 выходами:

![](https://sshots.shitpoet.cc/2023-10-10--222401--3211328334.png)

Пусть известно, что в регистре `R` хранится некоторое число `x`, например, `3`, но это не принципиально.

Завершить данную схему так, чтобы значение регистра `R` в какой-то момент времени увеличилось на 1 относительно его текущего значения.

В задании можно использовать дополнительный регистр `T` и любые другие компоненты, кроме дополнительных генераторов импульса, счётчиков и декодеров.

При разработке схемы важно учесть, чтобы не возникло "порочного круга" неконтроллируемого увеличения регистра R на 1, 2, 3 (и так далее) в рамках одного цикла работы.

Что будет после первых четырёх тактов работы -- считать несущественным. Главное, чтобы к концу 4-ого по порядку такта работы декодера значение в регистре инкрементировалось.

### Решение

![](https://i.ibb.co/HHx5QWT/image.png)

## Задание 12. Постфискная польская нотация

12.1. Какая формула в обычной (инфиксной) нотации соответствует следующией формуле в RPN:

    2 3 4 5 * / -

Ответ: `2 - 3 / (4 * 5)`

## ? Задание 13. Микроархитектура

13.1. Пусть дан модуль памяти RAM на четыре ячейки и один регистр.

![](https://shitpoet.cc/sshots/2021-04-07--152656--521217300.png)

Модуль памяти подключен к 2-битному счётчику.

Завершить схему так, чтобы в регистр `R` сохранялось последнее по порядку число из модуля памяти.

(В примере на изображении это число `2`, но число может быть и другим.)

Т.е. нужно чтобы 3-ая ячейка (считая от 0) памяти в какой-то момент времени сохранилась в регистр.

При этом нельзя разрывать уже установленные в схеме связи между элементми (генератор подкючён к счётчику, счётчик подключен к модулю памяти).

Имейте в виду, что счётчик конечен, поэтому после того, как он выдаст число 3 (`0b11` в двоичной системе), он снова вернётся к нулю (`0b00` в двоичной системе). Нужно убедиться, что после того, как число из модуля памяти попадает в регистр `R`, оно потом оттуда не исчезает и не затерается другим. В данной задаче этим пренебрегать запрещено.

Т.е. как только в регистр `R` попадает нужное число, он не должен после этого менять своё значение на другое. (Но разрешается повторная запись того же самого числа, так как это по сути не меняет состояние регистра.)

## Задание 14. Постфискная польская нотация

14.1. Какая формула в обычной (инфиксной) нотации соответствует следующией формуле в RPN:

    1 2 3 + 3 4 - 5 * / +

Ответ: `1 + (2 + 3) / ((3 - 4) * 5)`

## ? Задание 15. Синхронизированные логические схемы

15.1. Разработать схему, заполняющую память RAM некоторым числом `X`:

![](https://sshots.shitpoet.cc/2023-10-25--164701--1690213447.png)

В памяти исходно находятся числа `3 5 7 2`, поэтому вход управления текущим адресом `A` -- 2-битный (это показно на схеме с помощью числа рядом с косой чертой, перечёркивающей выход адреса `A`).

Напоминание: Выход осцилятора `clock` -- 1-битный: `0`, `1`, `0`, `1` и так далее.

## Задание 16. Стек и RPN

16.1. При вычислении некоторого выражения, записанного в форме RPN (т.е. в постфиксной нотации), стек менялся следующим образом:

    2  2  2  2  2  2  6  6  6  10
       5  5  5  5  3     5  4
          6  6  2        1
             3

Note: Один столбец в рисунке -- одно состояние стека. Т.е. в начале стек состоял из числа `2`, на втором шаге стек уже состоял из двух чисел: `2` и `5`, и так далее.

Задача: Найти исходное инфиксное выражение, RPN-форма которого при своём вычислении на стековой машине продуцирует такой стек.

Ответ:

- RPN: `2 5 6 3 / - * 5 1 - +`
- infix: `2 * (5 - 6 / 3) + 5 - 1`

## ? Задание 17. Синхронизированные логические схемы

Разработать схему, заполняющую память RAM числами `X` и `Y`, чередуя их, т.е. память заполняется последовательностью:

    X Y X Y X Y и т.д.

Например, если память содержить 4 регистра и `X == 2, Y == 7`, то содержимое памяти станет

    2 7 2 7

## Задание 18. Кодирование информации

Разработать кодировку (соответсвие некоторой информации конкретным битовым кодам) для хранения в компьютере формул RPN с максимальной длиной в 8 символов, включая специальный символ-терминатор выражения `$`.

Примеры RPN:

    2 2 + $

    1 2 + 3 4 - * $

    2 $

    3 4 5 6 - - + $

Условный символ `$` здесь обозначает конец выражения.

Он нужен для того, чтобы машине было проще понять, что вычисление окончено.

Считать, что в RPN формуле могут быть только:

- положительные числа от `0` до `7`
- операции `+`, `-`, `*`, `/`
- признак конца `$`

Какая тогда кодировка была бы удобной и более-менее компактно хранила бы подобные RPN-формулы.

Задача:

18.1. Разработать такую кодировку.

Ответ: Будем использовать 4 бита для кодировки одного символа. Если 4-й бит = 0, тогда это число от 0 до 7, если имеет 1 на 4 бите, тогда это операция или символ-терминатор. Вот алфавит для такой кодировки:

```sh
0 = 0000
1 = 0001
2 = 0010
3 = 0011
4 = 0100
5 = 0101
6 = 0110
7 = 0111
+ = 1000
- = 1001
* = 1010
/ = 1011
# ? = 1100
# ? = 1101
# ? = 1110
$ = 1111
```

Таким образом у нас еще есть 3 комбинации для других арифметических операций, которые мы можем использовать в будущем.

---

18.2. Привести конкретный пример кодирования для выражений. Т.е. какая последовательность из бит (нулей и единиц) будет соответствовать конкретно данной формуле при исползовании вашей кодировки.

Ответ:

```
         | $  | +  | 2  | 2
2 2 + $ = 1111 1000 0010 0010

                 | $  | *  | -  | 4  | 3  | +  | 2  | 1
1 2 + 3 4 - * $ = 1111 1010 1001 0100 0011 1000 0010 0001

     | $  | 2
2 $ = 1111 0010

                 | $  | +  | -  | -  | 6  | 5  | 4  | 3
3 4 5 6 - - + $ = 1111 1000 1001 1001 0110 0101 0100 0011
```

## ? Задание 19. Синхронизированные логические схемы

Пусть даны три регистра `R1-R3`, хранящие некотрые числа `a`, `b`, `c`. Какие конкретно эти число - для решения не принципиально:

![](https://sshots.shitpoet.cc/2023-10-25--162851--274011681.png)

Нужно завершить данную схему, чтобы через какое-то время значения регистров "сдвинулись", т.е. чтобы

- в регистр `R1` записалось число `X`,
- в регистр `R2` записалось исходное число из регистра `R1` (не новое значение `X`, а то, которыое было изначально в данном регистре)
- в регистр `R3` записалось исходное число из регистра `R2`

Таким образом, например, если изначально регистры хранили последовательность чисел, скажем

    3 5 7

то после некоторого времени, и если вход `X` равен 2, регистры должны поменяться на

    2 3 5

При этом последнее число (7) теряется.

## Задание 20. Микроархитектура

Пусть дан модуль памяти RAM на четыре ячейки, заполненный случайными чилсами.

![](https://sshots.shitpoet.cc/2023-10-10--215931--2953719836.png)

Завершить схему так, чтобы все ячейки в модуле памяти обнулились, т.е. стали равны нулю.

Hint: В данной схеме потребуется источник (генератор) прямоугольного импульса.

Справка: Модуль памяти -- это набор регистров, доступ осуществляется к одному из регистров в один момент времени. Такие регистры называются ячейками памяти.

## Задание 21. Синхронизированные логические схемы

Дано два модуля памяти RAM, каждый на 8 ячеек.

Задача: Разработать логическую схему, копирующую всё содержимое одного модуля (значения всех ячеек) во второй модуль по соответсвующим адресам.

Т.е. 0-ую ячеку из первого модуля в 0-ую ячейку второго модуля и т.д.

## Задание 22. Синхронизированные логические схемы

Разработать схему, которая имеет на выходе четыре лампочки `L1`, `L2`, `L3` и `L4`, и работает так, что:

    t     L1 L2 L3 L4
    -----------------
    0     1  0  0  0
    1     0  1  0  0
    2     0  0  1  0
    3     0  0  0  1
    0     0  0  0  1
    1     0  0  1  0
    2     0  1  0  0
    3     1  0  0  0
    0     1  0  0  0
    1     0  1  0  0
    2     0  0  1  0
    и т.д.

где `t` - это выход счётчика.

Обратите внимание, что здесь одному и тому же значению `t` соответствуют разные результаты. Поэтому данную задачу нельзя решить просто комбинаторным способом, т.е. просто соединя разные компоненты данную задачу не решить, пока не будет использована память: триггер(ы), регистр(ы) и/или модуль памяти.

Альтернативное решение -- это использовать счётчик большей разрядности.

Желательно предложить два решения:

1) используя счётчик большей разрядности и НЕ используя память (триггеры, регистры, модули памяти)
2) используя 2-битный счётчик `t` и используя память (триггеры, регистры и/или модули памяти)

Во втором варианте задачи, для решения с памятью (триггерами, регистрами и/или RAM) можно считать, что триггер или регистр имеет некотрое начальное состояние. Например, что регистр изначально хранит число `0`.

Второй вариант задачи, таким образом, сводится к тому, чтобы как-то манипулировать памятью, и затем использовать то, что в ней хранится, для того, чтобы менять поведение схемы.

## Задание 23. Синхронизированные логические схемы

Разработать схему, которая складывает значения трёх регистров `R1-R3`, используя одно АЛУ и не используя заменяющие его в данной задаче компоненты - сумматор `+`, компонент разницы `-`, операцию смены знака `-`, и т.д. Т.е. нахождение суммы должно быть за счёт исползования именно АЛУ. Другие АЛУ добавлять в схему также нельзя.

При этом, одно АЛУ за один такт работы может произвести только одну бинарную оперцию, т.е. например, только одно сложение двух чисел. Поэтому суть задачи в том, чтобы как-то тем не менее сложить три числа, переиспользуя один и тот же компонет (АЛУ) несколько раз.

Результат сложения нужно сохранить в отдельный регистр.

Также в схеме могут пригодиться дополнительные временные регистры и счётчик.

## Задание 24. Синхронизированные логические схемы

Дан модуль памяти RAM на 8 ячеек.

Пусть известно, что все ячейки содержат некоторые числа.

Разработать логическую схему, проходящую по всем ячейкам памяти и складывающую значения всех ячеек, подсчитывая тем самым общую сумму всех чисел, храняющихся в модуле памяти.

Для арифметических операций над числами из памяти схема должна использовать одно АЛУ, при этом схема должна содержать только одно АЛУ. (По сути в данной задаче можно использовать сумматор вместо АЛУ, т.к. мы не собираемся вычитать или умножать числа.)

При этом в схему при необходимости можно добавлять другие регистры с произвольным начальным состянием (хранимым значением-числом).

## Рекомендуемая литература и ресурсы

Charles Petzold. Code. The Hidden Language of Computer Hardware and Software
(Чарльз Петцольд. Код: тайный язык информатики)