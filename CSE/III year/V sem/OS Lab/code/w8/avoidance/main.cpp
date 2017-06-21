#include <stdlib.h>
#include <iostream>

int n, m, safe_count=0;

int *avail, **max, **alloc, **need, *work, *finish, *safe;

void computeVars(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
            std::cout<<need[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}

int checker(int l){
    for(int i=0; i<m; i++)
        if(need[l][i]>work[i])
            return 0;
    return 1;
}

int res_check(int pid, int a, int b, int c){
    if(a<=need[pid][0]&&b<=need[pid][1]&&c<=need[pid][2])
            return 1;
    return 0;
}
int res_check2(int pid, int a, int b, int c){
    if(a<=avail[0] && b<=avail[1] && c<=avail[2])
            return 1;
    return 0;
}

int fin_check(){
    for(int i=0; i<n; i++)
        if(finish[i]!=1)
            return 1;
    return 0;
}

int safety(){
    for(int i=0; i<m; i++)
        work[i] = avail[i];
    for(int i=0; i<n; i++)
        finish[i] = 0;

    while(fin_check()){
        int count = 0;
        for(int i=0; i<n; i++){
            if(finish[i]==0 && checker(i))
            {
                for(int j=0; j<m; j++){
                    work[j] = work[j] + alloc[i][j];
                    finish[i] = 1;
                }
                safe[safe_count++] = i;
                break;
            }
            else
                count++;
            if(count==n)
                return 0;
        }
        if(!fin_check())
            return 1;
    }
}

void allocator(){
    avail = new int[m];
    work = new int[n];
    finish = new int[n];
    safe = new int[n];
    max = new int*[n];
    need = new int*[n];
    alloc = new int*[n];
    for(int i=0; i<n; i++){
        max[i] = new int[m];
        need[i] = new int[m];
        alloc[i] = new int[m];
    }
}



int main()
{
    int c,t1,t2,t3,pid;
    std::cout<<"\nEnter number of processes - ";
    std::cin>>n;
    std::cout<<"\nEnter number of resources - ";
    std::cin>>m;
    allocator();
    for(int i=0; i<m; i++){
        std::cout<<"\nEnter instances of resource "<<i<<" - ";
        std::cin>>avail[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cout<<"\nALLOC PID "<<i<<" RES "<<j<<" -> ";
            std::cin>>alloc[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
     std::cout<<"\nMAX PID "<<i<<" RES "<<j<<" -> ";
            std::cin>>max[i][j];
        }
    }

    computeVars();
    while(1){
        std::cout<<"\nSystem is Safe";
        std::cout<<"\nRequest Interrupt ? : ";
        std::cin>>c;
        switch(c){
            case 0: continue;break;
            case 1: std::cout<<"\n PID R1 R2 R3 : ";
                    std::cin>>pid>>t1>>t2>>t3;
                    if(res_check(pid,t1,t2,t3)){
                        if(res_check2(pid,t1,t2,t3))
                        {
                            avail[0] -= t1;
                            avail[1] -= t2;
                            avail[2] -= t3;
                            alloc[pid][0] += t1;
                            alloc[pid][1] += t2;
                            alloc[pid][2] += t3;
                            need[pid][0] -= t1;
                            need[pid][1] -= t2;
                            need[pid][2] -= t3;

                            if(safety()){
                                std::cout<<"Request granted";
                            }
                            else{
                                std::cout<<"System unsafe Request cannot be granted";
                                avail[0] += t1;
                                avail[1] += t2;
                                avail[2] += t3;
                                alloc[pid][0] -= t1;
                                alloc[pid][1] -= t2;
                                alloc[pid][2] -= t3;
                                need[pid][0] += t1;
                                need[pid][1] += t2;
                                need[pid][2] += t3;
                            }
                        }
                        else{
                            std::cout<<"resource not available";
                        }
                    }
                    else
                        std::cout<<"Exceeded Max Claim\n";
                        break;
            case -1: return 0;
            deafult: break;
        }
    }
}
