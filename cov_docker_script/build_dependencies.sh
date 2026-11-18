#!/bin/bash
#
# Copyright 2020 Comcast Cable Communications Management, LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

set -x
set -e
##############################
GITHUB_WORKSPACE="${PWD}"
ls -la ${GITHUB_WORKSPACE}
cd ${GITHUB_WORKSPACE}

############################
# Install CMake 3.22 or higher (required by CMakeLists.txt)
CMAKE_VERSION="3.22.6"
CMAKE_DIR="cmake-${CMAKE_VERSION}-linux-x86_64"

# Check if cmake needs upgrade
NEED_CMAKE_INSTALL=false
if ! command -v cmake &> /dev/null; then
    echo "CMake not found, will install ${CMAKE_VERSION}"
    NEED_CMAKE_INSTALL=true
else
    CURRENT_CMAKE_VERSION=$(cmake --version | head -n1 | awk '{print $3}')
    REQUIRED_VERSION="3.22"
    if [ "$(printf '%s\n' "$REQUIRED_VERSION" "$CURRENT_CMAKE_VERSION" | sort -V | head -n1)" != "$REQUIRED_VERSION" ]; then
        echo "Current CMake version $CURRENT_CMAKE_VERSION is less than required $REQUIRED_VERSION"
        NEED_CMAKE_INSTALL=true
    fi
fi

if [ "$NEED_CMAKE_INSTALL" = true ]; then
    echo "Installing CMake ${CMAKE_VERSION}..."
    wget -q https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/${CMAKE_DIR}.tar.gz
    tar -xzf ${CMAKE_DIR}.tar.gz
    cp -rf ${CMAKE_DIR}/bin/* /usr/local/bin/
    cp -rf ${CMAKE_DIR}/share/* /usr/local/share/
    rm -rf ${CMAKE_DIR} ${CMAKE_DIR}.tar.gz
    echo "CMake ${CMAKE_VERSION} installed successfully"
fi
