package com.diekvoss.lifecycleawaredemo

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
  companion object {
    private val TAG: String = MainActivity::class.java.simpleName
  }

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)

    Log.i(TAG, "Owner onCreate")
    lifecycle.addObserver(MainActivityObserver())
  }
}
