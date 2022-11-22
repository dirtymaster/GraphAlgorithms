FLAGS = g++ -g -std=c++17 #-Wall -Wextra -Werror
SOURCES = Graph/*.cpp GraphAlgorithms/*.cpp DataStructures/Matrix/*.cpp \
			DataStructures/Stack/*.cpp DataStructures/Queue/*.cpp ConsoleEngine/ConsoleEngine.cpp \
			GraphAlgorithms/BranchAndBoundAlgorithmForTSM/*.cpp \
			GraphAlgorithms/AntAlgorithmForTSM/*.cpp

demo:
	$(FLAGS) $(SOURCES) ConsoleEngine/main.cpp -o app.out
	./app.out

test:
	$(FLAGS) -lgtest $(SOURCES) Tests/tests.cpp -o tests.out
	CK_FORKS=no leaks -atExit -- ./tests.out

clang_style:
	clang-format -i $(SOURCES)

clean:
	rm -rf app.out tests.out app.out.dSYM tests.out.DSYM
