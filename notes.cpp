class Model_OCV_and_SOC {        // The class
  public:              // Access specifier
    int Q // Total Capacity, Ah or mAh
    int delta_t
    }
};

// Derived class
class SOC: public Base {
  public:
    void SOC_calc() {
        for (int k=0; k<5; k++) {
            z[k+1] = z[k]-delta_t/Q*i[k]
        }

    }
};


int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}

// Base class
class Vehicle {
  public:
    string brand = "Ford";
    void honk() {
      cout << "Tuut, tuut! \n" ;
    }
};

// Derived class
class Car: public Vehicle {
  public:
    string model = "Mustang";
};

int main() {
  Car myCar;
  myCar.honk();
  cout << myCar.brand + " " + myCar.model;
  return 0;
} 