import JSONSerializable.JsonSerializer;
import JSONSerializable.Person;
import org.junit.Assert;
import org.junit.Test;




public class JsonsSerializerTest {
    @Test
    public void testSerialization(){
        Person p = new Person("Andrzej", "Podobinski", "21");
        String result = JsonSerializer.JSONSerialize(p);
        String expected = "{\"personAge\":\"21\",\"firstName\":\"Andrzej\",\"lastName\":\"Podobinski\"}";
        Assert.assertEquals(expected, result);
    }
}
