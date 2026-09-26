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

// NOT YET IMPLEMENTED - placeholder, always returns false
inline bool is_room_conflict(const TimetableEntry& new_entry,
                              const std::vector<TimetableEntry>& existing_entries) {
    return false;   // TODO: implement conflict check
}

// NOT YET IMPLEMENTED - placeholder, always returns false
inline bool is_instructor_conflict(const TimetableEntry& new_entry,
                                    const std::vector<TimetableEntry>& existing_entries) {
    return false;   // TODO: implement conflict check
}

// NOT YET IMPLEMENTED - always "succeeds" without checking conflicts
inline EntryResult create_timetable_entry(const TimetableEntry& new_entry,
                                           std::vector<TimetableEntry>& existing_entries) {
    existing_entries.push_back(new_entry);
    return {true, "Timetable entry published"};   // TODO: check conflicts first
}
