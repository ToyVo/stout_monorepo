/*
 * Copyright 2018, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.example.android.navigation

import android.content.Intent
import android.os.Bundle
import android.view.*
import androidx.core.app.ShareCompat
import androidx.databinding.DataBindingUtil
import androidx.fragment.app.Fragment
import androidx.navigation.Navigation
import com.example.android.navigation.databinding.FragmentGameWonBinding

/** fragment for the game won screen */
class GameWonFragment : Fragment() {
  /**
   * Inflate the correct view to the container Setup button to play a new game
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
    // Inflate the layout for this fragment
    val binding: FragmentGameWonBinding =
        DataBindingUtil.inflate(inflater, R.layout.fragment_game_won, container, false)

    binding.nextMatchButton.setOnClickListener(
        Navigation.createNavigateOnClickListener(R.id.action_gameWonFragment_to_gameFragment))
    setHasOptionsMenu(true)
    return binding.root
  }

  /**
   * set up options menu, in this case it just shows a share button
   *
   * @param menu Menu to be inflated
   * @param inflater inflates the menu
   */
  override fun onCreateOptionsMenu(
      menu: Menu,
      inflater: MenuInflater,
  ) {
    super.onCreateOptionsMenu(menu, inflater)
    inflater.inflate(R.menu.winner_menu, menu)
    if (null == getShareIntent().resolveActivity(activity!!.packageManager)) {
      menu.findItem(R.id.share)?.isVisible = false
    }
  }

  /**
   * sets up the intent that will be used
   *
   * @return Intent activity that gets started
   */
  private fun getShareIntent(): Intent {
    val args = GameWonFragmentArgs.fromBundle(arguments!!)
    return ShareCompat.IntentBuilder.from(activity)
        .setText(getString(R.string.share_success_text, args.numCorrect, args.numQuestions))
        .setType("text/plain")
        .intent
  }

  /** starts the share intent */
  private fun shareSuccess() {
    startActivity(getShareIntent())
  }

  /**
   * listens for clicks on the options menu When the share option is selected, it runs shareSuccess
   *
   * @param item item clicked on
   * @return Boolean
   */
  override fun onOptionsItemSelected(item: MenuItem): Boolean {
    when (item.itemId) {
      R.id.share -> shareSuccess()
    }
    return super.onOptionsItemSelected(item)
  }
}
