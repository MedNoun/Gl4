package com.gl4.tp1

import android.content.Intent
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.provider.MediaStore
import android.view.View
import android.widget.ImageView
import android.widget.TextView
import androidx.activity.result.contract.ActivityResultContracts

class WelcomeActivity : AppCompatActivity() {
    lateinit var txtWelcome : TextView
    lateinit var imgWelcome : ImageView;


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_welcome)
        this.txtWelcome = findViewById(R.id.textWelcome)
        val email = intent.getStringExtra("email")
        txtWelcome.setText("Bienvenue $email")
    }
    fun loadImage(v: View?) {
        if( v?.id == R.id.loadBtn){
            val intentGallery = Intent(Intent.ACTION_PICK, MediaStore.Images.Media.INTERNAL_CONTENT_URI);
            pickImage.launch(intentGallery);
        }
    }
    val pickImage =registerForActivityResult(ActivityResultContracts.StartActivityForResult()){
            result->
        if(result.resultCode == RESULT_OK && result.data != null){
            val selectedImg : Uri? = result.data?.data;
            imgWelcome.setImageURI(selectedImg);
        }
    }

}