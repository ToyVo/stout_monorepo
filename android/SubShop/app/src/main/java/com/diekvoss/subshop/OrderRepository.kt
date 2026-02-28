package com.diekvoss.subshop

import android.app.Application
import android.os.AsyncTask
import androidx.lifecycle.LiveData

/**
 * local repository
 *
 * @property application
 * @property orderDao
 * @property allOrders
 * @property orderDb
 */
class OrderRepository(
    application: Application,
) {
  private var orderDao: OrderDao
  var allOrders: LiveData<List<OrderEntity>>

  init {
    val orderDb = OrderRoomDatabase.getDatabase(application)
    orderDao = orderDb!!.orderDao()
    allOrders = orderDao.allOrders
  }

  /** @param order */
  fun insertOrder(order: OrderEntity) {
    AsyncInsertTask(orderDao).execute(order)
  }

  companion object {
    /** @property orderDao */
    private class AsyncInsertTask(
        private val orderDao: OrderDao,
    ) : AsyncTask<OrderEntity, Void, Unit>() {
      /** @param orders */
      override fun doInBackground(vararg orders: OrderEntity) {
        orderDao.insert(orders[0])
      }
    }
  }
}
