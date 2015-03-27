%module pyupm_i2c
%include "../upm.i"
%include "../carrays_int16_t.i"
%include "../carrays_float.i"

%typemap(out) int16_t * {
    $result = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_int16Array, 0 | 0 );
}

%typemap(out) float * {
    $result = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_floatArray, 0 | 0 );
}

%feature("autodoc", "3");

#ifdef DOXYGEN
%include "i2c_doc.i"
#endif

%include "../../include/i2c.h"
%{
    #include "../../include/i2c.h"
%}
