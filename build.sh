ENV=$1
BASEDIR=$(dirname $0)

if [ 'dev' = $ENV ]; then
    conan install "${BASEDIR}" -s 'build_type=Release' -s '&:build_type=Debug' -of "${BASEDIR}/build/dev" && conan build "${BASEDIR}" -of "${BASEDIR}/build/dev"
    exit
fi

if [ 'prd' = $ENV ]; then
    conan install "${BASEDIR}" -s 'build_type=Release' -s '&:build_type=Release' -of "${BASEDIR}/build/prd" && conan build "${BASEDIR}" -of "${BASEDIR}/build/prd"
    exit
fi

echo 'Unknown environment '\'${ENV}\'', please use one of: dev or prd'