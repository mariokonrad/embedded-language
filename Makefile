.PHONY: all clean \
	examples lua-examples js-examples tinyscheme-examples ecl-examples \
	lua lua-install \
	spidermonkey spidermonkey-install \
	tinyscheme tinyscheme-install \
	ecl ecl-install \
	chicken chicken-install \
	directories

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

export BIN_DIR=$(PREFIX)/bin
export LIB_DIR=$(PREFIX)/lib
export DOC_DIR=$(PREFIX)/man
export INC_DIR=$(PREFIX)/include
export INC_DIR_LUA=$(INC_DIR)/lua
export INC_DIR_JS=$(INC_DIR)/js
export INC_DIR_TINYSCHEME=$(INC_DIR)/tinyscheme
export INC_DIR_ECL=$(INC_DIR)
export INC_DIR_GUILE=$(INC_DIR)

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
	# TODO: elk

lua : directories
	$(MAKE) -C build lua

lua-install :  directories
	$(MAKE) -C build lua-install

lua-examples :
	$(MAKE) -C src lua

spidermonkey : directories
	$(MAKE) -C build spidermonkey

spidermonkey-install : directories
	$(MAKE) -C build spidermonkey-install

js-examples :
	$(MAKE) -C src js

tinyscheme : directories
	$(MAKE) -C build tinyscheme

tinyscheme-install : directories
	$(MAKE) -C build tinyscheme-install

tinyscheme-examples :
	$(MAKE) -C src tinyscheme

ecl : directories
	$(MAKE) -C build ecl

ecl-install : directories
	$(MAKE) -C build ecl-install

ecl-examples :
	$(MAKE) -C src ecl

elk : directories
	$(MAKE) -C build elk

elk-install : directories
	$(MAKE) -C build elk-install

elk-examples :
	# TODO

guile : directories
	$(MAKE) -C build guile

guile-install : directories
	$(MAKE) -C build guile-install

chicken : directories
	$(MAKE) -C build chicken

chicken-install :
	$(MAKE) -C build chicken-install

clean :
	$(MAKE) -C build clean
	$(MAKE) -C src clean
	$(RM) -fr $(PREFIX)

