PREFIX = /usr/local
LIBDIR = lib

all:

install:
	mkdir -p '$(DESTDIR)$(PREFIX)/include'
	mkdir -p '$(DESTDIR)$(PREFIX)/$(LIBDIR)/pkgconfig'
	cp -r include/ffnvcodec '$(DESTDIR)$(PREFIX)/include'
	sed 's#@@PREFIX@@#$(PREFIX)#' ffnvcodec.pc.in > '$(DESTDIR)$(PREFIX)/$(LIBDIR)/pkgconfig/ffnvcodec.pc'

uninstall:
	rm -rf '$(DESTDIR)$(PREFIX)/include/ffnvcodec' '$(DESTDIR)$(PREFIX)/$(LIBDIR)/pkgconfig/ffnvcodec.pc'

.PHONY: all install uninstall

