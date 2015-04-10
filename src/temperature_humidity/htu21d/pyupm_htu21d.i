%module pyupm_htu21d
%include "upm.i"

%feature("autodoc", "3");

#ifdef DOXYGEN
%include "htu21d_doc.i"
#endif

%include "temperature.h"
%{
    #include "temperature.h"
%}
%include "humidity.h"
%{
    #include "humidity.h"
%}
%include "htu21d.h"
%{
    #include "htu21d.h"
%}
