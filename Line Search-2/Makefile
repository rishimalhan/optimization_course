#https://www.youtube.com/watch?v=aw9wHbFTnAQ
CXX=g++
DEBUG   = -c -g
LDFLAGS = -Wall $(DEBUG) -std=c++11 -I /usr/local/include/eigen3/
OBJS = armijo.o
# OBJS = Newton1D.o

all: opt

opt: $(OBJS)
	$(CXX) -std=c++11 $(OBJS) -o armijo
# opt: $(OBJS)
	# $(CXX) -std=c++11 $(OBJS) -o Newton1D

armijo.o: armijo.cpp
	$(CXX) $(LDFLAGS) armijo.cpp
# Newton1D.o: Newton1D.cpp
	# $(CXX) $(LDFLAGS) Newton1D.cpp

clean:
	rm -rf *o tp    
