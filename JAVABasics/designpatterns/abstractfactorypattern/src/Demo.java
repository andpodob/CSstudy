import Shapes.Shape;
import factory.AbstractFactory;
import factory.FactoryProducer;

import java.util.ArrayList;

public class Demo {
    public static void main(String[] args){
        ArrayList<Shape> shapes = new ArrayList<>();
        AbstractFactory factory = FactoryProducer.getFactory(false);
        shapes.add(factory.getShape("RECT"));
        shapes.add(factory.getShape("SQUARE"));
        factory = FactoryProducer.getFactory(true);
        shapes.add(factory.getShape("RECT"));
        shapes.add(factory.getShape("SQUARE"));

        for(Shape shape : shapes){
            shape.draw();
        }
    }
}
