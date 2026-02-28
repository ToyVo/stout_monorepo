package com.diekvoss.aboutme

import android.content.Context
import android.os.Bundle
import android.view.View
import android.view.inputmethod.InputMethodManager
import androidx.appcompat.app.AppCompatActivity
import androidx.databinding.DataBindingUtil
import com.diekvoss.aboutme.databinding.ActivityMainBinding

/** Main activity that gets launched with the application */
class MainActivity : AppCompatActivity() {
  // initialize binding
  private lateinit var binding: ActivityMainBinding

  // bound data
  private val myName = MyName("Collin Diekvoss", "")

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    // set the view to the xml file
    binding = DataBindingUtil.setContentView(this, R.layout.activity_main)

    // bound data
    binding.myName = myName

    // listen for licks on the done button to set nickname
    binding.doneButton.setOnClickListener { addNickname(it) }
  }

  /** @param view the button that was clicked on */
  private fun addNickname(view: View) {
    // set the edit field and the button to gone, and display a non editable nickname in its place
    binding.apply {
      myName?.nickname = nicknameEdit.text.toString()
      invalidateAll()
      nicknameText.visibility = View.VISIBLE
      nicknameEdit.visibility = View.GONE
      doneButton.visibility = View.GONE
    }

    // close the keyboard
    val imm = getSystemService(Context.INPUT_METHOD_SERVICE) as InputMethodManager
    imm.hideSoftInputFromWindow(view.windowToken, 0)
  }
}
