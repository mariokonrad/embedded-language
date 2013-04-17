.PHONY: all clean lua spidermonkey tinyscheme ecl elk guile chicken dscript

export LUA_BINS=\
	$(LUA)/src/lua \
	$(LUA)/src/luac
export LUA_DOCS=\
	$(LUA)/doc/lua.1 \
	$(LUA)/doc/luac.1
export LUA_LIBS=\
	$(LUA)/src/liblua.a
export LUA_INCS=\
	$(LUA)/src/lua.h \
	$(LUA)/src/luaconf.h \
	$(LUA)/src/lualib.h \
	$(LUA)/src/lauxlib.h \
	$(LUA)/etc/lua.hpp

export JS_BINS=\
	js/src/Linux_All_DBG.OBJ/js \
	js/src/Linux_All_DBG.OBJ/jscpucfg \
	js/src/Linux_All_DBG.OBJ/jskwgen
export JS_DOCS=
export JS_LIBS=\
	js/src/Linux_All_DBG.OBJ/libjs.a \
	js/src/Linux_All_DBG.OBJ/libjs.so
export JS_INCS=\
	js/src/jsapi.h \
	js/src/jspubtd.h \
	js/src/jstypes.h \
	js/src/jscompat.h \
	js/src/jsproto.tbl \
	js/src/jsutil.h \
	js/src/jsotypes.h \
	js/src/jslong.h \
	js/src/jsconfig.h \
	js/src/Linux_All_DBG.OBJ/jsautocfg.h

export TINYSCHEME_BINS=\
	$(TINYSCHEME)/scheme
export TINYSCHEME_DOCS=
export TINYSCHEME_LIBS=\
	$(TINYSCHEME)/libtinyscheme.a \
	$(TINYSCHEME)/libtinyscheme.so
export TINYSCHEME_INCS=\
	$(TINYSCHEME)/scheme.h \
	$(TINYSCHEME)/scheme-private.h \
	$(TINYSCHEME)/opdefines.h

export ECL_BINS=
export ECL_DOCS=
export ECL_LIBS=
export ECL_INCS=

export ELK_BINS=
export ELK_DOCS=
export ELK_LIBS=
export ELK_INCS=

export CHICKEN_BINS=
export CHICKEN_DOCS=
export CHICKEN_LIBS=
export CHICKEN_INCS=

export SQUIRREL_BINS=\
	SQUIRREL3/bin/sq
export SQUIRREL_DOCS=
export SQUIRREL_LIBS=\
	SQUIRREL3/lib/libsqstdlib.a \
	SQUIRREL3/lib/libsquirrel.a
export SQUIRREL_INCS=\
	SQUIRREL3/include/sqstdaux.h \
	SQUIRREL3/include/sqstdblob.h \
	SQUIRREL3/include/sqstdio.h \
	SQUIRREL3/include/sqstdmath.h \
	SQUIRREL3/include/sqstdstring.h \
	SQUIRREL3/include/sqstdsystem.h \
	SQUIRREL3/include/squirrel.h

all : \
	lua \
	spidermonkey \
	tinyscheme \
	chicken \
	squirrel \
	ecl \
	elk

#	guile
#	dscript

lua :
	# build
	tar -xzf $(LUA).tar.gz
	$(MAKE) -C $(LUA) ansi
	# install
	cp $(LUA_BINS) $(BIN_DIR)
	cp $(LUA_DOCS) $(DOC_DIR)
	cp $(LUA_LIBS) $(LIB_DIR)
	cp $(LUA_INCS) $(INC_DIR_LUA)

spidermonkey :
	# build
	tar -xzf $(JS).tar.gz
	$(MAKE) -C js/src -f Makefile.ref
	# install
	cp $(JS_BINS) $(BIN_DIR)
	#cp $(JS_DOCS) $(DOC_DIR)
	cp $(JS_LIBS) $(LIB_DIR)
	cp $(JS_INCS) $(INC_DIR_JS)

tinyscheme :
	# build
	tar -xzf $(TINYSCHEME).tar.gz
	make -C $(TINYSCHEME) -f makefile
	# install
	cp $(TINYSCHEME_BINS) $(BIN_DIR)
	#cp $(TINYSCHEME_DOCS) $(DOC_DIR)
	cp $(TINYSCHEME_LIBS) $(LIB_DIR)
	cp $(TINYSCHEME_INCS) $(INC_DIR_TINYSCHEME)

ecl :
	# build
	tar -xzf $(ECL).tgz
	cd $(ECL) && ./configure --prefix=$(PREFIX)
	$(MAKE) -C $(ECL)
	# install
	#cp $(ECL_BINS) $(BIN_DIR)
	#cp $(ECL_DOCS) $(DOC_DIR)
	#cp $(ECL_LIBS) $(LIB_DIR)
	#cp $(ECL_INCS) $(INC_DIR_ECL)
	$(MAKE) -C $(ECL) install

elk :
	# build
	# TODO: build elk
	# install
	# TODO: install elk

guile :
	# build
	tar -xzf $(GUILE).tar.gz
	cd $(GUILE) && ./configure --prefix=$(PREFIX)
	$(MAKE) -C $(GUILE)
	# install
	$(MAKE) -C $(GUILE) install

chicken :
	# build
	tar -xzf $(CHICKEN).tar.gz
	cd $(CHICKEN) && mkdir local && make PLATFORM=linux PREFIX=$(PREFIX)
	# install
	cd $(CHICKEN) && make PLATFORM=linux PREFIX=$(PREFIX) install

squirrel :
	# build
	tar -xzf $(SQUIRREL).tar.gz
	cd SQUIRREL3 && make
	# install
	cp $(SQUIRREL_BINS) $(BIN_DIR)
	#cp $(SQUIRREL_DOCS) $(DOC_DIR)
	cp $(SQUIRREL_LIBS) $(LIB_DIR)
	cp $(SQUIRREL_INCS) $(INC_DIR_SQUIRREL)

dscript/%.o : dscript/%.cpp
	g++ -o $@ -c $< -O2 -Idscript

dscript :
	# build
	unzip dscript.zip
	$(MAKE) dscript/libdscript.a
	# install

dscript/libdscript.a : \
		dscript/compiler.o \
		dscript/compiler_save.o \
		dscript/context.o \
		dscript/floattable.o \
		dscript/functions.o \
		dscript/opcodes.o \
		dscript/stdlib.o \
		dscript/stringtable.o \
		dscript/value.o \
		dscript/vmachine.o
	cd dscript && ar rcs $@ $^

clean :
	rm -fr $(LUA)
	rm -fr $(JS) js
	rm -fr $(TINYSCHEME)
	rm -fr $(ECL)
	rm -fr $(GUILE)
	rm -fr $(CHICKEN)
	rm -fr SQUIRREL3
	rm -fr dscript

