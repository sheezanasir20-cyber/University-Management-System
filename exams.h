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
