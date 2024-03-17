CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage
HEADER = s21_decimal.h

all:
	gcc *.c -lm
	./a.out

bit:
	gcc main.c s21_bit/s21_bit.c s21_bit/nullify.c s21_base/get_bit.c s21_arithmetic/s21_div.c s21_base/set_bit.c s21_comparison/s21_is_less.c s21_other/s21_get_sign.c s21_comparison/s21_zero.c  s21_big_decimal/*.c
	./a.out

normalize_bit:
	gcc main.c s21_base/normalize.c s21_base/s21_shift.c s21_bit/s21_bit.c s21_base/set_to_zero.c #можно ли здесь не писать путь кадый раз
	./a.out

clang:
	find . -name '*.c' | xargs clang-format -i
