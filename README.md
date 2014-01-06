tinygl-for-vp
=============

This is a version of the TinyGL library and Gears example modified to run on a Vista virtual prototype simulator.

Building Requirements
=========================

You will need the following in your PATH:

- An ARM EABI toolchain. The Sourcery CodeBench ARM EABI toolchain will work fine.

- An installation of Vista.

Building Software-Only Unaccelerated vs GPU Accelerated Implementations
=========================

By default, invoking make will build a software-only unaccelerated
gears.axf executable.

To get the GPU accelerated implementation to build, you must set these
two environment variables before invoking make.

- GPU=1

- HWZERO=1

A command line build invocation would look like:

	 GPU=1 HWZERO=1 make

