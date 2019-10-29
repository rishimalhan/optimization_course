#https://www.youtube.com/watch?v=aw9wHbFTnAQ
CXX=g++
DEBUG   = -c -g
LDFLAGS = -Wall $(DEBUG) -std=c++11 -I /usr/local/include/eigen3/
OBJS = goldensection.o
# OBJS = bisection.o

all: opt

opt: $(OBJS)
	$(CXX) -std=c++11 $(OBJS) -o goldensection

# opt: $(OBJS)
	# $(CXX) -std=c++11 $(OBJS) -o bisection

goldensection.o: goldensection.cpp
	$(CXX) $(LDFLAGS) goldensection.cpp

# bisection.o: bisection.cpp
# 	$(CXX) $(LDFLAGS) bisection.cpp

clean:
	rm -rf *o tp    
