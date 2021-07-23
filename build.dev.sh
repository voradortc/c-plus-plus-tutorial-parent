BASEDIR=$(dirname $0)
cmake -S "${BASEDIR}" -B "${BASEDIR}/build/dev" -DCMAKE_BUILD_TYPE=Debug && cmake --build "${BASEDIR}/build/dev"