%module jsupm_mma7455
%include "upm.i"

%{
    #include "mma7455.h"
%}

%include "i2c.h"
%include "accelerometer.h"
%include "mma7455.h"
