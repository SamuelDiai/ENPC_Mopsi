import os, sys

from distutils.core import setup, Extension
from distutils import sysconfig
import numpy as np

cpp_args = ['-std=c++11', '-stdlib=libc++', '-mmacosx-version-min=10.7']

ext_modules = [
               Extension(
                         'wrap',
                         ['funcs.cpp', 'wrap.cpp','Trajectoire.cpp'],
                         include_dirs = ['np.get_include()','pybind11/stl.h'],
                         language='c++',
                         extra_compile_args = cpp_args,
                         ),
               ]

setup(
      name='wrap',
      version='0.0.1',
      author='Cliburn Chan',
      author_email='cliburn.chan@duke.edu',
      description='Example',
      ext_modules=ext_modules,
      )
