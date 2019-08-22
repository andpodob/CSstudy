package Shapes;

import java.util.ArrayList;

public class Demo {
    public static void main(String[] args){
        ArrayList<Shape> list = new ArrayList<>();
        list.add(new Circle());
        list.add(new Rectangle());
        list.add(new RedShapeDecorator(new Circle()));
        list.add(new RedShapeDecorator(new Rectangle()));

        list.forEach(a->a.draw());
    }
}
