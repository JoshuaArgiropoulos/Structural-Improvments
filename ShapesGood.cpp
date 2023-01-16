//Joshua Argiropoulos 19ja27 20212858

#include "ShapesGood.h"
#include <iostream>
#include <string>
using namespace std;

//---------------------------Shape Class----------------------

//Methods used for the class shape
//Creates default case
Shape::Shape() {
    length = 0;
    width = 0;
    outline = "N/A";
}
//Constructor method with arguments
Shape::Shape(const int setLength, const int setWidth, const string setOutline){
    length = setLength;
    width = setWidth;
    outline = setOutline;
}
    
//Destructor method
Shape::~Shape() {}
//Accessor methods for length, width and outline colour
int Shape::getLength()const{
    return length;
}
int Shape::getWidth()const{
    return width;
}
string Shape::getOutline()const{
    return outline;
}
//Default draw function to be overidden later
void Shape::draw(){
    printf("N/A");
}


//-------------------------------------Fill Class-----------------------------------

//Methods used for the class Fill
//Default constructor method
Fill::Fill(){
    fillColour = "N/A";
}
//Constructor method with arguments
Fill::Fill(string setFillColour){
    fillColour = setFillColour;
}
//Deconstrcutor method
 Fill::~Fill() {}

//Accessor to get the fill colour
string Fill::getFillColour()const{
    return fillColour;
} 
//Default fill info statement to be overiden later
void Fill::fillInfo(){
    printf("N/A");
}



//--------------------------Methods for Text class----------------------------
 
//Default constructor
Text::Text(){
    textMessage = "N/A";
}
//Constructor method with arguments
Text::Text(string setText){
    textMessage = setText;
}
    
//Destructor 
Text::~Text(){}

//Accessor methods for the text class to get the text message 
string Text::getText()const{
    return textMessage;
} 
//Default text info method to be overidden later
void Text::textInfo(){
    printf("N/A");
}

//-------------------------Square class ----------------------------------------------

//Square constructor which calls the shape constructor to initalize the objects
Square::Square(const int setLength, const int setWidth, const string setOutline):Shape(setLength, setWidth, setOutline){}
//destructor
Square::~Square(){}

//Overrides the shape info function to display the shape and border colour
void Square::shapeInfo(){
    cout << "\nDrawing a "<< Shape::getOutline() << " square.";
}

//-------------------------------Filled Square Class ------------------------------------

//Methods for filled square class

//Filled square constructor using the squae constructor and fill class constructor 
FilledSquare::FilledSquare(int setLength, int setWidth, string setOutline, string setFillColour): Square(setLength, setWidth, setOutline), Fill(setFillColour) {}
//destructor for filled square class
FilledSquare::~FilledSquare(){}
//Overridden fill info method to display the fill colour 
void FilledSquare::fillInfo(){
    cout <<" With " << Fill::getFillColour() << " fill.";
}

// -----------------------------Filled Text Square Class -------------------------------------


//Methods for filled text square

//Filled text Square constructor which calls Filled Square and text constructor 
FilledTextSquare::FilledTextSquare(const int setLength, const int setWidth, const string setOutline, const string setFillColour, const string setText):FilledSquare(setLength, setWidth, setOutline, setFillColour),Text(setText){}
//destructor
FilledTextSquare::~FilledTextSquare(){} 

//Overides the text info method to print the message into the filled square
void FilledTextSquare::textInfo() {
    cout << " Containing the text: \""<<Text::getText()<<"!\".";
}

//-----------------------------Circle Class---------------------------------------------------------
//Circle constructor which uses the shape constructor 
Circle::Circle(int setLength, int setWidth, string setOutline):Shape(setLength,setWidth,setOutline){}
Circle::~Circle(){} //destructor
//Overides the shape info method to print the colour and shape 
void Circle::shapeInfo() {
   cout << "\nDrawing a " <<Shape::getOutline()<< " circle.";
}

//-----------------------------Filled Circle Class ---------------------------------------------------

//Filled circle constructor which uses the circle and fill constructors
FilledCircle::FilledCircle(int setLength, int setWidth, string setOutline, string setFillColour):Circle(setLength,setWidth,setOutline),Fill(setFillColour) {}
FilledCircle::~FilledCircle() {}//destructor
//Overides the fill info method to print the fill colour 
void FilledCircle::fillInfo() {
    cout << " With " <<Fill::getFillColour() << " fill,";
}

// ----------------------------------------Arc class -------------------------------------------------

//Arc constructor which uses the shape constructor 
Arc::Arc(int setLength, int setWidth, string setOutline):Shape(setLength, setWidth,setOutline){}
Arc::~Arc(){} //destructor

//shape info is overriden to print the arc and the arc outline
void Arc::shapeInfo(){
    cout << "\nDrawing a "<<Shape::getOutline() << " arc.";
}