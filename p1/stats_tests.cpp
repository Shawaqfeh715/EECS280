/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Statistics Project
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();


// Add prototypes for you test functions here.
void test_count();
void test_median();
void test_sum();
void test_min();
void test_mean();
void test_stdev();
void test_filter();
void test_percentile();
void test_max();

int main() {
  test_sum_small_data_set();
  test_count();
  test_filter();
  test_max();
  test_min();
  test_percentile();
  test_stdev();
  test_sum();
  test_mean();
  test_median();
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

// Add the test function implementations here

void test_sum(){
     cout<<"test function sum"<<endl;

     vector<double> data;
     data.push_back(2);
     data.push_back(3);
     data.push_back(4);

     assert(sum(data)==9.0);

     vector<double> data1;
     data1.push_back(2.1);
     data1.push_back(1.1);
     data1.push_back(0.1);

     assert((sum(data1)-3.3)<1e-9);

     vector<double> data2;
     data2.push_back(-1);
     data2.push_back(1);
     data2.push_back(0);

     assert(sum(data2)==0.0);

     vector<double>data3;
     
     data3.push_back(exp(1));
     data3.push_back(M_PI);
     data3.push_back(-1);

     const double tolerance=1e-9;

     assert(abs(sum(data3)-(exp(1)+M_PI-1.0))<tolerance);

     vector<double> data4;

     assert(sum(data4)==0.0);

     vector <double> data5;

     data5.push_back(1.2);

     assert(abs(sum(data5))-1.2<tolerance);

     vector <double> data6;

     data6.push_back(1e20);
     data6.push_back(2e20);
     data6.push_back(-1e20);

     const double tol=1e10;

     assert(abs(sum(data6)-2e20)<tol);

     cout<<"PASS"<<endl;
}

void test_mean(){

     vector<double> data1;
     data1.push_back(2);
     data1.push_back(4);
     data1.push_back(6);
     
     assert(mean(data1)==4.0);

     vector <double> data2;
     data2.push_back(1.5);
     data2.push_back(2.5);
     data2.push_back(3.0);
     assert(abs(mean(data2)-2.333333333)<1e-6);

     vector<double>data3;
     data3.push_back(-5);
     data3.push_back(-10);
     data3.push_back(-15);
     assert(mean(data3)==-10.0);

     vector<double> data4;
     data4.push_back(-2);
     data4.push_back(0);
     data4.push_back(2);
     assert(mean(data4)==0.0);

     vector<double>data6;
     data6.push_back(7.5);
     assert(mean(data6)==7.5);

     cout << "PASS!" << endl;
}

void test_median(){
     vector<double>data1;
     data1.push_back(3);
     data1.push_back(1);
     data1.push_back(5);
     assert(median(data1)==3.0);

     vector<double>data2;
     data2.push_back(1);
     data2.push_back(2);
     data2.push_back(3);
     data2.push_back(4);
     assert(median(data2)==2.5);


     vector<double>data3;
     data3.push_back(1);
     data3.push_back(2);
     data3.push_back(3);
     assert(median(data3)==2.0);

     vector<double> data4;
     data4.push_back(5);
     data4.push_back(-3);
     data4.push_back(0);
     data4.push_back(10);
     data4.push_back(-1);
     assert(median(data4)==0.0);

     vector<double>data5;
     assert(median(data4)==0.0);

     vector <double> data6;
     data6.push_back(42.0);
     assert(median(data6)==42.0);
     cout << "PASS!" << endl;
}

void test_count(){
     vector<double>data1;
     data1.push_back(1);
     data1.push_back(2);
     data1.push_back(3);
     assert(count(data1)==3);

     vector <double> data2;
     assert(count(data2)==0);

     vector<double> data3;
     data3.push_back(5.5);
     assert(count(data3)==1);

     vector<double>data4;
     for (int i=0;i<100;i++){
         data4.push_back(i);
     }
     assert(count(data4)==100);

     vector<double>data5;
     data5.push_back(1.0);
     data5.push_back(2.0);

     assert(count(data5)==2);

     vector<double> data6;
     data6.push_back(1.0);
     data6.push_back(1.0);
     data6.push_back(1.0);
     assert(count(data6)==3);

     cout << "PASS!" << endl;
}

void test_min(){
     vector<double>data1;
     data1.push_back(5);
     data1.push_back(2);
     data1.push_back(8);
     assert(min(data1)==2.0);

     vector<double> data2;
     data2.push_back(-5);
     data2.push_back(-2);
     data2.push_back(-10);
     assert(min(data2)==-10.0);

     vector<double>data3;
     data3.push_back(3);
     data3.push_back(-7);
     data3.push_back(0);
     assert(min(data3)==-7);

     vector<double> data4;
     data4.push_back(1);
     data4.push_back(5);
     data4.push_back(9);
     assert(min(data4)==1.0);

     vector<double>data5;
     assert(min(data5)==0.0);

     vector<double> data6;
     data6.push_back(3.14);
     assert(min(data6)==3.14);
     cout << "PASS!" << endl;
}

void test_max(){
     vector<double>data1;
     data1.push_back(5);
     data1.push_back(2);
     data1.push_back(8);
     assert(max(data1)==8.0);

     vector<double> data2;
     data2.push_back(-5);
     data2.push_back(-2);
     data2.push_back(-10);
     assert(max(data2)== -2.0);

     vector<double>data3;
     data3.push_back(3);
     data3.push_back(-7);
     data3.push_back(0);
     assert(max(data3)==3.0);

     vector<double> data4;
     data4.push_back(1);
     data4.push_back(5);
     data4.push_back(9);
     assert(max(data4)==9.0);

     vector<double>data5;
     assert(max(data5)==0.0);

     vector<double> data6;
     data6.push_back(3.14);
     assert(max(data6)==3.14);
     cout << "PASS!" << endl;
}

void test_stdev() {
    cout << "test function stdev" << endl;
    
    const double TOLERANCE = 1e-6;
    
    vector<double> data1;
    data1.push_back(2);
    data1.push_back(4);
    data1.push_back(4);
    data1.push_back(4);
    data1.push_back(5);
    data1.push_back(5);
    data1.push_back(7);
    data1.push_back(9);
    assert(abs(stdev(data1) - 2.138089935) < TOLERANCE);
    
    vector<double> data2;
    data2.push_back(5);
    data2.push_back(5);
    data2.push_back(5);
    assert(stdev(data2) == 0.0);
    
    vector<double> data3;
    data3.push_back(1);
    data3.push_back(3);
    assert(abs(stdev(data3) - 1.414213562) < TOLERANCE);
    
    vector<double> data4;
    data4.push_back(-2);
    data4.push_back(0);
    data4.push_back(2);
    assert(abs(stdev(data4) - 2.0) < TOLERANCE);
    
    vector<double> data5;
    assert(stdev(data5) == 0.0);
    
    vector<double> data6;
    data6.push_back(7.5);
    assert(stdev(data6) == 0.0);
    cout << "PASS!" << endl;
}

void test_percentile() {
    cout << "test function percentile" << endl;
    
    const double TOLERANCE = 1e-9;
    
    vector<double> data1;
    data1.push_back(1);
    data1.push_back(2);
    data1.push_back(3);
    data1.push_back(4);
    data1.push_back(5);
    assert(abs(percentile(data1, 0.5) - 3.0) < TOLERANCE);
    
    vector<double> data2;
    data2.push_back(10);
    data2.push_back(20);
    data2.push_back(30);
    assert(percentile(data2, 0.0) == 10.0);
    
    vector<double> data3;
    data3.push_back(10);
    data3.push_back(20);
    data3.push_back(30);
    assert(percentile(data3, 1.0) == 30.0);
    
    vector<double> data4;
    data4.push_back(1);
    data4.push_back(2);
    data4.push_back(3);
    data4.push_back(4);
    assert(abs(percentile(data4, 0.25) - 1.75) < TOLERANCE);
    
    vector<double> data5;
    assert(percentile(data5, 0.5) == 0.0);
    
    vector<double> data6;
    data6.push_back(1);
    data6.push_back(2);
    assert(percentile(data6, -0.5) == 0.0);
    assert(percentile(data6, 1.5) == 0.0);
    cout << "PASS!" << endl;
}

void test_filter() {
    cout << "test function filter" << endl;
    
    vector<double> data1;
    data1.push_back(10);
    data1.push_back(20);
    data1.push_back(30);
    vector<double> criteria1;
    criteria1.push_back(1);
    criteria1.push_back(0);
    criteria1.push_back(1);
    vector<double> result1 = filter(data1, criteria1, 1);
    assert(result1.size() == 2);
    assert(result1[0] == 10);
    assert(result1[1] == 30);
    
    vector<double> data2;
    data2.push_back(5);
    data2.push_back(10);
    vector<double> criteria2;
    criteria2.push_back(0);
    criteria2.push_back(0);
    vector<double> result2 = filter(data2, criteria2, 1);
    assert(result2.size() == 0);
    
    vector<double> data3;
    data3.push_back(1);
    data3.push_back(2);
    data3.push_back(3);
    vector<double> criteria3;
    criteria3.push_back(1);
    criteria3.push_back(1);
    criteria3.push_back(1);
    vector<double> result3 = filter(data3, criteria3, 1);
    assert(result3.size() == 3);
    
    vector<double> data4;
    data4.push_back(100);
    data4.push_back(200);
    data4.push_back(300);
    vector<double> criteria4;
    criteria4.push_back(2);
    criteria4.push_back(3);
    criteria4.push_back(2);
    vector<double> result4 = filter(data4, criteria4, 2);
    assert(result4.size() == 2);
    assert(result4[0] == 100);
    assert(result4[1] == 300);
    
    vector<double> data5;
    vector<double> criteria5;
    vector<double> result5 = filter(data5, criteria5, 1);
    assert(result5.size() == 0);
    
    vector<double> data6;
    data6.push_back(42);
    vector<double> criteria6;
    criteria6.push_back(1);
    vector<double> result6 = filter(data6, criteria6, 1);
    assert(result6.size() == 1);
    assert(result6[0] == 42);
    cout << "PASS!" << endl;
}
