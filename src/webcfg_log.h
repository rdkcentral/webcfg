/*
 * Copyright 2020 Comcast Cable Communications Management, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _WEBCONFIG_LOG_H_
#define _WEBCONFIG_LOG_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#if ! defined(DEVICE_EXTENDER)
#include <cimplog.h>
#endif

#define WEBCFG_LOGGING_MODULE                     "WEBCONFIG"
/**
 * @brief Enables or disables debug logs.
 */
#if defined(BUILD_YOCTO) && ! defined(DEVICE_EXTENDER)

#define WEBCFG_RDK_LOGGING_MODULE                 "LOG.RDK.WEBCONFIG"

#define WebConfigLog(...)       __cimplog_rdk_generic(WEBCFG_RDK_LOGGING_MODULE, WEBCFG_LOGGING_MODULE, LEVEL_INFO, __VA_ARGS__)

#ifdef WEBCONFIG_BIN_SUPPORT

#define WebcfgError(...)	cimplog_error(WEBCFG_LOGGING_MODULE, __VA_ARGS__)
#define WebcfgInfo(...)		cimplog_info(WEBCFG_LOGGING_MODULE, __VA_ARGS__)
#define WebcfgDebug(...)	cimplog_debug(WEBCFG_LOGGING_MODULE, __VA_ARGS__)

#else

#define WebcfgError(...)	__cimplog_rdk_generic(WEBCFG_RDK_LOGGING_MODULE, WEBCFG_LOGGING_MODULE, LEVEL_ERROR, __VA_ARGS__)
#define WebcfgInfo(...)		__cimplog_rdk_generic(WEBCFG_RDK_LOGGING_MODULE, WEBCFG_LOGGING_MODULE, LEVEL_INFO, __VA_ARGS__)
#define WebcfgDebug(...)	__cimplog_rdk_generic(WEBCFG_RDK_LOGGING_MODULE, WEBCFG_LOGGING_MODULE, LEVEL_DEBUG, __VA_ARGS__)

#endif

#else
#define WebConfigLog(...)       printf(__VA_ARGS__)

#define WebcfgError(...)	printf(__VA_ARGS__)
#define WebcfgInfo(...)		printf(__VA_ARGS__)
#define WebcfgDebug(...)	printf(__VA_ARGS__)

#endif



#endif /* _WEBCONFIG_LOG_H_ */
