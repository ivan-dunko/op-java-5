import java.io.File;
import org.graalvm.polyglot.Source;
import org.graalvm.polyglot.Context;
import org.graalvm.polyglot.Value;
import org.graalvm.nativeimage.c.type.*;
import java.util.Map;
import java.util.HashMap;
import java.lang.String;

class SystemInfoLLVM{

    public static void main(String[] args){
        try{
            File file = new File("main.bc");
            Source s = Source.newBuilder("llvm", file).build();
            Context c = Context.newBuilder().allowAllAccess(true).build();
            
            
            Value v = c.eval(s);
            Value f = v.getMember("getCpuInfo");
            String str = f.execute().asString();
            
            System.out.println(str);
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}
