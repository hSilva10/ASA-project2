CFLAGS = -std=c++11 -O3 -Wall -lm

TEST = tests/test1.txt,tests/test2.txt,tests/test3.txt,tests/test4.txt,tests/test5.txt,tests/test6.txt,tests/test7.txt,tests/test8.txt,tests/test9.txt,tests/test10.txt

project_base: project_base.cpp
	g++ $(CFLAGS) -cpp project_base.cpp -o project_base

project_alt: project_alt.cpp
	g++ $(CFLAGS) -cpp project_alt.cpp -o project_alt

clean:
	rm -f *.o project_base project_alt

exec:
	./project_base

run: clean project_base exec

run1:
	./project_base < tests/t_input_1.txt

run2:
	./project_base < tests/t_input_2.txt

hyperfine:
	hyperfine --export-json data.json --runs 100 --warmup 5 --parameter-list TEST $(TEST) './project_base < {TEST}'
