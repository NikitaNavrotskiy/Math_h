CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11

NAME=my_math


all : $(NAME).a

$(NAME).a :
	$(CC) $(FLAGS) -c $(NAME).c
	ar rcs $(NAME).a $(NAME).o
	ranlib $(NAME).a
	rm -f $(NAME).o

test : clean
	$(CC) $(FLAGS) $(NAME).c test_math.c -o math_test -lcheck -lm
	./math_test
	
clang : 
	clang-format -i *.c *.h

gcov_report : clean
	$(CC) $(FLAGS) --coverage $(NAME).c test_math.c -o math_test -lcheck -lm 
	./math_test
	lcov -t "math_test" -o math_gcov.info -c -d .
	genhtml -o report math_gcov.info
	open report/index.html
	google-chrome report/index.html

clean :
	rm -f math_test* math_gcov.info
	rm -f $(NAME).a $(NAME).o
	rm -rf report
