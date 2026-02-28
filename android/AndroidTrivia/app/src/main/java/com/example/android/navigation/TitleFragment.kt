package com.example.android.navigation

import android.os.Bundle
import android.view.*
import androidx.databinding.DataBindingUtil
import androidx.fragment.app.Fragment
import androidx.navigation.Navigation
import androidx.navigation.findNavController
import androidx.navigation.ui.NavigationUI
import com.example.android.navigation.databinding.FragmentTitleBinding

/** Title fragment */
class TitleFragment : Fragment() {
  /**
   * Inflate the correct view to the container Setup button to navigate to the game fragment
   *
   * @param inflater LayoutInflater inflates view
   * @param container ViewGroup where the view is put
   * @param savedInstanceState Bundle save state for recall
   */
  override fun onCreateView(
      inflater: LayoutInflater,
      container: ViewGroup?,
      savedInstanceState: Bundle?,
  ): View? {
    val binding: FragmentTitleBinding =
        DataBindingUtil.inflate(
            inflater,
            R.layout.fragment_title,
            container,
            false,
        )

    binding.playButton.setOnClickListener(
        Navigation.createNavigateOnClickListener(R.id.action_titleFragment_to_gameFragment),
    )

    setHasOptionsMenu(true)

    return binding.root
  }

  /**
   * Inflates the menu
   *
   * @param menu menu to be inflated
   * @param inflater inflates the menu
   */
  override fun onCreateOptionsMenu(
      menu: Menu,
      inflater: MenuInflater,
  ) {
    super.onCreateOptionsMenu(menu, inflater)
    inflater.inflate(R.menu.overflow_menu, menu)
  }

  /**
   * listens for clicks on options navigate to location if valid, or do nothing
   *
   * @param item item selected
   * @return Boolean
   */
  override fun onOptionsItemSelected(item: MenuItem): Boolean {
    return NavigationUI.onNavDestinationSelected(item!!, view!!.findNavController()) ||
        return super.onOptionsItemSelected(item)
  }
}
