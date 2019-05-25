import factory.ShapeFactory;
import shapes.Shape;

import java.util.*;

public class Demo {
    public static void main(String[] args){
        ShapeFactory sF = new ShapeFactory();
        LinkedList<Shape> shapeList = new LinkedList<Shape>();
        shapeList.add(sF.getShape("CIRCLE"));
        shapeList.add(sF.getShape("RECT"));
        shapeList.add(sF.getShape("SQUARE"));

        for(Shape a : shapeList){
            a.draw();
        }
    }
}
