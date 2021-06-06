

#include <iostream>
#include <fstream>
#include <list>
#include <queue>

using namespace std;


//function to show list
void showlist(list <char> g)
{
    list <char> :: iterator it;
    for(it = g.begin();it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
//rubric cube class that contains the initial cube finalcube heroistic value of each state and weather it is visited or not 
class rubriccube
{   public:
    int cube[6][3][3];
    int finalcube[6][3][3];
    int heroval;
    int visited;
    
    bool operator>(rubriccube& node)
	{
		if(heroval>node.heroval)
                {
                    return true;
                }
               return false;
	}
    bool operator<(rubriccube& node)
	{
		if(heroval<node.heroval)
                {
                return true;
                }
                return false;
	}
    
    rubriccube()
    {
        
        
        heroval=0;
        visited=0;
    
    }
    
    /*rubriccube& operator=(rubriccube obj)
	{
		for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int z=0;z<3;z++)
                {
                    cube[i][j][z]=obj.cube[i][j][z];
                }

            }
        }

        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int z=0;z<3;z++)
                {
                    finalcube[i][j][z]=obj.finalcube[i][j][z];
                }

            }
        }
        heroval=obj.heroval;
        visited=obj.visited;
		return *this;
	}*/

    void inputfromfile()//takes input from file
    {
        fstream fin;
        fin.open("input.txt");

        string myarray;
        int intarray[54];

        getline(fin,myarray);

        int j=0;
        for(int i=0;i<108;i=i+2)
        {

            intarray[j]=myarray[i]-48;
            cout<<intarray[j]<<"  ";
            j++;
        }
        int k=0;
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                cube[0][i][z]=intarray[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                cube[5][i][z]=intarray[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                cube[2][i][z]=intarray[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                cube[3][i][z]=intarray[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                cube[1][i][z]=intarray[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                cube[4][i][z]=intarray[k];
                k++;
            }

        }




        string myarray2;
        int intarray2[54];

        getline(fin,myarray2);

        cout<<endl<<endl;

        j=0;
        for(int i=0;i<108;i=i+2)
        {

            intarray2[j]=myarray2[i]-48;
            cout<<intarray2[j]<<"  ";
            j++;
        }
        k=0;
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                finalcube[0][i][z]=intarray2[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                finalcube[5][i][z]=intarray2[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                finalcube[2][i][z]=intarray2[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                finalcube[3][i][z]=intarray2[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                finalcube[1][i][z]=intarray2[k];
                k++;
            }

        }
        for(int i=0;i<3;i++)
        {
            for(int z=0;z<3;z++)
            {
                finalcube[4][i][z]=intarray2[k];
                k++;
            }

        }
        
        heroval=0;



    }

    int heuristicfunction(rubriccube obj)// heuristic function for A*
 {
     int missmatchcount=0;
     
     for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int z=0;z<3;z++)
                {
                    if(obj.cube[i][j][z]!=obj.finalcube[i][j][z])
                    {
                        missmatchcount++;
                    }

                }
                
            }
            
        }
     
     
     return missmatchcount;
     
     
 
 
 }
    
    rubriccube copyfun(rubriccube obj)
    {
        rubriccube obj2;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int z=0;z<3;z++)
                {
                    obj2.cube[i][j][z]=obj.cube[i][j][z];
                }

            }
        }

        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int z=0;z<3;z++)
                {
                    obj2.finalcube[i][j][z]=obj.finalcube[i][j][z];
                }

            }
        }
        obj2.heroval=obj.heroval;
        visited=obj.visited;
        return obj2;

    }

    rubriccube clockwise(rubriccube obj,int phase) //moves on a cube which are clockwise on every phase
    {
        rubriccube obj2=obj.copyfun(obj);
        rubriccube obj3=obj.copyfun(obj);

        obj2.cube[phase][0][0]=obj3.cube[phase][2][0];
        obj2.cube[phase][0][1]=obj3.cube[phase][1][0];
        obj2.cube[phase][0][2]=obj3.cube[phase][0][0];
        obj2.cube[phase][1][0]=obj3.cube[phase][2][1];
        obj2.cube[phase][1][1]=obj3.cube[phase][1][1];
        obj2.cube[phase][1][2]=obj3.cube[phase][0][1];
        obj2.cube[phase][2][0]=obj3.cube[phase][2][2];
        obj2.cube[phase][2][1]=obj3.cube[phase][1][2];
        obj2.cube[phase][2][2]=obj3.cube[phase][0][2];

         if(phase==0)
         {
             obj2.cube[2][2][0]=obj3.cube[1][2][2];
             obj2.cube[2][2][1]=obj3.cube[1][1][2];
             obj2.cube[2][2][2]=obj3.cube[1][0][2];

             obj2.cube[4][0][0]=obj3.cube[2][2][0];
             obj2.cube[4][1][0]=obj3.cube[2][2][1];
             obj2.cube[4][2][0]=obj3.cube[2][2][2];

             obj2.cube[3][0][2]=obj3.cube[4][0][0];
             obj2.cube[3][0][1]=obj3.cube[4][1][0];
             obj2.cube[3][0][0]=obj3.cube[4][2][0];

             obj2.cube[1][0][2]=obj3.cube[3][0][0];
             obj2.cube[1][1][2]=obj3.cube[3][0][1];
             obj2.cube[1][2][2]=obj3.cube[3][0][2];

         }
         else if(phase==1)
         {
             obj2.cube[2][2][0]=obj3.cube[5][0][2];
             obj2.cube[2][1][0]=obj3.cube[5][1][2];
             obj2.cube[2][0][0]=obj3.cube[5][2][2];

             obj2.cube[0][0][0]=obj3.cube[2][0][0];
             obj2.cube[0][1][0]=obj3.cube[2][1][0];
             obj2.cube[0][2][0]=obj3.cube[2][2][0];

             obj2.cube[3][0][0]=obj3.cube[0][0][0];
             obj2.cube[3][1][0]=obj3.cube[0][1][0];
             obj2.cube[3][2][0]=obj3.cube[0][2][0];

             obj2.cube[5][2][2]=obj3.cube[3][0][0];
             obj2.cube[5][1][2]=obj3.cube[3][1][0];
             obj2.cube[5][0][2]=obj3.cube[3][2][0];


         }
         else if(phase==2)
         {
             obj2.cube[4][0][0]=obj3.cube[5][0][0];
             obj2.cube[4][0][1]=obj3.cube[5][0][1];
             obj2.cube[4][0][2]=obj3.cube[5][0][2];

             obj2.cube[0][0][0]=obj3.cube[4][0][0];
             obj2.cube[0][0][1]=obj3.cube[4][0][1];
             obj2.cube[0][0][2]=obj3.cube[4][0][2];

             obj2.cube[1][0][0]=obj3.cube[0][0][0];
             obj2.cube[1][0][1]=obj3.cube[0][0][1];
             obj2.cube[1][0][2]=obj3.cube[0][0][2];

             obj2.cube[5][0][0]=obj3.cube[1][0][0];
             obj2.cube[5][0][1]=obj3.cube[1][0][1];
             obj2.cube[5][0][2]=obj3.cube[1][0][2];

         }
         else if(phase==3)
         {
             obj2.cube[4][2][0]=obj3.cube[0][2][0];
             obj2.cube[4][2][1]=obj3.cube[0][2][1];
             obj2.cube[4][2][2]=obj3.cube[0][2][2];

             obj2.cube[5][2][0]=obj3.cube[4][2][0];
             obj2.cube[5][2][1]=obj3.cube[4][2][1];
             obj2.cube[5][2][2]=obj3.cube[4][2][2];

             obj2.cube[1][2][0]=obj3.cube[5][2][0];
             obj2.cube[1][2][1]=obj3.cube[5][2][1];
             obj2.cube[1][2][2]=obj3.cube[5][2][2];

             obj2.cube[0][2][0]=obj3.cube[1][2][0];
             obj2.cube[0][2][1]=obj3.cube[1][2][1];
             obj2.cube[0][2][2]=obj3.cube[1][2][2];

         }
         else if(phase==4)
         {
             obj2.cube[2][0][2]=obj3.cube[0][0][2];
             obj2.cube[2][1][2]=obj3.cube[0][1][2];
             obj2.cube[2][2][2]=obj3.cube[0][2][2];

             obj2.cube[5][2][0]=obj3.cube[2][0][2];
             obj2.cube[5][1][0]=obj3.cube[2][1][2];
             obj2.cube[5][0][0]=obj3.cube[2][2][2];

             obj2.cube[3][0][2]=obj3.cube[5][2][0];
             obj2.cube[3][1][2]=obj3.cube[5][1][0];
             obj2.cube[3][2][2]=obj3.cube[5][0][0];

             obj2.cube[0][0][2]=obj3.cube[3][0][2];
             obj2.cube[0][1][2]=obj3.cube[3][1][2];
             obj2.cube[0][2][2]=obj3.cube[3][2][2];


         }
         else if(phase==5)
         {
             obj2.cube[1][2][0]=obj3.cube[2][0][0];
             obj2.cube[1][1][0]=obj3.cube[2][0][1];
             obj2.cube[1][0][0]=obj3.cube[2][0][2];

             obj2.cube[3][2][2]=obj3.cube[1][2][0];
             obj2.cube[3][2][1]=obj3.cube[1][1][0];
             obj2.cube[3][2][0]=obj3.cube[1][0][0];

             obj2.cube[4][0][2]=obj3.cube[3][2][2];
             obj2.cube[4][1][2]=obj3.cube[3][2][1];
             obj2.cube[4][2][2]=obj3.cube[3][2][0];

             obj2.cube[2][0][0]=obj3.cube[4][0][2];
             obj2.cube[2][0][1]=obj3.cube[4][1][2];
             obj2.cube[2][0][2]=obj3.cube[4][2][2];

         }
        
        obj2.heroval=heuristicfunction(obj2);

         return obj2;



    }

    rubriccube Anticlockwise(rubriccube obj,int phase)//moves on a cube which are Anticlockwise on every phase
    {
        rubriccube temp=obj.clockwise(obj,phase);
        rubriccube temp2=temp.clockwise(temp,phase);
        rubriccube temp3=temp2.clockwise(temp2,phase);
        
        temp3.heroval=heuristicfunction(temp3);
        
        return temp3;
    }



};


bool compare(int cube1[6][3][3],int cube2[6][3][3])
{
    for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int z=0;z<3;z++)
                {
                    if(cube1[i][j][z]!=cube2[i][j][z])
                    {
                        return false;
                    }

                }

            }
        }
        return true;
}


 bool dfs(rubriccube obj,int depth,list<char> &steps) // recursive dfs function for solution 
    {

    char arraymovesclockwise[6]={'F','L','U','D','R','B'};
    char arraymovesanticlockwise[6]={'f','l','u','d','r','b'};

        if(compare(obj.cube,obj.finalcube))
        {
            return true;
        }

        if(depth==0)
        {
            return false;
        }

        for(int i=0;i<6;i++)
        {
            if(dfs(obj.clockwise(obj,i),depth-1,steps))
            {
                steps.push_back(arraymovesclockwise[i]);
                return true;
            }
        }


        for(int i=0;i<6;i++)
        {
            if(dfs(obj.Anticlockwise(obj,i),depth-1,steps))
            {
                steps.push_back(arraymovesanticlockwise[i]);

                return true;
            }
        }


        return false;

    }

 bool checkvisited(list <rubriccube> visitedarray,rubriccube obj)
 {
     list <rubriccube> :: iterator it;
    for(it = visitedarray.begin();it != visitedarray.end(); ++it)
    {
        if(compare(obj.cube,it->cube))
        {
            return true;
        }
        
        
    }
     return false;
 
 }
  class myComparator 
{ 
public: 
    int operator() (const rubriccube& p1, const rubriccube& p2) 
    { 
        return p1.heroval > p2.heroval;
    } 
}; 
 

 bool Astar(rubriccube obj)  // A* search
 {
     
    priority_queue <rubriccube, vector<rubriccube>, myComparator > que;
     obj.visited=1;
     que.push(obj);
     list <rubriccube> visitedarray;
     visitedarray.push_back(obj);
     
     while(que.empty() == false)
     {
         rubriccube temp=que.top();
         if(compare(temp.cube,temp.finalcube))
         {
             return true;
         }
         
        que.pop();
        for(int i=0;i<6;i++)
        {
            rubriccube temp2=temp.clockwise(temp,i);
            if(!checkvisited(visitedarray,temp2))
            {
                temp2.visited=1;
                visitedarray.push_back(temp2);
                que.push(temp2.clockwise(temp2,i));
            }
            
            
        }
        for(int i=0;i<6;i++)
        {
            rubriccube temp3=temp.Anticlockwise(temp,i);
            if(!checkvisited(visitedarray,temp3))
            {
                temp3.visited=1;
                visitedarray.push_back(temp3);
                que.push(temp3.Anticlockwise(temp3,i));
            }
        }
      
     
     }
     
     return false;
     
     
 
 }
 
 


 
 

int main()
{

   /* list <char> mysteps;
    rubriccube obj;

    obj.inputfromfile();

    cout<<endl<<endl;

        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int z=0;z<3;z++)
                {
                    cout<<obj.finalcube[i][j][z];

                }
                cout<<endl;
            }
            cout<<endl<<endl;
        }


        cout<<endl<<endl;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int z=0;z<3;z++)
                {
                    cout<<obj.cube[i][j][z];

                }
                cout<<endl;
            }
            cout<<endl<<endl;
        }


        cout<<endl<<endl;


        cout<<endl<<endl;

        obj=obj.clockwise(obj,0);

        obj=obj.clockwise(obj,1);

       obj=obj.clockwise(obj,2);

       obj=obj.clockwise(obj,3);


        obj=obj.clockwise(obj,4);


        obj=obj.clockwise(obj,5);

        if(compare(obj.cube,obj.finalcube))
        {
            cout<<"equal";

        }
        else{cout<<"not equal";}



        cout<<endl<<endl;
        cout<<endl<<endl;

    for(int i=0;i<10;i++)
    {


        if(dfs(obj,i,mysteps))
        {
            cout<<"solution found";
            break;

        }
        else{cout<<"solution not found";}

        cout<<endl;

    }




        cout<<endl<<endl;
        cout<<endl<<endl;

        cout<<"Solution in reverse order is : ";

        showlist(mysteps);
*/



    /*l[10], r[10];
    sum = 0;
    sum += abs(l[i] - r[i]);
    return 0;*/
    
    list <rubriccube> visitednodes;
    rubriccube obj;
    obj.inputfromfile();
    obj=obj.clockwise(obj,2);
   
    
    
    if(Astar(obj))
    {
        cout<<"solution found";
    }
    else
    {cout<<"not found";
    
    }
    
    
    
      
   
    
    
    
  
    return 0; 
    
    
    
    
}
