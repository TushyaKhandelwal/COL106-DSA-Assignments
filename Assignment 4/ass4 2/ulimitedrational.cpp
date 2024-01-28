/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"

UnlimitedRational::UnlimitedRational(){
    p = new UnlimitedInt(1);
    q = new UnlimitedInt(1);
    
}

UnlimitedRational* lowerest(UnlimitedInt* i1, UnlimitedInt* i2){
    UnlimitedInt* big = new UnlimitedInt(i1->get_array(),69,1,i1->get_size());
    UnlimitedInt* small = new UnlimitedInt(i2->get_array(),69,1,i2->get_size());
    UnlimitedInt* temp;
    while(UnlimitedInt::mod(big,small)!=0){
        temp = big;
        big = small;
        small = UnlimitedInt::mod(temp,small);
    }
    
}






UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){
    UnlimitedInt* big = new UnlimitedInt(num->get_array(),69,1,num->get_size());
    UnlimitedInt* small = new UnlimitedInt(den->get_array(),69,1,den->get_size());
    UnlimitedInt* temp;
    UnlimitedInt* zero = new UnlimitedInt(0);
    while(UnlimitedInt::mod(big,small)!=zero){
        temp = big;
        big = small;
        small = UnlimitedInt::mod(temp,small);
    }
    p = UnlimitedInt::div(num,small);
    q = UnlimitedInt::div(den,small);

}
UnlimitedInt* UnlimitedRational::get_p(){
    return p;
}
UnlimitedInt* UnlimitedRational::get_q(){
    return q;
}

string UnlimitedRational::get_p_str(){
    return p->to_string();
}
string UnlimitedRational::get_q_str(){
    return q->to_string();
}

string UnlimitedRational::get_frac_str(){
    return p->to_string() + "/" + q->to_string();
}

UnlimitedRational*  UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt* tempnum;
    UnlimitedInt* tempden;
    tempnum = UnlimitedInt::add(UnlimitedInt::mul(i1->p,i2->q),UnlimitedInt::mul(i1->q,i2->p));
    tempden = UnlimitedInt::mul(i1->q,i2->q);
    return new UnlimitedRational(tempnum,tempden);
}

UnlimitedRational*  UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt* tempnum;
    UnlimitedInt* tempden;
    tempnum = UnlimitedInt::sub(UnlimitedInt::mul(i1->p,i2->q),UnlimitedInt::mul(i1->q,i2->p));
    tempden = UnlimitedInt::mul(i1->q,i2->q);
    return new UnlimitedRational(tempnum,tempden);
}

UnlimitedRational* UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt* tempnum;
    UnlimitedInt* tempden;
    tempnum = UnlimitedInt::mul(i1->p,i2->p);
    tempden = UnlimitedInt::mul(i1->q,i2->q);
    return new UnlimitedRational(tempnum, tempden);

}

UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt* tempnum;
    UnlimitedInt* tempden;
    tempnum = UnlimitedInt::mul(i1->p,i2->q);
    tempden = UnlimitedInt::mul(i1->q,i2->p);
    return new UnlimitedRational(tempnum, tempden);
    
}