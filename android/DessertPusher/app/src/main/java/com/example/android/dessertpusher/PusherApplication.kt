package com.example.android.dessertpusher

import android.app.Application
import timber.log.Timber

/**
 * Overridden application to setup utilities Android interacts with application through this class
 */
class PusherApplication : Application() {
  /** Setup Timber */
  override fun onCreate() {
    super.onCreate()
    Timber.plant(Timber.DebugTree())
  }
}
