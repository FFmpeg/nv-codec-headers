PREFIX = /usr/local
LIBDIR = lib
INSTALL = install
SED = sed

all:
	$(SED) 's#@@PREFIX@@#$(PREFIX)#' ffnvcodec.pc.in > ffnvcodec.pc

install: all
	$(INSTALL) -m 0755 -d '$(DESTDIR)$(PREFIX)/include/ffnvcodec'
	$(INSTALL) -m 0644 include/ffnvcodec/*.h '$(DESTDIR)$(PREFIX)/include/ffnvcodec'
	$(INSTALL) -m 0755 -d '$(DESTDIR)$(PREFIX)/$(LIBDIR)/pkgconfig'
	$(INSTALL) -m 0644 ffnvcodec.pc '$(DESTDIR)$(PREFIX)/$(LIBDIR)/pkgconfig'

uninstall:
	rm -rf '$(DESTDIR)$(PREFIX)/include/ffnvcodec' '$(DESTDIR)$(PREFIX)/$(LIBDIR)/pkgconfig/ffnvcodec.pc'

.PHONY: all install uninstall

