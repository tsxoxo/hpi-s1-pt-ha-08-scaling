CC ?= clang
# Tip: override the compiler like `make CC=gcc`

# Build the MVP binary from the listed sources
mvp:
	$(CC) -o mvp.out mvp.c arraylistio_core.c arraylistio_basic.c

# Build the release binary (includes the fast implementation)
release:
	@echo "TODO: add the release build command"

# Build and run the MVP in one step
mvp-run:
	$(CC) -o mvp.out mvp.c arraylistio_core.c arraylistio_basic.c && ./mvp.out

# Build and run the release in one step
release-run:
	@echo "TODO: add the release build-and-run command"

# good practice: add `make clean` for cleanup
clean:
	rm -f *.out

# .PHONY marks targets that are not files. Without it, a file named "clean"
# (or "mvp", etc.) would make Make think the target is already up to date and
# skip the recipe. With .PHONY, Make always runs those recipes when requested.
.PHONY: mvp release mvp-run release-run clean


	
