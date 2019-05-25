package factory;

import Shapes.Shape;

public abstract class AbstractFactory {
    public abstract Shape getShape(String shape);
}
