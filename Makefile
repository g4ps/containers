CPPFLAGS = -std=c++98 -Wall -Werror -Wextra
CHECKERS = list_check.cpp vector_check.cpp

check: main.cpp $(CHECKERS) list.hpp vector.hpp map.hpp
	clang++ $(CPPFLAGS)  main.cpp $(CHECKERS) -o check
clean:
	rm check
