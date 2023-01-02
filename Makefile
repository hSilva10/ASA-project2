CFLAGS = -std=c++11 -O3 -Wall -lm

TEST = tests/t_input_1.txt,tests/t_input_2.txt,tests/t_0E.txt,tests/t_0V.txt,tests/t_sameW.txt,tests/t_26V.txt

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
	hyperfine --export-markdown data.md --runs 20 --warmup 2 --parameter-list TEST $(TEST) './project_base < {TEST}'
