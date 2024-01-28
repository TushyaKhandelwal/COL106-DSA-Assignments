/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"
// #include <iostream>
// using namespace std;
int flag(UnlimitedInt*i1, UnlimitedInt*i2){
    int flag = 0;
    int size1 = i1->get_size();
    int* arr1 = i1->get_array();
    int size2 = i2->get_size();
    int* arr2 = i2->get_array();
    if(size1>size2){return 1;}
    if(size1<size2){return -1;}
    else if(size1==size2){
        int c = size1-1;
        while((arr1[c]==arr2[c])and(c!=-1)){c--;}
        if (c==-1){return 0;}
        if (arr1[c]>arr2[c]and(c!=-1)){return 1;}
        else{return -1;}     
        
    }  
    return flag;
}

UnlimitedInt::UnlimitedInt()
{
    size=0;
    sign=0;
    capacity=0;

}
UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz)
{
    capacity = cap;
    size=sz;
    sign = sgn;
    unlimited_int= ulimited_int;
}
UnlimitedInt::UnlimitedInt(string s)
{
    if (s[0] == '-')
    {
        sign= -1;
        size = s.length()-1;
        capacity = size;
        unlimited_int = new int[size];
        for(int i =size-1; i>=0; i--)
        {
            unlimited_int[i]=static_cast<int>(s[size-i])- static_cast<int>('0');
        }

    }
    else
    {
        sign = +1;
        size = s.length();
        capacity = size;
         unlimited_int = new int[s.length()];
        for(int i =0;i<s.length();i++)
        {
            unlimited_int[s.length()-1-i]=static_cast<int>(s[i])- static_cast<int>('0');
        }
    }
    
}
UnlimitedInt::UnlimitedInt(int i)
{
    string s = std::to_string(i);
         if (s[0] == '-')
    {
        sign= -1;
        size = s.length()-1;
        capacity = size;
        unlimited_int = new int[size];
        for(int i =size-1; i>=0; i--)
        {
            unlimited_int[i]=static_cast<int>(s[size-i])- static_cast<int>('0');
        }

    }
    else
    {
        sign = +1;
        size = s.length();
        capacity = size;
         unlimited_int = new int[s.length()];
        for(int i =0;i<s.length();i++)
        {
            unlimited_int[s.length()-1-i]=static_cast<int>(s[i])- static_cast<int>('0');
        }
    }
}
UnlimitedInt::~UnlimitedInt()
{
    delete[]unlimited_int;
}
int UnlimitedInt::get_sign()
{
    return sign;
}
int UnlimitedInt::get_capacity()
{
    return capacity;
}
 int* UnlimitedInt::get_array()
 {
    return unlimited_int;
 }
int UnlimitedInt::get_size()
{
    return size;
}
string UnlimitedInt::to_string()
{
string s = "";
if(sign == -1) s+= "-";
for(int i = size - 1; i>=0;i--)
{
    s += char(unlimited_int[i] + int('0'));
}
return s;
}
UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2)
{
    int sz1 = i1->size;
    int sz2 = i2->size;
    int* prod = new int[i1->size+i2->size];
    for(int i=0; i<sz1+sz2;i++)
    {
        prod[i] =0;
    }
    int* tts = i1->unlimited_int;
    int* ass = i2->unlimited_int;
    for(int j=0;j<sz1;j++)
    {
        for(int k=0;k<sz2;k++)
    {
        int feet = tts[j]*ass[k];
        int thaigp = feet/10;
        prod[j+k] += feet%10;
        if(prod[j+k] >=10)
        {
            prod[j+k+1]+= prod[j+k]/10;
            prod[j+k] = prod[j+k]%10;
        }
        prod[j+k+1]+= thaigp;
    }

}
 int cmlto = sz1+sz2 ;
    while(cmlto>1 && prod[cmlto-1]==0)
    {
        cmlto-=1;
    }
UnlimitedInt* ans = new UnlimitedInt(prod,cmlto,i1->sign*i2->sign,cmlto);
return ans;

}
UnlimitedInt* UnlimitedInt:: add(UnlimitedInt* i1, UnlimitedInt* i2)
{
    if(i1->get_sign() == 1 && i2->get_sign() == 1)
    {
    int carry =0;
    int i=0;
    int j=0;
    string s = "";
    while(i<i1->get_size()|| j<i2->get_size()|| carry)
    {
        int sum =0;
        if(i<i1->size)
        {
            sum += i1->get_array()[i];
            i++;
        }
        if(j<i2->size)
        {
            sum += i2->get_array()[j];
            j++;
        }
        sum+=carry;
        carry = sum/10;
        char rem ='0' + sum%10;
        s = rem+s;
        


    }
    string ans = "";
if(s[0] == '-')
{
    ans += "-";
    int i = 1;
    while(s[i] == '0' and i < s.size())
    {
        i++;
    }
    if(i == s.size())
    {
        ans = "0";
    }
    else
    {
        while(i < s.size())
        {
            ans += s[i];
            i++;
        }
    }
}
else
{
    int i = 0;
    while(s[i] == '0' and i < s.size())
    {
        i++;
    }
    if(i == s.size())
    {
        ans = "0";
    }
    else
    {
        while(i < s.size())
        {
            ans += s[i];
            i++;
        }
    }
}
    return new UnlimitedInt(ans);
    }
    else if(i1->get_sign() == -1 && i2->get_sign() == -1)
    {

        UnlimitedInt* i3 = new UnlimitedInt(i1->to_string());
        i3->sign = 1;
        UnlimitedInt* i4 = new UnlimitedInt(i2->to_string());
        i4->sign = 1;
        UnlimitedInt* i5 = add(i3,i4);
        i5->sign = -1;
        return i5;
    }  
    else if(i1->get_sign() == -1)
    {
        UnlimitedInt* i6 = new UnlimitedInt(i1->to_string());
        i6->sign = 1;
        UnlimitedInt* ans = sub(i2,i6); 
        return ans;
}
  else if(i2->get_sign() == -1)
    {
        UnlimitedInt* i7 = new UnlimitedInt(i2->to_string());
        i7->sign = 1;
        UnlimitedInt* ans = sub(i1,i7); 
        return ans;

}
}
UnlimitedInt* UnlimitedInt:: sub(UnlimitedInt* i1, UnlimitedInt* i2)
{
    if(i1->sign == 1 && i2->sign ==1)
    {
    if(flag(i1,i2)==-1)
    {
        UnlimitedInt* i3 = sub(i2,i1);
        i3->sign=-1;
        return i3;
    }
    //cout << i1->to_string() <<endl << i2->to_string();
    int len1 = i1->size;
    int len2 = i2->size;
    int* result = new int[len1];
    int b = 0;
    int i = 0;
    while (i < len1) {
        int leftfoot = i1->unlimited_int[i];
        int rightfoot;
        if (i < len2) 
        {
            rightfoot = i2->unlimited_int[i];
        } 
        else
        {
            rightfoot = 0;
        }

        int d = leftfoot - rightfoot - b;

        if (d < 0) {
            d += 10;
            b = 1;
        } else {
            b = 0;
        }

        result[i] = d;
        i++;
    }
    int final_size = len1;
    while (final_size >= 2 && result[final_size - 1] == 0) {
        final_size--;
    }
    return new UnlimitedInt(result,final_size,1,final_size);
    }
    if(i1->sign <0 && i2->sign >0)
    {
        UnlimitedInt* i4 = new UnlimitedInt(i1->to_string());
        i4->sign = 1;
        UnlimitedInt* i3 = add(i4,i2);
        i3->sign = -1;
        return i3;
    }
     if(i1->sign >0 && i2->sign <0)
    {
        UnlimitedInt* i4 = new UnlimitedInt(i2->to_string());
        i4->sign = 1;
        UnlimitedInt* i3 = add(i1,i4);
        i3->sign = 1;
        return i3;
    }
    if(i1->sign <0 && i2->sign <0)
    {
        UnlimitedInt* i4 = new UnlimitedInt(i2->to_string());
        i4->sign = 1;
         UnlimitedInt* i5 = new UnlimitedInt(i2->to_string());
        i5->sign = 1;
        UnlimitedInt* i3 = sub(i4,i5);
        return i3;
    }
}
UnlimitedInt* UnlimitedInt:: div(UnlimitedInt* i1, UnlimitedInt* i2)
{
    if(i1->to_string() == "0" or i1->to_string() == "-0")
    {
        return new UnlimitedInt(0);
    }
    int len1 = i1->get_size();
    int len2 = i2->get_size();
    int slide = len1-len2;
    if(slide<0 && i1->get_sign()*i2->get_sign()==-1)
    {
        UnlimitedInt* ans = new UnlimitedInt(-1);
        return ans;
    }
    else if(slide<0 && i1->get_sign()*i2->get_sign()==1)
    {
         UnlimitedInt* ans = new UnlimitedInt(0);
        return ans;
    }

    else
    {
          UnlimitedInt* pns = new UnlimitedInt(i1->to_string());
          pns->sign=1;
          int* result = new int[len1-len2+1];
          for(int i=0;i<len1-len2+1;i++)
          {
            result[i] = 0;
          }
          while(slide>-1)
          {
            int* blz = new int[len2+slide];
            for(int i=len2+slide-1;i>-1;i--)
            {
                if (i>=slide)
                {
                    blz[i]=i2->unlimited_int[i-slide];
                }
                else
                {
                    blz[i]=0;
                }

            }
            UnlimitedInt* toes = new UnlimitedInt(blz,len2+slide,1,len2+slide);
            while(flag(pns,toes)>=0)
            {
                pns = sub(pns,toes);
                result[slide]+=1;
            }
            slide = slide-1;
          }
          int final_size = len1-len2+1;
          while(final_size>1 && result[final_size-1]==0)
          {
            final_size = final_size-1;
          }  
          UnlimitedInt* Quotient = new UnlimitedInt(result,final_size,1,final_size);
          if (i1->get_sign()*i2->get_sign()==-1)  
          {
            if(pns->size == 1 && pns->unlimited_int[0]==0)
            {
                Quotient->sign =-1;
            }
            else
            {
                Quotient = add(Quotient, new UnlimitedInt(1));
                Quotient->sign=-1;
                
            }
          }
          return Quotient;
    }
}
UnlimitedInt* UnlimitedInt::mod(UnlimitedInt*i1 , UnlimitedInt* i2){
    UnlimitedInt* temp;
    temp = div(i1, i2);
    temp = mul(i2,temp);
    temp = sub(i1,temp);
    return temp;

}
// int main()
// {
//     UnlimitedInt* a = new UnlimitedInt("43726648264786481364827364782647823");
//     UnlimitedInt* b = new UnlimitedInt("91283789217398127389127389127391273");
//     cout << UnlimitedInt::add(a,b)->to_string()<<endl;
//     cout << UnlimitedInt::sub(a,b)->to_string()<<endl;
//     cout << UnlimitedInt::div(a,b)->to_string();
//     }