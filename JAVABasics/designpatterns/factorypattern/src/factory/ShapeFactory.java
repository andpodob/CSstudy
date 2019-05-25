package factory;

import shapes.Circle;
import shapes.Rectangle;
import shapes.Shape;
import shapes.Square;

public class ShapeFactory {
    public Shape getShape(String shape){
        Shape toRet = null;
        switch (shape){
            case "RECT":
                toRet = new Rectangle();
                break;
            case "SQUARE":
                toRet = new Square();
                break;
            case "CIRCLE":
                toRet = new Circle();
                break;
        }
        return toRet;
    }
}
