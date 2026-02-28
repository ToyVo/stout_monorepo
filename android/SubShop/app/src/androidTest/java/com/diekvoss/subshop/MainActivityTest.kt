package com.diekvoss.subshop

import androidx.test.espresso.Espresso.onView
import androidx.test.espresso.action.ViewActions.click
import androidx.test.espresso.action.ViewActions.pressBack
import androidx.test.espresso.assertion.ViewAssertions.matches
import androidx.test.espresso.matcher.ViewMatchers.withId
import androidx.test.espresso.matcher.ViewMatchers.withText
import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.rule.ActivityTestRule
import org.junit.Rule
import org.junit.Test
import org.junit.runner.RunWith

@RunWith(AndroidJUnit4::class)
class MainActivityTest {
  @get:Rule var mainActivity = ActivityTestRule(MainActivity::class.java)

  @Test
  fun testBackButton() {
    onView(withId(R.id.order_button)).perform(click())
    onView(withId(R.id.order_title_text)).perform(pressBack())
    onView(withId(R.id.order_button)).check(matches(withText(R.string.order_now_text)))
  }
}
