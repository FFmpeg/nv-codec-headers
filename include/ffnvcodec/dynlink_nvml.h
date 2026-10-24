/*
 * This copyright notice applies to this header file only:
 *
 * Copyright (c) 2026
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the software, and to permit persons to whom the
 * software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#if !defined(FFNV_DYNLINK_NVML_H) && !defined(NVML_API_VERSION)
#define FFNV_DYNLINK_NVML_H

typedef enum nvmlReturn_enum {
    NVML_SUCCESS                   = 0,
    NVML_ERROR_UNINITIALIZED       = 1,
    NVML_ERROR_INVALID_ARGUMENT    = 2,
    NVML_ERROR_NOT_SUPPORTED       = 3,
    NVML_ERROR_NO_PERMISSION       = 4,
    NVML_ERROR_ALREADY_INITIALIZED = 5,
    NVML_ERROR_NOT_FOUND           = 6,
    NVML_ERROR_INSUFFICIENT_SIZE   = 7,
    NVML_ERROR_DRIVER_NOT_LOADED   = 9,
    NVML_ERROR_LIBRARY_NOT_FOUND   = 12,
    NVML_ERROR_FUNCTION_NOT_FOUND  = 13,
    NVML_ERROR_UNKNOWN             = 999
} nvmlReturn_t;

#define NVML_INIT_FLAG_NO_GPUS   1
#define NVML_INIT_FLAG_NO_ATTACH 2

#define NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE 80
#define NVML_SYSTEM_NVML_VERSION_BUFFER_SIZE   80
#define NVML_DEVICE_UUID_V2_BUFFER_SIZE        96
#define NVML_DEVICE_NAME_V2_BUFFER_SIZE        96

#define NVML_DEVICE_ARCH_KEPLER    2
#define NVML_DEVICE_ARCH_MAXWELL   3
#define NVML_DEVICE_ARCH_PASCAL    4
#define NVML_DEVICE_ARCH_VOLTA     5
#define NVML_DEVICE_ARCH_TURING    6
#define NVML_DEVICE_ARCH_AMPERE    7
#define NVML_DEVICE_ARCH_ADA       8
#define NVML_DEVICE_ARCH_HOPPER    9
#define NVML_DEVICE_ARCH_BLACKWELL 10
#define NVML_DEVICE_ARCH_UNKNOWN   0xffffffff

typedef struct nvmlDevice_st *nvmlDevice_t;
typedef unsigned int nvmlDeviceArchitecture_t;

typedef enum nvmlEncoderQueryType_enum {
    NVML_ENCODER_QUERY_H264    = 0x00,
    NVML_ENCODER_QUERY_HEVC    = 0x01,
    NVML_ENCODER_QUERY_AV1     = 0x02,
    NVML_ENCODER_QUERY_UNKNOWN = 0xFF
} nvmlEncoderType_t;

typedef struct nvmlEncoderSessionInfo_st {
    unsigned int sessionId;
    unsigned int pid;
    unsigned int vgpuInstance;
    nvmlEncoderType_t codecType;
    unsigned int hResolution;
    unsigned int vResolution;
    unsigned int averageFps;
    unsigned int averageLatency;
} nvmlEncoderSessionInfo_t;

typedef nvmlReturn_t tnvmlInit_v2(void);
typedef nvmlReturn_t tnvmlInitWithFlags(unsigned int flags);
typedef nvmlReturn_t tnvmlShutdown(void);
typedef const char *tnvmlErrorString(nvmlReturn_t result);
typedef nvmlReturn_t tnvmlSystemGetDriverVersion(char *version, unsigned int length);
typedef nvmlReturn_t tnvmlSystemGetNVMLVersion(char *version, unsigned int length);

typedef nvmlReturn_t tnvmlDeviceGetHandleByPciBusId_v2(const char *pciBusId, nvmlDevice_t *device);
typedef nvmlReturn_t tnvmlDeviceGetName(nvmlDevice_t device, char *name, unsigned int length);
typedef nvmlReturn_t tnvmlDeviceGetUUID(nvmlDevice_t device, char *uuid, unsigned int length);
typedef nvmlReturn_t tnvmlDeviceGetArchitecture(nvmlDevice_t device, nvmlDeviceArchitecture_t *arch);
typedef nvmlReturn_t tnvmlDeviceGetCurrPcieLinkGeneration(nvmlDevice_t device, unsigned int *currLinkGen);
typedef nvmlReturn_t tnvmlDeviceGetCurrPcieLinkWidth(nvmlDevice_t device, unsigned int *currLinkWidth);
typedef nvmlReturn_t tnvmlDeviceGetEncoderCapacity(nvmlDevice_t device, nvmlEncoderType_t encoderQueryType, unsigned int *encoderCapacity);
typedef nvmlReturn_t tnvmlDeviceGetEncoderSessions(nvmlDevice_t device, unsigned int *sessionCount, nvmlEncoderSessionInfo_t *sessionInfos);
typedef nvmlReturn_t tnvmlDeviceGetEncoderUtilization(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs);

#endif
