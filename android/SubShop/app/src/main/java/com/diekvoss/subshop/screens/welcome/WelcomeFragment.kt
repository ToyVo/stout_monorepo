package com.diekvoss.subshop.screens.welcome

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.databinding.DataBindingUtil
import androidx.fragment.app.Fragment
import androidx.navigation.fragment.findNavController
import com.diekvoss.subshop.R
import com.diekvoss.subshop.databinding.WelcomeFragmentBinding

/** Simple welcome fragment */
class WelcomeFragment : Fragment() {
  /**
   * WelcomeFragment onCreateView
   *
   * @param inflater
   * @param savedInstanceState
   */
  override fun onCreateView(
      inflater: LayoutInflater,
      container: ViewGroup?,
      savedInstanceState: Bundle?,
  ): View? {
    // Inflate the layout for this fragment
    val binding: WelcomeFragmentBinding =
        DataBindingUtil.inflate(inflater, R.layout.welcome_fragment, container, false)

    // Set up navigation for order button
    binding.orderButton.setOnClickListener {
      findNavController().navigate(WelcomeFragmentDirections.actionWelcomeFragmentToOrderFragment())
    }

    binding.historyButton.setOnClickListener {
      findNavController()
          .navigate(WelcomeFragmentDirections.actionWelcomeFragmentToOrderHistoryFragment())
    }

    return binding.root
  }
}
