set(ccache_url "https://github.com/cristianadam/ccache/releases/download/v$ENV{CCACHE_VERSION}/${{ runner.os }}.tar.xz")

file(DOWNLOAD "${ccache_url}" ./ccache.tar.xz SHOW_PROGRESS)

execute_process(COMMAND ${CMAKE_COMMAND} -E tar xvf ./ccache.tar.xz)