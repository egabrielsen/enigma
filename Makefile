CXX = g++
CXXFLAGS = -O -std=c++11

all: enigma.exe

enigma.exe: main.cpp Enigma.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	\rm -f *.txt enigma.exe
