# PROGRESS

## Current milestone
**M1 — Card representation + Hold'em 7-card hand evaluator (with tests)**

## Milestone 1 tasks
- [x] T0  Project skeleton: `src/` + `include/`, `poker_engine` library + `equity` exe, cmake/ninja building with g++ (MSYS2)
- [~] T1  Card encoding (`rank*4 + suit`), parse/print `"Ah"` ↔ int — code done, **tests pending (via T3)**
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
_(none)_

## Concepts learned
- Header (`include/`) vs implementation (`src/`); `constexpr` helpers live in headers
- CMake library + executable split, `PUBLIC` include dirs, Release already implies -O3
- Card encoding rank*4+suit; `>> 2` / `& 3` for rank/suit; `CardMask{1} << c` (64-bit shift)
- `std::optional` for fallible parsing; `unsigned char` cast before `toupper`
- `uint8_t` prints as a char with `std::cout`

## Session log
- 2026-11-11: Planned M1. T0 done, card.hpp/card.cpp written, builds clean, pushed (3b90862).
- 2026-11-12: Next: T3 test framework + card tests.
