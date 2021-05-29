//===---- device_environment.h - OpenMP GPU device environment --- CUDA -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Global device environment
//
//===----------------------------------------------------------------------===//

#ifndef _OMPTARGET_DEVICE_ENVIRONMENT_H_
#define _OMPTARGET_DEVICE_ENVIRONMENT_H_

#include "target_impl.h"
//#include "omptarget.h"

////////////////////////////////////////////////////////////////////////////////
// device stack trace components
////////////////////////////////////////////////////////////////////////////////
typedef struct ring_buffer_t {
  int32_t head;
  int32_t tail;
  int32_t capacity;
  bool is_full;
  bool is_empty;
  int32_t buffer; // This is actually an array of int32_t, but cuda doesn't support the dynamically sized array notation here.
} ring_buffer_t;

struct omptarget_device_environmentTy {
  int32_t debug_level;
  
  ring_buffer_t * StackTraceBuffer;
};

extern omptarget_device_environmentTy omptarget_device_environment;

#endif
