# Bug Fix Documentation - practice03.cpp

## 1. Bug in `sumRange(int start, int end)`

- **Issue:** The loop condition was `i < end`, leading to an off-by-one error.
- **Fix:** Changed the loop condition to `i <= end`.

## 2. Bug in `containsNegative(const std::vector<int>& numbers)`

- **Issue 1:** The loop condition was `i <= numbers.size()`, which caused an out-of-bounds error.
- **Fix:** Changed the condition to `i < numbers.size()`.
- **Issue 2:** The condition checked for `numbers[i] > 0` instead of `numbers[i] < 0`.
- **Fix:** Corrected the condition to `numbers[i] < 0`.

## 3. Bug in `findMax(const std::vector<int>& numbers)`

- **Issue 1:** Returning `0` when the list is empty is incorrect.
- **Fix:** Throw an `std::invalid_argument` exception instead.
- **Issue 2:** The loop condition was `i <= numbers.size()`, leading to an out-of-bounds error.
- **Fix:** Changed the condition to `i < numbers.size()`.
- **Issue 3:** Used `numbers[i] >= maxVal`, causing unnecessary reassignments.
- **Fix:** Changed it to `numbers[i] > maxVal`.
