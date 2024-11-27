SUBDIRS = src

@DX_RULES@

all-local:	doxygen-doc

doxygen-doc/man/man1/guesser.1:	doxygen-doc

man1_MANS = doxygen-doc/man/man1/guesser.1

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

http:	doxygen-doc
	python3 -m http.server --directory $</html 5000
