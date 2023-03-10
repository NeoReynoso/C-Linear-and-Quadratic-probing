//
//  main.cpp
//  Linear Quadratic Probing
//
//  Created by Ivan Reynoso on 1/25/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
#include <iostream>

#include <vector>

 

using namespace std;

const int TABLESIZE = 31;

 

//hash function defined as modulo operator

//receive an item key and return bucket index

template<typename T>

int hfun(T key)

{

        return key % TABLESIZE;

}

 

//insert an item in the hash table

//Collision resolution by Linear Probing

// retuns the number of collisions when inserting the key

template<typename T>

int hashInsertLprobe(vector<T>& h, T key)

{

        int bucket = hfun(key);

        int count = 0;

        while (count < TABLESIZE)

        {

                bucket = (bucket) % TABLESIZE;

                if (h[bucket] == -1 || h[bucket] == -2)

                {

                        h[bucket] = key;

                        break;

                }

                count++;

                bucket++;

        }

        return count;

}

 

template<typename T>

void printHashTable(vector<T>h)

{

        for (int i = 0; i < TABLESIZE; i++)

                cout << i << "---> " << h[i] << endl;

 

}

 

//hash insert, quadratic probing

// retuns the number of collisions when inserting the key

template<typename T>

int hashInsertQ(vector<T>& h, T key)

{

        int i = 0;

        int count = 0;

        int bucket = hfun(key);

        int bucket1 = bucket;

        while (count < TABLESIZE)

        {

                if (h[bucket] == -1 || h[bucket] == -2)

                {

                        h[bucket] = key;

                        break;

                }

                i++;

                bucket = (bucket1 + i + i * i) % TABLESIZE;

                count++;

        }

        return count;

}

 

int main()

{

        vector<int> hTableL(TABLESIZE, -1); //initialize the hash table (all cells set to -1)

        vector<int> hTableq(TABLESIZE, -1);

        int collisionCountL = 0;

        int collisionCountQ = 0;

        int x;

        cout << "Integers inserted into the hash:\n";

        for (int i = 0; i < 20; i++)

        {

                x = rand() % 101; //random integer between 0 and 100

                cout << x << "  "; // print list

                //insret key into the hash and increment collisions

                collisionCountL += hashInsertLprobe(hTableL, x);

                collisionCountQ += hashInsertQ(hTableq, x);

        }

        cout << endl;

        cout << "number of collisions for Linear probing: " << collisionCountL << endl;

        printHashTable(hTableL);

        cout << endl;

        cout << "number of collisions for quadratic probing: " << collisionCountQ << endl;

        printHashTable(hTableq);

        system("pause");

        return 0;

}
    return 0;
}
