package com.diekvoss.subshop.screens.receipt

import androidx.test.espresso.Espresso.onView
import androidx.test.espresso.action.ViewActions
import androidx.test.espresso.action.ViewActions.click
import androidx.test.espresso.action.ViewActions.pressBack
import androidx.test.espresso.assertion.ViewAssertions
import androidx.test.espresso.assertion.ViewAssertions.matches
import androidx.test.espresso.matcher.ViewMatchers
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
class ReceiptFragmentTest {
  @get:Rule var mainActivity = ActivityTestRule(MainActivity::class.java)

  @Before
  fun before() {
    onView(withId(R.id.order_button)).perform(ViewActions.click())
  }

  @Test
  fun testSandwich() {
    onView(withId(R.id.wheat_bread_chip)).perform(ViewActions.click())
    onView(withId(R.id.philly_chip)).perform(ViewActions.click())
    onView(withId(R.id.place_order_button)).perform(ViewActions.click())

    onView(withId(R.id.receipt_title_text))
        .check(ViewAssertions.matches(withText(R.string.receipt)))
    onView(withId(R.id.summary_text)).check(ViewAssertions.matches(withText("")))
    onView(withId(R.id.sandwich_type_text))
        .check(ViewAssertions.matches(withText(R.string.sandwich_type_philly)))
    onView(withId(R.id.bread_type_text))
        .check(ViewAssertions.matches(withText(R.string.bread_type_wheat)))
  }

  @Test
  fun testSandwich1() {
    onView(withId(R.id.flat_bread_chip)).perform(ViewActions.click())
    onView(withId(R.id.bbq_chicken_chip)).perform(ViewActions.click())
    onView(withId(R.id.cheese_chip)).perform(ViewActions.click())
    onView(withId(R.id.place_order_button)).perform(ViewActions.click())

    onView(withId(R.id.receipt_title_text))
        .check(ViewAssertions.matches(withText(R.string.receipt)))
    onView(withId(R.id.sandwich_type_text))
        .check(ViewAssertions.matches(withText(R.string.sandwich_type_bbq_chicken)))
    onView(withId(R.id.bread_type_text))
        .check(ViewAssertions.matches(withText(R.string.bread_type_flatbread)))
    onView(withId(R.id.summary_text)).check(ViewAssertions.matches(withText("with:\tCheese\n")))
  }

  @Test
  fun testSandwich2() {
    onView(withId(R.id.white_bread_chip)).perform(click())
    onView(withId(R.id.italian_chip)).perform(click())
    onView(withId(R.id.mustard_chip)).perform(click())
    onView(withId(R.id.mayo_chip)).perform(click())
    onView(withId(R.id.place_order_button)).perform(click())

    onView(withId(R.id.receipt_title_text)).check(matches(withText(R.string.receipt)))
    onView(withId(R.id.sandwich_type_text)).check(matches(withText(R.string.sandwich_type_italian)))
    onView(withId(R.id.bread_type_text)).check(matches(withText(R.string.bread_type_white)))
    onView(withId(R.id.summary_text)).check(matches(withText("with:\tMayo\n\tMustard\n")))
  }

  @Test
  fun testBackButton() {
    onView(ViewMatchers.withId(R.id.white_bread_chip)).perform(ViewActions.click())
    onView(ViewMatchers.withId(R.id.italian_chip)).perform(ViewActions.click())
    onView(ViewMatchers.withId(R.id.mustard_chip)).perform(ViewActions.click())
    onView(ViewMatchers.withId(R.id.mayo_chip)).perform(ViewActions.click())
    onView(ViewMatchers.withId(R.id.place_order_button)).perform(ViewActions.click())

    onView(ViewMatchers.withId(R.id.receipt_title_text))
        .check(ViewAssertions.matches(withText(R.string.receipt)))
    onView(ViewMatchers.withId(R.id.sandwich_type_text))
        .check(ViewAssertions.matches(withText(R.string.sandwich_type_italian)))
    onView(ViewMatchers.withId(R.id.bread_type_text))
        .check(ViewAssertions.matches(withText(R.string.bread_type_white)))
    onView(ViewMatchers.withId(R.id.summary_text))
        .check(ViewAssertions.matches(withText("with:\tMayo\n\tMustard\n")))

    onView(ViewMatchers.withId(R.id.summary_text)).perform(pressBack())
    onView(ViewMatchers.withId(R.id.order_button))
        .check(ViewAssertions.matches(withText(R.string.order_now_text)))
  }
}
