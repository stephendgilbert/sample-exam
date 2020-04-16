EXE = p1
CXX = @g++
CXXFLAGS = -std=c++17 -Wl,--allow-multiple-definition -O0
LIBS = $(EXE)
SRC = $(EXE).cpp
OBJS = $(EXE).o

$(EXE): $(OBJS) makefile
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)  -L./ -l$(LIBS)

# Remove object files from folder
clean:
	rm -f core $(EXE) *.o

run: $(EXE)
	./$(EXE)

debug: $(EXE)
	debug50 ./$(EXE)

stest: $(EXE)
	@./$(EXE) $(EXE).tests

test: $(EXE)
	@./$(EXE) -t

