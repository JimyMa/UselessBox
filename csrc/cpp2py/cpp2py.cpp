#include <pybind11/numpy.h>     // NOLINT
#include <pybind11/pybind11.h>  // NOLINT
#include <pybind11/stl.h>       // NOLINT

#include "csrc/decode/Berlekamp_Decoder.hpp"
#include "csrc/decode/Euclidean_Decoder.hpp"

namespace py = pybind11;

PYBIND11_MODULE(rs_decoder_py, rs_decoder_py) {
  py::class_<Berlekamp_Decoder>(rs_decoder_py, "Berlekamp_Decoder")
      .def(py::init<int>())
      .def("Decode",
           [](Berlekamp_Decoder& self, std::vector<int32_t> code) -> py::array {
             std::vector<int32_t> decode_code = self.Decode(code);
             return py::cast(decode_code);
           });
}
