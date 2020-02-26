TARGETS=adc_fitting

ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)

CXXFLAGS  = -Wall -O2 $(ROOTFLAGS)
CXXLIBS   = $(ROOTLIBS)

all: $(TARGETS)

adc_fitting: adc_fitting.o
		   g++ -o $@ adc_fitting.o $(CXXLIBS)

.cc.o:
	g++ -c $(CXXFLAGS) $<

clean:
	rm -f adc_fitting.o adc_fitting
