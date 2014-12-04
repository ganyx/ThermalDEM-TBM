void Crun::init_packing()
{	
	// System parameters for initial packing
	config.simule_thermal_conduction = false;
	config.simule_thermal_production = false;
	config.simule_thermal_expansion = false;
	config.cell.normal_stress_control=false; 
	config.cell.Vdilat=0; 
	config.cell.Adilat=0;
	config.cell.shear_stress_control=false; 
	config.cell.shear_rate = 0;
	config.parameter.MODULE_N = 1000;
	config.parameter.friction_coefficient = 0;
	config.parameter.tang_constant = 0;
	config.parameter.roll_constant = 0;
	
	config.parameter.bulk_conductivity = 1;
	config.parameter.specific_heat = 1;
	config.parameter.thermal_expansion = 0;
	
	LIQUID_TRANSFER = false;
	config.parameter.INITIAL_SATURATION = 0.5;
	config.parameter.FIXED_SATURATION = 0.5;
	config.parameter.CONTACT_ANGLE = PI/4.0;
	
	cout<<"Initial packing process started"<<endl<<endl;
	//time_step
	config.parameter.dimensionless_number(config.cell,config.P); //typical time scale and  dimensionless numbers
	
	dt = config.parameter.t_collision/10.; //some fraction of collision time

	//Particule update
	tstart = 0;
	tend = 100;
	save.next = 0;
	save.period = 10;
			
	screen.period=save.period; 
	screen.next=save.next;
	
	config.Voronoi_Update = true;	
	config.update_particle();
    config.update_wall();
	config.iterate(0.0);
	
	int vflag=0;
string his_file = where_save.path+"/ahistory";

double r0;
double c0 = 10.0;
double a0 = -exp(-c0*0.5);

for(config.t=tstart;config.t<tend;config.t+=dt)   //start time loop
	{
		config.iterate(dt); // make a evolution of configuration over a time step dt, with or without refreshing the neighbours
		
		r0 = R_SCALE_FACTOR-(R_SCALE_FACTOR-1.0)*(a0+exp(-(config.t-tstart)/(tend-tstart)*c0));
		r0 /= R_SCALE_FACTOR;
		if(r0>1.0) r0=1.0;
		
		for(int ip=0; ip<config.P.size();ip++){
			config.P[ip].R = r0 *config.P[ip].R_scale;
		}
		
		
		config.Voronoi_Update = false;
		if(vflag%20 == 0) config.Voronoi_Update = true;
		vflag++;
		
		if( save.should_do(config.t) ) //save if asked
		{ 
			config.fprint(where_save);
			where_save.current_file++;
		}

		if( config.t>=screen.next)     //print on screen if asked
		{ 
			screen.next += 1;
		
			double volume = 0.0;
			for(int ip=0; ip<config.P.size();ip++) 
				volume += pow(config.P[ip].R,3.0);
			volume *= 4.0 *PI /3.0 / (config.cell.L.x[0]*config.cell.L.x[1]*config.cell.L.x[2]);
		
		cout<<endl<<endl<<"Case: "<<where_save.path.c_str()<<endl; 
		cout<<"Progress: "<< config.t*100./(tend-tstart)<<" \% done"<<"\tTime step: "<<dt<<endl;
		cout<<"Number of grains: "<<config.P.size()<<"\tNumber of contact: "<<config.C.size()<<"\t Scaling R: "<<r0<<endl;
		cout<<"Volume Fraction: "<<volume<<"\t"<<"Stress level: "<<config.cell.stress.x[0][0]<<"/"
		<<config.cell.stress.x[1][1]<<"/"<<config.cell.stress.x[2][2]<<endl; 
		// history file
		ofstream file;	
		file.open(his_file.c_str(), std::ios_base::app); 
		file<<config.t<<"\t"<<volume<<"\t"<<config.cell.L.x[1]<<"\t"
		<<config.cell.stress.x[1][1]<<"\t"<<config.cell.stress.x[1][0]<<endl; 
		file.close();
		}
	}
    

    int ipflow = config.P.size();
    
    for(int ip=0; ip<config.P.size();ip++){
        config.P[ip].V *= 0.0;
        config.P[ip].Ome *= 0.0;
        
        // BALL_WALL_Y boundary conditions
        if(config.cell.boundary == "BALL_BOX_Y")
        {
        if(config.P[ip].X.x[1] >= config.cell.L.x[1]/2.0 - config.parameter.Dmax)
            config.P[ip].AM_I_BOUNDARY = 1;
        if(config.P[ip].X.x[1] <= -config.cell.L.x[1]/2.0 + config.parameter.Dmax)
            config.P[ip].AM_I_BOUNDARY = -1;
        if(config.P[ip].AM_I_BOUNDARY != 0) ipflow--;
        }
    }
    cout<<"The number of flowing particles is: "<<ipflow <<" out of total "<<config.P.size()<<" particles."<<endl;

	cout<<"Initial packing process finished: SUCCESS"<<endl<<endl;	
	return;
}