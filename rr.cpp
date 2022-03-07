// Implementation of Round Robin, preemptive scheduling
#include<iostream>
#include<iomanip>
using namespace std;
class Process{
    public:
    static int quantum;
    int p_id,a_time,b_time,f_time,tat,wt;
    int temp;
    bool x,y;
    Process(){
        x=false;
        y=false; // To see if the process has already been entertained or not
    }
    void getdata(){
        cout<<"-------------------------------\n";
        cout<<"P-id : ";
        cin>>p_id;
        cout<<"Arrival Time : ";
        cin>>a_time;
        cout<<"CPU burst Time : ";
        cin>>b_time;
        temp=b_time;
        cout<<"-------------------------------\n";
    }
   
};
int Process::quantum=0;
void TurnAroundTime(Process p[],int n){
    for(int i=0;i<n;i++){
        p[i].tat=p[i].f_time-p[i].a_time;
    }
}
void WaitingTime(Process p[],int n){
    for(int i=0;i<n;i++){
        p[i].wt=p[i].tat-p[i].b_time;
    }
}
void CalculateAverage(Process p[],int n){
    float avg1=0,avg2=0;
    for(int i=0;i<n;i++){
        avg1+=p[i].tat;
        avg2+=p[i].wt;
    }
    avg1=avg1/n;
    avg2=avg2/n;
    cout<<"Average Turn Around Time : "<<avg1<<endl;
    cout<<"Average Waiting Time : "<<avg2<<endl;
}
void FinishTime(Process p[],int n){
    int curr_time=0;
    bool flag=false;
    int i=0,j=0,k=0;
    int prev_k=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=p[i].b_time;
    }
    while(curr_time<sum){
        flag=false;
        while(i<n){
            if(p[i].a_time<=curr_time&&p[i].y==false){
                 p[i].x=true;
                 j++;
            }
            i++;
        }
       for(k=prev_k;k<n;k++){
           if(p[k].x==true){
               
               if(p[k].temp<Process::quantum){
                   curr_time+=p[k].temp;
                   p[k].temp=0;
               }
               else{
                  curr_time+=Process::quantum; 
                  p[k].temp-=Process::quantum;
               }
               p[k].f_time=curr_time;
               if(p[k].temp==0){
                   p[k].y=false;
               }
           }
       }
       prev_k=k;
        if(flag==false){
            curr_time++;
        }
        i=j=0;
    }
    
}
int main(){
   int n;
   cout<<"Enter the total number of processes : ";
   cin>>n;
   int x;
   cout<<"Enter the time quantum for all the processes : ";
   cin>>x;
   Process::quantum=x;
   Process obj[10];
   for(int i=0;i<n;i++){
       obj[i].getdata();
   }
   FinishTime(obj,n);
   TurnAroundTime(obj,n);
   WaitingTime(obj,n);
   cout<<endl;
    cout
        << left
        << setw(7)
        << "P_id"
        << left
        << setw(15)
        << "Arrival Time"
        << left
        << setw(20)
        << "CPU Burst Time"
        << left
        << setw(15)
        << "Finish Time"
        << left
        << setw(20)
        << "Turn Around Time"
        << left
        << setw(15)
        << "Waiting Time"
        << endl;

    for (int i = 0; i < n; i++)
    {
        cout
            << left
            << setw(7)
            << obj[i].p_id
            << left
            << setw(15)
            << obj[i].a_time
            << left
            << setw(20)
            << obj[i].b_time
            << left
            << setw(15)
            << obj[i].f_time
            << left
            << setw(20)
            << obj[i].tat
            << left
            << setw(15)
            << obj[i].wt
            << endl;
    }
    CalculateAverage(obj,n);
   return 0;
}
