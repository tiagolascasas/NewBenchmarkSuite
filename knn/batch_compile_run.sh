mkdir -p bin
rm -r ./bin/*

gcc *.c -o bin/knn_WI_K3_F.elf -D SCENARIO=WI_K3_F
gcc *.c -o bin/knn_WI_K3_D.elf -D SCENARIO=WI_K3_D
gcc *.c -o bin/knn_WI_K20_F.elf -D SCENARIO=WI_K20_F
gcc *.c -o bin/knn_WI_K20_D.elf -D SCENARIO=WI_K20_D
gcc *.c -o bin/knn_GA_K20_F.elf -D SCENARIO=GA_K20_F
gcc *.c -o bin/knn_GA_K20_D.elf -D SCENARIO=GA_K20_D
gcc *.c -o bin/knn_GB_K20_F.elf -D SCENARIO=GB_K20_F
gcc *.c -o bin/knn_GB_K20_D.elf -D SCENARIO=GB_K20_D

echo "------------------------------------------------"
./bin/knn_WI_K3_F.elf
echo "------------------------------------------------"
./bin/knn_WI_K3_D.elf
echo "------------------------------------------------"
./bin/knn_WI_K20_F.elf
echo "------------------------------------------------"
./bin/knn_WI_K20_D.elf
echo "------------------------------------------------"
./bin/knn_GA_K20_F.elf
echo "------------------------------------------------"
./bin/knn_GA_K20_D.elf
echo "------------------------------------------------"
./bin/knn_GB_K20_F.elf
echo "------------------------------------------------"
./bin/knn_GB_K20_D.elf
echo "------------------------------------------------"