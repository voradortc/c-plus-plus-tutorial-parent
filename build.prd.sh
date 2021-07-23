BASEDIR=$(dirname $0)
cmake -S "${BASEDIR}" -B "${BASEDIR}/build/prd" -DCMAKE_BUILD_TYPE=Release && cmake --build "${BASEDIR}/build/prd"