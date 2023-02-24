file(TO_CMAKE_PATH "$ENV{GITHUB_WORKSPACE}" ccache_basedir)
set(ENV{CCACHE_BASEDIR} "${ccache_basedir}")
set(ENV{CCACHE_DIR} "${ccache_basedir}/.ccache")
execute_process(COMMAND ccache -s)