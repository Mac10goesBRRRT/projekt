ls
#Small scirpt to run the tests and generate the coverage report
#cleans artifacts before building
date
ceedling clean
ceedling gcov:all
ceedling utils:gcov
cd build/artifacts/gcov
xdg-open GcovCoverageResults.html
