#include <iostream>
using namespace std;

char dType; //select domestic account type
double unit; //total e usage
char block; //block A: Consumption of 0 - 60 kWh per month. B: Consumption of above 60 kWh per month
double domesticCharge; //total electricity bill for domestic customer (tCharge+tax)
double tCharge; //sum of unit charge and fixed charge
const double pTax=0.025; //SSCL is charged at a rate of 2.5% from monthly electricity bills
double tax; //total tax amount for selected customer
double institutionCategoryCharge; //total electricity bill Religious & Charitable Institution Category (tCharge+tax)

//Domestic Category
void domestic () {

    //Prompt of Selection of domestic type
    cout << "................................................................................\n";
    cout<<"Select Domestic Type \n";
    cout << "................................................................................\n"
          "[N] Normal Domestic tariff structure \n"
          "[T] Time of Use Electricity tariff structure \n "
          "Type here (N/T) : ";
    cin>> dType;

    cout<<"";
    cout << "................................................................................\n\n\n";


    cout << "................................................................................\n";

    cout<<"Enter the Total Unit: ";
    cin>>unit;

    cout<<"";
    cout << "................................................................................\n\n\n\n";

    //For Normal Domestic tariff structure
    if (dType=='N') {

        //Consumption of 0 - 60 kWh per month.
        // Unit charges
        const double energyChargeA=12; //if unit>=30, energy charge (Rs/kWh) = Rs 12
        const double energyChargeB=30; //if 30<unit<=60, energy charge (Rs/kWh) = Rs 30

        //Fixed charges
        const double fixedChargeA=180; //if unit<=30, fixed charge (Rs/month) = Rs 180
        const double fixedChargeB=360; //if 30<unit<=60, fixed charge (Rs/month) = Rs 360


        //Consumption of above 60 kWh per month.
        // Unit charges
        const double energyChargeC=38; //if unit>=60, energy charge (Rs/kWh) = Rs 38
        const double energyChargeD=41; //if 60<unit<=90, energy charge (Rs/kWh) = Rs 41
        const double energyChargeE=59; //if 90<unit<=120, energy charge (Rs/kWh) = Rs 59
        const double energyChargeF=59; //if 120<unit<=180, energy charge (Rs/kWh) = Rs 59
        const double energyChargeG=89; //if unit>180, energy charge (Rs/kWh) = Rs 89

        //Fixed charges
        const double fixedChargeD=480; //if 60<unit<=90, fixed charge (Rs/month) = Rs 480
        const double fixedChargeE=1180; //if 90<unit<=120, fixed charge (Rs/month) = Rs 1180
        const double fixedChargeF=1770; //if 120<unit<=180, fixed charge (Rs/month) = Rs 1770
        const double fixedChargeG=2360; //if unit>180, fixed charge (Rs/month) = Rs 2360

        //switch
        if (unit<=60) {
            block = 'A';
        } else if (unit>60) {
            block = 'B';
        } else {
            cout<<"Invalid Entry!";
        }

        switch (block) {
            case 'A':
                // if unit>=30, charge calculation
                if (unit<=30) {
                    tCharge=((unit*energyChargeA)+fixedChargeA);
                    tax=tCharge*pTax;
                    domesticCharge=tCharge+tax;

                    // if 30<unit<=60, charge calculation
                } else if (unit>30 && unit<=60) {
                    tCharge=((unit*energyChargeB)+fixedChargeB);
                    tax=tCharge*pTax;
                    domesticCharge=tCharge+tax;

                }


                break;

            case 'B':
                // if unit<=60, charge calculation
                if (unit<=60) {
                    tCharge=unit*energyChargeC;
                    tax=tCharge*pTax;
                    domesticCharge=tCharge+tax;

                // if 60<unit<=90, charge calculation
                } else if (unit>60 && unit<=90) {
                    tCharge=((unit*energyChargeD)+fixedChargeD);
                    tax=tCharge*pTax;
                    domesticCharge=tCharge+tax;

                // if 90<unit<=120, charge calculation
                } else if (unit>90 && unit<=120) {
                    tCharge=((unit*energyChargeE)+fixedChargeE);
                    tax=tCharge*pTax;
                    domesticCharge=tCharge+tax;

                // if 120<unit<=180, charge calculation
                } else if (unit>120 && unit<=180) {
                    tCharge=((unit*energyChargeF)+fixedChargeF);
                    tax=tCharge*pTax;
                    domesticCharge=tCharge+tax;

                // if unit>180, charge calculation
                } else if (unit>180) {
                    tCharge=((unit*energyChargeG)+fixedChargeG);
                    tax=tCharge*pTax;
                    domesticCharge=tCharge+tax;

                }
        }

    //For Time of Use Electricity tariff structure
    } else if (dType=='E') {
        const double fixedChargeT=2360;
        const double dayTimeCharge=83; //Day Time (05:30 – 18:30), energy charge (Rs/kWh) = Rs 83
        const double peakTimeCharge=106; //Peak Time (18:30 – 22:30), energy charge (Rs/kWh) = Rs 106
        const double offPeakTimeCharge=35; //Off-Peak Time (22:30 – 05:30), energy charge (Rs/kWh) = Rs 35
        double dayTimeUnit; //Day Time unit count
        double peakTimeUnit; //Peak Time unit count
        double offPeakTimeUnit; //Off-Peak Time unit count

        //Prompt day time unit count
        cout<<"Enter Day Time Unit: ";
        cin>>dayTimeUnit;
        cout<<"";

        //Prompt peak time unit count
        cout<<"Enter Peak Time Unit: ";
        cin>>peakTimeUnit;
        cout<<"";

        //Prompt off-peak time unit count
        cout<<"Enter Off-Peak Time Unit: ";
        cin>>offPeakTimeUnit;
        cout<<"";

        //Calculating domestic charge for time use domestic customers
        tCharge=(dayTimeUnit*dayTimeCharge)+(peakTimeUnit*peakTimeCharge)+(offPeakTimeUnit*offPeakTimeCharge)+fixedChargeT;
        tax=tCharge*pTax;
        domesticCharge=tCharge+tax;

    } else {
        cout<<"Invalid Output!";
    }
}

//Religious and Charitable Institution Category
void religiousAndCharitableInstitutionCategory () {

    cout << "................................................................................\n";

    cout<<"Enter the Total Unit: ";
    cin>>unit;

    cout<<"";
    cout << "................................................................................\n\n\n\n";


    // Unit charges
    const double energyChargeA=12; //if unit<=30, energy charge (Rs/kWh) = Rs 12
    const double energyChargeB=24; //if 60<unit<=90, energy charge (Rs/kWh) = Rs 24
    const double energyChargeC=41; //if 90<unit<=120, energy charge (Rs/kWh) = Rs 41
    const double energyChargeD=53; //if 120<unit<=180, energy charge (Rs/kWh) = Rs 53
    const double energyChargeE=59; //if unit>180, energy charge (Rs/kWh) = Rs 59

    //Fixed charges
    const double fixedChargeA=180; //if unit<=30, fixed charge (Rs/month) = Rs 180
    const double fixedChargeB=300; //if 60<unit<=90, fixed charge (Rs/month) = Rs 300
    const double fixedChargeC=710; //if 90<unit<=120, fixed charge (Rs/month) = Rs 710
    const double fixedChargeD=1770; //if 120<unit<=180, fixed charge (Rs/month) = Rs 1770
    const double fixedChargeE=2360; //if 120<unit<=180, fixed charge (Rs/month) = Rs 2360

    //if unit<=30, charge calculation
    if (unit<=30) {
        tCharge=(unit*energyChargeA)+fixedChargeA;
        tax=tCharge*pTax;
        institutionCategoryCharge=tCharge+tax;

    //if 60<unit<=90, charge calculation
    } else if (unit>60 && unit<=90) {
        tCharge=((unit*energyChargeB)+fixedChargeB);
        tax=tCharge*pTax;
        institutionCategoryCharge=tCharge+tax;

    // if 90<unit<=120, charge calculation
    } else if (unit>90 && unit<=120) {
        tCharge=((unit*energyChargeC)+fixedChargeC);
        tax=tCharge*pTax;
        institutionCategoryCharge=tCharge+tax;

    // if 120<unit<=180, charge calculation
    } else if (unit>120 && unit<=180) {
        tCharge=((unit*energyChargeD)+fixedChargeD);
        tax=tCharge*pTax;
        institutionCategoryCharge=tCharge+tax;

        // if unit>180, charge calculation
    } else if (unit>180) {
        tCharge=((unit*energyChargeE)+fixedChargeE);
        tax=tCharge*pTax;
        institutionCategoryCharge=tCharge+tax;

    }

}

void finaloutput () {

    //final output
    cout << "................................................................................";
    cout << "\n                            BILL CALCULATOR           \n";
    cout << "                          Powered by THAMIZHI                                 \n";
    cout <<"................................................................................ \n";
    cout<<"Monthly Usage (Unit): "<<unit<<endl;
    cout<<"Monthly Usage: Rs "<<domesticCharge<<endl;
    cout << "................................................................................\n";
    cout<<"* The Public Utilities Commission of Sri Lanka approved the following Electricity \n Tariffs, effective from 20th October 2023 for all Tariff Consumer Categories. \n";
    cout<<"* As per the Social Security Contribution Levy (SSCL) Act No. 25 of 2022, SSCL is \n charged at a rate of 2.5% from monthly electricity bills of CEB customers \n effective from 1st October 2022. \n";
    cout<<"* Above tariff revision is hereby published in terms of Section 30 (2) (d) of \n the Sri Lanka Electricity Act, No. 20 of 2009. \n";
    cout << "................................................................................\n";
    cout << "................................................................................\n";

}

int main () {

    //Welcome Message
    cout << "\n\n"; 
    cout << "..............................................................................\n\n";
    cout << "           ...................................................\n";
    cout << "       |----------       CEYLON ELECTRICITY BOARD        ----------|\n";
    cout << "           ................................................... ";
    cout << "\n                            BILL CALCULATOR            \n";
    cout << "                          Powered by THAMIZHI                                 \n ";
    cout << "           ...................................................\n\n";
    cout << "................................................................................\n\n\n\n";

    char cType; // select CONSUMER CATEGORY

    cout << "................................................................................\n";
    cout<<"Select CONSUMER CATEGORY \n";
    cout << "................................................................................\n"
         "[D] Domestic Category \n"
         "[I] Religious & Charitable Institutions Category \n";
    cout<<"Enter your reply (D/I): ";
    cin>>cType;


    cout << "................................................................................\n";
    cout<<"\n\n";

    if (cType=='D') {
        cout << "................................................................................";
        cout << "\n                            DOMESTIC CATEGORY           \n";
        cout <<"................................................................................ \n";
        domestic();
        finaloutput();

    } else if (cType=='I') {
        cout << "................................................................................";
        cout << "\n                RELIGIOUS & CHARITABLE INSTITUTIONS CATEGORY           \n";
        cout <<"................................................................................ \n";
        religiousAndCharitableInstitutionCategory();
        finaloutput();

    } else {
        cout<<"Invalid Entry!";
    }
}