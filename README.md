[![Build status](https://ci.appveyor.com/api/projects/status/ab24pw2wpsklk064?svg=true)](https://ci.appveyor.com/project/lewis-weinberger/build-sdl2)

This is an exercise in automating the building and release of software projects. The goal is to use continuous integration (provided by [AppVeyor](https://www.appveyor.com/)) to build a simple cross-platform (Windows, MacOS, Linux) program with [SDL2](https://www.libsdl.org/), and automatically upload successfully compiled binaries to [GitHub Releases](https://help.github.com/en/github/administering-a-repository/managing-releases-in-a-repository).

## Details

We are going to use [CMake](https://cmake.org/) and [ninja](https://ninja-build.org/) for our build system. The application, [`main.c`](./main.c), is a small program written in C which presents the user with a blank window until closed.

We will bundle the application slightly differently on each platform, but dynamically link against SDL2 in all cases ([...as is recommendend](https://hg.libsdl.org/SDL/file/default/docs/README-dynapi.md)).

1. **Windows**: We will provide an executable (`.exe`) and all required dynamic library files (`.dll`), as well as the licenses. Compiling with `MSVC` toolchain.

2. **MacOS**: We will provide an app bundle (`.app`), which includes the SDL2 frameworks (containing the dynamic library files `.dylib`) and license files alongside the binary executable. Compiling with `AppleClang` toolchain.

3. **Linux**: We will provide only the binary executable and license file. Linux users will need to install the SDL2 shared library through their favourite package manager, or manually from source. Compiling with `GNU` toolchain.

AppVeyor has functionality to upload build artifacts to GitHub as releases. We will setup the following basic automation pipeline: pushing a new tag to GitHub will initiate an AppVeyor build that will upload a release under that tag label. Note also that AppVeyor has a [free service](https://www.appveyor.com/pricing/) for open source software.

## To-Do

- Include Windows DLL alongside executable.
- Download and use framework instead of homebrew on MacOS, so that an app bundle can be created with framework.
- Set up proper packaging with `cpack`?

## Licensing

[MIT LICENSE](./LICENSE)

Note that releases which ship a copy of the SDL2 library will also provide its license.

## Further resources

See also [SRombauts/sdlman](https://github.com/SRombauts/sdlman), and for general projects using CMake with SDL2 see [Trenki's Dev Blog](https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/).