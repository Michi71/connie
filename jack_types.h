
JACK-AUDIO-CONNECTION-KIT

    Main Page
    Related Pages
    Modules
    Data Structures
    Files

    File List
    Globals

    jack

types.h
Go to the documentation of this file.
 /*
     Copyright (C) 2001 Paul Davis
     Copyright (C) 2004 Jack O'Quin
     
     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU Lesser General Public License as published by
     the Free Software Foundation; either version 2.1 of the License, or
     (at your option) any later version.
     
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU Lesser General Public License for more details.
     
     You should have received a copy of the GNU Lesser General Public License
     along with this program; if not, write to the Free Software 
     Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  
 */
  
 #ifndef __jack_types_h__
 #define __jack_types_h__
  
 #include <inttypes.h>
 #include <pthread.h>
  
 typedef uint64_t jack_uuid_t;
  
 typedef int32_t jack_shmsize_t;
  
 #ifndef 
 #ifdef __GNUC__
 /*  needs to be a macro which
    expands into a compiler directive. The directive must
    tell the compiler to arrange the preceding structure
    declaration so that it is packed on byte-boundaries rather
    than use the natural alignment of the processor and/or
    compiler.
 */
 #ifdef __arm__
 #  define 
 #else
 #  define  __attribute__((__packed__))
 #endif /* ARM */
 #else
 /* Add other things here for non-gcc platforms */
 #endif
 #endif
  
  
 typedef uint32_t             jack_nframes_t;
  
 #define JACK_MAX_FRAMES (4294967295U)   /* This should be UINT32_MAX, but
                                            C++ has a problem with that. */
  
 typedef uint64_t jack_time_t;
  
 #define JACK_LOAD_INIT_LIMIT 1024
  
 typedef jack_uuid_t jack_intclient_t;
  
 typedef struct _jack_port    jack_port_t;
  
 typedef struct _jack_client  jack_client_t;
  
 typedef uint32_t             jack_port_id_t;
  
 enum JackOptions {
  
      JackNullOption = 0x00,
  
      JackNoStartServer = 0x01,
  
      JackUseExactName = 0x02,
  
      JackServerName = 0x04,
  
      JackLoadName = 0x08,
  
      JackLoadInit = 0x10,
  
      JackSessionID = 0x20
 };
  
 #define JackOpenOptions (JackSessionID|JackServerName|JackNoStartServer|JackUseExactName)
  
 #define JackLoadOptions (JackLoadInit|JackLoadName|JackUseExactName)
  
 typedef enum JackOptions jack_options_t;
  
 enum JackStatus {
  
      JackFailure = 0x01,
  
      JackInvalidOption = 0x02,
  
      JackNameNotUnique = 0x04,
  
      JackServerStarted = 0x08,
  
      JackServerFailed = 0x10,
  
      JackServerError = 0x20,
  
      JackNoSuchClient = 0x40,
  
      JackLoadFailure = 0x80,
  
      JackInitFailure = 0x100,
  
      JackShmFailure = 0x200,
  
      JackVersionError = 0x400,
  
      /*
       * BackendError
       */
      JackBackendError = 0x800,
  
      /*
       * Client is being shutdown against its will
       */
      JackClientZombie = 0x1000
 };
  
 typedef enum JackStatus jack_status_t;
  
 enum JackLatencyCallbackMode {
  
      JackCaptureLatency,
  
      JackPlaybackLatency
  
 };
  
 typedef enum JackLatencyCallbackMode jack_latency_callback_mode_t;
  
 typedef void (*JackLatencyCallback)(jack_latency_callback_mode_t mode, void *arg);
  
 struct _jack_latency_range
 {
     jack_nframes_t min;
     jack_nframes_t max;
 };
  
 typedef struct _jack_latency_range jack_latency_range_t;
  
 typedef int  (*JackProcessCallback)(jack_nframes_t nframes, void *arg);
  
 typedef void  (*JackThreadInitCallback)(void *arg);
  
 typedef int  (*JackGraphOrderCallback)(void *arg);
  
 typedef int  (*JackXRunCallback)(void *arg);
  
 typedef int  (*JackBufferSizeCallback)(jack_nframes_t nframes, void *arg);
  
 typedef int  (*JackSampleRateCallback)(jack_nframes_t nframes, void *arg);
  
 typedef void (*JackPortRegistrationCallback)(jack_port_id_t port, int /* register */, void *arg);
  
 typedef void (*JackPortRenameCallback)(jack_port_id_t port, const char* old_name, const char* new_name, void* arg);
  
 typedef void (*JackClientRegistrationCallback)(const char* name, int /* register */, void *arg);
  
 typedef void (*JackPortConnectCallback)(jack_port_id_t a, jack_port_id_t b, int connect, void* arg);
  
 typedef void (*JackFreewheelCallback)(int starting, void *arg);
  
 typedef void *(*JackThreadCallback)(void* arg);
  
 typedef void (*JackShutdownCallback)(void *arg);
  
 typedef void (*JackInfoShutdownCallback)(jack_status_t code, const char* reason, void *arg);
  
 #define JACK_DEFAULT_AUDIO_TYPE "32 bit float mono audio"
 #define JACK_DEFAULT_MIDI_TYPE "8 bit raw midi"
  
 typedef float jack_default_audio_sample_t;
  
 enum JackPortFlags {
  
      JackPortIsInput = 0x1,
  
      JackPortIsOutput = 0x2,
  
      JackPortIsPhysical = 0x4, 
  
      JackPortCanMonitor = 0x8,
  
      JackPortIsTerminal = 0x10
 };          
  
  
 #endif /* __jack_types_h__ */
Generated by doxygen 1.9.1
