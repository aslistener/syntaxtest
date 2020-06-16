VERSION=1.0.0.0
TARGET=test$(VERSION)
CROSS = 
CC = $(CROSS)gcc
CXX = $(CROSS)g++

src_root=.
build_root=$(shell pwd)
ifdef src
  src_root:=$(src)
endif

CFLAGS=-c -Wno-class-memaccess
incs=$(src_root)
CCFLAGS=-std=gnu++17
LDFLAGS=

sources = $(wildcard $(src_root)/*.cc)
object_files = $(patsubst %.cc, %.o, $(sources))


$(TARGET) : $(object_files)
	#@echo $(src_root)
	#@echo $(sources)
	#@echo $(object_files)
	#@echo $(build_root)
	$(CXX) $^ -o $@ $(LDFLAGS)
%.o:%.cc
	$(CXX) -I$(incs) $(CFLAGS) $(CCFLAGS) $< -o $@

clean:
	rm $(build_root)/$(TARGET) $(object_files)
