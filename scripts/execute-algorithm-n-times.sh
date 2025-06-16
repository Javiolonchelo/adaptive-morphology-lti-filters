#!/bin/bash
target_names=(
    "LOWPASS_33_TAPS"
    "ALL_PASS_FILTER_4"
    "BIQUAD_PEAK_7753_HZ"
    "BIQUAD_PEAK_440_HZ"
    "BIQUAD_LOWSHELF_3293_HZ"
    "FEEDBACK_COMB_FILTER_TOPOLOGY_1_ORDER_7"
    "FEEDBACK_COMB_FILTER_TOPOLOGY_1_ORDER_40"
    "FEEDBACK_COMB_FILTER_TOPOLOGY_2_ORDER_4"
    "FEEDBACK_COMB_FILTER_TOPOLOGY_2_ORDER_11"
)

counter=0
for target in "${target_names[@]}"; do
    for c in {6..10}; do
        echo "Configuring CMake project"
        cmake -B build -S .
        sleep 1

        echo "Building target: $target, iteration: $c"
        cmake --build build --target PFG -j 8
        sleep 1

        echo "Running PFG for target: $target, iteration: $c"
        mkdir -p ./results/$target/$c
        sleep 1

        echo "Output will be saved to ./results/$target/$c/results"
        outputFile="./results/$target/$c/results"
        ./build/PFG "1" $target $outputFile
        sleep 1
    done
done
