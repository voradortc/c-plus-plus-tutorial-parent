ENV=$1
BASEDIR=$(dirname $0)

if [ 'dev' = $ENV ]; then
    conan install "${BASEDIR}" -s build_type=Debug -if "${BASEDIR}/build/dev" && conan build "${BASEDIR}" -bf "${BASEDIR}/build/dev"
    exit
fi

if [ 'prd' = $ENV ]; then
    conan install "${BASEDIR}" -s build_type=Release -if "${BASEDIR}/build/prd" && conan build "${BASEDIR}" -bf "${BASEDIR}/build/prd"
    exit
fi

echo 'Unknown environment '\'${ENV}\'', please use one of: dev or prd'