// This macro is written for calculating the distribution for regular centrality intervals


void analysis()
{
	TCanvas *c1 = new TCanvas("c1","Net-Kaon");       
	TCanvas *c2 = new TCanvas("c2","Net-Kaon");
	TCanvas *c3 = new TCanvas("c3","Net-Kaon");
	TCanvas *c4 = new TCanvas("c4","Net-Kaon");
	TCanvas *c5 = new TCanvas("c5","Net-Kaon");
	TCanvas *c6 = new TCanvas("c6","Net-Kaon");
	TCanvas *c7 = new TCanvas("c7","Net-Kaon");
	TCanvas *c8 = new TCanvas("c8","Net-Kaon");
	TCanvas *c9 = new TCanvas("c9","Net-Kaon"); 


	TFile *f = new TFile("Particles_19.6_GeV.root","READ");
	TFile *f1   = new TFile("NetKaon_19.6GeV.root","RECREATE");

	TH1F *h1 = new TH1F("h1","For 0-5%  centrality",100,-50,50);
	TH1F *h2 = new TH1F("h2","For 5-10%  centrality",100,-50,50);
	TH1F *h3 = new TH1F("h3","For 10-20%  centrality",100,-50,50);
	TH1F *h4 = new TH1F("h4","For 20-30%  centrality",100,-50,50);
	TH1F *h5 = new TH1F("h5","For 30-40%  centrality",100,-50,50);
	TH1F *h6 = new TH1F("h6","For 40-50%  centrality",100,-50,50);
	TH1F *h7 = new TH1F("h7","For 50-60%  centrality",100,-50,50);
	TH1F *h8 = new TH1F("h8","For 60-70%  centrality",100,-50,50);
	TH1F *h9 = new TH1F("h9","For 70-80%  centrality",100,-50,50);
	TH1F *h10 = new TH1F("h10","",100,-50,50);

	TH1F *h = new TH1F("h","Net-Kaon",2880,0,2880);

	TTree *t = (TTree*)f->Get("tree");
	int i;
	int j= 0,k = 0;
	Double_t factor = 1.;
	

	int n = t->GetEntries();	
	cout<<"total entry is : "<<n<<endl;
	
	double Px,Py,Pz,Mass,id;
	int  mult,pkaon,nkaon,net;
	double m;
	
	  double A;
	  A=(n*0.05);
	  double B;
	  B=(n*0.1);
	  double C;
	  C=(n*0.2);
	  double D;
	  D=(n*0.3);
	  double E;
	  E=(n*0.4);
	  double F;
	  F=(n*0.5);
	  double G;
	  G=(n*0.6);
	  double H;
	  H=(n*0.7);
	  double I;
	  I=(n*0.8);

	
	for(int i = n;i>0;i--)
	{
	
                int a=0,b=0;

		t->SetBranchAddress("refmult",&mult);
		t->GetEntry(i);
		
		Int_t bincontent = mult;
		h->Fill(bincontent);
		}
		
		double total = 0;
		
		
		for(int i=2880;i>=0;i--)
		{
		m = h->GetBinContent(i);
		total+=m*i;
		}
		
		
		Int_t t1; 
Int_t t2; 
Int_t t3; 
Int_t t4; 
Int_t t5; 
Int_t t6; 
Int_t t7; 
Int_t t8; 
Int_t t9; 

  double sum=0;
  for(Int_t j=2880;j>0;j--)
  {  
    m=h->GetBinContent(j);
    sum=sum+m;
    if(sum>=A)
    {
      cout<<"5% centrality bin number"<<"    "<<j<<endl;
       t1=j;
      cout<<"t1"<<"="<<t1<<endl;
      break;
    
    }

    }
    sum=0;
    for(Int_t j=2880;j>0;j--)
  {  
    m=h->GetBinContent(j);
    sum=sum+m;
    if(sum>=B)
    {
      cout<<"10% centrality bin number"<<"    "<<j<<endl;
       t2=j;
      cout<<"t2"<<"="<<t2<<endl;
      break;
    
    }

    }
    sum=0;
    for(Int_t j=2880;j>0;j--)
  {  
    m=h->GetBinContent(j);
    sum=sum+m;
    if(sum>=C)
    {
      cout<<"20% centrality bin number"<<"    "<<j<<endl;
       t3=j;
      cout<<"t3"<<"="<<t3<<endl;
      break;
    
    }

    }
    
    sum=0;
    for(Int_t j=2880;j>0;j--)
  {  
    m=h->GetBinContent(j);
    sum=sum+m;
    if(sum>=D)
    {
      cout<<"30% centrality bin number"<<"    "<<j<<endl;
       t4=j;
      cout<<"t4"<<"="<<t4<<endl;
      break;
    
    }

    }
    sum=0;
    for(Int_t j=2880;j>0;j--)
  {  
    m=h->GetBinContent(j);
    sum=sum+m;
    if(sum>=E)
    {
      cout<<"40% centrality bin number"<<"    "<<j<<endl;
      t5=j;
      cout<<"t5"<<"="<<t5<<endl;
      break;
    
    }

    }
    
    sum=0;
    for(Int_t j=2880;j>0;j--)
  {  
    m=h->GetBinContent(j);
    sum=sum+m;
    if(sum>=F)
    {
      cout<<"50% centrality bin number"<<"    "<<j<<endl;
       t6=j;
      cout<<"t6"<<"="<<t6<<endl;
      break;
    
    }
    
    }
    
    sum=0;
    for(Int_t j=2880;j>0;j--)
  {  
    m=h->GetBinContent(j);
    sum=sum+m;
    if(sum>=G)
    {
      cout<<"60% centrality bin number"<<"    "<<j<<endl;
       t7=j;
      cout<<"t7"<<"="<<t7<<endl;
      break;
    
    }
    
    }
    
    sum=0;
    for(Int_t j=2880;j>0;j--)
  {  
    m=h->GetBinContent(j);
    sum=sum+m;
    if(sum>=H)
    {
      cout<<"70% centrality bin number"<<"    "<<j<<endl;
       t8=j;
      cout<<"t8"<<"="<<t8<<endl;
      break;
    
    }
    
    }
    
    sum=0;
    for(Int_t j=2880;j>0;j--)
  {  
    m=h->GetBinContent(j);
    sum=sum+m;
    if(sum>=I)
    {
      cout<<"80% centrality bin number"<<"    "<<j<<endl;
       t9=j;
      cout<<"t9"<<"="<<t9<<endl;
      break;
    
    }
    }
    t->SetBranchAddress("refmult",&mult);
		t->SetBranchAddress("PKaon",&pkaon);
		t->SetBranchAddress("NKaon",&nkaon);
    
    // For Centrality 0-5%
    for(int  i=1;i<=n;i++){
		
		t->GetEntry(i);
		
		if (mult>=t1){
		net = pkaon-nkaon;
		//cout<<" mult = "<<mult<<", PKaon = "<<pkaon<<", nkaon = "<<nkaon<<endl; 
		h1->Fill(net);
		
		}



// For Centrality 5-10
  
		
		if (mult>=t2&&mult<=t1){
		net = pkaon-nkaon;
		h2->Fill(net);
		
		
		
}


// For Centrality 10-20%
   
		
		if (mult>=t3&&mult<=t2){
		net = pkaon-nkaon;
		h3->Fill(net);
		
		
		
		
}



// For Centrality 20-30%
    
		
		if (mult>=t4&&mult<=t3){
		net = pkaon-nkaon;
		h4->Fill(net);
		
		
	
}


// For Centrality 30-40%
    
		
		if (mult>=t5&&mult<=t4){
		net = pkaon-nkaon;
		h5->Fill(net);
		
}


// For Centrality 40-50%
    
		
		if (mult>=t6&&mult<=t5){
		net = pkaon-nkaon;
		h6->Fill(net);
		
		
}



// For Centrality 50-60%
    
		
		if (mult>=t7&&mult<=t6){
		net = pkaon-nkaon;
		h7->Fill(net);
		
	
}


// For Centrality 60-70%
   
		
		if (mult>=t8&&mult<=t7){
		net = pkaon-nkaon;
		h8->Fill(net);
		
		
		
		
}
		
			




// For Centrality 70-80%
   
		
		if (mult>=t9&&mult<=t8){
		net = pkaon-nkaon;
		h9->Fill(net);
		
		
}
}


 c1->cd();
 h1->Draw();
 h1->Write();  
 c2->cd();
 h2->Draw();
 h2->Write();  
 c3->cd();
 h3->Draw();
 h3->Write();  
 c4->cd();
 h4->Draw();
 h4->Write();  
 c5->cd();
 h5->Draw();
 h5->Write();  
 c6->cd();
 h6->Draw();
 h6->Write();  
 c7->cd();
 h7->Draw();
 h7->Write();  
 c8->cd();
 h8->Draw();
 h8->Write();  
 c9->cd();
 h9->Draw(); 
 h9->Write();  
 
 


}
