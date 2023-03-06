struct container_traits {
    bool is_sorted;
    bool is_unique;
    bool is_ordered;
    bool is_map; // key-value structured container
};


template <typename T, typename Traits = container_traits>
class meta_container {
    // ...
};

using SortedUniqueContainer = meta_container<int, container_traits{true, true, true, false}>;
using SortedUniqueMapContainer = meta_container<int, container_traits{true, true, true, true}>;
using UnsortedUniqueContainer = meta_container<int, container_traits{false, true, true, false}>;
using UnsortedUniqueMapContainer = meta_container<int, container_traits{false, true, true, true}>;


container_traits make_container_properties(bool is_sorted = false, bool is_unique = true, bool is_ordered = true) {
    return {is_sorted, is_unique, is_ordered};
}
