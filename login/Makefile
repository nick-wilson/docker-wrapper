PREFIX_LOGIN=/usr/local
TARGET=container
INSTALLUSER=root
INSTALLGROUP=root
IMAGELIST=/var/run/docker-images

-include ../config.mk

SCRIPT=docker
ALIASES=nvidia-docker $(TARGET)
BACKEND=$(PREFIX_LOGIN)/bin

default_target: $(SCRIPT)
$(SCRIPT): templates/$@
	sed -e s,%IMAGELIST%,$(IMAGELIST),g templates/$@ > $@

.PHONY : install
install: $(SCRIPT)
	install -o $(INSTALLUSER) -g $(INSTALLGROUP) -m 0755 -d $(PREFIX_LOGIN)/bin
	install -o $(INSTALLUSER) -g $(INSTALLGROUP) -m 0755 -t $(PREFIX_LOGIN)/bin $(SCRIPT)
	for f in $(ALIASES) ; do ln -fs $(SCRIPT) $(PREFIX_LOGIN)/bin/$$f ; done

.PHONY : clean
clean:
	rm -f $(SCRIPT) $(HELPER)
