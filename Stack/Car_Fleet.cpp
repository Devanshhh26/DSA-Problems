//  https://leetcode.com/problems/car-fleet/description/
//  create a class so that you can group the postion and speed together  and store in vector
//  sort the vector on the basis of the position so that cars at left of number line go to the left side of vector
//  take out the time for each car by time =(target-position)/speed         i.e. time = distance/speed
//  if the time taken by a particular car is greater than the element at the top of the stack then we pop that element and push the time in stack
//  else we directly push the time in stack in the stack
// by doing this we know if the time is less than st.top( that means it will not create a fleet as they will never go bumper to bumper
// but if time was greater that st.top()that means the car will take more time than the car at its back therefore the car behind will catch up and create a fleet by going bumper to bumper as it can not overtake
// therefore we pop the top and push the time of new car
// at last the size of stack will tell us the total number of fleets2   


/*
class Solution {
    class Car{
        public:
        int pos;
        int speed;
        Car(int p,int s):pos(p),speed(s){};
    };
    static bool myComp(Car&a,Car&b){
        return a.pos<b.pos;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>cars;
        for(int i=0;i<position.size();i++)
        {
            Car car(position[i],speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(),cars.end(),myComp);
        stack<float>st;
        for(auto car:cars)
        {
            float time=(target-car.pos)/(float)car.speed;
            while(!st.empty()&&time>=st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};
*/