%module jsupm_i2c
%include "../upm.i"
%include "../carrays_int16_t.i"
%include "../carrays_float.i"

%{
    #include "i2c.h"
%}

%typemap(out) int16_t * {
    $result = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_int16Array, 0 | 0 );
}

%typemap(out) float * {
    $result = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_floatArray, 0 | 0 );
}

%include "../../include/i2c.h"

%include <carrays.i>
