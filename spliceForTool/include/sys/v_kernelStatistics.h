/*
 *                         Vortex OpenSplice
 *
 *   This software and documentation are Copyright 2006 to  ADLINK
 *   Technology Limited, its affiliated companies and licensors. All rights
 *   reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef V_KERNELSTATISTICS_H
#define V_KERNELSTATISTICS_H

/** \file kernel/include/v_kernelStatistics.h
 *  \brief This file defines the interface
 *
 */

#include "v_kernel.h"
#include "os_if.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

#define v_kernelStatistics(s) \
        (C_CAST(s,v_kernelStatistics))

OS_API v_kernelStatistics
v_kernelStatisticsNew(
    v_kernel k);

OS_API void
v_kernelStatisticsInit(
    v_kernelStatistics _this);

OS_API void
v_kernelStatisticsDeinit(
    v_kernelStatistics _this);

OS_API void
v_kernelStatisticsFree(
    v_kernelStatistics _this);

#undef OS_API

#endif
