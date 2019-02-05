#include"Account_Xinyu_Lyu.h"
double Account::getCash_Balance()
{
	return Cash_Balance;                            //return the cash balance
}
void Account::setCash_Balance(double cashbalance)
{
	Cash_Balance = cashbalance;                        //set the cash balance
}
Account::~Account(){}                         //destruction
void Account::GetTime(int &hour, int &minute, int &second, int &day, int &month, int &year)
{
	time_t rtime;                                // typedefine
	struct tm Time;                           // make tm struct return local time as the tm stuct
	time(&rtime);                              // get the rtime to rtime
	localtime_s(&Time, &rtime);                // convert  the rtime to the  local time save and return in the struct Time
    minute = Time.tm_min;                     // set the minute information
	hour = Time.tm_hour; 
	year = Time.tm_year + 1900;
	second = Time.tm_sec;
	month = Time.tm_mon + 1;
	day = Time.tm_mday;
}
Account::Account()                                    //construction
{
	vector<double>  Total_Portfolio, Index = {};
}
void Account::Write_Graph_Data(DoubleLinkList & list)     
{
	double TotalVal = 0.0;
	ofstream Matlab_Graph;
	Matlab_Graph.open("Matlab_Graph.txt", std::ios::app);      //open file and write
	for (int i = 0; i < 20; i++)
	{
		TotalVal = list.getTolPortfolio() + getCash_Balance();
		Matlab_Graph << TotalVal << endl;
		list.changePrice();
	}
	Matlab_Graph.close();
}
void Account::View_Portfolio_Graph()
{
	Total_Portfolio.clear();
	Index.clear();
	ifstream Matlab_Graph;
	Matlab_Graph.open("Matlab_Graph.txt");
	double TotalVal = 0.0;
	while (Matlab_Graph >> TotalVal) {
		Total_Portfolio.push_back(TotalVal);
	}
	for (unsigned int i = 0; i <  Total_Portfolio.size(); i++) {
		Index.push_back(i + 1);
	}
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL) {
		cout << "Error: Engine Open Failed" << endl;
		exit(1);
	}
	/* Exapmles for matlab output sinx:
	double step[100];
	for(int i=0;i<100;i++)
	{
	step[i]=i/10.0;
	}
	mxArray *A;
	A=mxCreateDoubleMatrix(1, 100, mxREAL);
	memcpy((void*)mxGetPtr(A),(void*)step,sizeof(double)*100);
	engPutVariable(ep, "X", A);
	engEvalString(ep,"y=sin(x);");
	engEvalString(ep,"plot(x,y)");
	system("pause");
	mxDestroyArray(A);
	engEvalString(ep,"close;");
	engClose(ep);
	return 0;
	*/
	double* x_val = new double[Total_Portfolio.size()];
	double* y_val = new double[Total_Portfolio.size()];
	for (unsigned int i = 0; i <  Total_Portfolio.size(); i++) {
		y_val[i] = Total_Portfolio[i];
		x_val[i] = Index[i];
	}
	const int arraysize = Total_Portfolio.size();
	for (unsigned int i = 0; i <  Total_Portfolio.size(); i++) {
		cout << x_val[i] << "\t" << y_val[i] << endl;
	}
	mxArray* SIN = mxCreateDoubleMatrix(1,arraysize , mxREAL);
	memcpy((void *)mxGetPr(SIN), (void *)y_val, sizeof(double)*arraysize);
	engPutVariable(ep, "Y", SIN);
	mxArray* DEG = mxCreateDoubleMatrix(1,arraysize, mxREAL);
	memcpy((void *)mxGetPr(DEG), (void *)x_val, sizeof(double)*arraysize);
	engPutVariable(ep, "X", DEG);
	engEvalString(ep, "figure('units', 'normalized','outerposition', [0 0 1 1]),");
	engEvalString(ep, "plot (X, Y, 'r'), grid minor, title(' Total Portfolio Value'),");
	engEvalString(ep, "xlabel('Time'), ylabel('Total Portfolio Value ($)')");
	engEvalString(ep, "set(gca,'YTickLabel',num2str(get(gca,'YTick').'))");
	engEvalString(ep, "axis([-inf,inf,0,inf])");
}
