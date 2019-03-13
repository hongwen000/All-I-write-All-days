from distutils.core import setup, Extension
cos_module = Extension('cos_module', sources=['cos_module.c'])
setup(ext_modules=[cos_module])