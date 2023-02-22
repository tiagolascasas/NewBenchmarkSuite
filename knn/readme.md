# Compilation instructions

Compile it with:

```
gcc *.c -o knn -D SCENARIO=<ID>
```

Where `<SCENARIO>` is the flag used to choose one of the following scenarios. Use the value from the first column, e.g., `-D SCENARIO=GA_K20_F`:

| Scenario ID | Dataset | Data type | #Features | #Samples Training | #Samples Testing | K   | Accuracy |
| ----------- | ------- | --------- | --------- | ----------------- | ---------------- | --- | -------- |
| WI_K3_F     | wisdm   | float     | 43        | 4336              | 1082             | 3   | 68.02%   |
| WI_K3_D     | wisdm   | double    | 43        | 4336              | 1082             | 3   | 68.02%   |
| WI_K20_F    | wisdm   | float     | 43        | 4336              | 1082             | 20  | 68.76%   |
| WI_K20_D    | wisdm   | double    | 43        | 4336              | 1082             | 20  | 68.76%   |
| GA_K20_F    | GA      | float     | 100       | 8004              | 1996             | 20  | 50.50%   |
| GA_K20_D    | GA      | double    | 100       | 8004              | 1996             | 20  | 50.50%   |
| GB_K20_F    | GB      | float     | 100       | 40002             | 9998             | 20  | 51.17%   |
| GB_K20_D    | GB      | double    | 100       | 40002             | 9998             | 20  | 51.17%   |

If you do not provide a scenario with the `-D` option, it will default to the `WI_K3_F` scenario.

To run the benchmark, simply type in:

```
./knn
```