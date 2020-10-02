# Load Flow Analyzer

# Programming Platform 
C++14

# Description:

In this project, Object-oriented Programming (OOP) concepts such as class, object, abstraction, function overloading, and operator overloading is applied in C++ to build a power flow analyzer using Gauss-Siedel algorithm for any number of buses.

The analyzer takes system's known information such as bus admittance matrix, bus parameters- real power P, reactive power Q, and voltage at each nodes. The analyzer solves the load flow problem and provides outputs such as voltage magnitude and angle, real and reactive power, and power losses for each node.

# Handling Complex Numbers:

To enter a complex value for the elements of a admittance matrix, or the power of a node, or the node voltage when asked; enter the data in the rectangular format- " a + i*b ", where a is the real part and b is the imaginary part of the complex number. Enter the data of this complex value in the following format:

   a   b

(seperating the real and imaginary part by a space)

For example, when asked to enter the admittance between any nodes, 

Enter the admisstance between nodes 1 and 2: 2 -3

Here, the value for Y12 was 2-j*3, where the real part was 2 and reactive part was -3.  
