#
# Print a message only if the `VERBOSE_OUTPUT` option is on
#

function(verbose_message content)
    if(XSTLVerboseOutput)
			message(STATUS ${content})
    endif()
endfunction()

##################################################################################
##################################################################################

#
# Add a target for formating the project using `clang-format` (i.e: cmake --build build --target clang-format)
#

function(add_clang_format_target)
    if(NOT ${PROJECT_NAME}_CLANG_FORMAT_BINARY)
			find_program(${PROJECT_NAME}_CLANG_FORMAT_BINARY clang-format)
    endif()

    if(${PROJECT_NAME}_CLANG_FORMAT_BINARY)
			if(XSTLBuildExe)
				add_custom_target(clang-format
						COMMAND ${${PROJECT_NAME}_CLANG_FORMAT_BINARY}
						-i ${XSTL_SOURCE_FILES} ${XSTL_HEADER_FILES}
						WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
			elseif(XSTLBuildHeadersOnly)
				add_custom_target(clang-format
						COMMAND ${${PROJECT_NAME}_CLANG_FORMAT_BINARY}
						-i ${headers}
						WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
			else()
				add_custom_target(clang-format
						COMMAND ${${PROJECT_NAME}_CLANG_FORMAT_BINARY}
						-i ${XSTL_SOURCE_FILES} ${XSTL_HEADER_FILES}
						WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
			endif()

			message(STATUS "Format the project using the `clang-format` target (i.e: cmake --build build --target clang-format).\n")
    endif()
endfunction()
