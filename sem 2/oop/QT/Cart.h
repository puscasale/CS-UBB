//
// Created by Ale on 05/16/2024.
//

#ifndef QT_CART_H
#define QT_CART_H
#include "Activity.h"
#include <vector>
#include "observer.h"
using std::vector;
class Cart:public Observable{
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
#endif //QT_CART_H
