//Joshua Argiropoulos 19ja27 20212858

#include <iostream>
#include <string>
using namespace std;


//----------------------------------Shape Class --------------------------------------

//Creates the parent class Shape
class Shape { 
//Declares instances to be used by all base shapes
private:
    int length;
    int width;
    string outline;

public:
//Creates constructor methods 
	Shape();
	Shape(const int setLength, const int setWidth, const string setOutline);
    
    //Destructor method
	virtual ~Shape(); 

    //Accessor methods for length, width and outline colour
	int getLength()const; 
	int getWidth()const;
    string getOutline()const;
    
    //Empty method used to be overide by children classes. Used to print the shape info to terminal 
	virtual void draw();
    

}; 

// -----------------------------Fill Class ------------------------------------------------------

//Creates the parent class Fill
class Fill { 
private:
//Creates instance to be used for the fill colour of each shape
    string fillColour;
public:
//Creates constructor methods 
	Fill();
	Fill(const string setFillColour);
    
    //Destructor 
	virtual ~Fill(); 

    //Accessor to get the fill colour
	string getFillColour()const; 
//Empty method used to be overide by children classes. Used to print the fill info to terminal 
	virtual void fillInfo();

}; 

// -----------------------------------Text Class -------------------------------------------------

//Creates the parent class Text
class Text { 
    //Creates instance to be used for the messages each shape
private:
    string textMessage;
public:
//Constructors methods
	Text();
	Text(const string setText);
    
    //Destructor 
	virtual ~Text(); 

    //Accessor methods for the text  
	string getText()const; 
//Empty method used to be overide by children classes. Used to print the text info to terminal 
	virtual void textInfo();

}; 

//----------------------------------------Square Class -------------------------------------------------


class Square : public Shape { 
//Creates Square class from the parent class Shape

//All of sqaures instances are already declared by shape parent class
public:
//Constructor method for square
	Square(const int setLength, const int setWidth, const string setOutline);
	virtual ~Square(); //destructor
    
    virtual void shapeInfo();
//Overrides the draw function of shapes to call shapeInfo() instead. shape Info will be used to print the squares info
	virtual void draw(){
        shapeInfo();
    }
	
};

//----------------------------------------Filled Square Class------------------------------------------------

//Creates child class of Fill and Square 
class FilledSquare : public Square, Fill { 

public:
//Filled square constructor 
	FilledSquare(const int setLength, const int setWidth, const string setOutline, const string setFillColour);

	~FilledSquare(); //destructor
    virtual void fillInfo();
//Overrides the draw function of shapes to call shapeInfo() and fill info() instead. shape Info will the same from square, however, fill info() will be overriden
	virtual void draw(){
        shapeInfo();
        fillInfo();
    }
	

};

//----------------------------------------------Filled Text Square Class ----------------------------------------------

//Creates child class of filled square and text class
class FilledTextSquare : public FilledSquare, Text { 

public:
//Filled text square constructor 
	FilledTextSquare(const int setLength, const int setWidth, const string setOutline, const string setFillColour, const string setText);
	virtual ~FilledTextSquare(); //destructor

    virtual void textInfo();
//Overrides the draw function of shapes to call shapeInfo(), fillInfo() and textInfo() instead. shapeInfo() and fillInfo() will be the same from fill square and textInfo() will be overriden to print text info.
	virtual void draw(){
        shapeInfo();
        fillInfo();
        textInfo();
    };
	

};

// ----------------------------------------------Circle Class -------------------------------------------------------------------

//Similar process of the square class but for circles now
class Circle : public Shape { 

public:
//Constructor method for circle 
	Circle(const int setLength, const int setWdith, const string setOutline);
	~Circle(); //destructor
    virtual void shapeInfo();
//Overrides the draw function of shapes to call shapeInfo() instead. shape Info will be used to print the circles info
	virtual void draw(){
        shapeInfo();
    }
};


//------------------------------------------------------Filled Circle Class --------------------------------------------------------

class FilledCircle : public Circle, Fill { 
//Creates child class from circle and fill
public:
//FilledCircle Constructor method

	FilledCircle(const int setLength,const int setWidth, const string setOutline, const string setText);
	virtual ~FilledCircle(); //destructor
    virtual void fillInfo();
//Overrides the draw function of shapes to call shapeInfo() and fillInfo() instead. fillInfo() will be used to print the circles fill info
	virtual void draw(){
        shapeInfo();
        fillInfo();
    }
};

//---------------------------------------------------------------Arc Class----------------------------------------------------

class Arc : public Shape { 
    //Child class of shape. Final shape in ShapesGood
public:

//Arc constructor method
	Arc(const int setLength, const int setWidth, const string setOutline);
	virtual ~Arc(); //destructor
    virtual void shapeInfo();
//Overrides the draw function of shapes to call shapeInfo() instead. shape Info will be used to print the arcs info
	virtual void draw(){
        shapeInfo();
    }
};