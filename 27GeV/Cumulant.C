#include<TMath.h>
#include<iostream>
#include<fstream>


void Cumulant()
{	cout<<endl;
	//cout<<"******************This is the calculation for centrality 70-80%**********************"<<endl<<endl;
	TFile *f=new TFile("NetKaon_27GeV.root");
	TH1F *h1 = (TH1F*)f->Get("h1");


	int ent = h1->GetEntries();
	cout<<"Total entry is ent :"<<ent<<endl;
	int i;
	double x = -50.;
	double y, y1;
	double sum = 0.,total = 0;
	double sum2 = 0.,c2;
	double sum3 = 0.,c3;
	double sum4 = 0.,c4;
	double sum5  = 0.,c5;
	double sum6 = 0.,c6;
	double sum7,sum8,sum9,sum10,sum11,sum12;
	double t1 =0. ;
	double norm =0.0;
	double s2,s3,s4;
	double ksigsqr;
	
	// Variables for Error estimation 
	double mu_1,mu_2,mu_3,mu_4,mu_5,mu_6,mu_7,mu_8,mu_9,mu_10,mu_11,mu_12;
	double m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12;
	double err_mean, err_sigma,error,err_ksigma,err_ssigma,err_sixorder;
	
	
	for(i=1;i<=h1->GetNbinsX();i++) { 
		y = h1->GetBinContent(i);
		sum+=x*y;
		total+=y;
		x++;
	}
	
	mu_1 = sum/total;
	
	cout<<"The value of first moment is   :"<< mu_1 <<endl;
	x = -50;
	for(i=1;i<=h1->GetNbinsX();i++) { 
		y = h1->GetBinContent(i);
		sum2+=(pow((x-mu_1),2))*y;
		x++;
	}
	
	mu_2 = sum2/total;
	double sigma = sqrt(mu_2);
	x = -50;

	for(i=1;i<=h1->GetNbinsX();i++) { 
		y = h1->GetBinContent(i);
		sum3+=(pow((x-mu_1),3))*y;
		sum4+=(pow((x-mu_1),4))*y;
		sum5+=(pow((x-mu_1),5))*y;
		sum6+=(pow((x-mu_1),6))*y;
		sum7+=(pow((x-mu_1),7))*y;
		sum8+=(pow((x-mu_1),8))*y;
		sum9+=(pow((x-mu_1),9))*y;
		sum10+=(pow((x-mu_1),10))*y;
		sum11+=(pow((x-mu_1),11))*y;
		sum12+=(pow((x-mu_1),12))*y;
		x++; 
	}
	
	mu_3 = sum3/total;
	mu_4 = sum4/total;
	mu_5 = sum5/total;
	mu_6 = sum6/total;
	mu_7 = sum7/total;
	mu_8 = sum8/total;
	mu_10 = sum10/total;
	mu_9 = sum9/total;
	mu_11 = sum11/total;
	mu_12 = sum12/total;
	
	
	// normalisation of cumulants 
	m3 = mu_3/pow(sigma,3);
	m4 = mu_4/pow(sigma,4);
	m5 = mu_5/pow(sigma,5);
	m6 = mu_6/pow(sigma,6);
	m7 = mu_7/pow(sigma,7);
	m8 = mu_8/pow(sigma,8);
	m9 = mu_9/pow(sigma,9);
	m10 = mu_10/pow(sigma,10);
	m11 = mu_11/pow(sigma,11);
	m12 = mu_12/pow(sigma,12);
	
	
	
	
	// Value of cumulants 
	c2 = mu_2;
	c3 = mu_3;
	c4 = mu_4-3*pow((mu_2),2);
	c5 = mu_5-5*mu_3*mu_2;
	c6 = mu_6-15*mu_4*mu_2-10*pow(mu_3,2)+30*pow(mu_2,3);
	
	
	// Error estimation using delta theorem
	
	err_mean = sigma/total;
	
	err_sigma = ((m4-1)*sigma*sigma)/(4*total);
	
	err_ssigma = (9-6*m4+m3*m3*(6+m4)-2*m3*m5+m6)*pow(sigma,2)/total;
	
	err_ksigma = ((-9+6*pow(m4,2)+pow(m4,3)+8*pow(m3,2)*(5+m4)-8*m3*m5+m4*(9-2*m6)-6*m6+m8)*pow(sigma,4))/total;
	
	err_sixorder = (10575-30*m10+m12+18300*pow(m3,2)+2600*pow(m3,4)-225*pow((-3+m4),2)-7440*m3*m5-520*pow(m3,3)*m5+216*m5*m5 
	-2160*m6-200*m3*m3*m6+52*m3*m5*m6+33*m6*m6+(-3+m4)*(10*(405-390*m3*m3+10*pow(m3,4)+24*m3*m5)-20*(6+m3*m3)*m6+m6*m6)+
	840*m3*m7-12*m5*m7+345*m8+20*m3*m3*m3*m8-2*m6*m8-40*m3*m9)*pow(sigma,8)/total;
	
	
	
	
	// Final Results
	
	cout<<"The value of second moment is : "<< mu_2 <<endl;
	cout<<"The value of third moment is  : "<< mu_3 <<endl;
	cout<<"The value of fourth moment is : "<<c4<<endl;
	cout<<"The value of ssigma  is : "<< c3/c2 << endl;
	cout<<"The value of Ksigmasquare is  : "<<c4/c2<<endl;
	cout<<"The error calculated in mean is : " << err_mean << endl;
	cout<<"The error calculated in sigma is : " << err_sigma << endl;
	cout<<"The error calculated in s_sigma is : " << err_ssigma << endl;
	cout<<"The error calculated in k_sigma is : " << err_ksigma << endl;
	cout<<"the value of sixth moment is  :"<<c6<<endl;
	cout<<"the value of ratio  c6/c2 is  :"<<(c6/c2)<<endl;
	cout<< " ther error in c6/c2 is : " << err_sixorder << endl;
	
	
	cout<< mu_1 <<"\t"<< mu_2 <<"\t" << mu_3 <<"\t" << c4 <<"\t"<< c3/c2 <<"\t"<< c4/c2 <<"\t"<< c6/c2 << endl;
	
	cout<<endl;


	
}
