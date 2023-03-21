#pragma once

#include <cmath>
#include "scenarios.h"

char get_class_name(CLASS_TYPE class_id);

void verify_results(int num_new_points, const CLASS_TYPE *classifications,
                    const CLASS_TYPE *key);

int get_reference_score(double time_s, int num_points);

void initialize_known_points(int num_points, Point *known_points,
                             int num_classes, int num_features);

void initialize_new_points(int num_new_points, Point *new_points,
                           int num_features);

void show_point(Point point, int num_features);

void minmax(DATA_TYPE *min, DATA_TYPE *max, int num_points, Point *known_points,
            int num_features);

void minmax_normalize(DATA_TYPE *min, DATA_TYPE *max, int num_points,
                      Point *points, int num_features);
