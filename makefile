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
test: queue.test.out table.test.out
	@./queue.test.out
	@./table.test.out

.PHONY: memcheck
memcheck: test/*.c  $(SRCS) 
	@echo Compiling $@...
	@$(CC) $(ASANFLAGS) $(CFLAGS) $(SRCS) test/vendor/unity.c test/*.c -o memcheck.out $(LIBS)
	@./memcheck.out
	@echo "Memory check passed"

.PHONY: clean
clean:
	rm -rf build/*.o build/*.out build/*.out.dSYM

queue.test.out:  $(TEST_DIR)/test_queue.c $(TEST_RNS)/test_queue_runner.c
	@echo Compiling $@...
	@$(CC) $(CFLAGS) $(SRCS) test/vendor/unity.c $^ -o $@ $(LIBS)


table.test.out:  $(TEST_DIR)/test_table.c $(TEST_RNS)/test_table_runner.c
	@echo Compiling $@...
	@$(CC) $(CFLAGS) $(SRCS) test/vendor/unity.c $^ -o $@ $(LIBS)

test/test_queue.c: 
	@touch ./$@
test/test_table.c: 
	@touch ./$@
test/test_runners/test_queue_runner.c: 
	@touch ./$@
test/test_runners/test_table_runner.c: 
	@touch ./$@
