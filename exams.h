// Sprint 1 - Examination Management
// Feature: US-05 (exam scheduling with clash check), US-06 (result entry with validation)
#pragma once

#include <string>
#include <vector>
#include "timetable.h"

inline EntryResult schedule_exam(const TimetableEntry& exam_entry,
                                  const std::vector<TimetableEntry>& timetable_entries) {
    for (const auto& entry : timetable_entries) {
        if (entry.room == exam_entry.room &&
            times_overlap(exam_entry.start_time, exam_entry.end_time,
                          entry.start_time, entry.end_time)) {
            return {false, "Exam clashes with a scheduled class"};
        }
    }
    return {true, "Exam scheduled"};
}

// ---------------------------------------------------------------------------
// Q7(c) REFACTORING EXAMPLE
//
// BEFORE (original, duplicated validation logic written during Sprint 1):
//
// EntryResult submit_result(const std::string& student_id, double mark,
//                            const std::vector<std::string>& enrolled) {
//     bool found = false;
//     for (auto& s : enrolled) if (s == student_id) found = true;
//     if (!found) return {false, "Student not enrolled"};
//     if (mark < 0) return {false, "Invalid mark"};
//     if (mark > 100) return {false, "Invalid mark"};
//     return {true, "Result submitted"};
// }
//
// Problem noticed during pairing: the range check was split into two
// separate, repetitive conditions instead of one clear rule, and the
// "is enrolled" lookup was written inline instead of as a reusable helper.
//
// AFTER (refactored into clearer, reusable helpers):
// ---------------------------------------------------------------------------

inline bool is_valid_mark(double mark) {
    return mark >= 0 && mark <= 100;
}

inline bool is_enrolled(const std::string& student_id,
                         const std::vector<std::string>& enrolled_students) {
    for (const auto& s : enrolled_students) {
        if (s == student_id) return true;
    }
    return false;
}

inline EntryResult submit_result(const std::string& student_id, double mark,
                                  const std::vector<std::string>& enrolled_students) {
    if (!is_enrolled(student_id, enrolled_students)) {
        return {false, "Student not enrolled"};
    }
    if (!is_valid_mark(mark)) {
        return {false, "Invalid mark"};
    }
    return {true, "Result submitted"};
}
