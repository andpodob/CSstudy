package factory;

import Shapes.Shape;

public abstract class AbstractFactory {
    abstract Shape getShape(String shape);
}
