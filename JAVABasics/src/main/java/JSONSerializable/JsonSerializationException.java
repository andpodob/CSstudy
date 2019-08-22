package JSONSerializable;

public class JsonSerializationException extends Exception {
    private String message;

    public JsonSerializationException(String message){
        this.message = message;
    }

    @Override
    public String toString(){
        return "JsonSerializationException"+this.message;
    }
}
