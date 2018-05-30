EXPERIMENTAL C++ code, based on the phase 1 sources.

Of note, each discrete item exists in its own subdirectory of the 'packages' directory. Any dependencies are noted in the CMakeLists.txt file which is in the same directory as the .h and .cpp files.
to compile (all) sources, go to /.../SCAVE2/dev/src/cpp/scripts, and run the following shell script:
...
	./build.sh
...
tests are included in each main.cpp file in the subdirectories, which can be run by the
...
	./test.sh
...
shell script. Or, each individual test can be run in the cpp/scripts/bin directory.


--NOTE--
The code is not fully-functional and only serves as a template.
Next steps:
	[ ] flesh out serial to actually read/write from /dev/ttyACM*
	[ ] rework the logic in tachometer::read
	[ ] perhaps create a ./run directory for the code to be run together instead of (in addition to) discrete packages
