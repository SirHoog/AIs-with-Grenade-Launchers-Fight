# Install script for directory: C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/xtensor" TYPE FILE FILES
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xaccessible.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xaccumulator.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xadapt.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xarray.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xassign.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xaxis_iterator.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xaxis_slice_iterator.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xblockwise_reducer.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xblockwise_reducer_functors.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xbroadcast.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xbuffer_adaptor.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xbuilder.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xchunked_array.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xchunked_assign.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xchunked_view.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xcomplex.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xcontainer.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xcsv.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xdynamic_view.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xeval.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xexception.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xexpression.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xexpression_holder.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xexpression_traits.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xfixed.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xfunction.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xfunctor_view.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xgenerator.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xhistogram.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xindex_view.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xinfo.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xio.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xiterable.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xiterator.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xjson.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xlayout.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xmanipulation.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xmasked_view.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xmath.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xmime.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xmultiindex_iterator.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xnoalias.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xnorm.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xnpy.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xoffset_view.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xoperation.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xoptional.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xoptional_assembly.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xoptional_assembly_base.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xoptional_assembly_storage.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xpad.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xrandom.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xreducer.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xrepeat.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xscalar.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xsemantic.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xset_operation.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xshape.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xslice.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xsort.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xstorage.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xstrided_view.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xstrided_view_base.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xstrides.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xtensor.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xtensor_config.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xtensor_forward.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xtensor_simd.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xutils.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xvectorize.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xview.hpp"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/lib/xtensor/include/xtensor/xview_utils.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor" TYPE FILE FILES
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtensor/xtensorConfig.cmake"
    "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtensor/xtensorConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor/xtensorTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor/xtensorTargets.cmake"
         "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtensor/CMakeFiles/Export/0f2a327e949144b0b747c96acb1eb12f/xtensorTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor/xtensorTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor/xtensorTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor" TYPE FILE FILES "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtensor/CMakeFiles/Export/0f2a327e949144b0b747c96acb1eb12f/xtensorTargets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" TYPE FILE FILES "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/lib/xtensor/xtensor.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build/xtensor.hpp")
endif()

