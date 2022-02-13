class ParkingSystem {
    
    int b = 0;
    int m = 0;
    int s = 0;
public:
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        
        bool parked = false;
        if(b > 0 && carType == 1){
            parked = true;
            b--;
        }else if(m>0 && carType == 2){
            parked = true;
            m--;
        }else if(s>0 && carType ==3){
            parked = true;
            s--;
        }
        
        return parked;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */