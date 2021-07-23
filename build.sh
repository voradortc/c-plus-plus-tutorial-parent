ENV=$1
BASEDIR=$(dirname $0)

if [ 'dev' = $ENV ]; then
    cmake -S "${BASEDIR}" -B "${BASEDIR}/build/dev" -DCMAKE_BUILD_TYPE=Debug && cmake --build "${BASEDIR}/build/dev"
    exit
fi

if [ 'prd' = $ENV ]; then
    cmake -S "${BASEDIR}" -B "${BASEDIR}/build/prd" -DCMAKE_BUILD_TYPE=Release && cmake --build "${BASEDIR}/build/prd"
    exit
fi

echo 'Unknown environment '\'${ENV}\'', please use one of: dev or prd'