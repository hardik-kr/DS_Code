#include<iostream>
#include<vector>
using namespace std;

int main(){
    int data;
    vector <int> v;
    while(cin>>data){
        
        v.push_back(data);
    }
    int size = v.size();
    int val = v[0];
    int zcr=0;
    int j=0;
    for(int i=1; i<size; i++){
     //   if(i%300 == 0)j++;
        if(val>0){
            if(v[i]<0){
                zcr++;
                val = v[i];
            }
        }
        else if(val<0){
            if(v[i]>0){
                zcr++;
                val = v[i];
            }
        }
    }
    /*int noofframe = 0;
    int sum = 0;
    for(int i=0;i<120;i++){
        if(zcr!=0){
            sum+=zcr[i];
            noofframe++;
        }
        else{
            break;
        }
    }
    cout<<sum/noofframe<<endl;*/
    cout<<zcr<<endl;
    return 0;
}