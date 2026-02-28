package com.diekvoss.colormyviews

import android.graphics.Color
import android.os.Bundle
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import kotlinx.android.synthetic.main.activity_main.*

/** Main entry point to application */
class MainActivity : AppCompatActivity() {
  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)

    // set appropriate resource for the main view
    setContentView(R.layout.activity_main)

    setListeners()
  }

  /** Listen for clicks on every textView, Button, and background */
  private fun setListeners() {
    val clickableViews: List<View> =
        listOf(
            box_one_text,
            box_two_text,
            box_three_text,
            box_four_text,
            box_five_text,
            constraint_layout,
            red_button,
            green_button,
            yellow_button,
        )

    for (item in clickableViews) {
      item.setOnClickListener { makeColored(it) }
    }
  }

  /** Depending on the id of the item clicked, change the color */
  private fun makeColored(view: View) {
    when (view.id) {
      R.id.box_one_text -> {
        view.setBackgroundColor(Color.DKGRAY)
      }

      R.id.box_two_text -> {
        view.setBackgroundColor(Color.GRAY)
      }

      R.id.box_three_text -> {
        view.setBackgroundColor(
            ContextCompat.getColor(
                this,
                android.R.color.holo_green_light,
            ),
        )
      }

      R.id.box_four_text -> {
        view.setBackgroundColor(
            ContextCompat.getColor(
                this,
                android.R.color.holo_green_dark,
            ),
        )
      }

      R.id.box_five_text -> {
        view.setBackgroundColor(
            ContextCompat.getColor(
                this,
                android.R.color.holo_green_light,
            ),
        )
      }

      R.id.red_button -> {
        box_three_text.setBackgroundResource(R.color.my_red)
      }

      R.id.yellow_button -> {
        box_four_text.setBackgroundResource(R.color.my_yellow)
      }

      R.id.green_button -> {
        box_five_text.setBackgroundResource(R.color.my_green)
      }

      else -> {
        view.setBackgroundColor(Color.LTGRAY)
      }
    }
  }
}
