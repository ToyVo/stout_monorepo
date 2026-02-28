package com.diekvoss.viewmodeldemo

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {
  companion object {
    private val TAG: String = MainActivity::class.java.simpleName
  }

  lateinit var viewModel: MainActivityViewModel

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)

    //        viewModel = MainActivityViewModel()
    viewModel = ViewModelProviders.of(this).get(MainActivityViewModel::class.java)

    val myRandomNumber = viewModel.getNumber()

    myRandomNumber.observe(
        this,
        Observer<String> {
          tvNumber.text = it
          Log.i(TAG, "Random Number Set")
        },
    )

    bRandom.setOnClickListener { viewModel.createNumber() }
  }
}
