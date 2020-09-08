## If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

LIBS = -lm

ALL_SRCS = $(wildcard src/*.c)
ALL_SRCS += $(wildcard src/vendor/*.c)
ALL_SRCS += $(wildcard src/utils/*.c)
SRCS     = $(filter-out src/lexer.c, $(ALL_SRCS))

TEST_DIR = test
TEST_RNS = test/test_runners

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
	
build/main.out: src/*.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) $(ALL_SRCS)  -o build/main.out $(LIBS)

.PHONY: test
test: build/queue.test.out build/table.test.out
	@echo =======================
	@echo Running Test Suites
	@echo -----------------------
	@echo  1.	Queue Test Suite 
	@echo -----------------------
	@./build/queue.test.out
	@echo -----------------------
	@echo  2.	Table Test Suite 
	@echo -----------------------
	@./build/table.test.out

.PHONY: memcheck
memcheck: test/*.c  $(SRCS) 
	@echo Compiling $@...
	@$(CC) $(ASANFLAGS) $(CFLAGS) $(SRCS) test/vendor/unity.c test/*.c -o memcheck.out $(LIBS)
	@./memcheck.out
	@echo "Memory check passed"

.PHONY: clean
clean:
	rm -rf build/*.o build/*.out build/*.out.dSYM

build/%.test.out:  $(TEST_DIR)/test_%.c $(TEST_RNS)/test_%_runner.c
	@$(CC) $(CFLAGS) $(SRCS) test/vendor/unity.c $^ -o $@ $(LIBS)

test/test_*.c: 
	@touch ./$@

test/test_runners/test_*_runner.c: 
	@touch ./$@
