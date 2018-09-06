"""
setup.py
"""
#! /usr/bin/env python

from distutils.core import *
from distutils      import sysconfig

import numpy

try:
    numpy_include = numpy.get_include()
except AttributeError:
    numpy_include = numpy.get_numpy_include()
setup(name = "RS255", 
      version = "1.0", 
      ext_modules = [
          Extension(
              "_RS255", 
              sources=["RS255_wrap.cxx", 
                       "Berlekamp.cpp",
                       "Euclidean.cpp",
                       "GF256/GF256.cpp",
                       "GF256/GF256_poly.cpp",
                       "GF256/GF256_num_list.cpp"],
              extra_compile_args = ['-std=c++11'],
              include_dirs=["GF256",
			    numpy_include],
              ),
      ],
      py_modules=['RS255']
     )
"""
"""
