/* CASE 380: RANDOMISED SET CLASS */

#include <stdlib.h> // rand()
#include <unordered_set>
#include <vector>

class RandomizedSet {
public:
    
    std::unordered_map<int, int> htable; // key holds vector index
    std::vector<int> values;
    
    RandomizedSet() {
        // BLANK for now
    }
    
    // note, htable.find(), htable[insertion], htable.erase() are all O(1)
    
    bool insert(int val) {
        if (htable.find(val) == htable.end()) {
            values.push_back(val); // push back is O(1)
            htable[val] = values.size() - 1; // store index of vector at this state
            return true;
        }
        return false;
        
    }
    
    bool remove(int val) { // tricky part
        if (htable.find(val) != htable.end()) {
            values[htable[val]] = values.back(); // find (htable find, O(1)), copy back (vector access, O(1)) there, eliminate val from vector
            values.pop_back(); // remove duplicate (vector pop back, O(1); generic remove is not O(1), so this is important)
            htable[values[htable[val]]] = htable[val]; // find (htable find, O(1))
            htable.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
        // rand() is an integer from 0 to at least 2^15 - 1
        // we can't use an iterator (types are different)
        // so we use the subscript [] operator instead
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/*

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
*/

/* Explanation of Remove()

First copy the back element of the vector to val's location in the vector by replacing val with the back element of vector. 
This effectively removes val from the vector.

Because you have a duplicate (two values.back()'s in the vector), you pop back. Popping back is O(1), since there's a pointer in the vector class to it.

Next, we update the hash table, which currently still has both val and its (old) vector location, and the (old) back element and its (old) vector location (at the back).
In the middle of the nested square brackets is the old index of val in the vector, which is now occupied by the old back. 
We want to store old back's new position in the hash table, so we access the vector 'values[location of val]' which is equal to old back. 
Now it is obvious that htable[values[location of val]] = htable[val] will update old back's new position, which changed to where val used to be.

Finally, htable.erase() eliminates val from the hash table.
*/
