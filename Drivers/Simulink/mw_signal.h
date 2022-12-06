/* Copyright 2016 The MathWorks, Inc. */
#ifndef __MW_SIGNAL__H__
#define __MW_SIGNAL__H__

#include "mw_thread.h"

typedef struct _mw_signal_event_t {
    mw_thread_t * thread_def;
    int32_t signals;
} mw_signal_event_t;

/* Set the specified Signal Flags of an active thread. */
int32_t mw_osSignalSet (mw_thread_t thread_def, int32_t signals);
/* Clear the specified Signal Flags of an active thread. */
int32_t mw_osSignalClear(mw_thread_t thread_def, int32_t signals);
/* Wait for one or more Signal Flags to become signaled for the current RUNNING thread */
osEvent mw_osSignalWaitEver(int32_t signals);
/* Wait for one or more Signal Flags to become signaled for the current RUNNING thread */
osEvent mw_osSignalWait (int32_t signals, uint32_t millisec);

/* Set the specified Signal Flags of an active thread. */
int32_t mw_osSignalEventCreate (mw_signal_event_t * signal_event_def);
/* Clear the specified Signal Flags of an active thread. */
int32_t mw_osSignalEventRelease(mw_signal_event_t * signal_event_def);
/* Wait for one or more Signal Flags to become signaled for the current RUNNING thread */
osEvent mw_osSignalEventWaitEver(mw_signal_event_t * signal_event_def);
/* Wait for one or more Signal Flags to become signaled for the current RUNNING thread */
void mw_osSignalEventDelete(mw_signal_event_t * signal_event_def);

#endif /* __MW_SIGNAL__H__ */