set (libname "mma7660")
set (libdescription "upm mma7660 I2C 3-axis digital accelermeter (1.5g)")
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
set (module_src ${Accelerometer_src} ${I2C_src} ${libname}.cxx)
set (module_h ${Accelerometer_inc} ${I2C_inc} ${libname}.h)

upm_module_init()
