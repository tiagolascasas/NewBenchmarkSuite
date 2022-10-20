/**
 * FEUP.DEI, v0.6 November 2021
 */
#ifndef __SCENARIOS_H__
#define __SCENARIOS_H__

///////////////////////////////////////////////////////////////////////////////
//                         CHOOSE YOUR SCENARIO HERE                         //
///////////////////////////////////////////////////////////////////////////////

#ifndef SCENARIO
#define SCENARIO SCENARIO_WISDM_K3_FLOAT
#endif

///////////////////////////////////////////////////////////////////////////////
//                                 SETTINGS                                  //
///////////////////////////////////////////////////////////////////////////////
// clang-format off
#define DATASETS_DIRECTORY ./datasets

#define SCENARIO_WISDM_K3_FLOAT 1
#define SCENARIO_WISDM_K3_DOUBLE 2
#define SCENARIO_WISDM_K20_FLOAT 3
#define SCENARIO_WISDM_K20_DOUBLE 4
#define SCENARIO_gen100x8x10000_K20_FLOAT 5
#define SCENARIO_gen100x8x10000_K20_DOUBLE 6
#define SCENARIO_gen100x8x50000_K20_FLOAT 7
#define SCENARIO_gen100x8x50000_K20_DOUBLE 8

#if SCENARIO == SCENARIO_WISDM_K3_FLOAT
#define SCENARIO_FILE params-k3-float.h
#define SCENARIO_DIRECTORY scenario-wisdm
#elif SCENARIO == SCENARIO_WISDM_K3_DOUBLE
#define SCENARIO_FILE params-k3-double.h
#define SCENARIO_DIRECTORY scenario-wisdm
#elif SCENARIO == SCENARIO_WISDM_K20_FLOAT
#define SCENARIO_FILE params-k20-float.h
#define SCENARIO_DIRECTORY scenario-wisdm
#elif SCENARIO == SCENARIO_WISDM_K20_DOUBLE
#define SCENARIO_FILE params-k20-double.h
#define SCENARIO_DIRECTORY scenario-wisdm
#elif SCENARIO == SCENARIO_gen100x8x10000_K20_FLOAT
#define SCENARIO_FILE params-k20-float.h
#define SCENARIO_DIRECTORY scenario-gen100x8x10000
#elif SCENARIO == SCENARIO_gen100x8x10000_K20_DOUBLE
#define SCENARIO_FILE params-k20-double.h
#define SCENARIO_DIRECTORY scenario-gen100x8x10000
#elif SCENARIO == SCENARIO_gen100x8x50000_K20_FLOAT
#define SCENARIO_FILE params-k20-float.h
#define SCENARIO_DIRECTORY scenario-gen100x8x50000
#elif SCENARIO == SCENARIO_gen100x8x50000_K20_DOUBLE
#define SCENARIO_FILE params-k20-double.h
#define SCENARIO_DIRECTORY scenario-gen100x8x50000
#endif

// clang-format on

///////////////////////////////////////////////////////////////////////////////
//                                 DEFAULTS                                  //
///////////////////////////////////////////////////////////////////////////////
#include <float.h>
#include <stdint.h>

// clang-format off
#define STR(x) #x
#define PATH_BUILDER(directory, scenarioDirectory, scenarioFile) STR(directory/scenarioDirectory/scenarioFile)
#define SCENARIO_PARAMS PATH_BUILDER(DATASETS_DIRECTORY, SCENARIO_DIRECTORY, SCENARIO_FILE)
// clang-format on

#include SCENARIO_PARAMS

#ifndef DATATYPE
#warning("DATATYPE not set by scenario.")
#define DATATYPE float
#endif
typedef DATATYPE datatype;

#define FP_TYPE_float 1
#define FP_TYPE_double 2

#define _FP_TYPE(x) FP_TYPE_##x
#define FP_TYPE(x) _FP_TYPE(x)

#if FP_TYPE(DATATYPE) == FP_TYPE_double
#define MAX_FP_VAL DBL_MAX
#define MIN_FP_VAL -DBL_MAX
#elif FP_TYPE(DATATYPE) == FP_TYPE_float
#define MAX_FP_VAL FLT_MAX
#define MIN_FP_VAL -FLT_MAX
#else
#error("Unrecognized DATATYPE")
#define MAX_FP_VAL unknown
#define MIN_FP_VAL unknown
#endif

#ifndef TIMMING
#warning("TIMING not set by scenario.")
/**
 * 0: without
 * 1: Linux/Windows
 * 2: specific timers (not implemented)
 */
#define TIMMING 1
#endif

#ifndef VERIFY
#warning("VERIFY not set by scenario.")
/**
 * 0: none verification;
 * 1: to verify if the results are according to the ones expected only for READ
 * 	= 1, scenario A1, or READ = 2
 */
#define VERIFY 0
#endif

#ifndef ACCURACY
#warning("ACCURACY not set by scenario.")
/**
 * 0: no
 * 1: to report the accuracy of the classification only used for READ = 1 or
 * 	READ = 2
 */
#define ACCURACY 1
#endif

#ifndef NORMALIZE
#warning("NORMALIZE not set by scenario.")
/**
 * 0: nothing
 * 1: minmax normalization of features
 */
#define NORMALIZE 1
#endif

#if TIMMING == 1
#include "timer.h"
#endif

#if NUM_CLASSES > 128
#define class_t short // consider 0..32767 classes and -1 for unknown
#else
#define class_t char // consider 0..127 classes and -1 for unknown
#endif

typedef struct
{
    datatype features[NUM_FEATURES];
    class_t classification_id;
} Point;

typedef struct
{
    class_t classification_id;
    datatype distance;
} BestPoint;

#define TRAINING_DATA_FILE                               \
    PATH_BUILDER(DATASETS_DIRECTORY, SCENARIO_DIRECTORY, \
                 TRAINING_DATA_FILE_NAME)

#define TEST_DATA_FILE \
    PATH_BUILDER(DATASETS_DIRECTORY, SCENARIO_DIRECTORY, TEST_DATA_FILE_NAME)

#define VERIFICATION_DATA_FILE                           \
    PATH_BUILDER(DATASETS_DIRECTORY, SCENARIO_DIRECTORY, \
                 VERIFICATION_DATA_FILE_NAME)

// these are just some aliases for the macros used in knn_arrays
// hopefully they will not cause any issues
#define N_TRAINING NUM_TRAINING_SAMPLES
#define N_FEATURES NUM_FEATURES
#define N_TESTING NUM_TESTING_SAMPLES
#define N_CLASSES NUM_CLASSES

#define CLASS_TYPE class_t
#define DATA_TYPE datatype

#endif
