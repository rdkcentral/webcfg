## Origin

This repository is based on the original
[webcfg](https://github.com/xmidt-org/webcfg) source code
maintained under the xmidt-org organization. The code was copied into the
rdkcentral organization, where ongoing maintenance and development now take place.

- Original project: https://github.com/xmidt-org/webcfg
- Current repository: https://github.com/rdkcentral/webcfg

[![Build Status](https://github.com/rdkcentral/webcfg/workflows/CI/badge.svg)](https://github.com/rdkcentral/webcfg/actions)
[![Apache V2 License](http://img.shields.io/badge/license-Apache%20V2-blue.svg)](https://github.com/rdkcentral/webcfg/blob/develop/LICENSE)

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
