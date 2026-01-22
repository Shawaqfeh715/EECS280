// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt, modf

using namespace std;

int count(vector<double> v) {
    return v.size();
}

double sum(vector<double> v) {
       if (v.empty()){
          return 0.0;
       }

       double s=0.0;
       for (size_t i=0;i<v.size();i++){
           s+=v[i];
       }
       return s;
}

double mean(vector<double> v) {
       if (v.empty()){
          return 0.0;
       }
       return sum(v)/count(v);
}

double median(vector<double> v) {
       if (v.empty()){
          return 0.0;
       }
       std::sort(v.begin(),v.end());

       if (count(v)%2==0){
          size_t i=(count(v)+1)/2;
          return v[i];
       }else{
        size_t mid_idx1=count(v)/2-1;
        size_t mid_idx2=count(v)/2;
        return (v[mid_idx1]+v[mid_idx2])/2.0;
       }
       
}

double min(vector<double> v) {
       if (v.empty()){
          return 0.0;
       }
       double minimum=v[0];
       
       for (size_t i =0;i<v.size();i++){
           if (v[i]<minimum){
              minimum=v[i];
           }
       }

       return minimum;
}

double max(vector<double> v) {
       if (v.empty()){
          return 0.0;
       }

       double maximum=v[0];

       for (size_t i=0;i<v.size();i++){
           if (v[i]>maximum){
              maximum=v[i];
           }
       }

       return maximum;
}

double stdev(vector<double> v) {
       if (count(v)<2){
          return 0.0;
       }
       double mu=mean(v);

       double numerator;
       for (size_t i=0;i<v.size();i++){
           numerator+=(v[i]-mu)*(v[i]-mu);
       }
      double res =numerator/(count(v)-1);
      return sqrt(res);
}

double percentile(vector<double> v, double p) {
       if (v.empty() or p<0.0 or p>1.0){
          return 0.0;
       }
       double rank=p*(count(v)-1)+1;

       double k=0;
       double d=0;

       d=modf(rank,&k);

       std::sort(v.begin(),v.end());

       double vp=0.0;

       if (k+1>v.size())
       {
        return vp;
       }else{
         vp = v[k]+d*(v[k+1]-v[k]);
       }
       
       
       return vp;
}

vector<double> filter(vector<double> v,
                      vector<double> criteria,
                      double target) {
               vector<double> result;

               result.reserve(v.size());

               for (size_t i=0;i<v.size();++i){
                   if (criteria[i]==target)
                   {
                    result.push_back(v[i]);
                   }
                   
               }
               return result;
}
