# Copy and adapt the contents of a makefile here.
# Use separate compilation, support "make clean", and name your 
# executable "fans" as per the specification
COURSE = cs240
SEMESTER = spring2022

# Update the CP_NUMBER if you adapt this makefile for future assignments
CP_NUMBER = 4

# Change the following to your own information
LASTNAME = bozan
GITUSERID = nilsubozan

# Name files according to CS240 naming conventions
REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar


fans: fans.cpp fans.h LinkedList.h Email.h Phone.h Fan.h BST.cpp
	g++ -Wall -Wextra -g fans.cpp BST.cpp Email.cpp Fan.cpp Phone.cpp -o bin/fans

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm bin/fans