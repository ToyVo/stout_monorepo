package com.diekvoss.subshop.screens.order

import androidx.test.espresso.Espresso.onView
import androidx.test.espresso.action.ViewActions.click
import androidx.test.espresso.action.ViewActions.pressBack
import androidx.test.espresso.assertion.ViewAssertions.matches
import androidx.test.espresso.matcher.ViewMatchers.withId
import androidx.test.espresso.matcher.ViewMatchers.withText
import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.rule.ActivityTestRule
import com.diekvoss.subshop.MainActivity
import com.diekvoss.subshop.R
import org.junit.Before
import org.junit.Rule
import org.junit.Test
import org.junit.runner.RunWith

@RunWith(AndroidJUnit4::class)
class OrderFragmentTest {
  @get:Rule var mainActivity = ActivityTestRule(MainActivity::class.java)

  @Before
  fun before() {
    onView(withId(R.id.order_button)).perform(click())
  }

  @Test
  fun testSandwichCreationNoBreadType() {
    onView(withId(R.id.philly_chip)).perform(click())

    onView(withId(R.id.place_order_button)).perform(click())
    // should still be on order
    onView(withId(R.id.order_title_text)).check(matches(withText(R.string.build_your_sub_text)))
  }

  @Test
  fun testSandwichCreationNoSandwichType() {
    onView(withId(R.id.flat_bread_chip)).perform(click())

    onView(withId(R.id.place_order_button)).perform(click())
    // should still be on order
    onView(withId(R.id.order_title_text)).check(matches(withText(R.string.build_your_sub_text)))
  }

  @Test
  fun testBackButton() {
    onView(withId(R.id.order_title_text)).perform(pressBack())
    onView(withId(R.id.order_button)).check(matches(withText(R.string.order_now_text)))
  }
}
