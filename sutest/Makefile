# Make utility for modhead2
#
#
CURRDIR := $(shell /bin/pwd)
PKG     := $(notdir $(CURRDIR))
DllSuf  = so
#
#LIBFLAGS= -lgpibapi
LIBRARIES     := $(PKG)
ifneq (,$(wildcard bin/LIBRARIES))
LIBRARIES     +=  $(shell sed "s;\#.*;;" bin/LIBRARIES 2> /dev/null)
endif

LIB_COMPONENTS := $(shell sed -e "s;\#.*;;" -e "s;.*SAM.*;;" src/COMPONENTS 2> /dev/null)
LIB_SOURCES    := $(LIB_COMPONENTS:%=src/%.cpp)
LIB_OBJECTS    := $(LIB_COMPONENTS:%=tmp/%.o)
LIB_TARGET     := lib/lib$(PKG).$(DllSuf)
LIB_STATIC_TGT := lib/lib$(PKG).a
TARGET = lib$(PACKAGE)

ifneq (,$(wildcard bin/BINARIES))
BIN_COMPONENTS := $(shell sed "s;\#.*;;" bin/BINARIES 2> /dev/null)
BIN_SOURCES    := $(BIN_COMPONENTS:%=bin/%.cpp)
BIN_OBJECTS    := $(BIN_COMPONENTS:%=tmp/%.o)
BIN_TARGETS    := $(BIN_COMPONENTS:%=bin/%)
STATIC_OBJECTS := $(BIN_COMPONENTS:%=tmp/%.o)
STATIC_TARGETS := $(BIN_COMPONENTS:%=bin/%_static)
endif

DICTS_HEADERS  := $(filter-out src/SAM%,$(wildcard src/*_linkdef.h))
DICTS_SOURCES  := $(DICTS_HEADERS:src/%_linkdef.h=tmp/%_dict.cpp)
DICTS_RDICTPCM := $(DICTS_HEADERS:src/%_linkdef.h=lib/%_dict_rdict.pcm)
DICTS_OBJECTS  := $(DICTS_SOURCES:%.cpp=%.o) 
LIB_DEPENDS    := $(LIB_COMPONENTS:%=tmp/%.d) $(DICTS_SOURCES:%.cpp=%.d)
BIN_DEPENDS    := $(BIN_COMPONENTS:%=tmp/%.d)



#LDFLAGS       := -L./lib $(LIBRARIES:%=-l%) -lTreePlayer -lMinuit -lGui  $(shell root-config --libs) -lGpad  -lGX11 -lX3d  
#LDFLAGS       := -L./lib $(LIBRARIES:%=-l%)  
LDFLAGS       := -L./lib $(LIBRARIES:%=-l%) -lTreePlayer -lMinuit -lGui  $(shell root-config --libs) -lGpad  -lGX11 -lX3d  


OUTFLAGS     := -o
INCLUDEFLAGS := -I/usr/local/include   -I./include
CXXDEBUG     := -g -O
CXXPROFILE   := -pg -O2 -g
CXXOPTIMIZE  := -g -O2
#
CXX          := g++
AR           := ar
#
ifeq ($(SRT_QUAL),maxopt)
#CXXFLAGS := $(shell root-config --cflags ) -fPIC $(CXXOPTIMIZE) -Wall
#CXXFLAGS := -pthread  -fPIC $(CXXOPTIMIZE) -Wall
CXXFLAGS := $(shell root-config --cflags )  -fPIC $(CXXOPTIMIZE) -Wall
else
#CXXFLAGS := $(shell root-config --cflags ) -fPIC $(CXXDEBUG) -Wall
CXXFLAGS := $(shell root-config --cflags )  -fPIC $(CXXDEBUG) -Wall
#CXXFLAGS := -pthread  -fPIC $(CXXDEBUG) -Wall
endif
#	@echo "$(CXXFLAGS)`"
#
default:	all

.PRECIOUS:   tmp/%_dict.cpp

#all:		lib bin lib_static bin_static
all:		lib bin 
#
tmp/%.o: src/%.cpp 
	@echo "$(PKG) -- Compiling component `basename $< .c`"
#	@echo "$(CXX) -I./$(PKG) $(CXXFLAGS) $(INCLUDEFLAGS) -c $< -o $@"
	@$(CXX) -I../$(PKG) $(CXXFLAGS) $(INCLUDEFLAGS) -c $< -o $@
#
tmp/%.o: bin/%.cpp 
	@echo "$(PKG) -- Compiling  binary `basename $< .c`"
	@echo "$(CXX) -I./$(PKG) $(CXXFLAGS) $(INCLUDEFLAGS) -c $< -o $@"
	@$(CXX) -I../$(PKG) $(CXXFLAGS) $(INCLUDEFLAGS) -c $< -o $@
#

tmp/%_dict.cpp: include/%.hpp 
	@echo "-- Generating dictionary for `basename $<`"
#	@echo "@rootcint -f   $@ -c -p $(INCLUDEFLAGS) `basename $< ` src/`basename $< .hpp`_linkdef.h"
	@rootcint -f $@ -c -p $(INCLUDEFLAGS) `basename $<`  src/`basename $< .hpp`_linkdef.h
#	@echo "@if [ -e  tmp/`basename $< .hpp`_dict_rdict.pcm  ] ; then mv -f tmp/`basename $< .hpp`_dict_rdict.pcm  $(CURDIR)/lib/ ; fi" # ROOT 6
	@if [ -e  tmp/`basename $< .hpp`_dict_rdict.pcm  ] ; then mv -f tmp/`basename $< .hpp`_dict_rdict.pcm $(CURDIR)/lib/ ; fi # ROOT 6
#	@if [ -e $(DICTIONARY:%.cxx=%_rdict.pcm) ] ; then mv -f $(DICTIONARY:%.cxx=%_rdict.pcm) $(CURDIR)/lib/ ; fi # ROOT 6

tmp/%.d:src/%.cpp
#	@echo "@$(CXX) -I../include $(CXXFLAGS) $(INCLUDEFLAGS) -MM $< | sed \"s;^\(.*:\);./tmp/\1;\" > $@"
	@$(CXX) -I../include $(CXXFLAGS) $(INCLUDEFLAGS) -MM $< | sed "s;^\(.*:\);./tmp/\1;" > $@

tmp/%.d: bin/%.cpp
	@$(CXX) -I../include $(CXXFLAGS) $(INCLUDEFLAGS) -MM $< | sed "s;^\(.*:\);../tmp/\1;" > $@

tmp/%.d: tmp/%.cpp
	@$(CXX) -I../include $(CXXFLAGS) $(INCLUDEFLAGS) -MM $< | sed "s;^\(.*:\);../tmp/$(PKG)/\1;" > $@


tmp/%.o: tmp/%.cpp
	@echo "$(PKG) -- Compiling dictionary for `basename $< .cpp`"
	@$(CXX) -I./include $(CXXFLAGS) $(INCLUDEFLAGS) -c $< -o $@

lib: $(LIB_TARGET)
#
$(LIB_TARGET):  $(LIB_DEPENDS)  $(DICTS_OBJECTS)  $(LIB_OBJECTS) 
	@echo "$(PKG) -- Linking Shared Library"
	@$(CXX) -o $(LIB_TARGET) -shared $(LIB_OBJECTS) $(DICTS_OBJECTS)
#	@echo "$(PKG) -- Linking Static Library"
#	@$(AR)  -rcs $(LIB_STATIC_TGT) $(LIB_OBJECTS)

lib_static: $(LIB_STATIC_TGT)
$(LIB_STATIC_TGT):   $(LIB_OBJECTS)  $(LIB_DEPENDS)  $(DICTS_OBJECTS)
	@echo "$(PKG) -- Linking Static Library"
	@echo "$(AR)  -rcs $(LIB_STATIC_TGT) $(LIB_OBJECTS)"
	@$(AR)  -rcs $(LIB_STATIC_TGT) $(LIB_OBJECTS) $(DICTS_OBJECTS)

bin:	$(BIN_OBJECTS) $(BIN_TARGETS)
#	@echo "$(PKG) -- Linking Binary `basename $@ `"

bin/%:  tmp/%.o  $(LIBRARIES:%=lib/lib%.$(DllSuf))
	@echo "$(PKG) -- Linking Binary `basename $@ `"
# Uncomment for debug
	@echo "$(CXX) -o $@ $< $(LDFLAGS)"
	@$(CXX) -o $@ $< $(LDFLAGS) 

bin_static:	$(STATIC_OBJECTS) $(STATIC_TARGETS)
	@echo "$(PKG) -- Linking Static Binary `basename $@ `"
bin/%_static:  tmp/%.o  $(LIBRARIES:%=lib/lib%.$(DllSuf))
	@echo "$(PKG) -- Linking Binary `basename $@ `"

# Uncomment for debug
	@echo "$(PKG) -- Linking Static Binary `basename $@ `"
	@echo "$(CXX) -static  -I./ -o $@_static $< $(LDFLAGS) "
	@$(CXX) -static  -I./ -o $@ $< $(LDFLAGS)  


#
clean:	
	@echo "$(PKG) -- Cleaning Object Files, Libraries (and Bundles) and Binaries"
		@/bin/rm -f $(BIN_COMPONENTS) $(BIN_TARGETS) $(LIB_OBJECTS) $(LIB_TARGET) $(LIB_STATIC_TGT) $(subst .$(DllSuf),.so,$(LIB_TARGET)) $(DICTS_OBJECTS) $(BIN_TARGETS) $(BIN_OBJECTS) $(STATIC_TARGETS) $(LIB_DEPENDS) $(DICTS_SOURCES)  $(DICTS_RDICTPCM) tmp/*_dict.h

debug:
	@echo "PKG         = $(PKG)"
	@echo "CXXFLAGS    = $(CXXFLAGS)"
	@echo "COMPONENTS  = $(LIB_COMPONENTS)"
	@echo "BINARIES    = $(BIN_COMPONENTS)"
	@echo "LIB_OBJECTS = $(LIB_OBJECTS)"
	@echo "LIB_TARGET  = $(LIB_TARGET)"
	@echo "BIN_OBJECTS = $(BIN_OBJECTS)"
	@echo "BIN_TARGETS = $(BIN_TARGETS)"
	@echo "DICTS_OBJECTS  = $(DICTS_OBJECTS)"
	@echo "LIB_DEPENDS  = $(LIB_DEPENDS)"
	@echo "DICTS_RDICTPCM  = $(DICTS_RDICTPCM)"
	@echo "PWD         = `/bin/pwd`"
