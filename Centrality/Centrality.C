// This Macro takes input from .root file and calculate centrality for different classes

#include<TMath.h>
#include<iostream>


void Centrality()
{
	gBenchmark->Start("centrality");	
	TH1F *h1 = new TH1F("h1","For 0-5% Centrality",100,-50,50);


	TFile *f = new TFile("AmptAfterART7.root","READ"); // give you input file here
	

	TH1F *h = new TH1F("h","Net-Kaon",1765,0,1765);

	TTree *t = (TTree*)f->Get("AnaTree");
	int i;
	int j= 0,k = 0;


	int n = t->GetEntries();	
	cout<<"total entry is : "<<n<<endl;

	double Px,Py,Pz,Mass,id;
	int  mult,pkaon,nkaon,net;
	double m;

	double A;
	A=(n/20);
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

	// Extracting of refmult is from here 

	for(int i = n;i>0;i--)
	{

		int a=0,b=0;

		t->SetBranchAddress("refmult",&mult);
		t->GetEntry(i);

		Int_t bincontent = mult;
		h->Fill(bincontent);
	}
	h->Draw();

	double total = 0;


	for(int i=1765;i>=0;i--)
	{
		m = h->GetBinContent(i);
		total+=m;
	}
	cout<<"total as per calculation is :"<<total<<endl; 


	Int_t t1; 
	Int_t t2; 
	Int_t t3; 
	Int_t t4; 
	Int_t t5; 
	Int_t t6; 
	Int_t t7; 
	Int_t t8; 
	Int_t t9; 

	// Centrality calculation starts from here 
	double sum=0;
	for(Int_t j=1765;j>0;j--)
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
	for(Int_t j=1765;j>0;j--)
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
	for(Int_t j=1765;j>0;j--)
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
	for(Int_t j=1765;j>0;j--)
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
	for(Int_t j=1765;j>0;j--)
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
	for(Int_t j=1765;j>0;j--)
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
	for(Int_t j=1765;j>0;j--)
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
	for(Int_t j=1765;j>0;j--)
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
	for(Int_t j=1765;j>0;j--)
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

	cout<<"Centrality Calculation is done upto here "<<endl;



}

