#include "flapmap.hh"

void add_sample(uintptr_t start, size_t duration, size_t flapcount) {
    // Placeholders to avoid compiler warnings. Replace them with your code.
    assert(true);
    assert(duration>0); //will throw runtime error if this isn't true
    auto it = flapmap.insert({start, {.start=start, .duration=duration, .flapcount=flapcount}});

    //try to coalesce
    if (can_coalesce_up())

    //(void) start, (void) duration, (void) flapcount;  //void in paren and variable names is because C++ does bring up warnings when compile
}

bool has_sample(uintptr_t t) {
    // Placeholders to avoid compiler warnings. Replace them with your code.
    //(void) t; 
    for (auto it = flapmap.begin(); it!= flapmap.end(); it++) {
        if (it ->second.start <= t && it->second.start + it->second.duration >t) {
            return true;
        }
    }
    return false;
}

bool has_sample2(uintptr_t t) {
    auto it = flapmap.upper_bound(t).;
    if (it == flapmap.begin()) {
        return false;
    }
    it--;
    return it->second.start <= t && it->second.start + it->second.duration >t;
}

bool sample_overlaps(uintptr_t start, size_t duration) {
    // Placeholders to avoid compiler warnings. Replace them with your code.
    (void) start, (void) duration; 
	return false;
}

bool can_coalesce_up(flapmap_iter it) {
    // Placeholders to avoid compiler warnings. Replace them with your code.
    //void) it; 
    auto next = it;
    next++;
    if (next == flapmap.end()) {
        return false;
    }
    //key: it-> first
    //value: it->second
    assert(it -> first == it->second.start)
    // returns true if the current sample is aligned to the next one
    // will use in pset
	return it->second.start + it->second.duration == next->second.start
}

void coalesce_up(flapmap_iter it) {
    // Placeholders to avoid compiler warnings. Replace them with your code.
    //(void) it; 
    assert (can_coalesce_up(it))
    auto next = it;
    next++;
    it->second.duration += next->second.duration;
    flapmap.erase(next);
}

bool can_coalesce_down(flapmap_iter it) {
    // Placeholders to avoid compiler warnings. Replace them with your code.
    (void) it; 
	return false;
}

void print_flapmap() {
    for (auto it = flapmap.begin(); it != flapmap.end(); ++it) {
        fprintf(stderr, "[%zu, %zu): %zu\n", it->first, it->first + it->second.duration, it->second.flapcount);
    }
}


int main() {
	// Tests for add_sample

    // Should print nothing
    print_flapmap();
    fprintf(stderr, "\n");

    add_sample(1, 3, 1);
    add_sample(4, 3, 2);
    add_sample(8, 2, 1);
    // Should print three samples
    print_flapmap();

	// Add tests for other functions!

}