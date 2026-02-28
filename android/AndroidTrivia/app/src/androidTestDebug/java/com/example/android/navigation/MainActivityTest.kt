package com.example.android.navigation

import androidx.test.espresso.Espresso.onView
import androidx.test.espresso.action.ViewActions.click
import androidx.test.espresso.assertion.ViewAssertions.matches
import androidx.test.espresso.matcher.ViewMatchers.isDisplayed
import androidx.test.espresso.matcher.ViewMatchers.withId
import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.rule.ActivityTestRule
import org.junit.Rule
import org.junit.Test
import org.junit.runner.RunWith

@RunWith(AndroidJUnit4::class)
class MainActivityTest {
  @get:Rule
  var mainActivity: ActivityTestRule<MainActivity> = ActivityTestRule(MainActivity::class.java)

  @Test
  fun testPlayButton() {
    // check if title fragment is loaded
    onView(withId(R.id.titleConstraint)).check(matches(isDisplayed()))
    // click button
    onView(withId(R.id.playButton)).perform(click())
    // check if game fragment is loaded
    onView(withId(R.id.gameConstraint)).check(matches(isDisplayed()))
  }

  @Test fun onCreate() {}

  @Test fun onSupportNavigateUp() {}
}
