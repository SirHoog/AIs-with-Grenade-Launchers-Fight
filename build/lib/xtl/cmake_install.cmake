# Install script for directory: C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/AI_with_jetpack_and_grenade_launcher")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/msys64/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/xtl" TYPE FILE FILES
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xany.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xbasic_fixed_string.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xbase64.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xclosure.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xcompare.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xcomplex.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xcomplex_sequence.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xspan.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xspan_impl.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xdynamic_bitset.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xfunctional.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xhalf_float.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xhalf_float_impl.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xhash.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xhierarchy_generator.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xiterator_base.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xjson.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xmasked_value_meta.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xmasked_value.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xmeta_utils.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xmultimethods.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xoptional_meta.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xoptional.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xoptional_sequence.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xplatform.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xproxy_wrapper.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xsequence.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xsystem.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xtl_config.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xtype_traits.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xvariant.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xvariant_impl.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtl/include/xtl/xvisitor.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/xtl" TYPE FILE FILES
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtl/xtlConfig.cmake"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtl/xtlConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtl/xtlTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtl/xtlTargets.cmake"
         "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtl/CMakeFiles/Export/2fc63ec57839ed115fc15a5438bb5aec/xtlTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtl/xtlTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtl/xtlTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/xtl" TYPE FILE FILES "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtl/CMakeFiles/Export/2fc63ec57839ed115fc15a5438bb5aec/xtlTargets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" TYPE FILE FILES "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtl/xtl.pc")
endif()

