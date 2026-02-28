package com.diekvoss.subshop.screens.history

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.databinding.DataBindingUtil
import androidx.fragment.app.Fragment
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import androidx.navigation.fragment.findNavController
import androidx.recyclerview.widget.LinearLayoutManager
import com.diekvoss.subshop.OrderListAdapter
import com.diekvoss.subshop.R
import com.diekvoss.subshop.databinding.OrderHistoryFragmentBinding

/**
 * OrderHistory Fragment
 *
 * @property viewModel
 * @property binding
 */
class OrderHistoryFragment : Fragment() {
  private lateinit var viewModel: OrderHistoryViewModel
  private lateinit var binding: OrderHistoryFragmentBinding

  /**
   * inflate layout setup navigation get orders
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
    // inflate layout and get binding
    binding =
        DataBindingUtil.inflate(
            inflater,
            R.layout.order_history_fragment,
            container,
            false,
        )

    // Button to go back to main menu
    binding.backToMenuButton.setOnClickListener {
      findNavController()
          .navigate(OrderHistoryFragmentDirections.actionOrderHistoryFragmentToWelcomeFragment())
    }

    // setup the recyclerview
    val orderListAdapter = OrderListAdapter(context!!)
    binding.recyclerView.adapter = orderListAdapter
    binding.recyclerView.layoutManager = LinearLayoutManager(context)

    viewModel = ViewModelProviders.of(this).get(OrderHistoryViewModel::class.java)

    // get orders and set them in the adapter
    viewModel.allOrders.observe(
        this,
        Observer { orders -> orders?.let { orderListAdapter.setOrders(orders) } },
    )

    return binding.root
  }
}
