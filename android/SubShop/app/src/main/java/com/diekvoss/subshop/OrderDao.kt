package com.diekvoss.subshop

import androidx.lifecycle.LiveData
import androidx.room.Dao
import androidx.room.Insert
import androidx.room.Query

/**
 * OrderDao
 *
 * @property allOrders all orders from orders table
 */
@Dao
interface OrderDao {
  /** All orders in table */
  @get:Query("SELECT * FROM orders") val allOrders: LiveData<List<OrderEntity>>

  /**
   * insert order into database
   *
   * @param order
   */
  @Insert fun insert(order: OrderEntity)
}
