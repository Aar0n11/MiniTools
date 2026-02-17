.PHONY: build_dir
build_dir:
	mkdir build

minils: src/minils.c
	gcc -o build/minils src/minils.c

minicat: src/minicat.c
	gcc -o build/minicat src/minicat.c

miniecho: src/miniecho.c
	gcc -o build/miniecho src/miniecho.c

.PHONY: all
all:
	make build_dir
	make minils
	make minicat
	make miniecho

