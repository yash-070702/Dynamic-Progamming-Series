# Dynamic Programming Practice — Series

This repository contains a day-by-day collection of dynamic programming problems implemented in C++ (files named `*.cpp`).  
The goal is to practice classic and contest-style DP problems, document solutions, and collect notes/approaches for each problem.
Each `Day X` folder contains C++ solution files and a `README.md` with a short description and tips.

## How to compile & run
From the project root or inside a day folder:

```bash
# compile
g++ -std=c++17 -O2 MySolution.cpp -o MySolution

Progress

Track which problems you’ve completed by adding ✅ next to filenames in each day's README.


---

# Day 1 README (`Day 1/README.md`)
```md
# Day 1 — Dynamic Programming Problems

Files:
- `Climbing_Stairs.cpp` — Count ways to climb stairs (classic Fibonacci / DP with O(1) space).
- `CoinChange.cpp` — Minimum coins to make amount (unbounded knapsack).
- `Fibonacci_Number.cpp` — Compute nth Fibonacci (DP / matrix exponentiation for large n).
- `House_Robber.cpp` — Max sum with no adjacent houses (1D DP).
- `House_RobberII.cpp` — Circular variant of House Robber (handle wrap-around).
- `Max_sum_without_adjacent.cpp` — General max sum without adjacent elements.
- `Minimum_number_of_coins.cpp` — Count combinations or minimum coins (depends on implementation).

## How to run
```bash
g++ -std=c++17 -O2 Climbing_Stairs.cpp -o Climb
./Climb

DP Tips (Day 1)

Many of these are 1D DP with states dp[i] = best up to i.

For space optimize to two variables when dp depends only on i-1 and i-2.

For coin change, clarify whether order matters: combinations vs permutations.

TODO / Notes

Add constraints & example input at top of each file.

Mark solved ✅ when verified on sample tests.


---

# Day 2 README (`Day 2/README.md`)
```md
# Day 2 — Dynamic Programming Problems

Files:
- `Combination_sum_IV.cpp` — Count permutations to reach target (order matters) — usually DP on sum.
- `Maximize_the_cut_segments.cpp` — Max number of segments for rope cutting (DP: dp[i] = max over cuts).
- `Minimum_cost_for_tickets.cpp` — Ticket cost with passes (interval DP or greedy + DP).
- `Paint_the_fence.cpp` — Ways to paint fence with restrictions (combinatorics / DP).
- `Perfect_square.cpp` — Minimum number of perfect squares summing to n (classic DP).

## How to run
```bash
g++ -std=c++17 -O2 Combination_sum_IV.cpp -o comb4
./comb4

DP Tips (Day 2)

For coin/permutation count problems, use 1D dp up to target; watch for overflow.

For partition/cut problems, initialize dp[0] correctly (often 0 or 1 depending on problem).

For minimum cost problems, think of dp[i] as min cost to reach i (or min passes covering up to i).

TODO / Notes

Include sample testcases to check both small and large inputs.


---

# Day 3 README (`Day 3/README.md`)
```md
# Day 3 — Dynamic Programming Problems

Files:
- `ArithmaticSlices.cpp` — Count arithmetic subarrays (linear scan / DP).
- `CuttingRod(GFG).cpp` — Max profit for rod cutting (unbounded knapsack style).
- `DeleteAndEarn.cpp` — Transform to house-robber variant using frequency array.
- `MaximumSubArray.cpp` — Kadane's algorithm (DP interpretation).
- `Tibonacci_Number(GFG).cpp` — Fibonacci (typo in name; classic).

## How to run
```bash
g++ -std=c++17 -O2 MaximumSubArray.cpp -o maxsub
./maxsub

DP Tips (Day 3)

Many conversions: Delete and Earn -> reduce to non-adjacent sum by aggregating values.

Arithmetic Slices can be solved by counting consecutive patterns (O(n)).

For rod cutting, think dp[i] = max over price[j] + dp[i-j].

TODO / Notes

Add references to problem pages (LeetCode/GFG) in comments.


---

 Day 4 README (`Day 4/README.md`)
```md
# Day 4 — Dynamic Programming Problems

Files:
- `0-1_Knapsack(GFG).cpp` — Classic 0/1 Knapsack: choose items to maximize value under weight constraint (2D DP or optimized 1D).
- `LongestIncreasingSubsequence.cpp` — LIS: find longest strictly increasing subsequence (DP O(n^2) or patience/O(n log n) method).
- `Maximal_Squares.cpp` — Largest square of 1s in binary matrix (DP using histogram of consecutive ones).
- `minimum-score-triangulation-of-polygon.cpp` — Minimum score triangulation (interval DP over polygon diagonals).

## How to compile & run
From inside `Day 4/` (or give full path):

```bash
# compile one file
g++ -std=c++17 -O2 LongestIncreasingSubsequence.cpp -o lis

# run (redirect input if required)
./lis < input.txt

Day 5 README (Day 5/README.md)
# Day 5 — Dynamic Programming Problems

Files:
- `EditDistance.cpp` — Minimum edits (insert/delete/replace) to convert strings (classic DP).
- `LongestArithmeticSubsequence.cpp` — Longest arithmetic subsequence (DP with hashmap per index).
- `LongestCommonSubsequence.cpp` — LCS of two strings (2D DP).
- `LongestPalindromicSubsequence.cpp` — LPS via 2D DP (or LCS with reversed string).
- `RussianDolls.cpp` — Maximum number of envelopes (sort + LIS on one dimension).

## How to run
```bash
g++ -std=c++17 -O2 LongestCommonSubsequence.cpp -o lcs
./lcs

DP Tips (Day 5)

LCS & Edit Distance use 2D DP; consider rolling arrays to reduce memory if necessary.

Longest arithmetic subsequence often is O(n^2) with dp[i][diff].

For Russian Dolls (envelopes), sort by width asc and height desc, then LIS on heights.

TODO / Notes

Add complexity notes and example testcases to each file header.


---

# Day 6 README (`Day 6/README.md`)
```md
# Day 6 — Dynamic Programming Problems

Files:
- `longestAPWithDiff.cpp` — Longest arithmetic progression with given difference (or longest AP) — DP with hashmap.
- `maximalRectangle.cpp` — Max rectangle of 1s in binary matrix (stack + histogram DP trick).
- `uniqueBST.cpp` — Count structurally unique BSTs (Catalan numbers / DP).
- `wildCardPatternMatching.cpp` — Pattern matching with wildcards (DP table).

## How to run
```bash
g++ -std=c++17 -O2 maximalRectangle.cpp -o maxrect
./maxrect

DP Tips (Day 6)

maximalRectangle uses largest-rectangle-in-histogram per row approach.

uniqueBST uses dp[n] = sum(dp[i-1]*dp[n-i]) — Catalan.

Pattern matching (with ?/*) needs careful initialization of dp[0][j].

TODO / Notes

Test wildcard cases with consecutive * and empty strings.


---

# Day 7 README (`Day 7/README.md`)
```md
# Day 7 — Dynamic Programming Problems

Files:
- `BuyAndSell_I.cpp` — Best time to buy & sell stock once.
- `BuyAndSell_II.cpp` — Max profit with unlimited transactions.
- `BuyAndSell_III.cpp` — Max profit with at most two transactions.
- `BuyAndSell_with_fee.cpp` — Max profit with transaction fee.
- `MCTFromLeafValues.cpp` — Minimum Cost Tree From Leaf Values (stack / DP interval variant).

## How to run
```bash
g++ -std=c++17 -O2 BuyAndSell_III.cpp -o bns3
./bns3

DP Tips (Day 7)

Stock problems: maintain DP states (hold / not hold) or use greedy transforms.

MCTFromLeafValues can be solved with stack-based greedy; DP interval O(n^3) is possible but slower.

TODO / Notes

Add run examples for fees and transaction limits.


---

# Day 8 README (`Day 8/README.md`)
```md
# Day 8 — Dynamic Programming Problems

Files:
- `FrogJump.cpp` — Frog jump with variable jump costs (DP on positions).
- `MaximumHeightByStackCuboid.cpp` — Stack cuboids (3D box stacking -> LIS on dimensions).
- `minimumSidewaysJump.cpp` — Minimum sideway jumps (grid + DP/BFS hybrid).
- `pizzaWith3nSlices.cpp` — Max sum selecting n non-adjacent slices from circular pizza (DP on circle).
- `reducingDishes.cpp` — Max satisfaction problem with order multipliers (DP / greedy variants).

# Day 9 — Dynamic Programming Problems

Files:
- `deleteOprOnStrings.cpp` — Minimum deletions to make two strings equal (edit distance variant).
- `guessNumberHigherOrLower_II.cpp` — Min cost to guarantee win (interval DP).
- `minimumSwaps.cpp` — Minimum swaps to sort / arrange (varies by problem statement).
- `noOfDiceRollsWithTargetSum.cpp` — Count number of dice rolls to reach target (DP by sum).
- `partitionEqualSubsetSum.cpp` — Partition array into two subsets with equal sum (subset-sum DP).

## How to run
```bash
g++ -std=c++17 -O2 partitionEqualSubsetSum.cpp -o part
./part

DP Tips (Day 9)

- String operations often reduce to edit-distance style DP.
- Dice rolls problem is classic: dp[rolls][sum].
- Partition subset sum → classic knapsack boolean DP.


# Day 10 — Dynamic Programming Problems

Files:
- `BuyAndSellWithCooldown.cpp` — Max profit with cooldown days.
- `MaxProfitInAJobScheduling.cpp` — Weighted interval scheduling (DP + binary search).
- `minDiffOfAJob.cpp` — Partition jobs to minimize difference (subset sum variant).
- `minimumCostToCutStick.cpp` — Min cost to cut stick (interval DP).
- `scrambleString.cpp` — Check if one string is scramble of another (recursive DP with memoization).

## How to run
```bash
g++ -std=c++17 -O2 MaxProfitInAJobScheduling.cpp -o jobs
./jobs

DP Tips (Day 10)

- Cooldown stock problems require 3 states (buy, sell, rest).
- Interval DP (cut stick / scramble) often O(n^3).


# Day 11 — Dynamic Programming Problems

Files:
- `eggDropping.cpp` — Min attempts to find critical floor (classic DP / binary search).
- `geeksTraining.cpp` — Max points over days with no repeat activity.
- `MatrixChainMultiplication.cpp` — Optimal matrix multiplication order (interval DP).
- `palindromicPartition.cpp` — Min cuts for palindrome partitioning.
- `wordBreak.cpp` — Word break problem (DP with dictionary lookup).

## How to run
```bash
g++ -std=c++17 -O2 eggDropping.cpp -o eggs
./eggs

DP Tips (Day 11)

- Egg dropping optimized with binary search over partitions.
- Matrix chain & palindrome partition are interval DP with cuts.


# Day 12 — Dynamic Programming Problems

Files:
- `minimumFallingPathSum_II.cpp` — Min falling path with restrictions (O(n^3) DP).
- `minimumFallingPathSum.cpp` — Simple falling path sum.
- `minimumPathSum.cpp` — Min path sum in grid.
- `triangle.cpp` — Min path in triangle grid.
- `uniquePath_II.cpp` — Unique paths with obstacles.
- `uniquePaths.cpp` — Classic grid path counting.

## How to run
```bash
g++ -std=c++17 -O2 minimumPathSum.cpp -o mps
./mps

DP Tips (Day 12)

- Grid path problems often use dp[i][j] = cost/ways up to cell.
- Space optimization possible to O(n).


# Day 13 — Dynamic Programming Problems

Files:
- `CherryPickup_II.cpp` — Collect max cherries with 2 robots.
- `CherryPickup.cpp` — Collect max cherries (grid traversal).
- `largestDivisibleSubset.cpp` — Largest subset where each divides the other (LIS variant).
- `longestBitonicSubsequence.cpp` — LIS + LDS combination.
- `longestChainString.cpp` — Longest chain of strings (DP on sorted words).

## How to run
```bash
g++ -std=c++17 -O2 CherryPickup.cpp -o cherry
./cherry

DP Tips (Day 13)

- Cherry pickup is 3D DP on grid + positions.
- Bitonic subsequence = LIS up + LIS down.

# Day 14 — Dynamic Programming Problems

Files:
- `DominoTrominoTilling.cpp` — Ways to tile with domino & tromino.
- `FlipToMonotoneIncrease.cpp` — Min flips to make string monotone increasing.
- `Jump_Game.cpp` — Jump game with DP/greedy.
- `Restore_the_Array.cpp` — Restore array with DP on valid partitions.
- `Ugly_Number_2.cpp` — Find nth ugly number (DP with pointers).

## How to run
```bash
g++ -std=c++17 -O2 Jump_Game.cpp -o jump
./jump

DP Tips (Day 14)

- Tiling problems → recurrence relations.
- Monotone string → prefix DP.
- Ugly numbers → DP with multiple indices.

# Day 15 — Dynamic Programming Problems

Files:
- `Count_Ways_to_build_good_strings.cpp` — Count good strings with restrictions.
- `Maximum_Approach_After_N_Operations.cpp` — Maximize array/number after N operations (DP/greedy).
- `Stone_Game_II.cpp` — Stone game variant (minimax + DP).
- `Stone_Game_III.cpp` — Another stone game variant (prefix sums + DP).
- `Stone_Game.cpp` — Classic stone game.
- `uncrossed_lines.cpp` — Max uncrossed lines (LCS variant).

## How to run
```bash
g++ -std=c++17 -O2 Stone_Game.cpp -o stone
./stone

DP Tips (Day 15)

- Stone games → interval DP / prefix sums.
- Uncrossed lines reduces to LCS.


## How to run
```bash
g++ -std=c++17 -O2 FrogJump.cpp -o frog
./frog

DP Tips (Day 8)

Problems often need careful index handling for circular arrays (pizza) and state definitions for jumps.

MaximumHeightByStackCuboid — normalize cuboids by sorting dimensions to reduce to LIS-like DP.

TODO / Notes

Include problem links and constraint notes for each file header.


---

### Final suggestions
- Add a short header comment at the top of each `.cpp` with:
  - Problem name & link (LeetCode/GFG/other)
  - Complexity (time/space)
  - Approach summary: DP state, transition, base cases
- Consider adding a `tests/` folder or small `run_all.sh` script to compile & run all solutions you’ve verified.

---

If you want, I can:
- generate `README.md` files and place them into the repository (tell me whether you want me to create real files here), or
- produce a `run_all.sh` that compiles and runs every `.cpp`, or
- add a `TROUBLESHOOTING.md` with common DP pitfalls.

Which of those would you like me to do next? (I can paste the exact file contents or create a shell script for 

