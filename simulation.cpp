#include<iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>


using namespace std;
class montecarlosimulator{
    private:
       double S0,mu,sigma,volatility;
       int steps,simulations;

       double generatenormal(){
           double u1= ((double)rand()/ RAND_MAX);
           double u2 =((double)rand()/RAND_MAX);
           return sqrt(-2*log(u1)) * cos(2*3.14159265358979323846*u2);
       }
    public:
         montecarlosimulator(double inint_price , double drift , double volatility , int time_steps ,int sim_count ){
            S0 = inint_price;
            mu = drift;
            sigma = volatility;
            steps = time_steps;
            simulations = sim_count;
            srand(time(0));


         }
         vector<double>simulate(){
            vector<double> path;
            double S= S0;
            path.push_back(S);
            for(int i=1;i<=steps;i++){
                double Z =generatenormal();
                 S =S *exp((mu-0.5*sigma*sigma)+sigma*Z);

                path.push_back(S);
            }

            return path;
         }
         
         vector<vector<double>> run_simulation(){
            vector<vector<double>> final_prices;
            for(int i=1; i<= simulations;i++){
                final_prices.push_back(simulate());
            }


            return final_prices;

         }

};
// demo run 
int main(){
    double initial_price = 100.0;
    double drift = 0.05;            
    double volatility = 0.2;        
    int time_steps = 10;            
    int sim_count = 3;

    montecarlosimulator simulator(initial_price, drift, volatility, time_steps, sim_count);
    vector<vector<double>> results = simulator.run_simulation();

    cout << "Monte Carlo Simulation Results:" << endl;
    for (int j =0;j<results.size();j++) {
    cout<<"Simulation "<<j+1<<":  ";
    for (int k=0;k<results[j].size();k++) {
        cout<<results[j][k]<< " ";
    }
    cout << endl;
}
}