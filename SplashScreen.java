package smart.bus.ideology;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import smart.bus.ideology.MainActivity;

public class SplashScreen extends AppCompatActivity {
   protected void onCreate(Bundle var1) {
      super.onCreate(var1);
      this.requestWindowFeature(1);
      this.getWindow().setFlags(1024, 1024);
      this.setContentView(2131361821);
      (new Handler()).postDelayed(new Runnable() {
         public void run() {
            Intent var1 = new Intent(SplashScreen.this, MainActivity.class);
            SplashScreen.this.startActivity(var1);
            SplashScreen.this.finish();
         }
      }, 3000L);
   }
}
