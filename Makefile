VERSION=1.0.0.0
TARGET=test$(VERSION).out
# CROSS = mips64el-linux-gnuabi64
# CC = $(CROSS)-gcc
# CXX = $(CROSS)-g++

#CC = clang
#CXX = clang++	

src_root=.
build_root=$(shell pwd)
ifdef src
  src_root:=$(src)
endif

# used for cross compiling mips64el
# CFLAGS="-c -Wno-class-memaccess --sysroot=${SYSROOT}" 
CFLAGS="-c" 


CPPFLAGS=$(CFLAGS)
incs=$(src_root)
#CCFLAGS=-std=gnu++14
LDFLAGS=-lpthread   ## --sysroot=${SYSROOT}
#-Wl,--sysroot=${SYSROOT}

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
