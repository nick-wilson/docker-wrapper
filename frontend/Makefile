PREFIX=/usr/local
TARGET=container
INSTALLUSER=root
INSTALLGROUP=root

-include ../config.mk

SCRIPT=container
HELPER=container.run
LIBEXEC=$(PREFIX)/libexec/container
# Backend will go in PATH when ready, until then put in LIBEXEC
#BACKEND=$(PREFIX)/bin
BACKEND=$(LIBEXEC)

default_target: $(SCRIPT) $(HELPER)
$(SCRIPT) $(HELPER): templates/$@
	sed -e s,%LIBEXEC%,$(LIBEXEC),g -e s,%TARGET%,$(TARGET), -e s,%BACKEND%,$(BACKEND), templates/$@ > $@

.PHONY : install
install: $(SCRIPT) $(HELPER)
	install -o $(INSTALLUSER) -g $(INSTALLGROUP) -m 0755 -d $(PREFIX)/bin $(LIBEXEC)
	install -o $(INSTALLUSER) -g $(INSTALLGROUP) -m 0755 -T $(SCRIPT) $(PREFIX)/bin/$(TARGET)
	for f in $(HELPER) ; do install -o $(INSTALLUSER) -g $(INSTALLGROUP) -m 0755 -t $(LIBEXEC) $$f ; done

.PHONY : clean
clean:
	rm -f $(SCRIPT) $(HELPER)
