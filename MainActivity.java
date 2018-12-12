package smart.bus.ideology;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import smart.bus.ideology.Home;

public class MainActivity extends AppCompatActivity {
   EditText name;
   EditText pass;

   protected void onCreate(Bundle var1) {
      super.onCreate(var1);
      this.setContentView(2131361820);
      this.name = (EditText)this.findViewById(2131230785);
      this.pass = (EditText)this.findViewById(2131230839);
      ((Button)this.findViewById(2131230818)).setOnClickListener(new OnClickListener() {
         public void onClick(View var1) {
            Intent var2;
            if(MainActivity.this.name.getText().toString().equalsIgnoreCase("A") && MainActivity.this.pass.getText().toString().equalsIgnoreCase("123")) {
               var2 = new Intent(MainActivity.this, Home.class);
               var2.putExtra("Email", "A");
               MainActivity.this.startActivity(var2);
            } else if(MainActivity.this.name.getText().toString().equalsIgnoreCase("B") && MainActivity.this.pass.getText().toString().equalsIgnoreCase("123")) {
               var2 = new Intent(MainActivity.this, Home.class);
               var2.putExtra("Email", "B");
               MainActivity.this.startActivity(var2);
            } else if(MainActivity.this.name.getText().toString().equalsIgnoreCase("C") && MainActivity.this.pass.getText().toString().equalsIgnoreCase("123")) {
               var2 = new Intent(MainActivity.this, Home.class);
               var2.putExtra("Email", "C");
               MainActivity.this.startActivity(var2);
            } else {
               Toast.makeText(MainActivity.this, "Wrong credentials !", 0).show();
            }

         }
      });
   }
}
