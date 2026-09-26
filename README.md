# Sprint 2 — Student Academic Profile (C++)

Covers: US-07, US-09, US-10.

## Structure
```
third_party/doctest.h        -> single-header test framework
sprint2/
  student_profile.h          -> US-07, US-09, US-10 (auto-update, history view)
  test_student_profile.cpp   -> TDD tests for automatic profile updates
```

## Build and run
```bash
cd sprint2
g++ -std=c++17 -o test_student_profile test_student_profile.cpp && ./test_student_profile
```
