# NumCppConfig.cmake
# --------------------
#
# NumCpp cmake module.
# This module sets the following variables in your project::
#
#   NumCpp_FOUND - true if NumCpp found on the system
#   NumCpp_VERSION - NumCpp version in format Major.Minor.Release
#   NumCpp_INCLUDE_DIR - Directory where NumCpp headers are located.
#
# The following variables can be set to guide the search for this package::
#
#   NumCpp_DIR - CMake variable, set to directory containing this Config file
#   CMAKE_PREFIX_PATH - CMake variable, set to root directory of this package
#   PATH - environment variable, set to bin directory of this package
#

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was NumCppConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

if(NOT TARGET NumCpp::NumCpp)
    include("${CMAKE_CURRENT_LIST_DIR}/NumCppTargets.cmake")
    set_and_check(NumCpp_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include")
    check_required_components("NumCpp")

    if(NUMCPP_NO_USE_BOOST)
        set_property(TARGET NumCpp::NumCpp APPEND 
            PROPERTY 
            INTERFACE_COMPILE_DEFINITIONS
            NUMCPP_NO_USE_BOOST
        )
    else()
        find_package(Boost 1.68.0 REQUIRED COMPONENTS date_time)
        set_property(TARGET NumCpp::NumCpp APPEND 
            PROPERTY 
            INTERFACE_LINK_LIBRARIES 
            Boost::boost 
            $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:Boost::date_time>
        )
    endif()

    if(NUMCPP_USE_MULTITHREAD)
        set_property(TARGET NumCpp::NumCpp APPEND 
            PROPERTY 
            INTERFACE_COMPILE_DEFINITIONS
            NUMCPP_USE_MULTITHREAD
        )
        if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            find_package(TBB REQUIRED)
        endif()
        set_property(TARGET NumCpp::NumCpp APPEND 
            PROPERTY 
            INTERFACE_LINK_LIBRARIES  
            $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:TBB::tbb>
        )
    endif()

    if(NUMCPP_INCLUDE_PYBIND_PYTHON_INTERFACE OR NUMCPP_INCLUDE_BOOST_PYTHON_INTERFACE)
        find_package(Python REQUIRED
            COMPONENTS
            Interpreter
            Development.Module
        )

        set_property(TARGET NumCpp::NumCpp
            PROPERTY
            POSITION_INDEPENDENT_CODE ON
        )

        if(NUMCPP_INCLUDE_PYBIND_PYTHON_INTERFACE)
            find_package(pybind11 CONFIG REQUIRED)
            set_property(TARGET NumCpp::NumCpp APPEND 
                PROPERTY 
                INTERFACE_COMPILE_DEFINITIONS
                NUMCPP_INCLUDE_PYBIND_PYTHON_INTERFACE
            )
            set_property(TARGET NumCpp::NumCpp APPEND 
                PROPERTY 
                INTERFACE_LINK_LIBRARIES
                pybind11::module
            )
        endif()

        if(NUMCPP_INCLUDE_BOOST_PYTHON_INTERFACE)
            find_package(Boost 1.68.0 REQUIRED COMPONENTS python numpy)
            set_property(TARGET NumCpp::NumCpp APPEND 
                PROPERTY 
                INTERFACE_COMPILE_DEFINITIONS
                NUMCPP_INCLUDE_BOOST_PYTHON_INTERFACE
            )
            set_property(TARGET NumCpp::NumCpp APPEND 
                PROPERTY 
                INTERFACE_LINK_LIBRARIES 
                Boost::boost 
                $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:Boost::python>
                $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:Boost::numpy>
            )
        endif()

        set_property(TARGET NumCpp::NumCpp APPEND 
            PROPERTY 
            INTERFACE_LINK_LIBRARIES
            Python::Module
        )
    endif()

    message(STATUS "Found NumCpp: ${NumCpp_INCLUDE_DIR} (found version ${NumCpp_VERSION})")
endif()
