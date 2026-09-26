#pragma once

#include <string>
#include <vector>

struct TimetableEntry {
    std::string course;
    std::string room;
    std::string instructor;
    int start_time;
    int end_time;
};

struct EntryResult {
    bool success;
    std::string reason;
};

inline bool times_overlap(int start1, int end1, int start2, int end2) {
    return start1 < end2 && start2 < end1;
}

inline bool is_room_conflict(const TimetableEntry& new_entry,
                              const std::vector<TimetableEntry>& existing_entries) {
    for (const auto& entry : existing_entries) {
        if (entry.room == new_entry.room &&
            times_overlap(new_entry.start_time, new_entry.end_time,
                          entry.start_time, entry.end_time)) {
            return true;
        }
    }
    return false;
}
inline bool is_instructor_conflict(const TimetableEntry& new_entry,
                                    const std::vector<TimetableEntry>& existing_entries) {
    for (const auto& entry : existing_entries) {
        if (entry.instructor == new_entry.instructor &&
            times_overlap(new_entry.start_time, new_entry.end_time,
                          entry.start_time, entry.end_time)) {
            return true;
        }
    }
    return false;
}
inline EntryResult create_timetable_entry(const TimetableEntry& new_entry,
                                           std::vector<TimetableEntry>& existing_entries) {
    if (is_room_conflict(new_entry, existing_entries)) {
        return {false, "Room conflict"};
    }
    if (is_instructor_conflict(new_entry, existing_entries)) {
        return {false, "Instructor conflict"};
    }
    existing_entries.push_back(new_entry);
    return {true, "Timetable entry published"};
}

