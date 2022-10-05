package com.gl4.tp1

import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.EditText
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity


class MainActivity : AppCompatActivity() {
    lateinit var txtEmail : EditText
    lateinit var txtPassword : EditText



    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        txtEmail = findViewById(R.id.editTextEmail)
        txtPassword = findViewById(R.id.editPassword)

    }

    fun login(v: View?) {
        var email = txtEmail.text.toString()
        var password = txtEmail.text.toString()
        val intent = Intent(v?.context,WelcomeActivity::class.java)

        if( v?.id == R.id.btnLogin){
            if (email.equals("a")  && password.equals("a")){
                val toast = Toast.makeText(applicationContext, "les données sont correctes", Toast.LENGTH_LONG)
                toast.show()
                intent.putExtra("email",email)
                startActivity(intent)
            }else{
                val toast = Toast.makeText(applicationContext, "les données sont incorrecte", Toast.LENGTH_LONG)
                toast.show()
            }
        }
    }
}