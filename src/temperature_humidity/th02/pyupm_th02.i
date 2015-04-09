%module pyupm_th02
%include "upm.i"

%feature("autodoc", "3");

%include "temperature.h"
%{
    #include "temperature.h"
%}
%include "humidity.h"
%{
    #include "humidity.h"
%}
%include "th02.h"
%{
    #include "th02.h"
%}
