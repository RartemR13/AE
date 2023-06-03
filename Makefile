build-tests:
	mkdir build || true
	mkdir build/Debug || true
	cmake -B build/Debug -DCMAKE_BUILD_TYPE=Debug .
	cmake --build build/Debug

run-tests:
	cd build/Debug; \
		ctest