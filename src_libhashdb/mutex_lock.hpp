// Author:  Bruce Allen
// Created: 2/25/2013
//
// The software provided here is released by the Naval Postgraduate
// School, an agency of the U.S. Department of Navy.  The software
// bears no warranty, either expressed or implied. NPS does not assume
// legal liability nor responsibility for a User's use of the software
// or the results of such use.
//
// Please note that within the United States, copyright protection,
// under Section 105 of the United States Code, Title 17, is not
// available for any work of the United States Government and/or for
// any works created by United States Government employees. User
// acknowledges that this software contains work which was created by
// NPS government employees and is therefore in the public domain and
// not subject to copyright.
//
// Released into the public domain on February 25, 2013 by Bruce Allen.

/**
 * \file
 * Provides mutex macros for pthreads.
 */

#ifndef MUTEX_LOCK_HPP
#define MUTEX_LOCK_HPP

#include <config.h>

#ifdef HAVE_PTHREAD
#define MUTEX_INIT(M)   pthread_mutex_init(M,NULL);
#define MUTEX_LOCK(M)   pthread_mutex_lock(M)
#define MUTEX_UNLOCK(M) pthread_mutex_unlock(M)
#define MUTEX_DESTROY(M)   pthread_mutex_destroy(M)
#else
#define MUTEX_INIT(M)   {}
#define MUTEX_LOCK(M)   {}
#define MUTEX_UNLOCK(M) {}
#define MUTEX_DESTROY(M) {}
#endif

#endif

