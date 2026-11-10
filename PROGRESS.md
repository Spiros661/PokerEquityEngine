# PROGRESS

## Current milestone
**M1 — Card representation + Hold'em 7-card hand evaluator (with tests)**

## Milestone 1 tasks
- [ ] T0  Project skeleton: move `main.cpp` → `src/`, get `cmake` building with g++ (MSYS2)
- [ ] T1  Card encoding (`rank*4 + suit`), parse/print `"Ah"` ↔ int, plus tests
- [ ] T2  Hand/board as `uint64_t` bitmask; add/remove/contains/count cards
- [ ] T3  Add a test framework (Catch2 or GoogleTest) via CMake; first tests pass
- [ ] T4  Design the hand-value type: category + tiebreak packed into one comparable integer
- [ ] T5  Evaluate flush / straight flush (incl. A-high and wheel straights)
- [ ] T6  Evaluate quads / full house / trips / two pair / pair / high card with kickers
- [ ] T7  Edge-case test suite + brute-force cross-check (all 133,784,560 7-card hands → category counts)

## Roadmap
1. Card repr + 7-card evaluator  ← **in progress**
2. Exact enumeration → exact equity
3. CLI `./equity AhKh QsQd --board 2c7d9h` + README
4. Monte Carlo + standard error, validated vs exact
5. Multithreading + benchmarks
6. PLO (exactly 2 hole + 3 board)
7. Optional: range-vs-range, GUI/web

## Open bugs / issues
- `CMakeLists.txt` builds `src/main.cpp`, but `main.cpp` is at the repo root → build fails.
- `cmake` is not on PATH (g++ 15.2 from MSYS2 ucrt64 is). Install with `pacman -S mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja`.

## Concepts learned
_(nothing yet)_

## Session log
- 2026-11-11: Set up tutor mode, created PROGRESS.md, planned M1.
