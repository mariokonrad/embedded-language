.PHONY: all clean
.PHONY: examples
.PHONY: lua lua-examples
.PHONY: spidermonkey js-examples
.PHONY: tinyscheme tinyscheme-examples
.PHONY: ecl ecl-examples
.PHONY: chicken chicken-examples
.PHONY: squirrel
.PHONY: dscript
.PHONY: directories

# TODO: SIOD (http://people.delphiforums.com/gjc/siod.html) LICENSE:???
#            (http://siod.codeplex.com/) LICENSE:LGPL
# TODO: EEL (http://eel.olofson.net/) LICENSE:???
# TODO: elk (http://www-rn.informatik.uni-bremen.de/software/elk/) LICENSE:???
# TODO: Squirrel (http://squirrel-lang.org/) LICENSE:???
# TODO: EJScript (http://ejscript.org) LICENSE:GPL/commercial
# TODO: AngelCode (http://www.angelcode.com/angelscript/) LICENSE:zlib
# TODO: Ch (http://www.softintegration.com/) LICENSE:commercial
# TODO: Nasal (http://www.plausible.org/nasal/) LICENSE:???
# TODO: dscript (http://boost-spirit.com/repository/applications/show_contents.php) LICENSE:???
# TODO: delta (http://www.ics.forth.gr/hci/files/plang/Delta/Delta.html) LICENSE:???
# TODO: guile (https://gnu.org/software/guile/) LICENSE:???

export CXX=g++
export RM=rm -f
export MV=mv -f

export PREFIX=$(CURDIR)/local

export LUA=lua-5.1.4
export JS=js-1.8.0-rc1
export TINYSCHEME=tinyscheme1.39
export ECL=ecl-10.2.1
export ELK=elk-3.0
export GUILE=guile-2.0.7
export CHICKEN=chicken-4.8.0.3
export SQUIRREL=squirrel_3_0_4_stable

export BIN_DIR=$(PREFIX)/bin
export LIB_DIR=$(PREFIX)/lib
export DOC_DIR=$(PREFIX)/man
export INC_DIR=$(PREFIX)/include
export INC_DIR_LUA=$(INC_DIR)/lua
export INC_DIR_JS=$(INC_DIR)/js
export INC_DIR_TINYSCHEME=$(INC_DIR)/tinyscheme
export INC_DIR_ECL=$(INC_DIR)
export INC_DIR_GUILE=$(INC_DIR)
export INC_DIR_SQUIRREL=$(INC_DIR)/squirrel
export INC_DIR_DSCRIPT=$(INC_DIR)/dscript

all :
	$(MAKE) directories
	$(MAKE) -C build all
	$(MAKE) examples

examples :
	$(MAKE) -C src all

directories :
	mkdir -p $(BIN_DIR)
	mkdir -p $(LIB_DIR)
	mkdir -p $(DOC_DIR)
	mkdir -p $(INC_DIR_LUA)
	mkdir -p $(INC_DIR_JS)
	mkdir -p $(INC_DIR_TINYSCHEME)
	mkdir -p $(INC_DIR_ECL)/ecl
	mkdir -p $(INC_DIR_GUILE)
	mkdir -p $(INC_DIR_SQUIRREL)
	mkdir -p $(INC_DIR_DSCRIPT)
	# TODO: elk

lua : directories
	$(MAKE) -C build lua

lua-examples :
	$(MAKE) -C src lua

spidermonkey : directories
	$(MAKE) -C build spidermonkey

js-examples :
	$(MAKE) -C src js

tinyscheme : directories
	$(MAKE) -C build tinyscheme

tinyscheme-examples :
	$(MAKE) -C src tinyscheme

ecl : directories
	$(MAKE) -C build ecl

ecl-examples :
	$(MAKE) -C src ecl

elk : directories
	$(MAKE) -C build elk

elk-examples :
	# TODO

guile : directories
	$(MAKE) -C build guile

chicken : directories
	$(MAKE) -C build chicken

chicken-examples :
	$(MAKE) -C src chicken

squirrel : directories
	$(MAKE) -C build squirrel

dscript : directories
	$(MAKE) -C build dscript

clean :
	$(MAKE) -C build clean
	$(MAKE) -C src clean
	$(RM) -fr $(PREFIX)

