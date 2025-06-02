🔎What is This?

This is a C++ project that simulates how a stock price could behave in the future using the Monte Carlo method and Geometric Brownian Motion (GBM). It’s built entirely with Object-Oriented Programming (OOP) principles to model real-world behavior in a modular and reusable way.

The simulator creates multiple possible future paths of a stock’s price, showing how volatility and randomness can affect financial forecasting.



📑The Math Behind It

We assume that the stock price follows Geometric Brownian Motion (GBM), a commonly used model in quantitative finance.

The formula used to evolve the stock price is:

S = S * exp((μ - 0.5 * σ²) + σ * Z)

Where:

S is the current stock price.

μ is the expected return (drift).

σ is the volatility (standard deviation of returns).

Z is a random number from the standard normal distribution (mean 0, std dev 1).

exp() is the exponential function.


This simulates log-normal returns by accounting for both expected growth and randomness.

The random number Z is generated using the Box-Muller transform:

double u1 = (double)rand() / RAND_MAX;
double u2 = (double)rand() / RAND_MAX;
Z = sqrt(-2 * log(u1)) * cos(2 * π * u2);

To ensure different outputs on every run, we use:

srand(time(0)); // Seeds



⚒️How to Use It

1. Compile the Code

g++ -o simulator main.cpp

2. Run the Program

./simulator

3. Example Output

Simulation 1: 100 103.12 107.45 105.30 ...
Simulation 2: 100 98.65 95.43 99.01 ...
Simulation 3: 100 101.22 104.88 107.65 ...

Each line represents a simulated future path of a stock's price, starting from the same initial price but following different trajectories due to randomness.




🧑🏻‍💻 Note

This project was created out of curiosity for financial modeling and the power of C++. It’s beginner-friendly but grounded in real financial mathematics. Fork it, use it, or build on it — all contributions are welcome!