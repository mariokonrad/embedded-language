.PHONY: all clean \
	lua lua-install \
	spidermonkey spidermonkey-install \
	tinyscheme tinyscheme-install \
	ecl ecl-install \
	elk elk-install

export LUA=lua-5.1.4
export JS=js-1.8.0-rc1
export TINYSCHEME=tinyscheme1.39
export ECL=ecl-10.2.1
export ELK=elk-3.0

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


all : \
	lua lua-install \
	spidermonkey spidermonkey-install \
	tinyscheme tinyscheme-install \
	ecl ecl-install \
	elk elk-install

lua :
	tar -xzf $(LUA).tar.gz
	$(MAKE) -C $(LUA) ansi
	$(MAKE) lua-install

lua-install :
	cp $(LUA_BINS) $(BIN_DIR)
	cp $(LUA_DOCS) $(DOC_DIR)
	cp $(LUA_LIBS) $(LIB_DIR)
	cp $(LUA_INCS) $(INC_DIR_LUA)

spidermonkey :
	tar -xzf $(JS).tar.gz
	$(MAKE) -C js/src -f Makefile.ref
	$(MAKE) spidermonkey-install

spidermonkey-install :
	cp $(JS_BINS) $(BIN_DIR)
	#cp $(JS_DOCS) $(DOC_DIR)
	cp $(JS_LIBS) $(LIB_DIR)
	cp $(JS_INCS) $(INC_DIR_JS)

tinyscheme :
	tar -xzf $(TINYSCHEME).tar.gz
	make -C $(TINYSCHEME) -f makefile
	$(MAKE) tinyscheme-install

tinyscheme-install :
	cp $(TINYSCHEME_BINS) $(BIN_DIR)
	#cp $(TINYSCHEME_DOCS) $(DOC_DIR)
	cp $(TINYSCHEME_LIBS) $(LIB_DIR)
	cp $(TINYSCHEME_INCS) $(INC_DIR_TINYSCHEME)

ecl :
	tar -xzf $(ECL).tgz
	cd $(ECL) && ./configure --prefix=$(PREFIX)
	make -C $(ECL)
	$(MAKE) ecl-install

ecl-install :
	#cp $(ECL_BINS) $(BIN_DIR)
	#cp $(ECL_DOCS) $(DOC_DIR)
	#cp $(ECL_LIBS) $(LIB_DIR)
	#cp $(ECL_INCS) $(INC_DIR_ECL)
	$(MAKE) -C $(ECL) install

elk :
	# TODO

elk-install :
	# TODO

clean :
	rm -fr $(LUA)
	rm -fr $(JS) js
	rm -fr $(TINYSCHEME)
	rm -fr $(ECL)
