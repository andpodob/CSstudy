package JSONSerializable;

@JSONSerializable
public class Person {

    @JSONElement
    private String firstName;

    @JSONElement
    private String lastName;

    @JSONElement (key="personAge")
    private String age;

    private String address;

    public Person(String firstName, String lastName, String age){
            this.firstName = firstName;
            this.lastName = lastName;
            this.age = age;
    }

    public Person(String firstName, String lastName){
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public Person(String firstName, String lastName, String age, String address){
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.address = address;
    }

    @Init
    private void initNames() {
        this.firstName = this.firstName.substring(0, 1).toUpperCase()
                + this.firstName.substring(1);
        this.lastName = this.lastName.substring(0, 1).toUpperCase()
                + this.lastName.substring(1);
    }
}
