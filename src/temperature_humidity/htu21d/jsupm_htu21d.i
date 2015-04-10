%module jsupm_htu21d
%include "upm.i"

%{
    #include "htu21d.h"
%}

%include "temperature.h"
%include "humidity.h"
%include "htu21d.h"
