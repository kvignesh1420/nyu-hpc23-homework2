## Homework 2

### Setup
The `linserv1.cims.nyu.edu` host was used for running all the experiments. The details of the processor are as follows:

```
[vk2115@linserv1 nyu-hpc23-homework2]$ lscpu
Architecture:          x86_64
CPU op-mode(s):        32-bit, 64-bit
Byte Order:            Little Endian
CPU(s):                64
On-line CPU(s) list:   0-63
Thread(s) per core:    2
Core(s) per socket:    8
Socket(s):             4
NUMA node(s):          8
Vendor ID:             AuthenticAMD
CPU family:            21
Model:                 1
Model name:            AMD Opteron(TM) Processor 6272
Stepping:              2
CPU MHz:               2099.939
BogoMIPS:              4199.87
Virtualization:        AMD-V
L1d cache:             16K
L1i cache:             64K
L2 cache:              2048K
L3 cache:              6144K
NUMA node0 CPU(s):     0-7
NUMA node1 CPU(s):     8-15
NUMA node2 CPU(s):     32-39
NUMA node3 CPU(s):     40-47
NUMA node4 CPU(s):     48-55
NUMA node5 CPU(s):     56-63
NUMA node6 CPU(s):     16-23
NUMA node7 CPU(s):     24-31
Flags:                 fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx mmxext fxsr_opt pdpe1gb rdtscp lm constant_tsc art rep_good nopl nonstop_tsc extd_apicid amd_dcm aperfmperf pni pclmulqdq monitor ssse3 cx16 sse4_1 sse4_2 popcnt aes xsave avx lahf_lm cmp_legacy svm extapic cr8_legacy abm sse4a misalignsse 3dnowprefetch osvw ibs xop skinit wdt fma4 nodeid_msr topoext perfctr_core perfctr_nb cpb hw_pstate ssbd rsb_ctxsw ibpb vmmcall retpoline_amd arat npt lbrv svm_lock nrip_save tsc_scale vmcb_clean flushbyasid decodeassists pausefilter pfthreshold
```
### Question 1: Valgrind fixes

Comments in `val_test01_solved.cpp` and `val_test02_solved.cpp` files.


### Question 2: Matrix multiplication

I found that `BLOCK_SIZE=24` gave the highest improvement over the reference implementation. Please check the `Supplementary.md` file in this folder for additional experimental results.

Baseline with MMult0 and `BLOCK_SIZE=24`:
```
[vk2115@linserv1 hw2]$ ./MMult1 
 Dimension       Time    Gflop/s       GB/s        Error
        24   0.715211   2.796377  44.742034 0.000000e+00
        72   0.614761   3.254287  52.068589 0.000000e+00
       120   0.706759   2.831267  45.300274 0.000000e+00
       168   0.664997   3.008987  48.143796 0.000000e+00
       216   0.647595   3.112344  49.797504 0.000000e+00
       264   0.633195   3.196441  51.143056 0.000000e+00
       312   0.616575   3.251036  52.016580 0.000000e+00
       360   0.625801   3.280380  52.486073 0.000000e+00
       408   0.643703   3.165311  50.644975 0.000000e+00
       456   0.874102   2.386465  38.183440 0.000000e+00
       504   0.911482   2.247311  35.956983 0.000000e+00
       552   0.989679   2.039407  32.630515 0.000000e+00
       600   1.214594   1.778373  28.453964 0.000000e+00
       648   1.299194   1.675487  26.807793 0.000000e+00
       696   1.204024   1.680134  26.882140 0.000000e+00
       744   1.474454   1.675864  26.813820 0.000000e+00
       792   1.778022   1.676446  26.823138 0.000000e+00
       840   1.415451   1.674955  26.799277 0.000000e+00
       888   1.669664   1.677528  26.840455 0.000000e+00
       936   1.960690   1.672933  26.766925 0.000000e+00
       984   2.280925   1.670838  26.733405 0.000000e+00
      1032   1.402442   1.567416  25.078650 0.000000e+00
      1080   1.706305   1.476538  23.624608 0.000000e+00
      1128   1.966143   1.459964  23.359424 0.000000e+00
      1176   2.235381   1.455125  23.282002 0.000000e+00
      1224   2.533494   1.447619  23.161906 0.000000e+00
      1272   2.858529   1.439955  23.039273 0.000000e+00
      1320   3.204312   1.435546  22.968733 0.000000e+00
      1368   3.578413   1.430862  22.893796 0.000000e+00
      1416   3.978059   1.427409  22.838548 0.000000e+00
      1464   4.431811   1.416029  22.656457 0.000000e+00
      1512   4.878222   1.417176  22.674817 0.000000e+00
      1560   5.388938   1.408966  22.543461 0.000000e+00
      1608   5.926166   1.403183  22.450930 0.000000e+00
      1656   6.503123   1.396655  22.346473 0.000000e+00
      1704   7.083192   1.397043  22.352688 0.000000e+00
      1752   7.689714   1.398692  22.379072 0.000000e+00
      1800   8.358514   1.395463  22.327415 0.000000e+00
      1848   9.081630   1.389863  22.237813 0.000000e+00
      1896   9.800090   1.390961  22.255376 0.000000e+00
      1944  10.592900   1.387088  22.193401 0.000000e+00
      1992  11.418313   1.384510  22.152158 0.000000e+00
```

Tiled version with `BLOCK_SIZE=24` gives $\approx 2.5x$ speedup for larger matrices.

```
[vk2115@linserv1 hw2]$ ./MMult1 
 Dimension       Time    Gflop/s       GB/s        Error
        24   0.499275   4.005810  64.092956 0.000000e+00
        72   0.534262   3.744620  59.913925 0.000000e+00
       120   0.532775   3.755853  60.093643 0.000000e+00
       168   0.542576   3.687904  59.006469 0.000000e+00
       216   0.541399   3.722833  59.565330 0.000000e+00
       264   0.547884   3.694162  59.106594 0.000000e+00
       312   0.547003   3.664530  58.632486 0.000000e+00
       360   0.560052   3.665486  58.647773 0.000000e+00
       408   0.577204   3.529978  56.479656 0.000000e+00
       456   0.589093   3.541063  56.657014 0.000000e+00
       504   0.594193   3.447337  55.157397 0.000000e+00
       552   0.579952   3.480220  55.683526 0.000000e+00
       600   0.616133   3.505736  56.091770 0.000000e+00
       648   0.625263   3.481385  55.702163 0.000000e+00
       696   0.580375   3.485541  55.768659 0.000000e+00
       744   0.719227   3.435612  54.969787 0.000000e+00
       792   0.851483   3.500668  56.010687 0.000000e+00
       840   0.680240   3.485265  55.764234 0.000000e+00
       888   0.805092   3.478994  55.663900 0.000000e+00
       936   0.946178   3.466686  55.466977 0.000000e+00
       984   1.114635   3.419106  54.705691 0.000000e+00
      1032   0.656788   3.346907  53.550510 0.000000e+00
      1080   0.742790   3.391837  54.269397 0.000000e+00
      1128   0.855547   3.355163  53.682602 0.000000e+00
      1176   0.956652   3.400150  54.402401 0.000000e+00
      1224   1.081630   3.390749  54.251980 0.000000e+00
      1272   1.212347   3.395191  54.323059 0.000000e+00
      1320   1.351517   3.403534  54.456549 0.000000e+00
      1368   1.522588   3.362839  53.805416 0.000000e+00
      1416   1.672339   3.395436  54.326973 0.000000e+00
      1464   1.868588   3.358456  53.735293 0.000000e+00
      1512   2.032835   3.400817  54.413068 0.000000e+00
      1560   2.227592   3.408538  54.536615 0.000000e+00
      1608   2.474550   3.360406  53.766503 0.000000e+00
      1656   2.658179   3.416857  54.669712 0.000000e+00
      1704   2.951273   3.352968  53.647491 0.000000e+00
      1752   3.185099   3.376832  54.029307 0.000000e+00
      1800   3.429139   3.401437  54.422990 0.000000e+00
      1848   3.713384   3.399116  54.385857 0.000000e+00
      1896   4.002253   3.405967  54.495474 0.000000e+00
      1944   4.367708   3.364071  53.825139 0.000000e+00
      1992   4.696955   3.365748  53.851970 0.000000e+00
```

OpenMP with `8` threads and `BLOCK_SIZE=24` gives $\approx 16x$ speedup for large matrices over the non-tiled baseline.

```
[vk2115@linserv1 hw2]$ ./MMult1 
 Dimension       Time    Gflop/s       GB/s        Error
        24   0.753430   2.654526  42.472424 0.000000e+00
        72   0.200770   9.964694 159.435110 0.000000e+00
       120   0.112602  17.770828 284.333247 0.000000e+00
       168   0.077645  25.770681 412.330902 0.000000e+00
       216   0.114937  17.536092 280.577470 0.000000e+00
       264   0.095792  21.128839 338.061416 0.000000e+00
       312   0.079974  25.064529 401.032472 0.000000e+00
       360   0.072596  28.277879 452.446067 0.000000e+00
       408   0.094619  21.533977 344.543639 0.000000e+00
       456   0.089447  23.321347 373.141559 0.000000e+00
       504   0.082686  24.772993 396.367888 0.000000e+00
       552   0.071706  28.147803 450.364842 0.000000e+00
       600   0.094363  22.890447 366.247146 0.000000e+00
       648   0.092444  23.547145 376.754316 0.000000e+00
       696   0.078440  25.789375 412.630002 0.000000e+00
       744   0.092707  26.653813 426.461009 0.000000e+00
       792   0.122631  24.306712 388.907384 0.000000e+00
       840   0.101296  23.404770 374.476313 0.000000e+00
       888   0.114347  24.494755 391.916076 0.000000e+00
       936   0.130615  25.112695 401.803114 0.000000e+00
       984   0.157258  24.234375 387.750007 0.000000e+00
      1032   0.101568  21.642779 346.284467 0.000000e+00
      1080   0.116954  21.541976 344.671624 0.000000e+00
      1128   0.127451  22.522420 360.358720 0.000000e+00
      1176   0.140691  23.119823 369.917174 0.000000e+00
      1224   0.177418  20.671763 330.748210 0.000000e+00
      1272   0.195280  21.078240 337.251832 0.000000e+00
      1320   0.209886  21.916321 350.661132 0.000000e+00
      1368   0.219662  23.309470 372.951520 0.000000e+00
      1416   0.268924  21.114919 337.838703 0.000000e+00
      1464   0.287813  21.804335 348.869353 0.000000e+00
      1512   0.307566  22.477468 359.639482 0.000000e+00
      1560   0.334067  22.728452 363.655228 0.000000e+00
      1608   0.405607  20.501351 328.021616 0.000000e+00
      1656   0.413557  21.962182 351.394907 0.000000e+00
      1704   0.438406  22.571579 361.145269 0.000000e+00
      1752   0.470610  22.854474 365.671587 0.000000e+00
      1800   0.536904  21.724564 347.593024 0.000000e+00
      1848   0.565793  22.308898 356.942371 0.000000e+00
      1896   0.605502  22.512794 360.204700 0.000000e+00
      1944   0.639710  22.968677 367.498824 0.000000e+00
      1992   0.723018  21.864958 349.839334 0.000000e+00
```

Regarding the order of for loops in `void MMult1` function, I observed that the order `n, k, m` gives the best result. Also since we use symmetric matrices in our experiments, the other two orders of `k, n, m` and `n, m, k` were explored.


Order `n, m, k` with `BLOCK_SIZE=24`:
```
[vk2115@linserv1 hw2]$ ./MMult1 
 Dimension       Time    Gflop/s       GB/s        Error
        24   2.604724   0.767836  12.285378 0.000000e+00
        72   2.619107   0.763852  12.221625 0.000000e+00
       120   2.619225   0.763976  12.223608 0.000000e+00
       168   2.623502   0.762709  12.203346 0.000000e+00
       216   2.647744   0.761229  12.179664 0.000000e+00
       264   2.661373   0.760499  12.167986 0.000000e+00
       312   2.638908   0.759597  12.153558 0.000000e+00
       360   2.705634   0.758737  12.139788 0.000000e+00
       408   2.688921   0.757746  12.123939 0.000000e+00
       456   2.760904   0.755555  12.088875 0.000000e+00
       504   2.714804   0.754524  12.072384 0.000000e+00
       552   2.674232   0.754744  12.075898 0.000000e+00
       600   2.862504   0.754584  12.073346 0.000000e+00
       648   2.886776   0.754053  12.064849 0.000000e+00
       696   2.679722   0.754900  12.078397 0.000000e+00
       744   3.275406   0.754406  12.070489 0.000000e+00
       792   3.945854   0.755415  12.086646 0.000000e+00
       840   3.141285   0.754728  12.075650 0.000000e+00
       888   3.713831   0.754183  12.066929 0.000000e+00
       936   4.348998   0.754221  12.067528 0.000000e+00
       984   5.063380   0.752670  12.042724 0.000000e+00
      1032   2.931224   0.749929  11.998860 0.000000e+00
      1080   3.346887   0.752766  12.044263 0.000000e+00
      1128   3.819205   0.751596  12.025533 0.000000e+00
      1176   4.328345   0.751502  12.024031 0.000000e+00
      1224   4.885079   0.750763  12.012202 0.000000e+00
      1272   5.469819   0.752521  12.040328 0.000000e+00
      1320   6.114945   0.752245  12.035919 0.000000e+00
      1368   6.815158   0.751298  12.020772 0.000000e+00
      1416   7.546466   0.752447  12.039159 0.000000e+00
      1464   8.352785   0.751315  12.021036 0.000000e+00
      1512   9.185508   0.752631  12.042098 0.000000e+00
      1560  10.088242   0.752642  12.042267 0.000000e+00
      1608  11.050882   0.752473  12.039575 0.000000e+00
      1656  12.062598   0.752957  12.047310 0.000000e+00
      1704  13.143427   0.752888  12.046202 0.000000e+00
      1752  14.288173   0.752758  12.044134 0.000000e+00
      1800  15.483482   0.753319  12.053103 0.000000e+00
      1848  16.765199   0.752882  12.046119 0.000000e+00
      1896  18.109994   0.752708  12.043332 0.000000e+00
      1944  19.510941   0.753079  12.049265 0.000000e+00
      1992  21.017290   0.752179  12.034866 0.000000e+00
```

Order `k, n, m` with `BLOCK_SIZE=24`:
```
[vk2115@linserv1 hw2]$ ./MMult1 
 Dimension       Time    Gflop/s       GB/s        Error
        24   0.572174   3.495440  55.927047 0.000000e+00
        72   0.652785   3.064730  49.035677 0.000000e+00
       120   0.643729   3.108489  49.735816 0.000000e+00
       168   0.634274   3.154739  50.475816 0.000000e+00
       216   0.606272   3.324479  53.191668 0.000000e+00
       264   0.817969   2.474388  39.590205 0.000000e+00
       312   0.635907   3.152204  50.435269 0.000000e+00
       360   0.788075   2.604908  41.678532 0.000000e+00
       408   0.833117   2.445657  39.130508 0.000000e+00
       456   0.861148   2.422364  38.757825 0.000000e+00
       504   0.902620   2.269378  36.310046 0.000000e+00
       552   0.868948   2.322761  37.164182 0.000000e+00
       600   0.753359   2.867158  45.874529 0.000000e+00
       648   0.932665   2.333938  37.343002 0.000000e+00
       696   0.738199   2.740348  43.845566 0.000000e+00
       744   0.865301   2.855636  45.690181 0.000000e+00
       792   1.002709   2.972706  47.563295 0.000000e+00
       840   0.835378   2.838017  45.408271 0.000000e+00
       888   1.035587   2.704657  43.274517 0.000000e+00
       936   1.083947   3.026074  48.417180 0.000000e+00
       984   1.303021   2.924784  46.796546 0.000000e+00
      1032   0.999645   2.198989  35.183831 0.000000e+00
      1080   0.858950   2.933144  46.930310 0.000000e+00
      1128   0.986518   2.909728  46.555648 0.000000e+00
      1176   1.082776   3.004093  48.065485 0.000000e+00
      1224   1.278610   2.868377  45.894035 0.000000e+00
      1272   1.496543   2.750439  44.007024 0.000000e+00
      1320   1.552324   2.963258  47.412121 0.000000e+00
      1368   1.762521   2.905053  46.480851 0.000000e+00
      1416   2.458442   2.309723  36.955560 0.000000e+00
      1464   2.119365   2.961062  47.376984 0.000000e+00
      1512   2.303881   3.000719  48.011511 0.000000e+00
      1560   2.505233   3.030788  48.492613 0.000000e+00
      1608   2.992922   2.778387  44.454187 0.000000e+00
      1656   3.188766   2.848317  45.573078 0.000000e+00
      1704   3.448834   2.869238  45.907801 0.000000e+00
      1752   3.582092   3.002587  48.041390 0.000000e+00
      1800   5.046399   2.311351  36.981617 0.000000e+00
      1848   4.213808   2.995444  47.927099 0.000000e+00
      1896   4.523377   3.013577  48.217226 0.000000e+00
      1944   4.989151   2.945047  47.120746 0.000000e+00
      1992   5.526874   2.860345  45.765522 0.000000e+00
```

The reason for the effectiveness of `n, k, m` order is that since the matrix is stored in column major format, the data fetch operations are fast due to the entire cacheline being filled with data that will surely be accessed in the subsequent iterations. On the other hand, other ordering schemes change the corresponding column of interest more frequently and can not leverage the locality of cached data to a full extent.

Next, the theoretical max flops (PER CORE) can be calculated using:
```
tflops = clock_speed * num_cores * simd_factor * fma_factor * super_scalarity_factor
       = 2099.939 * 10^9 * 1 * 256/32 * 128/32 * 1
       = 67,168 MFlops = 67.168 GFlops
```
Note that since we are not utilizing the simd optimizations in our code, if we can ignore the corresponding factor of `8` in the above calculation, we still get $\approx 8.3$ Gflops. Based on our results for `BATCH_SIZE=24`, our best performance is $\approx 50\%$ of the tflops ,i.e for smaller matrices that fit into cache. As the size increases, we tend to get $\approx 40\%$ of the tflops (PER CORE).


### Question 3: Approximation using Taylor Series and Vectorization

I updated all the `AVX, SSE2` and the `Vector` implementations to improve the approximation accuracy in `fast-sin.cpp`

### Question 4: Pipelining

The `pipeline.cpp` file contains `10` implementations (including a reference function) to analyse the pipelining performance. Especially, the unrolling has been implemented for 2, 4 and 8 steps along with fine-tuning.

Considering an inner-product between arrays `a, b` of size `N`, I report the timings for all the `10` implementations with `-O3` optimization over `100` runs.

- Case `N=10,000`
```
[vk2115@linserv1 hw2]$ ./pipeline 
Time taken: 0.021021  Inner product reference result: 2496.016785
Time taken: 0.010533  Inner product unroll 2 result: 2495.670691
Time taken: 0.010507  Inner product unroll 2 decouple result: 2495.670691
Time taken: 0.010549  Inner product unroll 2 decouple far result: 2495.180116
Time taken: 0.006207  Inner product unroll 4 result: 2495.180116
Time taken: 0.006424  Inner product unroll 4 decouple result: 2495.180116
Time taken: 0.006971  Inner product unroll 4 decouple far result: 2493.349650
Time taken: 0.006938  Inner product unroll 8 result: 2493.349650
Time taken: 0.006911  Inner product unroll 8 decouple result: 2493.349650
Time taken: 0.006958  Inner product unroll 8 decouple far result: 2489.930821
```

- Case `N=100,000`
```
[vk2115@linserv1 hw2]$ ./pipeline 
Time taken: 0.021115  Inner product reference result: 24981.464585
Time taken: 0.011189  Inner product unroll 2 result: 24980.874887
Time taken: 0.011081  Inner product unroll 2 decouple result: 24980.874887
Time taken: 0.011149  Inner product unroll 2 decouple far result: 24980.656870
Time taken: 0.008729  Inner product unroll 4 result: 24980.656870
Time taken: 0.008719  Inner product unroll 4 decouple result: 24980.656870
Time taken: 0.008981  Inner product unroll 4 decouple far result: 24980.281389
Time taken: 0.008872  Inner product unroll 8 result: 24980.281389
Time taken: 0.008830  Inner product unroll 8 decouple result: 24980.281389
Time taken: 0.009066  Inner product unroll 8 decouple far result: 24978.823427
```

- Case `N=1,000,000`
```
[vk2115@linserv1 hw2]$ ./pipeline 
Time taken: 0.231154  Inner product reference result: 249745.580668
Time taken: 0.209748  Inner product unroll 2 result: 249745.400152
Time taken: 0.207209  Inner product unroll 2 decouple result: 249745.400152
Time taken: 0.206635  Inner product unroll 2 decouple far result: 249745.368407
Time taken: 0.189877  Inner product unroll 4 result: 249745.368407
Time taken: 0.189468  Inner product unroll 4 decouple result: 249745.368407
Time taken: 0.188752  Inner product unroll 4 decouple far result: 249744.857898
Time taken: 0.194759  Inner product unroll 8 result: 249744.857898
Time taken: 0.194578  Inner product unroll 8 decouple result: 249744.857898
Time taken: 0.192922  Inner product unroll 8 decouple far result: 249743.278355
```

- Case `N=10,000,000`
```
[vk2115@linserv1 hw2]$ ./pipeline 
Time taken: 2.670356  Inner product reference result: 2499522.874784
Time taken: 2.976284  Inner product unroll 2 result: 2499522.772712
Time taken: 2.071216  Inner product unroll 2 decouple result: 2499522.772712
Time taken: 2.064970  Inner product unroll 2 decouple far result: 2499521.847489
Time taken: 1.885821  Inner product unroll 4 result: 2499521.847490
Time taken: 1.884091  Inner product unroll 4 decouple result: 2499521.847490
Time taken: 1.883566  Inner product unroll 4 decouple far result: 2499521.234199
Time taken: 1.947113  Inner product unroll 8 result: 2499521.234199
Time taken: 1.945523  Inner product unroll 8 decouple result: 2499521.234199
Time taken: 1.906340  Inner product unroll 8 decouple far result: 2499518.331310
```

Even though the sizes of the arrays were larger than cache sizes, due to `-O3` optimizations, I was able to get a maximum of $\approx 30\%$ improvement by unrolling 4 steps over the reference implementation for larger matrices which do not fit into cache. Additional unrolling by `8` didn't lead to significantly different results. However, for smaller matrices such as `N=10,000`, unrolling 4 steps gave $\approx 70\%$ reduction over the reference implementation. Observe that since such small matrices fit into the cache (`L1d cache: 16K, L1i cache: 64K`) of the host, the data transfer to/from the slower RAM is minimized and the simultaneous execution of pipeline `stages` is fast. One the other, since larger matrices increase the latency of the `fetch` stage, the benefit of pipelining is limited to the data that is currently in cache. Thus, when slower memory operations are performed more frequently, the reduction in gains from $70\%$ to $30\%$ seem reasonable.

Additionally, I tried the `-O0` optimization option and got the following results:

- Case `N=10,000`
```
[vk2115@linserv1 hw2]$ ./pipeline 
Time taken: 0.007733  Inner product reference result: 2496.016785
Time taken: 0.005317  Inner product unroll 2 result: 2495.670691
Time taken: 0.006236  Inner product unroll 2 decouple result: 2495.670691
Time taken: 0.005326  Inner product unroll 2 decouple far result: 2495.180116
Time taken: 0.004524  Inner product unroll 4 result: 2495.180116
Time taken: 0.004759  Inner product unroll 4 decouple result: 2495.180116
Time taken: 0.004391  Inner product unroll 4 decouple far result: 2493.349650
Time taken: 0.004025  Inner product unroll 8 result: 2493.349650
Time taken: 0.004368  Inner product unroll 8 decouple result: 2493.349650
Time taken: 0.003743  Inner product unroll 8 decouple far result: 2489.930821
```

- Case `N=100,000`
```
[vk2115@linserv1 hw2]$ ./pipeline 
Time taken: 0.077195  Inner product reference result: 24981.464585
Time taken: 0.054044  Inner product unroll 2 result: 24980.874887
Time taken: 0.062754  Inner product unroll 2 decouple result: 24980.874887
Time taken: 0.053048  Inner product unroll 2 decouple far result: 24980.656870
Time taken: 0.045179  Inner product unroll 4 result: 24980.656870
Time taken: 0.047380  Inner product unroll 4 decouple result: 24980.656870
Time taken: 0.044500  Inner product unroll 4 decouple far result: 24980.281389
Time taken: 0.039670  Inner product unroll 8 result: 24980.281389
Time taken: 0.043323  Inner product unroll 8 decouple result: 24980.281389
Time taken: 0.038426  Inner product unroll 8 decouple far result: 24978.823427
```

- Case `N=1,000,000`
```
[vk2115@linserv1 hw2]$ ./pipeline 
Time taken: 0.871319  Inner product reference result: 249745.580668
Time taken: 0.848748  Inner product unroll 2 result: 249745.400152
Time taken: 0.720393  Inner product unroll 2 decouple result: 249745.400152
Time taken: 0.562375  Inner product unroll 2 decouple far result: 249745.368407
Time taken: 0.501355  Inner product unroll 4 result: 249745.368407
Time taken: 0.537458  Inner product unroll 4 decouple result: 249745.368407
Time taken: 0.477376  Inner product unroll 4 decouple far result: 249744.857898
Time taken: 0.429152  Inner product unroll 8 result: 249744.857898
Time taken: 0.464018  Inner product unroll 8 decouple result: 249744.857898
Time taken: 0.416010  Inner product unroll 8 decouple far result: 249743.278355
```

- Case `N=10,000,000`
```
vk2115@linserv1 hw2]$ ./pipeline 
Time taken: 8.636712  Inner product reference result: 2499522.874784
Time taken: 5.644396  Inner product unroll 2 result: 2499522.772712
Time taken: 6.527518  Inner product unroll 2 decouple result: 2499522.772712
Time taken: 5.638806  Inner product unroll 2 decouple far result: 2499521.847489
Time taken: 4.824016  Inner product unroll 4 result: 2499521.847490
Time taken: 5.097620  Inner product unroll 4 decouple result: 2499521.847490
Time taken: 4.752785  Inner product unroll 4 decouple far result: 2499521.234199
Time taken: 4.314816  Inner product unroll 8 result: 2499521.234199
Time taken: 4.664994  Inner product unroll 8 decouple result: 2499521.234199
Time taken: 4.164108  Inner product unroll 8 decouple far result: 2499518.331310
```

With less aggressive optimizations from the compiler, we can see $\approx 50\%$ reduction in computation time for matrices of all sizes.
