package com.diekvoss.labone

import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.EditText
import androidx.appcompat.app.AppCompatActivity

const val EXTRA_MESSAGE = "com.diekvoss.labone.EXTRA_MESSAGE"

/**  */
class MainActivity : AppCompatActivity() {
  /** Init */
  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)
  }

  fun sendMessage(view: View) {
    val editText = findViewById<EditText>(R.id.editText)
    val message = editText.text.toString()
    val intent = Intent(this, DisplayMessage::class.java).apply { putExtra(EXTRA_MESSAGE, message) }
    startActivity(intent)
  }
}
