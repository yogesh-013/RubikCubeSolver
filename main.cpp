#include <bits/stdc++.h>
using namespace std;
template <typename K , typename V >
class UnorderedMapProbing{
    public :
    static const int defaultCapacity = 19 ;
    pair<K , V> *table ;
    bool *occupied ;
    int capacity ;
    int count ;
    int hash(const K &key )const {
        return key%capacity ;
    }
    UnorderedMapProbing(int cap = defaultCapacity): capacity(cap) , count(0) {
        table = new pair<K,V> [capacity];
        occupied = new bool [capacity]() ;
    }
    ~UnorderedMapProbing(){
        delete [] table ;
        delete [] occupied ;
    }
    void rehashing(){
            pair<K , V > *newTable = new pair<K,V> [2*capacity] ;
            bool *newOccupied = new bool [2*capacity]() ;
            for(int i = 0; i < capacity ; i++){
                if(!occupied[i]){
                    newTable[i] = table[i] ;
                    newOccupied[i] = occupied[i] ;
                }
            }

            delete [] table ;
            delete [] occupied ;
            table = newTable ;
            occupied   = newOccupied ;
            capacity = 2*capacity ;

        }
    void insert(const K& key , const V& value ){

        int hashed = hash(key) ;
        while(occupied[hashed] && table[hashed].first != key){
             hashed = (hashed + 1)%capacity;
        }
        if(occupied[hashed] && table[hashed].first == key){
            table[hashed].second = value ;
             return  ;
        }
        if(count == capacity){
            rehashing() ;
        }
        table[hashed] = {key , value} ;
        occupied[hashed] = true ;
        count++ ;
    }

    bool contains(const K& key){
        int hashed = hash(key) ;
        while(occupied[hashed] && table[hashed].first != key){
            hashed = (hashed + 1)%capacity;
        }
        if(occupied[hashed]){
            return true  ;
        }
        return false ;
    }
    V get(const K& key){
        int hashed = hash(key) ;
     while(occupied[hashed] && table[hashed].first != key){
            hashed = (hashed + 1)%capacity;
        }
        if(occupied[hashed]){
            return table[hashed].second ;
        }
        return NULL   ;

    }

    void erase(const K& key){
        int hashed = hash(key) ;
         while(occupied[hashed] && table[hashed].first != key){
            hashed = (hashed + 1)%capacity;
        }
        if(occupied[hashed]){
           --count ;
           occupied[hashed] = false;
        }
    }
    size_t size(){
        return count ;
    }
    size_t capa(){
        return capacity ;
    }

};
int main() {
	  UnorderedMapProbing<int , int> mp;
	  mp.insert(90 , 34) ;
	  mp.insert(56 , 67);
	  mp.insert(41 , 10) ;
	  cout<<mp.size()<<endl ;
	  if(mp.contains(90)){
	      cout<<mp.get(90)<<endl  ;
	  }
	  mp.erase(32) ;
	  mp.erase(56) ;
	  cout<<mp.size()<<" "<<mp.capa()<<endl ;

}
