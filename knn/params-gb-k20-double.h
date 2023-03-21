#ifndef __KNN_SCENARIO_PARAMS_H__
#define __KNN_SCENARIO_PARAMS_H__

#define N_TRAINING 40002

#define N_TESTING 9998

#define N_FEATURES 100

#define N_CLASSES 8

// clang-format off
#define TRAINING_DATA_FILE "gb-train.dat"
#define TEST_DATA_FILE "gb-test.dat"
// clang-format on

#define TIMMING 1
#define ACCURACY 1
#define NORMALIZE 1
#define K 20
#define DATA_TYPE double

#define VERIFY 1

// clang-format off
#define VERIFICATION_DATA_FILE "key-gb-k20.dat"
// clang-format on

#endif
