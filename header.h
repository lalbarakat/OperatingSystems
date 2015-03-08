#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>

//Task class represents a task in a Job.
class task
{

  private:
    // member variables
    int task_id; // task id unqiue for each task in a job.
    int CPU_time; // Amount of time CPU takes to execute the task.
    int memory_required; // Amount of Main Memory required to execute the task.

  public :
   // Constructor
   task(int taskid, int cputime, int memoryrequired)
   {
     task_id = taskid;
     CPU_time = cputime;
     memory_required = memoryrequired;
   }

   //get functions
   int get_taskid() { return task_id;}
   int get_cputime() { return CPU_time;}
   int get_memrequired() { return memory_required;}

   //Set functions
   void set_taskid(int taskid) { task_id = taskid; }
   void set_cputime(int cputime) { CPU_time = cputime;}
   void set_memrequired(int memoryrequired) { memory_required = memoryrequired; }

};

class Job
{
  private :
    int job_id;
    std::vector <std::list<task> > adlist;

  public :
    Job()
    {
    }
    //constructor
    Job(int jobid, std::vector <std::list<task> > &graph)
    {
      job_id = jobid;
      adlist = graph;
    }
};

class Global_Clock
{
  int counter;
};

class JobGen_PJS : public Job
{
 public:
   JobGen_PJS() : Job(){}

};

class Node_PJS
{
};

class CCU_Node
{
  int memory_usage;
};

class PJS_Node
{

};

class CCU_PJS
{

};

class communication : Global_Clock, public JobGen_PJS, Node_PJS, CCU_Node, PJS_Node, CCU_PJS
{
  public:
     communication() {}
};

class Job_Generator : public communication
{


  std::vector<Job> list_jobs;


  public:


    void genereate_jobs(std::vector <std::list<task> > &Graph)
    {
      Job *job_obj = new Job(1,Graph);
      list_jobs.push_back(*job_obj);
    }
     
    void print_jobs()
    {
       std::vector<Job>::iterator itr;
  	for(itr=list_jobs.begin();itr!=list_jobs.end();itr++)
	  {
		Job *job = *itr;
		cout<< "job id" << job->job_id;
		cout<<"Graph";
	  }
  
    }
    
    void DFS(int el,std::vector <std::list<task> > &adlist,int visited[])
    {
	    cout<<"  element is  "<<el;
	    std::list<task> listt = adlist[el];
	    for(std::list<task>::iterator k = listt.begin();k!=listt.end();k++)
	    {
	      if(visited[*k]==0)
	      {
		 visited[*k] = 1;
		 DFS(*k,adlist,visited);
		 
	      }
	    }  
     }

};

class PJS : communication
{

};

class Apollo : PJS
{

};

class Baseline : PJS
{

};

class CCU : communication
{
  private:
    std::vector<std::vector<int>> wait_time_matrix;
    std::vector <Node*> node_list;
  public:
    int apply_matrix(Task t);
    void update_matrix();
};

class Node : communication
{

};


