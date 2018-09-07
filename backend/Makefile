PREFIX=/usr/local
INSTALLUSER=root
INSTALLGROUP=root

-include ../config.mk

SCRIPT=docker nvidia-docker
LIBEXEC=$(PREFIX)/libexec/container
# Backend will go in PATH when ready, until then put in LIBEXEC
#BACKEND=$(PREFIX)/bin
BACKEND=$(LIBEXEC)

default_target: $(SCRIPT)
$(SCRIPT): templates/docker
	sed -e s,%BACKEND%,$(BACKEND), templates/docker > $@

.PHONY : install
install: $(SCRIPT)
	install -o $(INSTALLUSER) -g $(INSTALLGROUP) -m 0755 -d $(BACKEND)
	for f in $(SCRIPT) ; do install -o $(INSTALLUSER) -g $(INSTALLGROUP) -m 0755 -t $(BACKEND) $$f ; done

.PHONY : clean
clean:
	rm -f $(SCRIPT)
