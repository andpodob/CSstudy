package factory;

import Shapes.Rectangle;
import Shapes.Shape;
import Shapes.Square;

public class ShaprShapesFactory extends AbstractFactory {
    @Override
    public Shape getShape(String shape) {
        if(shape.equalsIgnoreCase("RECT")){
            return new Rectangle();
        }else if(shape.equalsIgnoreCase("SQUARE")){
            return new Square();
        }
        return null;
    }
}
