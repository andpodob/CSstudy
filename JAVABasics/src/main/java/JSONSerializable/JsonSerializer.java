package JSONSerializable;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Objects;
import java.util.stream.Collectors;

public class JsonSerializer {

    private static void checkObject(Object object) throws Exception{
        if(Objects.isNull(object)){
            throw new JsonSerializationException("Provided object was null");
        }
        else{
            Class<?> c = object.getClass();
            if(!c.isAnnotationPresent(JSONSerializable.class)){
                throw new JsonSerializationException("Provided object is not annotated with @JSONSerializable");
            }
        }
    }

    private static void invokeInitMethod(Object object){
        Class c = object.getClass();
        for(Method m : c.getDeclaredMethods()){
            if(m.getAnnotation(Init.class) != null){
                try {
                    m.setAccessible(true);
                    m.invoke(object);
                }catch (Exception e){
                    System.out.println(e.getMessage());
                }
            }
        }
    }

    private static String getKey(Field field) {
        String value = field.getAnnotation(JSONElement.class).key();
        return value.isEmpty() ? field.getName() : value;
    }

    private static String serialize(Object object){
        Class<?> c = object.getClass();
        try{
            checkObject(object);
            invokeInitMethod(object);
            HashMap<String, String> jsonObjectMap = new HashMap();

            for(Field field : c.getDeclaredFields()){
                field.setAccessible(true);
                if(field.isAnnotationPresent(JSONElement.class)){
                    jsonObjectMap.put(getKey(field), (String) field.get(object));
                }
            }

            String jsonString = jsonObjectMap.entrySet().stream().map(entry -> "\""+entry.getKey()+"\""+":"+"\""+entry.getValue()+"\"").collect(Collectors.joining(","));
            return "{"+jsonString+"}";
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
        return "";
    }

    public static String JSONSerialize(Object object){
        try{
            checkObject(object);
            invokeInitMethod(object);
            return serialize(object);
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
        return "";
    }
}
