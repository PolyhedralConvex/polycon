# PolyCon

PolyCon is a set of libraries to handle polyhedral convex functions, represented as the maximum of a set of affine functions, with optional boundaries.

It supports common expected mathematical operations, like the legendre transformation, infimal convolution, ...

Internally, it is written in C++ and highly optimized (use of SIMD/SIMT instructions, `O(N log N)` algorithms where possible, ...).

Currently, there are bindings C++ and Python, but more languages are in the pipeline (feel free to ask if your favorite language is not represented :) ).

Here is the documentation for
* [the Python bindings](src/python/README.md)
* [the C++ bindings](src/c++/README.md)
