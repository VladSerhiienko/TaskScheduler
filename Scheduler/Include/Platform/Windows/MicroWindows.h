// The MIT License (MIT)
//
// 	Copyright (c) 2015 Sergey Makeev, Vadim Slyusarev
//
// 	Permission is hereby granted, free of charge, to any person obtaining a copy
// 	of this software and associated documentation files (the "Software"), to deal
// 	in the Software without restriction, including without limitation the rights
// 	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// 	copies of the Software, and to permit persons to whom the Software is
// 	furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
// 	all copies or substantial portions of the Software.
//
// 	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// 	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// 	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// 	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// 	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// 	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// 	THE SOFTWARE.
#pragma once

#include <MTConfig.h>
#include <MTTypes.h>

#ifdef _WIN32

#ifndef STRICT
#define STRICT
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#endif

#include <Windows.h>

#ifdef YieldProcessor
#undef YieldProcessor
#endif


//
// micro windows header is used to avoid including heavy windows header to MTPlatform.h
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define MW_WINBASEAPI __declspec(dllimport)
#define MW_WINAPI __stdcall

//
// windows.h is already included, simply create aliases to the MW_ types
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef LARGE_INTEGER MW_LARGE_INTEGER;
typedef BOOL MW_BOOL;
typedef HANDLE MW_HANDLE;

typedef DWORD MW_DWORD;
typedef WORD MW_WORD;
typedef DWORD64 MW_DWORD64;
typedef ULONG_PTR MW_ULONG_PTR;

typedef LPTHREAD_START_ROUTINE TThreadStartFunc;

typedef SYSTEM_INFO MW_SYSTEM_INFO;

typedef CRITICAL_SECTION MW_CRITICAL_SECTION;
typedef CONDITION_VARIABLE MW_CONDITION_VARIABLE;

typedef CONTEXT MW_CONTEXT;

#define MW_INFINITE (INFINITE)
#define MW_WAIT_OBJECT_0 (WAIT_OBJECT_0)
#define MW_MEM_COMMIT (MEM_COMMIT)
#define MW_PAGE_READWRITE (PAGE_READWRITE)
#define MW_PAGE_NOACCESS (PAGE_NOACCESS)
#define MW_MEM_RELEASE (MEM_RELEASE)
#define MW_ERROR_TIMEOUT (ERROR_TIMEOUT)

#define MW_CURRENT_FIBER_OFFSET (FIELD_OFFSET(NT_TIB, FiberData))
#define MW_STACK_BASE_OFFSET (FIELD_OFFSET(NT_TIB, StackBase))
#define MW_STACK_STACK_LIMIT_OFFSET (FIELD_OFFSET(NT_TIB, StackLimit))
#define MW_CONTEXT_FULL (CONTEXT_FULL)


#define MW_FIBER_FLAG_FLOAT_SWITCH (FIBER_FLAG_FLOAT_SWITCH)

#define MW_THREAD_PRIORITY_HIGHEST (THREAD_PRIORITY_HIGHEST)
#define MW_THREAD_PRIORITY_NORMAL (THREAD_PRIORITY_NORMAL)
#define MW_THREAD_PRIORITY_LOWEST (THREAD_PRIORITY_LOWEST)

#define MW_CREATE_SUSPENDED (CREATE_SUSPENDED)

#define MW_MAXIMUM_PROCESSORS (MAXIMUM_PROCESSORS)
