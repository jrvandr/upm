# Do not need any of this unless we're building a library for Accelerometer class
#set (libname "accelerometer")
#set (libdescription "libupm accelerometer base library")
include_directories (${PROJECT_SOURCE_DIR}/include)
#set (module_src ${libname}.cxx)
#set (module_h ${libname}.h)

#set (module_src ${Accelerometer_src} ${I2C_src})
#set (module_h ${Accelerometer_inc} ${I2C_inc})

# Don't need subdirlist since we don't intend on deriving from I2c
#subdirlist(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
#foreach(subdir ${SUBDIRS})
#    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
#        add_subdirectory(${subdir})
#    endif()
#endforeach()

#upm_module_init()
