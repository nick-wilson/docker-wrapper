default_target: all

.PHONY : all
all:
	make -C backend/libexec
	make -C backend
	make -C frontend

.PHONY : install
install:
	make -C backend/libexec install
	make -C backend install
	make -C frontend install

.PHONY : clean
clean:
	make -C backend/libexec clean
	make -C backend clean
	make -C frontend clean
