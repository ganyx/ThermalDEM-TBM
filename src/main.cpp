#include "soft_dynamics.h" 

//int main(int argc, char **argv)
int main(void)
{
omp_set_num_threads(NTHREADS); // MPI

     clock_t start, end;
     time_t  t0, t1;
     double cpu_time_used;
     double wall_time_used;

	
cout<<endl<<endl<<"Version 2013 for Integrated DEM simulations"<<endl<<endl;

cout<<"Select the branch for simulations, branches provide typical parameter presetting:"<<endl;
cout<<"\tLIB: DEM for Lithium-ion batteries"<<endl;
cout<<"\tNORMAL: Standard input"<<endl;
//string branch;
//cin>> branch;

cout<<"Type the action you want to perform (check the documentation for more details):"<<endl;
cout<<"\tCREATE: creates a new random configuration"<<endl;
cout<<"\tEVOLVE: reads an existing configuration and makes it evolves"<<endl;
//cout<<"\tPOST_PROCESS: reads an existing configuration and measures all sort of averages"<<endl;
//cout<<"\tVISUALISATION: reads an existing configuration and draws it on an opengl basis"<<endl;

string action;
cin>> action;

if(action!="CREATE" && action!="EVOLVE")
	{serror="The action '"+action+"' does not exit. Choices are  'CREATE' / 'EVOLVE'";
	STOP("main.cpp", "main()",serror);}
	
cout<<"The selected action is: "<<action<<endl<<endl;


if(action=="CREATE")//not parallel
{	
	Crun_create run;

	cout<<"Enter the path where to write the saving files (without final /) and the number of the file to be written (usually 1)"<<endl;
	cin>>run.where_save.path>>run.where_save.current_file;
	run.where_save.check_path('w');//check wheter the path already exist. If yes, stop.	
	
	run.config.create_random();	//create
	run.init_packing();
	run.config.fprint(run.where_save);//save
}


if(action=="EVOLVE")//can be parallel
	{
	Crun Lrun[1];//24 is the max number of processor
		
	Lrun[0].init_evolve();
	start = clock(); t0 = time(NULL);
	Lrun[0].evolve();
	
	end = clock();t1 = time(NULL);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC / NTHREADS;
	wall_time_used = t1-t0;
	cout<<"Number of CPUs:\t"<<NTHREADS<<endl;
	cout<<"CPU time (s):\t"<<cpu_time_used<<endl;
	cout<<"Wall time (s):\t"<<wall_time_used<<endl;
	}

	return(1);
}







      
     
