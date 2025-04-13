#include "E_M_F.cpp"    

int main()
{
	electric_field E_default;
	electric_field E_components(1e5, 10.9,1.7e2);
	 	

	electric_field E_comp(2,6,5);
	E_default.setX(2);
	E_default.setY(6);
	E_default.setZ(5);
	
	magnetic_field M_default;
        magnetic_field M_comp(10,8,4);
        M_default.setX(2);
        M_default.setY(6);
        M_default.setZ(5);


	E_default.calculateInnerProduct();
	std::cout << "E_default Magnitude: " << E_default.calculateMagnitude() << std::endl;
	std::cout << "M_default Magnitude: " << M_default.calculateMagnitude() << std::endl;


	M_comp.unitVector();
	
	electric_field e1(1.0, 2.0, 3.0);
	magnetic_field m1(2.0, 2.0, 2.0);
	

	e1.GaussLaw(1e-6, 0.5);
	std::cout << "Electric field from Gauss' Law: " << e1.getCalculatedEF() << " N/C" << std::endl;

	
	std::cout << "Magnetic field magnitude: " << m1.calculateMagnitude() << " T" << std::endl;


	
	
	electric_field e2(4.0, 5.0, 6.0);
	electric_field e3 = e1 + e2;
	
	std::cout << "e1: "; 
	e1.printMagnitude();
	std::cout << "e2: ";
	 e2.printMagnitude();
	std::cout << "e3 (e1 + e2): " ;
	 e3.printMagnitude();
	

	magnetic_field m2(1.0, 3.0, 4.0);
	magnetic_field m3 = m1 + m2;

	std::cout << "m1: " ;
	m1.printMagnitude(); 
	std::cout << "m2: " ;
	m2.printMagnitude();
	std::cout << "m3 (m1 + m2): " ;
	m3.printMagnitude(); 
	

	return 0;



}
