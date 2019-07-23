PREFIX=/usr/local
INSTALLUSER=root
INSTALLGROUP=root

-include ../config.mk

SCRIPT=docker
LIBEXEC=$(PREFIX)/libexec/container
# If wrapper is first in PATH then nvidia-docker calls docker wrapper which fails
#BACKEND=$(PREFIX)/bin
BACKEND=$(LIBEXEC)

default_target: $(SCRIPT)
$(SCRIPT): templates/docker
	sed -e s,%BACKEND%,$(BACKEND), -e s,%LIBEXEC%,$(LIBEXEC), -e s,%NAME%,$@, templates/docker > $@

.PHONY : install
install: $(SCRIPT)
	install -o $(INSTALLUSER) -g $(INSTALLGROUP) -m 0755 -d $(BACKEND)
	for f in $(SCRIPT) ; do install -o $(INSTALLUSER) -g $(INSTALLGROUP) -m 0755 -t $(BACKEND) $$f ; done

.PHONY : clean
clean:
	rm -f $(SCRIPT)
