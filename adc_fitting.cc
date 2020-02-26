#include"TApplication.h"
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<TROOT.h>
#include<TStyle.h>
#include<TGraph.h>
#include<TCanvas.h>
#include<TAxis.h>
#include<TMath.h>
#include<TH1.h>
#include<TGaxis.h>

// time-constant-dist.csv N=25
// single-charge.csv N=69

int main(int argc, char **argv){

  TApplication theApp("App",&argc,argv);
  char NoUse,filename[100];
  int j,N=61;
  Double_t x[N],px[N];

  std::ifstream data_file;
  sprintf(filename,"phe-fitting.csv");
  data_file.open(filename);
  if(!data_file) {
    printf("file open error \n");
  }
  else{
    for(j=0;j<N;j++){
      data_file >> x[j];
      data_file >> NoUse;
      data_file >> px[j];
    }
  }
  data_file.close();
  TCanvas c1;
  //c1.SetLogy();
  TGraph *gr=new TGraph(N,x,px);
  gr->SetFillColor(8);
  gr->Draw("AB");
  //gr->GetXaxis()->SetRangeUser(1900,3500);
  //gr->GetYaxis()->SetRangeUser(1,1e7);
  theApp.Run();
  return 0;
}
