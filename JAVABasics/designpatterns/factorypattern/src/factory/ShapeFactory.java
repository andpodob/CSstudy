package factory;

import shapes.Circle;
import shapes.Rectangle;
import shapes.Shape;
import shapes.Square;

public class ShapeFactory {
    public Shape getShape(String shapeType){
        Shape toRet = null;
        if(shapeType == null){
            return null;
        }else{
            switch (shapeType){
                case "CIRCLE":
                    toRet = new Circle();
                    break;
                case "SQUARE":
                    toRet = new Square();
                    break;
                case "RECT":
                    toRet = new Rectangle();
                    break;
            }
        }
        return toRet;
    }
}
