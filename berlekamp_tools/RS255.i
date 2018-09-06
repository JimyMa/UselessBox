%module RS255
%include "std_vector.i"
%{
    #define SWIG_FILE_WITH_INIT
    #include "Berlekamp.h"
    #include "Euclidean.hpp"
    #include <zconf.h>
%}
%include "numpy.i"

%init %{
    import_array();
%}
%apply (unsigned short IN_ARRAY1[ANY]) {(u_int16_t before[255])}
%apply (unsigned short INPLACE_ARRAY1[ANY]){(u_int16_t after[255])}
%inline %{
    void berlekamp_decoder(unsigned int t, u_int16_t before[255], u_int16_t after[255]) {
        BerlekampDecoder(t, before, after);
    }
%}
%inline %{
void euclidean_decoder(unsigned int t, u_int16_t before[255], u_int16_t after[255]) {
    EuclideanDecoder(t, before, after);
}
%}
