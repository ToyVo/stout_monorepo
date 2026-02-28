package com.diekvoss.subshop.screens.welcome

import androidx.test.espresso.Espresso.onView
import androidx.test.espresso.action.ViewActions
import androidx.test.espresso.assertion.ViewAssertions
import androidx.test.espresso.matcher.ViewMatchers
import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.rule.ActivityTestRule
import com.diekvoss.subshop.MainActivity
import com.diekvoss.subshop.R
import org.junit.Rule
import org.junit.Test
import org.junit.runner.RunWith

@RunWith(AndroidJUnit4::class)
class WelcomeFragmentTest {
  @get:Rule var mainActivity = ActivityTestRule(MainActivity::class.java)

  @Test
  fun testNavigationFromWelcomeToOrder() {
    onView(ViewMatchers.withId(R.id.order_button)).perform(ViewActions.click())
    onView(ViewMatchers.withId(R.id.order_title_text))
        .check(ViewAssertions.matches(ViewMatchers.withText(R.string.build_your_sub_text)))
  }
}
