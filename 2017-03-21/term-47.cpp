struct tag_input_iterator {};
struct tag_output_iterator {};
struct tag_forward_iterator : public tag_input_iterator{};
struct tag_bidirectional_iterator : public tag_forward_iterator{};
struct tag_random_access_iterator : public tag_bidirectional_iterator{};

