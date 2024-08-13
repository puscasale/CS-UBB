#include <vector>
#include <random>
#include <algorithm>
using std::shuffle;
#include "Cart.h"

void Cart::add_cart(const Activity &a) {
    this->cart.push_back(a);
    notify();
}

void Cart::empty() {
    this->cart.clear();
    notify();
}

void Cart::random_activity(int n, vector<Activity> activity) {
    shuffle(activity.begin(), activity.end(),std::default_random_engine(std::random_device{}()));
    while(cart.size() < n && activity.size() > 0)
        cart.push_back(activity.back()), activity.pop_back();
    notify();
}

const vector<Activity>& Cart::get_all_cart() {
    return this->cart;
}

