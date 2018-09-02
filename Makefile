all: all-release

cmake-debug-static:
	mkdir -p build/debug
	cd build/debug && cmake -D STATIC=ON -D CMAKE_BUILD_TYPE=Debug ../..

build-debug-static: cmake-debug-static
	cd build/debug && $(MAKE)

cmake-debug:
	mkdir -p build/debug
	cd build/debug && cmake -D CMAKE_BUILD_TYPE=Debug ../..

build-debug: cmake-debug
	cd build/debug && $(MAKE)

test-debug: build-debug
	cd build/debug && $(MAKE) test

all-debug: build-debug

cmake-release-static:
	mkdir -p build/release
	cd build/release && cmake -D STATIC=ON -D CMAKE_BUILD_TYPE=Release ../..

build-release-static: cmake-release-static
	cd build/release && $(MAKE)

cmake-release:
	mkdir -p build/release
	cd build/release && cmake -D CMAKE_BUILD_TYPE=Release ../..

build-release: cmake-release
	cd build/release && $(MAKE)

test-release: build-release
	cd build/release && $(MAKE) test

all-release: build-release

clean:
	rm -rf build

tags:
	ctags -R --sort=1 --c++-kinds=+p --fields=+iaS --extra=+q --language-force=C++ src contrib tests/gtest

.PHONY: all cmake-debug build-debug test-debug all-debug cmake-release-static build-release-static cmake-release build-release test-release all-release clean tags
