package com.diekvoss.subshop.screens.order

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.databinding.DataBindingUtil
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProviders
import androidx.navigation.NavDirections
import androidx.navigation.fragment.findNavController
import com.diekvoss.subshop.R
import com.diekvoss.subshop.SandwichItem
import com.diekvoss.subshop.SandwichOrder
import com.diekvoss.subshop.databinding.OrderFragmentBinding
import com.google.android.material.chip.Chip

/**
 * orderFragment
 *
 * @property binding
 * @property viewModel
 */
class OrderFragment : Fragment() {
  private lateinit var viewModel: OrderViewModel
  private lateinit var binding: OrderFragmentBinding

  /**
   * onCreateView
   *
   * @param inflater
   * @param container
   * @param savedInstanceState
   */
  override fun onCreateView(
      inflater: LayoutInflater,
      container: ViewGroup?,
      savedInstanceState: Bundle?,
  ): View? {
    // inflate view
    binding = DataBindingUtil.inflate(inflater, R.layout.order_fragment, container, false)

    viewModel = ViewModelProviders.of(this).get(OrderViewModel::class.java)
    binding.orderViewModel = viewModel
    binding.lifecycleOwner = this

    // setup navigation
    binding.placeOrderButton.setOnClickListener {
      if (binding.breadTypeChipGroup.checkedChipId == -1 ||
          binding.sandwichTypeChipGroup.checkedChipId == -1) {
        Toast.makeText(
                context,
                "Select both a sandwich type and bread type",
                Toast.LENGTH_SHORT,
            )
            .show()
      } else {
        // Variables to construct order
        var sandwichType: SandwichItem? = null
        var breadType: SandwichItem? = null
        val toppings: MutableSet<SandwichItem?> = mutableSetOf()

        // get list of toppings
        for (i in 0 until binding.toppingsChipGroup.childCount) {
          val chip: Chip = binding.toppingsChipGroup.getChildAt(i) as Chip
          if (chip.isChecked) {
            toppings.add(viewModel.toppingOptions.find { it.name == chip.text.toString() })
          }
        }

        // get Bread Type
        for (i in 0 until binding.breadTypeChipGroup.childCount) {
          val chip: Chip = binding.breadTypeChipGroup.getChildAt(i) as Chip
          if (chip.isChecked) {
            breadType = viewModel.breadTypes.find { it.name == chip.text.toString() }
          }
        }

        // get Sandwich Type
        for (i in 0 until binding.sandwichTypeChipGroup.childCount) {
          val chip: Chip = binding.sandwichTypeChipGroup.getChildAt(i) as Chip
          if (chip.isChecked) {
            sandwichType = viewModel.sandwichTypes.find { it.name == chip.text.toString() }
          }
        }

        // construct order
        val order =
            SandwichOrder(
                breadType as SandwichItem,
                sandwichType as SandwichItem,
                toppings.filterNotNull().toSet(),
            )

        // Pass order and navigate
        val directions: NavDirections =
            OrderFragmentDirections.actionOrderFragmentToReceiptFragment(order)
        findNavController().navigate(directions)
      }
    }

    return binding.root
  }
}
