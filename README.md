# Sprint 1 — Timetable & Examination Management (C++)

Covers: US-01, US-02 (Timetable) and US-05, US-06 (Examination).

## Structure
```
third_party/doctest.h   -> single-header test framework
sprint1/
  timetable.h           -> US-01, US-02 (create timetable, clash detection)
  test_timetable.cpp    -> TDD tests for clash detection
  exams.h               -> US-05, US-06 (exam scheduling, result validation)
                             includes documented BEFORE/AFTER refactor
  test_exams.cpp        -> tests for scheduling + validated result submission
```

## Build and run
```bash
cd sprint1
g++ -std=c++17 -o test_timetable test_timetable.cpp && ./test_timetable
g++ -std=c++17 -o test_exams test_exams.cpp && ./test_exams
```
