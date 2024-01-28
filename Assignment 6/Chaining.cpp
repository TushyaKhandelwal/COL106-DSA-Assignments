#include "Chaining.h"
#include <iostream>
#include <vector>
using namespace std;

Chaining::Chaining(){
    size=0;
    for (int i=0;i<99991;i++){
        bankStorage2d.push_back({});
    }
}
void Chaining::mergesort(vector<int> &vec,int left,int right){
        if (left<right){
        int mid=(left+right)/2;
        mergesort(vec,left,mid);
        mergesort(vec,mid+1,right);
        merge(vec,left,mid,right);
    }
}

void Chaining::merge(vector<int> &vec,int left, int mid,int right){
    int Left[mid-left+2],Right[right-mid+1];
    for (int i=0;i<mid-left+1;i++){
        Left[i]=vec[left+i];
    } 
    Left[mid-left+1] = INT_MAX;

    for (int j=0;j<right-mid;j++){
        Right[j]=vec[mid+1+j];
    }
    Right[right-mid] = INT_MAX;

    int k=left;
    int i=0,j=0;
    while (i<mid-left+1 && j<right-mid){
        if (Left[i]<=Right[j]){
            vec[k]=Left[i];
            i++;
        } else{
            vec[k]=Right[j];
            j++;
        } k++;
    } 
   
}

void Chaining::createAccount(std::string id, int count) {
    Account new_acc;
    new_acc.id=id;
    new_acc.balance=count;
    int ind=hash(id);
    bankStorage2d[ind].push_back(new_acc);
    size+=1;
}

std::vector<int> Chaining::getTopK(int k){
    vector<int> vec={};
    for (int i=0;i<99991;i++){
        for (int j=0;j<bankStorage2d[i].size();j++){
            vec.push_back(bankStorage2d[i][j].balance);
            }
        } if (k>=size){
            int si=vec.size();
            mergesort(vec,0,si-1);
            vector<int> vec1={};
            for (int i=si-1;i>=0;i--){
                vec1.push_back(vec[i]);
            }
            return vec1;
        } else{
            int si=vec.size();
            mergesort(vec,0,si-1);
            vector<int> vec1={};
            for (int i=si-1;i>si-1-k;i--){
                vec1.push_back(vec[i]);

            } 
            return vec1;
        } 
        return vec;
    
}

int Chaining::getBalance(std::string id) {
    if (doesExist(id)==false){
        return -1;
    } else{
        int ind=hash(id);
        for (int j=0;j<bankStorage2d[ind].size();j++){
            if (bankStorage2d[ind][j].id==id){
                return bankStorage2d[ind][j].balance;
        }
    }  
    } 
    return -1;
}

void Chaining::addTransaction(std::string id, int count) {
    int ind=hash(id);
    if (doesExist(id)==true){
        for (int j=0;j<bankStorage2d[ind].size();j++){
            if (bankStorage2d[ind][j].id==id){
                   bankStorage2d[ind][j].balance+=count;
                   break;
        }
    }  
    } else{
        createAccount(id,count);
    } 
}

bool Chaining::doesExist(std::string id) {
    int ind=hash(id);
    bool flag=false;
    for (int j=0;j<bankStorage2d[ind].size();j++){
        if (bankStorage2d[ind][j].id==id){
            flag=true;
            break;
        }
    }
    return flag; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id) {
    if (doesExist(id)==false){
        return false;
    } else{
        int ind=hash(id);
        int m;
        for (int j=0;j<bankStorage2d[ind].size();j++){
        if (bankStorage2d[ind][j].id==id){
            m=j;
            break;
        }
    } bankStorage2d[ind].erase(bankStorage2d[ind].begin()+m);
        size=size-1;
        return true;
    }
}
int Chaining::databaseSize() {
    return size; // Placeholder return value
}

int Chaining::hash(std::string id) {
    int prod=1;
    int n= id.length();
    for (int i=0;i<n;i++){
        int c= (int)id[i];
        prod*=c;
        prod=prod%99991;
    }
    return prod; // Placeholder return value
}

