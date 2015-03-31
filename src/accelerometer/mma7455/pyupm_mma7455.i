%module pyupm_mma7455
%include "upm.i"

%feature("autodoc", "3");

%include "i2c.h"
%{
    #include "i2c.h"
%}

%include "accelerometer.h"
%{
    #include "accelerometer.h"
%}

%include "mma7455.h"
%{
    #include "mma7455.h"
%}
