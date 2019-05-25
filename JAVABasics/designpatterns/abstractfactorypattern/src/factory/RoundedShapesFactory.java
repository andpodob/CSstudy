package factory;

import Shapes.RoundedRectangle;
import Shapes.RoundedSquare;
import Shapes.Shape;

public class RoundedShapesFactory extends AbstractFactory {
    @Override
    Shape getShape(String shape) {
        if(shape.equalsIgnoreCase("RECT")){
            return new RoundedRectangle();
        }else if(shape.equalsIgnoreCase("SQUARE")){
            return new RoundedSquare();
        }
        return null;
    }
}
