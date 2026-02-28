package com.diekvoss.diceroller

import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import androidx.appcompat.app.AppCompatActivity
import kotlin.random.Random

/**
 * Main entry point to the application
 *
 * @property diceImage image to be displayed
 */
class MainActivity : AppCompatActivity() {
  lateinit var diceImage: ImageView

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)

    // set display to appropriate resource
    setContentView(R.layout.activity_main)

    // listen for clicks on the roll button and roll when clicked
    val rollButton: Button = findViewById(R.id.roll_button)
    rollButton.setOnClickListener { rollDice() }
  }

  /** Generate a random number and display a matching drawable */
  private fun rollDice() {
    val randomInt = Random.nextInt(6) + 1
    val diceImage: ImageView = findViewById(R.id.dice_image)
    val drawableResource =
        when (randomInt) {
          1 -> R.drawable.dice_1
          2 -> R.drawable.dice_2
          3 -> R.drawable.dice_3
          4 -> R.drawable.dice_4
          5 -> R.drawable.dice_5
          else -> R.drawable.dice_6
        }
    diceImage.setImageResource(drawableResource)
  }
}
