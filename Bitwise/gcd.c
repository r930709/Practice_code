#include<stdio.h>

/*
     wiki reference 1 -> https://en.wikipedia.org/wiki/Greatest_common_divisor 
     wiki reference 2 -> https://en.wikipedia.org/wiki/Binary_GCD_algorithm          

     18 = 2 x 3^2
     6 = 2 x 3  
     gcd(a,b) = g x 2^d 
     --------- d = 0,d count the number of times that a and b have been both divided by 2¡iremeber both!!¡j 
     --------- g must be odd¡ino matter 3 x 7 x 11 x ....¡j
     --------- It's because we use recursive algorithm, so we don't neet the variable d to record            

*/
/*
unsigned int Binary_gcd_recursive(unsigned int u,unsigned int v){
         
             if(u==v){    return(u);     }
             
             if(u==0){    return(v);     }     //Mistake-proofing input example(0,20)
             
             if(v==0){    return(u);     }     //Mistake-proofing input example(0,20)  
             
             if(~u & 1){    // confirm u is even
                     if(v & 1){    //confirm v is odd
                          return(Binary_gcd_recursive(u>>1,v));
                     }else{       //confirm v is even
                          return(Binary_gcd_recursive(u>>1,v>>1) <<1 );
                     }
                  
             }
             if(~v & 1){    //confirm u is odd,v is even                                     
                        return(Binary_gcd_recursive(u,v>>1));   
             
             }
             if(u>v){      //confirm u is odd,v is odd,and then compare¡iu>v¡j,reduce large argument
                           //odd - odd = even ,so need to divide 2          
                     return(Binary_gcd_recursive((u-v)>>1,v));      
             }
                            //confirm u is odd,v is odd,and then compare¡iv>u¡j,reduce large argument
                           //odd - odd = even ,so need to divide 2                                          
             return(Binary_gcd_recursive(u,(v-u)>>1));         
         }
*/
unsigned int Binary_gcd_iterative(unsigned int u,unsigned int v){
     
            int shift;        //d count the number of times that a and b have been both divided by 2                      
            
            /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
            if(u==0){    return(v);     }     
            if(v==0){    return(u);     }
            
            /*dividing both u and v. */
            for(shift = 0; (( u|v ) & 1)==0 ;shift++){   
                  u >>= 1;
                  v >>= 1;
                  
            }
            
            while((u&1)==0){     //if u is even ,and then divide 2 until it's an odd number
                  u >>= 1;         
            }
              /* From here on, u is always odd. */
            do{
                  
                  /* remove all factors of 2 in v -- they are not common */
                  /*   note: v is not zero, so while will terminate */
                  while((v&1)==0){   //if v is even ,and then divide 2 until it's an odd number
                         v >>= 1;         
                  }
                  /* Now u and v are both odd. Swap if necessary so u <= v,
                  then set v = v - u (which is even). For bignums, the
                  swapping is just pointer movement, and the subtraction
                  can be done in-place. */
                  
                  // we always  v = v - u to compare each other,so if u > v,and then we need to swap each other value
                  if(u > v){    // Swap u and v.        
                            u = u ^ v;
                            v = u ^ v;
                            u = u ^ v;
                  
                  }
                  
                   v = v - u;
                  
                  
            }while(v!=0);
            printf("shift %d\n",shift);
            return(u << shift);
     }

         

int main(){
    
    unsigned int a = 18,b = 6;
    
    //printf("Gcd(%d,%d) is %d\n",a,b,Binary_gcd_recursive(a,b));
    printf("Gcd(%d,%d) is %d\n",a,b,Binary_gcd_iterative(a,b));
    
    system("pause");
    return(0);
    }
