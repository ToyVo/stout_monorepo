package com.diekvoss.subshop

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.databinding.DataBindingUtil
import androidx.drawerlayout.widget.DrawerLayout
import androidx.navigation.NavController
import androidx.navigation.NavDestination
import androidx.navigation.findNavController
import androidx.navigation.ui.NavigationUI
import com.diekvoss.subshop.databinding.ActivityMainBinding

/**
 * Creates an Activity that hosts all of the fragments in the app
 *
 * @property binding
 * @property drawerLayout
 * @property navController
 */
class MainActivity : AppCompatActivity() {
  private lateinit var binding: ActivityMainBinding
  private lateinit var drawerLayout: DrawerLayout
  private lateinit var navController: NavController

  /**
   * MainActivity onCreate
   *
   * @param savedInstanceState
   */
  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)

    // initialize class properties
    binding = DataBindingUtil.setContentView(this, R.layout.activity_main)
    drawerLayout = binding.drawerLayout
    navController = this.findNavController(R.id.nav_host_fragment)

    // Setup Drawer and back button
    NavigationUI.setupActionBarWithNavController(this, navController, drawerLayout)
    NavigationUI.setupWithNavController(binding.navView, navController)

    // Lock drawer to only welcome screen
    navController.addOnDestinationChangedListener { nc: NavController, nd: NavDestination, _ ->
      if (nd.id == nc.graph.startDestination) {
        drawerLayout.setDrawerLockMode(DrawerLayout.LOCK_MODE_UNLOCKED)
      } else {
        drawerLayout.setDrawerLockMode(DrawerLayout.LOCK_MODE_LOCKED_CLOSED)
      }
    }
  }

  /** navigate up using back button */
  override fun onSupportNavigateUp(): Boolean = NavigationUI.navigateUp(navController, drawerLayout)
}
