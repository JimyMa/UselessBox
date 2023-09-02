#include <pybind11/numpy.h>     // NOLINT
#include <pybind11/pybind11.h>  // NOLINT
#include <pybind11/stl.h>       // NOLINT


# include "csrc/decode/Berlekamp_Decoder.hpp"
# include "csrc/decode/Euclidean_Decoder.hpp"

namespace py = pybind11;

PYBIND11_MODULE(rs_decoder_py, rs_decoder_py) {
  py::class_<Berlekamp_Decoder>(rs_decoder_py, "Berlekamp_Decoder")
      .def(py::init<int, std::vector<int>>())
      .def("Decode", [](Berlekamp_Decoder& self,
                        std::vector<int>& code) { self.Decode(code); });
}

