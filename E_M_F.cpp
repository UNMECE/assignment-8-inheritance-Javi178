#include <cmath>
#include <iostream>


class Field
{
        protected:
        double *value;

        public:
        Field()
        {
                value = new double[3];
                for (int i = 0; i < 3; i++)
                {
                        value[i] = 0.0;
                }
        }


        Field(double x, double y, double z)
        {
                value = new double[3];
                value[0] = x;
                value[1] = y;
                value[2] = z;

        }

        ~Field()
        {
                delete[] value;
        }

        void printMagnitude()
        {
                std::cout << "X comp:  " << value[0]
                          << "y comp:  " << value[1]
                          << "z comp:  " << value[2] << std::endl;
        }

};


class electric_field : public Field 
{	
	private:
	
	double calculatedEF;
        double calculatedB;

	public:

	
		
	electric_field(double x, double y, double z)
	{
		value = new double [3];
		value[0] = x;
		value[1] = y;
		value[2] = z;
        	calculatedEF = 0.0;
        	calculatedB = 0.0;
	}

	electric_field()
	{	
		value = new double[3];
		value[0] = 0.0;
		value[1] = 0.0;
		value[2] = 0.0;

		if (value == NULL)
 		std::cout<< "Fail alocation E is empty"<< std::endl;
		else
		std::cout<< "Electric field Memory correctly allocated"<< std::endl;
	}

	~electric_field(){}
	double getCalculatedEF() const
	{
		return calculatedEF;
	}


	void setX(double x)
	{
       		value[0] = x;
	}
	double getX() const
	{
        	return value[0];
	}


	void setY(double y)
	{
        	value[1] = y;
	}
	double getY() const
	{
        	return value[1];
	}



	void setZ(double z)
	{
        	value[2] = z;
	}
	double getZ() const 
	{
        	return value[2];

	}
	
	double calculateMagnitude()
	{
        	double X = value[0]*value[0];
        	double Y = value[1]*value[1];
        	double Z = value[2]*value[2];

        	return sqrt(X+Y+Z);
	}
	   
	void calculateInnerProduct()
	{
        	double IP =  (value[0] * value[0]) + (value[1] * value[1]) + (value[2] * value[2]);
    		std::cout<<"Calculated Inner product: "<< IP<<std::endl;
	}

	void GaussLaw(double Q, double r)
	{
		double result;
		double pi = 3.14159; // had to look up value
		double epsilon =8.85e-12; // had to look valuelculatedEF() const {

		result = Q/(4*pi*pow(r,2) *epsilon);
		
		calculatedEF = result;	
	}

	void EFdistance(double I, double r)
	{
		double result;
		double pi = 3.14159;
		double magconstant = 4 * pi * 1e-7; // had to look up value	
		
		result = I/(2 * pi * r *  magconstant);
		
		calculatedB = result;
	}	
	
	
	electric_field operator+(const electric_field& rhs)
	{
		double x = this->value[0] + rhs.value[0];
		double y = this->value[1] + rhs.value[1];
		double z = this->value[2] + rhs.value[2];

		electric_field result(x, y, z);
		return result;
	
	}
	
	
};
	std::ostream& operator<<(std::ostream& os, const electric_field& E)
	{
		 os << "X comp: " << E.getX()
                << ", Y comp: " << E.getY()
                << ", Z comp: " << E.getZ();
                return os;
        }
 




class magnetic_field : public Field 
{
        private:
       
        public:
	
        magnetic_field(double x, double y, double z)
        {
                value = new double [3];
                value[0] = x;
                value[1] = y;
                value[2] = z;
        }

        magnetic_field()
        {
		value = new double [3];
                value[0] = 0.0;
                value[1] = 0.0;
                value[2] = 0.0;
		
                if (value == NULL)
                std::cout<< "Fail alocation M is empty"<< std::endl;
                else
                std::cout<< "Mag_field Memory correctly allocated"<< std::endl;
        }

        ~magnetic_field(){}

	void setX(double x)
	{
        	value[0] = x;
	}
	double getX()const
	{
        	return value[0];
	}


	void setY(double y)
	{
        	value[1] = y;
	}
	double getY() const
	{
       		return value[1];
	}



	void setZ(double z)
	{
        	value[2] = z;
	}
	double getZ()const
	{
        	return value[2];
	}
	double calculateMagnitude()
	{
        	double X = value[0]*value[0];
        	double Y = value[1]*value[1];
        	double Z = value[2]*value[2];

        	return sqrt(X+Y+Z);
	}
	
	void unitVector()
	{	
		double mag = calculateMagnitude();
		for (int i = 0; i < 3; i++) 
		{
    			double unit = value[i] / mag;
			std::cout << "Component " << i << ": " << unit << std::endl;
		}
	}
	

	magnetic_field operator+(const magnetic_field& rhs) 
	{
		double x = this->value[0] + rhs.value[0];	
		double y = this->value[1] + rhs.value[1];
		double z = this->value[2] + rhs.value[2];
		
		magnetic_field result(x, y, z);
		return result;
	}

};


        std::ostream& operator<<(std::ostream& os, const magnetic_field& M)
        {
                os << "X comp: " << M.getX()
                << ", Y comp: " << M.getY()
                << ", Z comp: " << M.getZ();
                return os;
        }
