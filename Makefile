#                                                                                        
# UTD CS3377 CDK Example                                                     
# Dr. Perkins                                                                                           
# stephen.perkins@utdallas.edu                                                                            
#                         

CXX = g++
CXXFLAGS =
CPPFLAGS = -Wall -g -I/scratch/perkins/include
LDFLAGS = -L/scratch/perkins/lib
LDLIBS = -lcdk -lcurses

# Executable Name                                                                                                                          
EXECFILE = cdkexample
# Auto include all .cc files                                                                                                               
SOURCES := $(wildcard *.cc)
OBJS = $(SOURCES:.cc=.o)

# Rely on implicit rules for compilation                                                                                                 

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *~ \#*


$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)
backup: clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
