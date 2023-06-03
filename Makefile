build-tests:
	mkdir build/Debug || true
	cmake build/Debug -DCMAKE_BUILD_TYPE=Debug .
	cmake --build build/Debug

run-tests:
	cd build/Debug; \
		ctest