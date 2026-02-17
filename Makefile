.PHONY: build_dir
build_dir:
	mkdir build

minils: minils.c
	gcc -o build/minils minils.c

minicat: minicat.c
	gcc -o build/minicat minicat.c

miniecho: miniecho.c
	gcc -o build/miniecho miniecho.c

.PHONY: all
all:
	make build_dir
	make minils
	make minicat
	make miniecho

