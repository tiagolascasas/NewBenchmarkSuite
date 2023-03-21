
#include <float.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/**
 * Returns a letter identifying the class based on the original numeric ID.
 */
char get_class_name(CLASS_TYPE class_id) { return 'A' + (CLASS_TYPE)class_id; }

/**
 * Verify if the classifications equal the original ones stored in key
 */
void verify_results(int num_new_points, const CLASS_TYPE *classifications,
                    const CLASS_TYPE *key)
{

    if (key == NULL)
    {
        printf("Invalid key. Skipping verification.\n");
        return;
    }

    bool passed = true;
    printf("Verifying results...\n");
    for (int i = 0; i < num_new_points; i++)
    {

        if (classifications[i] != key[i])
        {
            printf("[%d] %c %s %c\n", i, get_class_name(classifications[i]),
                   "!=", get_class_name(key[i]));
            passed = false;
        }
    }

    printf("Verification is complete: ");
    if (passed)
    {
        printf("Passed!\n");
    }
    else
    {
        printf("Failed!\n");
    }
}

/**
 * Get the score according to the execution times in the ANTAREX machine.
 * This is used when READ = 2.
 */
int get_reference_score(double time_s, int num_points)
{

    switch (num_points)
    {
    case 1000:
        return (int)(0.0084 / time_s * 100);
    case 250000:
        return (int)(8.2217 / time_s * 100);
    case 1000000:
        return (int)(64.3585 / time_s * 100);
    default:
        return 0;
    }
}

/**
 * return an integer number from min to max.
 */
static int rand_int(int min, int max)
{

    int number = (int)(min + rand() / (RAND_MAX / (max - min + 1) + 1));
    return number;
}

/**
 * return a floating-point number from min to max.
 */
static DATA_TYPE rand_double(DATA_TYPE min, DATA_TYPE max)
{

    DATA_TYPE number =
        (DATA_TYPE)(min + rand() / (RAND_MAX / (max - min + 1) + 1));
    return number;
}

/**
 * return a floating-point number between 0 and 1
 */
static DATA_TYPE get_rand_feature_value() { return rand_double(0, 1); }

/**
 * Initialize points with random values
 */
void initialize_known_points(int num_points, Point *known_points,
                             int num_classes, int num_features)
{

    for (int i = 0; i < num_points; i++)
    {
        for (int j = 0; j < num_features; j++)
        {
            known_points[i].features[j] = (DATA_TYPE)get_rand_feature_value();
        }
        known_points[i].classification_id =
            (CLASS_TYPE)rand_int(0, num_classes - 1);
    }
}

/**
 * Initialize new points with random values.
 */
void initialize_new_points(int num_new_points, Point *new_points,
                           int num_features)
{

    for (int i = 0; i < num_new_points; i++)
    {
        for (int j = 0; j < num_features; j++)
        {
            new_points[i].features[j] = (DATA_TYPE)get_rand_feature_value();
        }
        new_points[i].classification_id = (CLASS_TYPE)-1;
    }
}

/**
 * show the values of a point: features and class.
 */
void show_point(Point point, int num_features)
{

    for (int j = 0; j < num_features; j++)
    {
        if (j == 0)
            printf("%.3f", point.features[j]);
        else
            printf(",%.3f", point.features[j]);
    }
    printf(", class = %d\n", point.classification_id);
}

/**
 * Determine the min and max values for each feature for a set of
 * points.
 */
void minmax(DATA_TYPE *min, DATA_TYPE *max, int num_points, Point *known_points,
            int num_features)
{

    for (int j = 0; j < num_features; j++)
    {
        min[j] = MAX_FP_VAL;
        max[j] = MIN_FP_VAL;
    }

    for (int i = 0; i < num_points; i++)
    {
        for (int j = 0; j < num_features; j++)
        {
            if (known_points[i].features[j] < min[j])
                min[j] = known_points[i].features[j];
            if (known_points[i].features[j] > max[j])
                max[j] = known_points[i].features[j];
        }
    }
}

/*
 * Normalize the features of each point using minmac normalization.
 */
void minmax_normalize(DATA_TYPE *min, DATA_TYPE *max, int num_points,
                      Point *points, int num_features)
{

    for (int i = 0; i < num_points; i++)
    {
        for (int j = 0; j < num_features; j++)
        {

            DATA_TYPE nfeature = (DATA_TYPE)((points[i].features[j] - min[j]) /
                                             (max[j] - min[j]));

            // in case the normalization returns a NaN or INF
            if (std::isnan(nfeature))
                nfeature = (DATA_TYPE)0.0;
            else if (std::isinf(nfeature))
                nfeature = (DATA_TYPE)1.0;

            points[i].features[j] = nfeature;
        }
    }
}
