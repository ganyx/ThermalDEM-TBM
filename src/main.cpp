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

    // Branch information to preset the code
    cout<<"Select the branch for simulations, branches provide typical parameter presetting:"<<endl;
    cout<<"\tCREATE: prepare initial packing."<<endl;
    cout<<"\tLIB: DEM for Lithium-ion batteries"<<endl;
    cout<<"\tCAPDEM: DEM for capillary interaction"<<endl;
    cout<<"\tTBM: DEM code for fusion blanket TBM systems"<<endl;
    cout<<"\tNORMAL: Standard input"<<endl;
    cin>> BRANCH;
    
    // Boundary type: cubic box / cylidical + periodic / wall
    cout<<"Type of geometrical boundary, selection from below:"<<endl;
    cout<<"\tPERIODIC_BOX: periodic cubic box with stress/strain control at y-axis."<<endl;
    cout<<"\tPERIODIC_BOX_XYZ: periodic cubic box with stress/strain control at all direction."<<endl;
    cout<<"\tPERIODIC_TILT: tilting periodic cubic box."<<endl;
    cout<<"\tWALL_SHEAR: rough wall conditions."<<endl;
    cout<<"\tWALL_INCLINED: included wall condition."<<endl;
    cout<<"\tWALL_BOX: fixed wall condition at x, y and z-axis."<<endl;
    cout<<"\tWALL_BOX_Y: special case with WALL_BOX, walls at y-axis."<<endl;
    cout<<"\tWALL_BOX_XYZ: controllable wall conditions at all directions."<<endl;
    cout<<"\tBALL_BOX: rough walls at x, y, and z-axis."<<endl;
    cout<<"\tBALL_BOX_Y: rough walls at y-axis, periodic conditions at x and z-axis."<<endl;
    cout<<"\tCYLINDER: wall conditon with cyliderical container."<<endl;
    cout<<"\tPERIODIC_CYLINDER: periodic condition along cylinderical height."<<endl;
    cin>> BOUNDARY;

//if(action!="CREATE" && action!="EVOLVE")
//	{serror="The action '"+action+"' does not exit. Choices are  'CREATE' / 'EVOLVE'";
//	STOP("main.cpp", "main()",serror);}
//	
//cout<<"The selected action is: "<<action<<endl<<endl;


if(BRANCH=="CREATE")
{	
	Crun_create run;

	cout<<"Enter the path where to write the saving files (without final /) and the number of the file to be written (usually 1)"<<endl;
	cin>>run.where_save.path>>run.where_save.current_file;
	run.where_save.check_path('w');//check wheter the path already exist. If yes, stop.	
	
	run.config.create_random();	//create
	run.init_packing();
	run.config.fprint(run.where_save);//save the final configuration
}


if(BRANCH!="CREATE")
	{
        Crun Lrun;
		
	Lrun.init_evolve();
	start = clock(); t0 = time(NULL);
	Lrun.evolve();
	
	end = clock();t1 = time(NULL);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC / NTHREADS;
	wall_time_used = t1-t0;
	cout<<"Number of CPUs:\t"<<NTHREADS<<endl;
	cout<<"CPU time (s):\t"<<cpu_time_used<<endl;
	cout<<"Wall time (s):\t"<<wall_time_used<<endl;
	}

	return(1);
}







      
     
