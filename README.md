# webcfg

webcfg is the client implementation of webconfig.

[![Apache V2 License](http://img.shields.io/badge/license-Apache%20V2-blue.svg)](https://github.com/rdkcentral/webcfg/blob/develop/LICENSE)
[![GitHub release](https://img.shields.io/github/release/rdkcentral-org/webcfg.svg)](CHANGELOG.md)


# Building and Testing Instructions

```
mkdir build
cd build
cmake ..
make
make test
```
# To run webconfig as a standalone binary

```
mkdir build
cd build
cmake .. -DWEBCONFIG_BIN_SUPPORT:BOOL=true
make
make test
```
