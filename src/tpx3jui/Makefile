

LFLAGS        = -g3 -m64 -Wl,-O1 -shared -Wl,-soname,libSpidrDaqJ.so.1
LIBS          = $(SUBLIBS) -L/usr/lib/x86_64-linux-gnu -lpthread -lQtNetwork -lQtCore  -L/home/idarraga/daq/SPIDR/software/trunk/Release -lSpidrTpx3Lib
INCPATH       = -I/usr/lib/jvm/java-6-openjdk-amd64/include -I./ -I/home/idarraga/daq/SPIDR/software/trunk/SpidrTpx3Lib

all:	messages bind
	@echo "... done"

messages:
	@echo "make bind (to create shared lib)"
	@echo "make buildfiles (to build C wrapper)"

bind:	tpx3jui_SpidrDaqJ.o
	g++ $(LFLAGS) -o libSpidrDaqJ.so tpx3jui_SpidrDaqJ.o $(LIBS)

tpx3jui_SpidrDaqJ.o:	tpx3jui_SpidrDaqJ.cpp
	g++ -g3 -m64 -pipe -Wall -W -D_REENTRANT -fPIC -c $(INCPATH) tpx3jui_SpidrDaqJ.cpp

buildfiles:	
	bash ./buildfiles.sh

clean:
	rm -f tpx3jui_SpidrDaqJ.o libSpidrDaqJ.so
