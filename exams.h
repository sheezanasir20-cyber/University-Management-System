// Sprint 1 - Examination Management (BEFORE REFACTOR VERSION - commit 3)
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

// Messy version: inline enrollment loop + repeated range checks
inline EntryResult submit_result(const std::string& student_id, double mark,
                                  const std::vector<std::string>& enrolled) {
    bool found = false;
    for (auto& s : enrolled) {
        if (s == student_id) found = true;
    }
    if (!found) return {false, "Student not enrolled"};
    if (mark < 0) return {false, "Invalid mark"};
    if (mark > 100) return {false, "Invalid mark"};
    return {true, "Result submitted"};
}
