
# Default target will list all the available targets
TARGETS=$(shell ls *.mk | cut -d'.' -f1 | xargs echo)
all:
	@echo "Specify a target to build for:"
	@for B in ${TARGETS}; do \
		echo "    make " $$B; \
	done

microchip-pic32mz:
	make pic32mz -C axtls-lite
	$(eval include microchip-pic32mz.mk)
	make -C libsal

test: clean
	make test -C libsal

clean:
	make clean -C axtls-lite
	make clean -C libsal

