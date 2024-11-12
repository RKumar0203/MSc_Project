//  This macro converts raw .root file in a identified particles .root file


void ReadMacro()
{
	gBenchmark->Start("loop");



	



	TFile *f = new TFile("Au_Au_7.7GeV_run_8.root","READ");

	TFile *file = new TFile("Au_Au_7.7GeV_Particles_less.root","recreate");


	TH1F *h1 = new TH1F("Histogram","Net-Kaon Multiplicity Distribution",100,-50,50 );

	TTree *tree = new TTree("tree","tree");

	TTree *t = (TTree*)f->Get("hadronTree");





	//  Total Paticles 
	Int_t ro = 0;

	//Particle Variables
	Int_t NKaon,PKaon,PProton,NProton,Neutron,AntiNeutron,Lambda_zero,Sigma_minus,Sigma_plus,Sigma_zero,Xi_minus,Xi_zero,
	      Omega_minus,AntiLambda_zero,AntiSigma_minus,AntiSigma_plus,AntiSigma_zero,AntiXi_minus,AntiXi_zero,AntiOmega_minus;

	//Index Variable 
	Int_t i,j,k;			
	Int_t m;
	Int_t l;

	// Kinematic Variable
	Float_t Px,Py,Pz,pt,eta;
	Int_t id,mult,NPart;
	Float_t  phi;


	//Declaring Tree Branches 

	tree->Branch("refmult",&mult,"refmult/I");
	tree->Branch("NPart",&NPart,"NPart/I");
	tree->Branch("PKaon",&PKaon,"PKaon/I");
	tree->Branch("Neutron",&Neutron,"Neutron/I");
	tree->Branch("PProton",&PProton,"PProton/I");
	tree->Branch("Lambda_zero",&Lambda_zero,"Lambda_zero/I");
	tree->Branch("Sigma_minus",&Sigma_minus,"Sigma_minus/I");
	tree->Branch("Sigma_plus",&Sigma_plus,"Sigma_plus/I");
	tree->Branch("Sigma_zero",&Sigma_zero,"Sigma_zero/I");
	tree->Branch("Xi_minus",&Xi_minus,"Xi_minus/I");
	tree->Branch("Xi_zero",&Xi_zero,"Xi_zero/I");
	tree->Branch("Omega_minus",&Omega_minus,"Omega_minus/I");

	// For Anti-Particles
	tree->Branch("NKaon",&NKaon,"Nkaon/I");
	tree->Branch("AntiNeutron",&AntiNeutron,"AntiNeutron/I");
	tree->Branch("NProton",&NProton,"NProton/I");
	tree->Branch("AntiLambda_zero",&AntiLambda_zero,"AntiLambda_zero/I");
	tree->Branch("AntiSigma_minus",&AntiSigma_minus,"AntiSigma_minus/I");
	tree->Branch("Antisigma_plus",&AntiSigma_plus,"AntiSigma_plus/I");
	tree->Branch("AntiSigma_zero",&AntiSigma_zero,"AntiSigma_zero/I");
	tree->Branch("AntiXi_minus",&AntiXi_minus,"AntiXi_minus/I");
	tree->Branch("AntiXi_zero",&AntiXi_zero,"AntiXi_zero/I");
	tree->Branch("AntiOmega_minus",&AntiOmega_minus,"AntiOmega_minus/I");



	// Entry Variable
	Int_t entry = t->GetEntries();

	cout<<"Total Enteries are : "<<entry<<endl;

	cout<<"wait while program is running"<<endl;

	// Loop for Enteries
	for(i=1;i<=entry;i++)
	{


		t->SetBranchAddress("nMultiplicityTree",&mult);
		t->SetBranchAddress("nPartTree",&NPart);

		t->GetEntry(i);

		ro+=mult;


		//  Initialisation of Net-Proton Value in each Event to be zero 
		PKaon  = 0,NKaon = 0,PProton =0,NProton = 0,Neutron = 0,AntiNeutron = 0,Lambda_zero = 0,Sigma_minus = 0,Sigma_plus = 0,
		Sigma_zero = 0,Xi_minus = 0,Xi_zero = 0,Omega_minus = 0,AntiLambda_zero = 0,AntiSigma_minus = 0,
		AntiSigma_plus = 0,AntiSigma_zero = 0,AntiXi_minus = 0,AntiXi_zero = 0,AntiOmega_minus = 0;
		 
		
		// Loop over multiplicities
		for(j=1;j<=mult;j++)
		{
			id = t->GetLeaf("pidTree")->GetValue(j);

			pt = t->GetLeaf("ptTree")->GetValue(j);

			eta = t->GetLeaf("etaTree")->GetValue(j);

			if(pt>=0.2 && pt<= 2 && abs(eta)<1)     // Giving range to transverse momentum and rapidity 
			{
				if(id == 321){
					PKaon++;
				}
				if(id == -321)
				{
					NKaon++;
				}
				if(id == 2212)
				{
				PProton++;
				}
				if(id == -2212)
				{
				NProton++;
				}
				if(id == 2112)
				{
				Neutron++;
				}
				if(id == -2112)
				{
				AntiNeutron++;
				}
				if(id == 3122)
				{
				Lambda_zero++;
				}
				if(id == 3212)
				{
				Sigma_zero++;
				}
				if(id == 3222)
				{
				Sigma_plus++;
				}
				if(id == 3112)
				{
				Sigma_minus++;
				}
				if(id == 3322)
				{
				Xi_zero++;
				}
				if(id == 3312)
				{
				Xi_minus++;
				}
				if(id == 3334)
				{
				Omega_minus++;
				}
				if(id == -3122)
				{
				AntiLambda_zero++;
				}
				if(id == -3212)
				{
				AntiSigma_zero++;
				}
				if(id == -3222)
				{
				AntiSigma_minus++;
				}
				if(id == -3112)
				{
				AntiSigma_plus++;
				}
				if(id == -3322)
				{
				AntiXi_zero++;
				}
				if(id == -3312)
				{
				AntiXi_minus++;
				}
				if(id == -3334)
				{
				AntiOmega_minus++;
				}
			}





		} // End Multiplicity Loop 


		tree->Fill();


	} // End of  Event Loop 
	tree->Write();





	gBenchmark->Show("loop");    // To show the Cpu and Run Time

}          // End  of main loop
