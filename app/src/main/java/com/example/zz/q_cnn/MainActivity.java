package com.example.zz.q_cnn;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }


    private Button btn;
    private ImageView img;
    private static boolean flag = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //img = (ImageView)findViewById(R.id.img);
        btn = (Button)findViewById(R.id.btn);
        btn.setOnClickListener(new ProcessClickListener());

        // Example of a call to a native method
       // TextView tv = (TextView) findViewById(R.id.INFO);
       // TextView tv1=(TextView) findViewById(R.id.classname);
        //tv.setText(stringFromJNI());
      //  tv1.setText(string1());
       // String s=string1();
       // String a=stringFromJNI();
       // tv.setText(s+"\n");
    }

    public void procSrc2Gray(){

        TextView tv = (TextView) findViewById(R.id.INFO);
        int groundtruthname=stringFromJNI();
        String info=INFO();
        String timestring=time();
        btn.setText("Program Processed!");
        tv.setText(info+"\n"+groundtruthname+"\n"+timestring);

    }
    public class ProcessClickListener implements View.OnClickListener{

        @Override
        public void onClick(View v) {
            // TODO Auto-generated method stub


                procSrc2Gray();


        }
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native int stringFromJNI();
    public native String INFO();
    public native String time();
    public native String msg();

}
