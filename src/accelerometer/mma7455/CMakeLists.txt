set (libname "mma7455")
set (libdescription "upm MMA7455")
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
set (module_src ${Accelerometer_src} ${I2C_src} ${libname}.cxx)
set (module_h ${Accelerometer_inc} ${I2C_inc} ${libname}.h)

upm_module_init()
