.PHONY: build  memtest  tests

all:   build memtest  tests

check:
	./linters/run.sh
memtest:
	./memtest/memtest.sh