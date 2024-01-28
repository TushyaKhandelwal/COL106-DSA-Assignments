/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"
#include <iostream>
#include <string>

UnlimitedInt::UnlimitedInt()
{
    size = 1;
    sign = 1;
    capacity = 69;
    cout<<"maakichut"<<endl;
    unlimited_int= new int[capacity];
    unlimited_int[0]=0;
}

UnlimitedInt::~UnlimitedInt(){
    delete unlimited_int;
}

UnlimitedInt::UnlimitedInt(string s)
{
    
    if(s[0]=='-')
    {
        sign=-1;size=s.length()-1;capacity=69
        ;
        unlimited_int= new int[capacity];

        for(int i=size-1;i>=0;i--)
            {
                unlimited_int[size-1-i]=s[i+1]-'0';
                
            }
    }
    else
    {
    
        sign=1;size=s.length();capacity=69
        ;
        unlimited_int= new int[capacity];
        
        for(int i=size-1;i>=0;i--)
        {
            unlimited_int[size-1-i]=s[i]-'0';
            
        }

        /*cout<<size<<endl;
        cout<<s[1]<<"check"<<endl;
        */
    }
    for(int f =size; f<69;f++){unlimited_int[f]=0;}
    
}
UnlimitedInt::UnlimitedInt(int i)
{
    /*if(i<0){sign=-1;}
    else{sign=1;}*/
    string s = std::to_string(i);
    
    if(s[0]=='-')
    {
        
        sign=-1;size=s.length()-1;capacity=69
        ;
        
        unlimited_int= new int[capacity];
        for(int i=size-1;i>=0;i--)
            {
                unlimited_int[size-1-i]=s[i+1]-'0';
                
            }
        
    }
    else
    {
    
        sign=1;size=s.length();capacity=69
        ;
        unlimited_int= new int[capacity];
        
        for(int i=size-1;i>=0;i--)
        {
            unlimited_int[size-1-i]=s[i]-'0';
            
        }

        /*cout<<size<<endl;
        cout<<s[1]<<"check"<<endl;
        */
    }
    for(int f =size; f<69;f++){unlimited_int[f]=0;}
    
}

UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz)
{
    capacity= cap;
    sign = sgn;
    size = sz;
    unlimited_int = ulimited_int;
}



int UnlimitedInt::get_size(){
    return size;
}

int* UnlimitedInt::get_array(){
    return unlimited_int;
}

int UnlimitedInt::get_capacity(){
    return capacity;
}

int UnlimitedInt::get_sign(){
    return sign;
}

UnlimitedInt* UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2){
    
    
    bool flag = 0;
    if((*i1).size>(*i2).size){flag =1;}
    else if((*i1).size==(*i2).size){
        int c = (*i1).size;
        while(((*i1).unlimited_int[c]==(*i2).unlimited_int[c])and(c!=-1)){c--;}
        if ((*i1).unlimited_int[c]>(*i2).unlimited_int[c]and(c!=-1)){flag= 1;}
        else{flag= 0;}     
        if (c==-1 and (((*i1).sign == 1 and (*i2).sign==-1) or ((*i1).sign == -1 and (*i2).sign==1))){
            UnlimitedInt* zero = new UnlimitedInt(0);
            return zero;
        }
    } 
    
    if((*i1).sign == 1 and (*i2).sign==1){
    int *arr;
    arr = new int[69];
    for(int f =0; f<69;f++){arr[f]=0;}
    int carry=0;
    int cap =69;
    int sizer = max((*i1).size,(*i2).size);
    for(int i =0;i<sizer;i++){
        arr[i]=(carry+(*i1).unlimited_int[i]+(*i2).unlimited_int[i])%10;
        carry=(carry+(*i1).unlimited_int[i]+(*i2).unlimited_int[i])/10;
    }
    if (carry==1){arr[sizer]=1;sizer++;}
    UnlimitedInt* temp = new UnlimitedInt(arr, cap, 1,sizer);
    return temp;}

    else if((*i1).sign == 1 and (*i2).sign==-1 and flag == 1){
        int *arr;
        arr = new int[69];
        for(int f =0; f<69;f++){arr[f]=0;}
        int carry=1;
        int cap =69
        ;
        int sizer = max((*i1).size,(*i2).size);
        for(int i =0;i<=sizer;i++){
            arr[i]=(carry+(*i1).unlimited_int[i]+9-(*i2).unlimited_int[i])%10;
            carry=(carry+(*i1).unlimited_int[i]+9-(*i2).unlimited_int[i])/10;
    }
    while(arr[sizer-1]==0){sizer--;}
    UnlimitedInt* temp = new UnlimitedInt(arr, cap, 1,sizer);
    return temp; }


    else if((*i1).sign == 1 and (*i2).sign==-1 and flag == 0){
        int *arr;
        arr = new int[69];
        for(int f =0; f<69;f++){arr[f]=0;}
        int carry=1;
        int cap =69
        ;
        int sizer = max((*i1).size,(*i2).size);
        for(int i =0;i<=sizer;i++){
            arr[i]=(carry-(*i1).unlimited_int[i]+9+(*i2).unlimited_int[i])%10;
            carry=(carry-(*i1).unlimited_int[i]+9+(*i2).unlimited_int[i])/10;
    }
    while(arr[sizer-1]==0){sizer--;}
    UnlimitedInt* temp = new UnlimitedInt(arr, cap, -1,sizer);
    return temp;}

    else if((*i1).sign == -1 and (*i2).sign==-1){
        
    int *arr;
    arr = new int[69];
    for(int f =0; f<69;f++){arr[f]=0;}
    int carry=0;
    int cap =69;
    int sizer = max((*i1).size,(*i2).size);
    for(int i =0;i<=max((*i1).size,(*i2).size);i++){
        arr[i]=(carry+(*i1).unlimited_int[i]+(*i2).unlimited_int[i])%10;
        carry=(carry+(*i1).unlimited_int[i]+(*i2).unlimited_int[i])/10;
    }
    if (carry==1){arr[sizer]=1;sizer++;}
    UnlimitedInt* temp = new UnlimitedInt(arr, cap, -1,sizer);
    return temp;}

    else if((*i1).sign == -1 and (*i2).sign==1 and flag == 0){
        int *arr;
        arr = new int[69];
        for(int f =0; f<69;f++){arr[f]=0;}
        int carry=1;
        int cap =69;
        int sizer = max((*i1).size,(*i2).size);
        for(int i =0;i<=sizer;i++){
            arr[i]=(carry-(*i1).unlimited_int[i]+9+(*i2).unlimited_int[i])%10;
            carry=(carry-(*i1).unlimited_int[i]+9+(*i2).unlimited_int[i])/10;
    }
    while(arr[sizer-1]==0){sizer--;}
    UnlimitedInt* temp = new UnlimitedInt(arr, cap, 1,sizer);
    return temp; }

    else/*((*i1).sign == -1 and (*i2).sign==1 and flag == 1)*/{
       
        int *arr;
        arr = new int[69];
        for(int f =0; f<69;f++){arr[f]=0;}
        int carry=1;
        int cap =69;
        int sizer = max((*i1).size,(*i2).size);
        for(int i =0;i<sizer;i++){
            arr[i]=(carry+(*i1).unlimited_int[i]+9-(*i2).unlimited_int[i])%10;
            carry=(carry+(*i1).unlimited_int[i]+9-(*i2).unlimited_int[i])/10;
            
    }
    while(arr[sizer-1]==0){sizer--;}
    UnlimitedInt* temp = new UnlimitedInt(arr, cap, -1,sizer);
    return temp;}
    
    
}

UnlimitedInt* UnlimitedInt::sub(UnlimitedInt* i1, UnlimitedInt* i2){
    UnlimitedInt* temp = i2;
    temp->sign = -1;
    return (UnlimitedInt::add(i1, temp));
};

UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){
    UnlimitedInt* temp = new UnlimitedInt(0); 
    UnlimitedInt* temp1 = i1;
    int tempsigni1 = i1->sign;
    int prosign = (tempsigni1)*(i2->sign);
    temp1->sign =1;
    for(int i=0;i<(i2->size);i++){
        UnlimitedInt* temper = new UnlimitedInt(0);
        for(int j=0;j<i2->unlimited_int[i];j++){
        temper = UnlimitedInt::add(temper, temp1);
        }
        string tempstring = temper->to_string();
        for(int k = 0; k<i;k++){
            tempstring+='0';
        }
        UnlimitedInt* tempnew = new UnlimitedInt(tempstring);
        temp = add(tempnew, temp);
    }
    i1->sign=tempsigni1;
    temp->sign=prosign;
    return temp;
};

int flag(UnlimitedInt*i1, UnlimitedInt*i2){
    int flag = 0;
    int size1 = i1->get_size();
    int* arr1 = i1->get_array();
    int size2 = i2->get_size();
    int* arr2 = i2->get_array();
    if(size1>size2){return 1;}
    if(size1<size2){return -1;}
    else if(size1==size2){
        int c = size1;
        while((arr1[c]==arr2[c])and(c!=-1)){c--;}
        if (c==-1){return 0;}
        if (arr1[c]>arr2[c]and(c!=-1)){return 1;}
        else{return -1;}     
        
    }  
    return flag;
}

UnlimitedInt* UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2){

    /*UnlimitedInt* tempdividend = new UnlimitedInt(i1->to_string());
    UnlimitedInt* tenstring = new UnlimitedInt(1);
    UnlimitedInt* tenint = new UnlimitedInt(10);
    for(int i=0; i<(i2->size-i1->size);i++){
        tenstring = mul(tenstring,tenint);
    }
    string quotient;
    int current=1;
    while (sub(tempdividend,mul(i2,tenstring))>0){
        tempdividend= sub(tempdividend,mul(i2,tenstring));
        current++;   
    } current--;

    UnlimitedInt* tempdivisor;*/

    if(i1->size==1 and i1->unlimited_int[0]==0){return i1;}
    int ans_sign = i1->sign*i2->sign;
    if (flag(i1,i2)==-1){return new UnlimitedInt(0);}
    if (flag(i1,i2)==0 and ans_sign==1){return new UnlimitedInt(1);}
    else if(flag(i1,i2)==0 and ans_sign==-1){return new UnlimitedInt(-1);}

    int size1 = i1->size;
    int size2 = i2->size;


    UnlimitedInt* tempi2;
    if (i2->sign==-1){
        tempi2 = new UnlimitedInt(i2->to_string());
        UnlimitedInt* m_one = new UnlimitedInt(-1);
        tempi2 = mul(tempi2, m_one);
    }else{ tempi2 = new UnlimitedInt(i2->to_string());}

    int maxsize = size1 - size2 +1;
    int *arr = new int[69];
    UnlimitedInt* remainder = new UnlimitedInt(0);
    UnlimitedInt* divisor = tempi2;
    UnlimitedInt* ten = new UnlimitedInt(10);

    for(int i=size1-1;i>=0;i--){
        int digit =0;
        UnlimitedInt* current = new UnlimitedInt(i1->unlimited_int[i]);
        UnlimitedInt* tempdiv = add(current,mul(ten,remainder));
        while(flag(tempdiv,tempi2)!=-1){
            tempdiv = sub(tempdiv,tempi2);
            digit=digit+1;
        }
        arr[i]=digit;
        remainder = tempdiv;

    }
    UnlimitedInt* one = new UnlimitedInt(1);
    int sizer = maxsize;
    while(sizer>1 and arr[sizer-1]==0){
        sizer--;
    }

    UnlimitedInt* final = new UnlimitedInt(arr,69,ans_sign,sizer);
    if(ans_sign==1 and remainder->to_string()!="0"){
        final = sub(final,one);        
    }
    return final;


}

string UnlimitedInt::to_string(){
    
    string temp= "";
    if((*this).sign==1){
        
        for(int i=(*this).size-1;i>=0;i--){
        temp+=std::to_string((*this).unlimited_int[i]);
        
    }
    }else{temp ="-";
        for(int i=(*this).size-1;i>=0;i--){
        temp+=std::to_string((*this).unlimited_int[i]);
    }
    }
    return temp;
}

UnlimitedInt* UnlimitedInt::mod(UnlimitedInt*i1 , UnlimitedInt* i2){
    UnlimitedInt* temp;
    temp = div(i1, i2);
    temp = mul(i2,temp);
    temp = sub(i1,temp);
    return temp;

}
int main()
{
    cout<<"main"<<endl;
    UnlimitedInt* c = new UnlimitedInt(101); 
    UnlimitedInt* d = new UnlimitedInt(34);
    UnlimitedInt* a = UnlimitedInt::div(c,d);
    string lund = a->to_string();
    cout<<lund;
    return 0;
}