# Copy or link this makefile into source code directory
CXX         := g++
TARGET      := main
CXXFLAGS    += -std=c++11

buildtype :=

ifeq ($(buildtype),release)
	CXXFLAGS += -s -O2
else
	CXXFLAGS += -DEBUG -W -Wall -Wextra -Wfloat-equal -Wundef -fsanitize=undefined -g3
	LDFLAGS += -ubsan
endif

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $^

.PHONY: clean
clean:
	rm -f *.o
