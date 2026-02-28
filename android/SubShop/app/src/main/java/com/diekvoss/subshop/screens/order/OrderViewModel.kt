package com.diekvoss.subshop.screens.order

import android.app.Application
import androidx.lifecycle.AndroidViewModel
import com.diekvoss.subshop.R
import com.diekvoss.subshop.SandwichItem

/** order view model separate the possible */
class OrderViewModel(
    application: Application,
) : AndroidViewModel(application) {
  // List of available sandwich types
  val sandwichTypes: MutableSet<SandwichItem> =
      mutableSetOf(
          SandwichItem(
              application.resources.getString(R.string.sandwich_type_italian),
              application.resources.getString(R.string.sandwich_type_italian_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.sandwich_type_philly),
              application.resources.getString(R.string.sandwich_type_philly_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.sandwich_type_bbq_chicken),
              application.resources.getString(R.string.sandwich_type_bbq_chicken_price).toDouble(),
          ),
      )

  // set of bread types
  val breadTypes: MutableSet<SandwichItem> =
      mutableSetOf(
          SandwichItem(
              application.resources.getString(R.string.bread_type_flatbread),
              application.resources.getString(R.string.bread_type_flatbread_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.bread_type_wheat),
              application.resources.getString(R.string.bread_type_wheat_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.bread_type_white),
              application.resources.getString(R.string.bread_type_white_price).toDouble(),
          ),
      )

  // set of topping options
  val toppingOptions: MutableSet<SandwichItem> =
      mutableSetOf(
          SandwichItem(
              application.resources.getString(R.string.toppings_bacon),
              application.resources.getString(R.string.toppings_bacon_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.toppings_cheese),
              application.resources.getString(R.string.toppings_cheese_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.toppings_lettuce),
              application.resources.getString(R.string.toppings_lettuce_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.toppings_mayo),
              application.resources.getString(R.string.toppings_mayo_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.toppings_mustard),
              application.resources.getString(R.string.toppings_mustard_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.toppings_tomato),
              application.resources.getString(R.string.toppings_tomato_price).toDouble(),
          ),
          SandwichItem(
              application.resources.getString(R.string.toppings_spinach),
              application.resources.getString(R.string.toppings_spinach_price).toDouble(),
          ),
      )
  // state booleans
}
