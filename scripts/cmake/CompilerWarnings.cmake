# from here:
#
# https://github.com/lefticus/cppbestpractices/blob/master/02-Use_the_Tools_Avai
# lable.md
# Courtesy of Jason Turner

function(set_ci_project_warnings project_name)
   set(MSVC_CXXFLAGS
      /W4     # Baseline reasonable warnings
      /w14242 # 'identifier': conversion from 'type1' to 'type1', possible loss
            # of data
      /w14254 # 'operator': conversion from 'type1:field_bits' to
            # 'type2:field_bits', possible loss of data
      /w14263 # 'function': member function does not override any base class
            # virtual member function
      /w14265 # 'classname': class has virtual functions, but destructor is not
            # virtual instances of this class may not be destructed correctly
      /w14287 # 'operator': unsigned/negative constant mismatch
      /we4289 # nonstandard extension used: 'variable': loop control variable
            # declared in the for-loop is used outside the for-loop scope
      /w14296 # 'operator': expression is always 'boolean_value'
      /w14311 # 'variable': pointer truncation from 'type1' to 'type2'
      /w14545 # expression before comma evaluates to a function which is missing
            # an argument list
      /w14546 # function call before comma missing argument list
      /w14547 # 'operator': operator before comma has no effect; expected
            # operator with side-effect
      /w14549 # 'operator': operator before comma has no effect; did you intend
            # 'operator'?
      /w14555 # expression has no effect; expected expression with side- effect
      /w14619 # pragma warning: there is no warning number 'number'
      /w14640 # Enable warning on thread un-safe static member initialization
      /w14826 # Conversion from 'type1' to 'type_2' is sign-extended. This may
            # cause unexpected runtime behavior.
      /w14905 # wide string literal cast to 'LPSTR'
      /w14906 # string literal cast to 'LPWSTR'
      /w14928 # illegal copy-initialization; more than one user-defined
            # conversion has been implicitly applied
      /permissive- # standards conformance mode for MSVC compiler.
   )

   # Ignored Clang warnings:
   # -Wno-c++98-compat               The library targets C++11.
   # -Wno-c++98-compat-pedantic      The library targets C++11.
   # -Wno-deprecated-declarations    The library contains annotations for deprecated functions.
   # -Wno-extra-semi-stmt            The library uses std::assert which triggers this warning.
   # -Wno-padded                     We do not care about padding warnings.
   # -Wno-covered-switch-default     All switches list all cases and a default case.
   # -Wno-weak-vtables               The library is header-only.
   # -Wreserved-identifier           See https://github.com/onqtam/doctest/issues/536.

   set(CLANG_CXXFLAGS
      -Weverything
      -Wno-c++98-compat
      -Wno-c++98-compat-pedantic
      -Wno-deprecated-declarations
      -Wno-extra-semi-stmt
      -Wno-padded
      -Wno-covered-switch-default
      -Wno-weak-vtables
      -Wno-reserved-identifier
   )

   # Warning flags determined for GCC 13.0 (experimental) with https://github.com/nlohmann/gcc_flags:
   # Ignored GCC warnings:
   # -Wno-abi-tag                    We do not care about ABI tags.
   # -Wno-aggregate-return           The library uses aggregate returns.
   # -Wno-long-long                  The library uses the long long type to interface with system functions.
   # -Wno-namespaces                 The library uses namespaces.
   # -Wno-padded                     We do not care about padding warnings.
   # -Wno-system-headers             We do not care about warnings in system headers.
   # -Wno-templates                  The library uses templates.

   set(GCC_CXXFLAGS
      -pedantic
      --all-warnings
      --extra-warnings
      -W
      -WNSObject-attribute
      -Wno-abi-tag
      -Waddress
      -Waddress-of-packed-member
      -Wno-aggregate-return
      -Waggressive-loop-optimizations
      -Waligned-new=all
      -Wall
      -Walloc-zero
      -Walloca
      -Wanalyzer-double-fclose
      -Wanalyzer-double-free
      -Wanalyzer-exposure-through-output-file
      -Wanalyzer-file-leak
      -Wanalyzer-free-of-non-heap
      -Wanalyzer-malloc-leak
      -Wanalyzer-mismatching-deallocation
      -Wanalyzer-null-argument
      -Wanalyzer-null-dereference
      -Wanalyzer-possible-null-argument
      -Wanalyzer-possible-null-dereference
      -Wanalyzer-shift-count-negative
      -Wanalyzer-shift-count-overflow
      -Wanalyzer-stale-setjmp-buffer
      -Wanalyzer-tainted-allocation-size
      -Wanalyzer-tainted-array-index
      -Wanalyzer-tainted-divisor
      -Wanalyzer-tainted-offset
      -Wanalyzer-tainted-size
      -Wanalyzer-too-complex
      -Wanalyzer-unsafe-call-within-signal-handler
      -Wanalyzer-use-after-free
      -Wanalyzer-use-of-pointer-in-stale-stack-frame
      -Wanalyzer-use-of-uninitialized-value
      -Wanalyzer-va-arg-type-mismatch
      -Wanalyzer-va-list-exhausted
      -Wanalyzer-va-list-leak
      -Wanalyzer-va-list-use-after-va-end
      -Wanalyzer-write-to-const
      -Wanalyzer-write-to-string-literal
      -Warith-conversion
      -Warray-bounds=2
      -Warray-compare
      -Warray-parameter=2
      -Wattribute-alias=2
      -Wattribute-warning
      -Wattributes
      -Wbool-compare
      -Wbool-operation
      -Wbuiltin-declaration-mismatch
      -Wbuiltin-macro-redefined
      -Wc++0x-compat
      -Wc++11-compat
      -Wc++11-extensions
      -Wc++14-compat
      -Wc++14-extensions
      -Wc++17-compat
      -Wc++17-extensions
      -Wc++1z-compat
      -Wc++20-compat
      -Wc++20-extensions
      -Wc++23-extensions
      -Wc++2a-compat
      -Wcannot-profile
      -Wcast-align
      -Wcast-align=strict
      -Wcast-function-type
      -Wcast-qual
      -Wcatch-value=3
      -Wchar-subscripts
      -Wclass-conversion
      -Wclass-memaccess
      -Wclobbered
      -Wcomma-subscript
      -Wcomment
      -Wcomments
      -Wconditionally-supported
      -Wconversion
      -Wconversion-null
      -Wcoverage-invalid-line-number
      -Wcoverage-mismatch
      -Wcpp
      -Wctad-maybe-unsupported
      -Wctor-dtor-privacy
      -Wdangling-else
      -Wdangling-pointer=2
      -Wdate-time
      -Wdelete-incomplete
      -Wdelete-non-virtual-dtor
      -Wdeprecated
      -Wdeprecated-copy
      -Wdeprecated-copy-dtor
      -Wdeprecated-declarations
      -Wdeprecated-enum-enum-conversion
      -Wdeprecated-enum-float-conversion
      -Wdisabled-optimization
      -Wdiv-by-zero
      -Wdouble-promotion
      -Wduplicated-branches
      -Wduplicated-cond
      -Weffc++
      -Wempty-body
      -Wendif-labels
      -Wenum-compare
      -Wenum-conversion
      -Wexceptions
      -Wexpansion-to-defined
      -Wextra
      -Wextra-semi
      -Wfloat-conversion
      -Wfloat-equal
      -Wformat-diag
      -Wformat-overflow=2
      -Wformat-signedness
      -Wformat-truncation=2
      -Wformat=2
      -Wframe-address
      -Wfree-nonheap-object
      -Whsa
      -Wif-not-aligned
      -Wignored-attributes
      -Wignored-qualifiers
      -Wimplicit-fallthrough=5
      -Winaccessible-base
      -Winfinite-recursion
      -Winherited-variadic-ctor
      -Winit-list-lifetime
      -Winit-self
      -Winline
      -Wint-in-bool-context
      -Wint-to-pointer-cast
      -Winterference-size
      -Winvalid-imported-macros
      -Winvalid-memory-model
      -Winvalid-offsetof
      -Winvalid-pch
      -Wliteral-suffix
      -Wlogical-not-parentheses
      -Wlogical-op
      -Wno-long-long
      -Wlto-type-mismatch
      -Wmain
      -Wmaybe-uninitialized
      -Wmemset-elt-size
      -Wmemset-transposed-args
      -Wmisleading-indentation
      -Wmismatched-dealloc
      -Wmismatched-new-delete
      -Wmismatched-tags
      -Wmissing-attributes
      -Wmissing-braces
      -Wmissing-declarations
      -Wmissing-field-initializers
      -Wmissing-include-dirs
      -Wmissing-profile
      -Wmissing-requires
      -Wmissing-template-keyword
      -Wmultichar
      -Wmultiple-inheritance
      -Wmultistatement-macros
      -Wno-namespaces
      -Wnarrowing
      -Wnoexcept
      -Wnoexcept-type
      -Wnon-template-friend
      -Wnon-virtual-dtor
      -Wnonnull
      -Wnonnull-compare
      -Wnormalized=nfkc
      -Wnull-dereference
      -Wodr
      -Wold-style-cast
      -Wopenacc-parallelism
      -Wopenmp-simd
      -Woverflow
      -Woverlength-strings
      -Woverloaded-virtual
      -Wpacked
      -Wpacked-bitfield-compat
      -Wpacked-not-aligned
      -Wno-padded
      -Wparentheses
      -Wpedantic
      -Wpessimizing-move
      -Wplacement-new=2
      -Wpmf-conversions
      -Wpointer-arith
      -Wpointer-compare
      -Wpragmas
      -Wprio-ctor-dtor
      -Wpsabi
      -Wrange-loop-construct
      -Wredundant-decls
      -Wredundant-move
      -Wredundant-tags
      -Wregister
      -Wreorder
      -Wrestrict
      -Wreturn-local-addr
      -Wreturn-type
      -Wscalar-storage-order
      -Wsequence-point
      -Wshadow=compatible-local
      -Wshadow=global
      -Wshadow=local
      -Wshift-count-negative
      -Wshift-count-overflow
      -Wshift-negative-value
      -Wshift-overflow=2
      -Wsign-compare
      -Wsign-conversion
      -Wsign-promo
      -Wsized-deallocation
      -Wsizeof-array-argument
      -Wsizeof-array-div
      -Wsizeof-pointer-div
      -Wsizeof-pointer-memaccess
      -Wstack-protector
      -Wstrict-aliasing=3
      -Wstrict-null-sentinel
      -Wno-strict-overflow
      -Wstring-compare
      -Wstringop-overflow=4
      -Wstringop-overread
      -Wstringop-truncation
      -Wsubobject-linkage
      -Wsuggest-attribute=cold
      -Wsuggest-attribute=const
      -Wsuggest-attribute=format
      -Wsuggest-attribute=malloc
      -Wsuggest-attribute=noreturn
      -Wsuggest-attribute=pure
      -Wsuggest-final-methods
      -Wsuggest-final-types
      -Wsuggest-override
      -Wswitch
      -Wswitch-bool
      -Wswitch-default
      -Wswitch-enum
      -Wswitch-outside-range
      -Wswitch-unreachable
      -Wsync-nand
      -Wsynth
      -Wno-system-headers
      -Wtautological-compare
      -Wno-templates
      -Wterminate
      -Wtrampolines
      -Wtrigraphs
      -Wtrivial-auto-var-init
      -Wtsan
      -Wtype-limits
      -Wundef
      -Wuninitialized
      -Wunknown-pragmas
      -Wunreachable-code
      -Wunsafe-loop-optimizations
      -Wunused
      -Wunused-but-set-parameter
      -Wunused-but-set-variable
      -Wunused-const-variable=2
      -Wunused-function
      -Wunused-label
      -Wunused-local-typedefs
      -Wunused-macros
      -Wunused-parameter
      -Wunused-result
      -Wunused-value
      -Wunused-variable
      -Wuse-after-free=3
      -Wuseless-cast
      -Wvarargs
      -Wvariadic-macros
      -Wvector-operation-performance
      -Wvexing-parse
      -Wvirtual-inheritance
      -Wvirtual-move-assign
      -Wvla
      -Wvla-parameter
      -Wvolatile
      -Wvolatile-register-var
      -Wwrite-strings
      -Wzero-as-null-pointer-constant
      -Wzero-length-bounds
   )

   if (XSTLWarningsAsErrors)
      set(CLANG_CXXFLAGS ${CLANG_CXXFLAGS} -Werror)
       set(GCC_CXXFLAGS ${GCC_CXXFLAGS} -Werror)
      set(MSVC_CXXFLAGS ${MSVC_CXXFLAGS} /WX)
   endif()

   if(MSVC)
      set(PROJECT_WARNINGS ${MSVC_CXXFLAGS})
   elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
      set(PROJECT_WARNINGS ${CLANG_CXXFLAGS})
   elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set(PROJECT_WARNINGS ${GCC_CXXFLAGS})
   else()
      message(AUTHOR_WARNING "No compiler warnings set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
   endif()

   if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 6)
      # setl all GCC warnings avialable for gcc version > 6 
      set(GCC_CXXFLAGS 
         -Wpedantic
         -Wpedantic-errors
         -Wall
         -Wextra
         -Wabi
         -Wabi-tag
         -Walloc-zero
         -no-coverage-mismatch
      )
      
   elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4)
      set(CLANG_CXXFLAGS
         -Wpedantic
         -Wpedantic-errors
         -Wall
         -Wextra
         -Wabi
         -Wabi-tag
         -Walloc-zero
         -no-coverage-mismatch
      )
   else()
      message(AUTHOR_WARNING "No compiler warnings set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
   endif()

   if(XSTLBuildHeadersOnly)
      target_compile_options(${project_name} INTERFACE ${PROJECT_WARNINGS})
   else()
      target_compile_options(${project_name} PUBLIC ${PROJECT_WARNINGS})
   endif()

   if(NOT TARGET ${project_name})
      message(AUTHOR_WARNING "${project_name} is not a target, thus no compiler warning were added.")
   endif()
endfunction()

function(set_project_warnings project_name)
  set(MSVC_WARNINGS
      /W4     # Baseline reasonable warnings
      /w14242 # 'identifier': conversion from 'type1' to 'type1', possible loss
              # of data
      /w14254 # 'operator': conversion from 'type1:field_bits' to
              # 'type2:field_bits', possible loss of data
      /w14263 # 'function': member function does not override any base class
              # virtual member function
      /w14265 # 'classname': class has virtual functions, but destructor is not
              # virtual instances of this class may not be destructed correctly
      /w14287 # 'operator': unsigned/negative constant mismatch
      /we4289 # nonstandard extension used: 'variable': loop control variable
              # declared in the for-loop is used outside the for-loop scope
      /w14296 # 'operator': expression is always 'boolean_value'
      /w14311 # 'variable': pointer truncation from 'type1' to 'type2'
      /w14545 # expression before comma evaluates to a function which is missing
              # an argument list
      /w14546 # function call before comma missing argument list
      /w14547 # 'operator': operator before comma has no effect; expected
              # operator with side-effect
      /w14549 # 'operator': operator before comma has no effect; did you intend
              # 'operator'?
      /w14555 # expression has no effect; expected expression with side- effect
      /w14619 # pragma warning: there is no warning number 'number'
      /w14640 # Enable warning on thread un-safe static member initialization
      /w14826 # Conversion from 'type1' to 'type_2' is sign-extended. This may
              # cause unexpected runtime behavior.
      /w14905 # wide string literal cast to 'LPSTR'
      /w14906 # string literal cast to 'LPWSTR'
      /w14928 # illegal copy-initialization; more than one user-defined
              # conversion has been implicitly applied
      /permissive- # standards conformance mode for MSVC compiler.
  )

  set(CLANG_WARNINGS
      -Wall
      -Wextra  # reasonable and standard
      -Wshadow # warn the user if a variable declaration shadows one from a
               # parent context
      -Wnon-virtual-dtor # warn the user if a class with virtual functions has a
                         # non-virtual destructor. This helps catch hard to
                         # track down memory errors
      -Wold-style-cast # warn for c-style casts
      -Wcast-align     # warn for potential performance problem casts
      -Wunused         # warn on anything being unused
      -Woverloaded-virtual # warn if you overload (not override) a virtual
                           # function
      -Wpedantic   # warn if non-standard C++ is used
      -Wconversion # warn on type conversions that may lose data
      -Wsign-conversion  # warn on sign conversions
      -Wnull-dereference # warn if a null dereference is detected
      -Wdouble-promotion # warn if float is implicit promoted to double
      -Wformat=2 # warn on security issues around functions that format output
                 # (ie printf)
  )

  if (XSTLWarningsAsErrors)
    set(CLANG_WARNINGS ${CLANG_WARNINGS} -Werror)
    set(MSVC_WARNINGS ${MSVC_WARNINGS} /WX)
  endif()

  set(GCC_WARNINGS
      ${CLANG_WARNINGS}
      -Wmisleading-indentation # warn if indentation implies blocks where blocks
                               # do not exist
      -Wduplicated-cond # warn if if / else chain has duplicated conditions
      -Wduplicated-branches # warn if if / else branches have duplicated code
      -Wlogical-op   # warn about logical operations being used where bitwise were
                     # probably wanted
      -Wuseless-cast # warn if you perform a cast to the same type
      -ggdb3 # for debugging, to specify line numbers when used with valgrind
  )

  if(MSVC)
    set(PROJECT_WARNINGS ${MSVC_WARNINGS})
  elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    set(PROJECT_WARNINGS ${CLANG_WARNINGS})
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(PROJECT_WARNINGS ${GCC_WARNINGS})
  else()
    message(AUTHOR_WARNING "No compiler warnings set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
  endif()

  if(XSTLBuildHeadersOnly)
        target_compile_options(${project_name} INTERFACE ${PROJECT_WARNINGS})
  else()
        target_compile_options(${project_name} PUBLIC ${PROJECT_WARNINGS})
  endif()

  if(NOT TARGET ${project_name})
    message(AUTHOR_WARNING "${project_name} is not a target, thus no compiler warning were added.")
  endif()
endfunction()