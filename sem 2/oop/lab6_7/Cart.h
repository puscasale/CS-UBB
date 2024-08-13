#include "Activity.h"
#include <vector>
using std::vector;
#ifndef LAB6_7_COS_H
#define LAB6_7_COS_H
class Cart{
private:
    vector<Activity> cart;
public:
    /**
     * Constructor
     */
    Cart() =default;

    /**
     * Adds an ativity to the cart
     * @param a : the activity
     */
    void add_cart(const Activity& a);

    /**
     * Empties the cart
     */
    void empty();

    /**
     * Adds a random amount of activities to the cart
     * @param n : the number
     * @param activity : a vector of all the activities
     */
    void random_activity(int n, vector<Activity> activity);

    /**
     * Returns all the activities from the cart
     */
    const vector<Activity>& get_all_cart();
};
#endif //LAB6_7_COS_H
