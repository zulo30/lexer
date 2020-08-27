## If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

LIBS = -lm

###
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer

.PHONY: build
build: build/main.out
	@./build/main.out
	
build/main.out: src/*.c src/*.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/*.c  -o build/main.out $(LIBS)

.PHONY: test
test: build/tests.out
	@./build/tests.out

.PHONY: memcheck
memcheck: test/*.c src/*.c src/*.h
	@echo Compiling $@
	@$(CC) $(ASANFLAGS) $(CFLAGS) src/*.c test/vendor/unity.c test/*.c -o memcheck.out $(LIBS)
	@./memcheck.out
	@echo "Memory check passed"

.PHONY: clean
clean:
	rm -rf build/*.o build/*.out build/*.out.dSYM

build/tests.out: test/*.c src/*.c src/*.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/*.c test/vendor/unity.c test/*.c -o build/tests.out $(LIBS)
