package com.diekvoss.subshop.screens.history

import android.app.Application
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.LiveData
import com.diekvoss.subshop.OrderEntity
import com.diekvoss.subshop.OrderRepository

/**
 * @property repository local database
 * @property allOrders all orders from the repository
 */
class OrderHistoryViewModel(
    application: Application,
) : AndroidViewModel(application) {
  private val repository: OrderRepository = OrderRepository(application)
  val allOrders: LiveData<List<OrderEntity>> = repository.allOrders

  /** pass through for repository insert */
  fun insertOrder(order: OrderEntity) {
    repository.insertOrder(order)
  }
}
