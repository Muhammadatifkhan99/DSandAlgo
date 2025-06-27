#include<bits/stdc++.h>


using namespace std;





int main(){


    // pair<int,int> p;
    // p = {1,2};
    // cout << p.first << p.second << endl;

    // pair<int,int> arr[] = {{1,2},{2,5},{5,1}};
    // cout << arr[1].first << endl;


    // vector<int> v;
    // v.push_back(121);
    // v.emplace_back(2);
    // cout << v[0] << " " << v[1] << endl;

    // v.emplace(v.begin(),1);

    // vector<int>::iterator it = v.begin();
    // it++;
    // cout << "v.begin(): " << *(it) << endl;

    // vector<int>::iterator i = v.end();
    // i--;
    // i--;
    // cout << "v.end(): " << *(i) << endl;


    // cout << "LOOPING ON VECTORS USING ITERATOR SYNTAX: " << endl;
    // vector<int> vec = {10,20,30,40};
    // for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
    //     cout << *(it) << endl;
    // }

    // cout << "LOOPING ON VECTORS USING SHORTER ITERATOR SYNTAX: " << endl;
    // for(auto it = vec.begin(); it != vec.end(); it++){
    //     cout << *(it) << endl;
    // }

    // cout << "LOOPING ON USING FOR EACH LOOP: " << endl;
    // for(auto it : vec){
    //     cout << it << endl;
    // }

    // cout << "ERASING FROM VECTOR: " << endl;

    // //{10,20,30,40};
    // vec.erase(v.begin()+1);
    // for(auto val : vec){
    //     cout << val << endl;
    // }

    // cout << "ERASING FROM VECTOR: " << endl;
    // vec.erase(v.begin()+2);
    // for(auto val : vec){
    //     cout << val << endl;
    // }

    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);
    ls.emplace_front();

    while (!ls.empty())
    {
        cout << ls.front() << endl;
        ls.pop_front();
    }

    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(4);
    s.insert(3);

    auto it = s.find(4); //return an iterator pointing at 4
    cout << *(it) << endl;

    cout << "Data inside the set" << endl;
    for(auto it:s){
        cout << it << endl;
    }

    cout << s.count(2) << endl;
    cout << s.count(8) << endl;


    cout << binary_search(s.begin(),s.end(),4) << endl;
    


    // //LOWER BOUND AND UPPER BOUND IN STL
    // cout << "LOWER BOUND IN STL" << endl;

    // vector<int> vt = {1,2,3,5,6,8};

    // int ind = lower_bound(vt.begin(),vt.end(),2) - vt.begin(); // returns the index
    // cout << ind << endl;
    // auto indi = lower_bound(vt.begin(),vt.end(),2); //returns the iterator to that element
    // cout << *(indi) << endl;
    // int ind1 = lower_bound(vt.begin(),vt.end(),4) - vt.begin(); // returns the index of the next greator element if the element is not found
    // cout << ind1 << endl;
    // int ind2 = lower_bound(vt.begin(),vt.end(),10) - vt.begin(); // returns the index of the next greator element if the element is not found
    // cout << ind2 << endl;


    // cout << "UPPER BOUND IN STL" << endl;

    // int indii = upper_bound(vt.begin(),vt.end(),4) - vt.begin();  //if 4 is found/not found it will return next greater element
    // cout << indii << endl;

    // int ind3i = upper_bound(vt.begin(),vt.end(),4) - vt.begin();
    // cout << ind3i << endl; //returns the next greater as 4 is not in the array 

    // int ind4i = upper_bound(vt.begin(),vt.end(),9) - vt.begin();
    // cout << ind4i << endl; // returns the end() of the vector bcose the element is not in the vector


    //Q. Find the last occurances of x in a sorted array, if it does not exists return -1;
    cout << "Question #1 " << endl;




    vector<int> vec1 = {1,2,4,4,4,4,9,9,10,10};
    int n = vec1.size();



    int x = 4;
    int index1 = upper_bound(vec1.begin(),vec1.end(),x) - vec1.begin();
    index1 --;
    if((index1 >= 0 ) && (vec1[index1] == x)) {
        cout << vec1[index1];}
    else 
        cout << -1;
    cout << endl;

    cout << "Question #2 " << endl;
    //{1,4,4,4,4,9,9,10,10};

    //find the first occurance of an element in an array

    x = 1;
    index1 = lower_bound(vec1.begin(),vec1.end(),x) - vec1.begin();
    if(index1 >= 0 && index1 <= n && vec1[index1] == x) cout << vec1[index1];
    else cout << -1 ;

    cout << endl;

    cout << "Question #3 " << endl;
    //{1,4,4,4,4,9,9,10,10};

    //find the largest numbelr smallar than x in a sorted array. if no number exists return -1;
    x = 2;
    index1 = lower_bound(vec1.begin(),vec1.end(),4) - vec1.begin();
    index1 --;
    if(index1 >= 0 && vec1[index1] == x) cout << vec1[index1];
    else cout << -1 ;


    




    






    // int numberOfTestCases;
    // cin >> numberOfTestCases;

    // for(int i{0};i<numberOfTestCases;i++){
    //     int n;
    //     cin >> n;
    //     pattern22(n);
    //     cout << endl;
    // }
    return 0;
}