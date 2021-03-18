import math

class Model_OCV_and_SOC:
    # k represents a discrete time

    def __init__(self):

        self.Q=1 # Total Capacity, Ah or mAh
        # self.j=some_number
        # 

    def SOC_calc:
        for k in whatever:
            z[k+1] = z[k]-delta_t/Q*i[k]

    def SOC_with_Coulombic_efficieny:
        nu[k]=1 # Discharge
        z[k+1] = z[k]-i[k]*nu[k]*delta_t/Q

    def Coulombic_efficieny:
        coul_eff=charge_out/charge_in

    def OCV:
        v[k] = OCV(z[k])


class Model_voltage_polarization(Model_OCV_and_SOC):
    
    def difusion_voltage(self):
        # Defined as "Rint" model. Voltage drop when under load
        # v(t) = OCV(z(t))-i(t)R_0
        pass
    def thevenin_model(self):
        # Diffusion Model using parallel resistor-capacitor sub-circuit
        # v(t) = OCV(z(t))-v_C1(t)-i(t)R_0
        # In practice, easier v(t) = OCV(z(t))-R1*i_R1(t)-i(t)R_0
        pass

class Werberg_Impedence(Model_OCV_and_SOC):

    def __init__(self):

        self.Z_w = A_w/math.sqrt(j*omega)