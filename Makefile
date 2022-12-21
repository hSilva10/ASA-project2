CFLAGS = -std=c++11 -O3 -Wall -lm

project_base: project_base.cpp
	g++ $(CFLAGS) -cpp project_base.cpp -o project_base

project_alt: project_alt.cpp
	g++ $(CFLAGS) -cpp project_alt.cpp -o project_alt

clean:
	rm -f *.o project_base project_alt

run1:
	./project_base < tests/t_input_1.txt

run2:
	./project_base < tests/t_input_2.txt	
