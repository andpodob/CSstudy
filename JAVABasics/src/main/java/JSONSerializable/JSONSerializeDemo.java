package JSONSerializable;

public class JSONSerializeDemo {
    public static void main(String[] args){
        Person p = new Person("Andrzej","Podobinski");
        System.out.println(JsonSerializer.JSONSerialize(p));
    }
}
