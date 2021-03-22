#include <cmath>

class Base {        // The class
  public:              // Access specifier
    int Q; // Total Capacity (Discharge cell 100% to 0% SOC), Ah or mAh
    float charge_capacity; // 0-100% SOC 
    int delta_t; // Iterations of time per sample
    float delta_i; // Current applied to battery, A
    float C1 = delta_t_graph/(5*R1); // Capacitor in Thevenin RC Model, calculated from Graph

    float v0; // Instantaneous voltage once constant current removed
    float R0=v0/delta_i;
    float v_inf; // Measured once Voltage stabilizes
    float R1=v_inf/delta_i-R0; // Resistor in Thevenin RC Model, Calculated from graph    
    float delta_t_graph; // Time to reach steady state from graph
    float eta=Q/charge_capacity; //Coluombic Efficieny, eta

};

// Derived class
class SOC: public Base {
  public:
    void SOC_calc() {
        for (int k=0; k<5; k++) {
            z[k+1] = z[k]-delta_t/Q*i[k];
        }
    void SOC_with_Coulombic_efficieny() {
        for (int k=0; k<5; k++) {
            z[k+1] = z[k]-i[k]*eta[k]*delta_t/Q;
        }
    }

    void resistor_current() {
      i_R1[k+1] = exp(-delta_t/(R1*C1))*i_R1[k]+(1-exp(-delta_t/(R1*C1)))*i[k];
    }

    void cell_terminal_voltage() {
      v[k]=OCV(z[k])-R1*i_R1[k]-R0*i[k];
    }
};

class Hysteresis : public Base {
  // For every SOC, range of possible stable "OCV" values
  public:
    int gamma // rate_of_decay
    void unitless_hysteresis_state() {
      h[k+1] = exp(-(abs(eta*i[k]*delta_t/Q)))*h[k] - (1-exp(-abs(eta[k]*i[k]*gamma*delta_t/Q)))*sgn(i[k])
      v_h[k]=Mh[k]
    }

    void instantaneous_hysteresis() {
      h_i[k]=M_0*s[k] // Instantaneous hysteresis
      v_h[k]= M_0*s[k]+M*h[k] // Overall hysteresis
    }
}