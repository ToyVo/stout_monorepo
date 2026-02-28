package com.diekvoss.subshop

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import java.text.SimpleDateFormat
import java.util.*
import kotlinx.android.synthetic.main.list_item.view.*

/**
 * Adapter
 *
 * @property context
 * @property orderList
 */
class OrderListAdapter(
    private val context: Context,
) : RecyclerView.Adapter<OrderListAdapter.OrderViewHolder>() {
  private var orderList: List<OrderEntity> = mutableListOf()

  /**
   * returns the size of the list
   *
   * @return size of orderList
   */
  override fun getItemCount(): Int = orderList.size

  /**
   * @param parent
   * @param viewType
   * @return holder
   */
  override fun onCreateViewHolder(
      parent: ViewGroup,
      viewType: Int,
  ): OrderViewHolder {
    val itemView = LayoutInflater.from(context).inflate(R.layout.list_item, parent, false)
    return OrderViewHolder(itemView)
  }

  /**
   * @param holder
   * @param position
   */
  override fun onBindViewHolder(
      holder: OrderViewHolder,
      position: Int,
  ) {
    val order = orderList[position]
    holder.setData(order.subType, order.price, order.date)
  }

  /**
   * set orderList to new order
   *
   * @param orders
   */
  fun setOrders(orders: List<OrderEntity>) {
    orderList = orders
    notifyDataSetChanged()
  }

  /** @property orderView */
  inner class OrderViewHolder(
      private val orderView: View,
  ) : RecyclerView.ViewHolder(orderView) {
    /**
     * set the text on the screen the the order
     *
     * @param subType
     * @param price
     * @param date
     */
    fun setData(
        subType: String,
        price: Double,
        date: Date,
    ) {
      orderView.tvSubType.text = subType
      orderView.tvDate.text = getFormattedDate(date)
      orderView.tvPrice.text = price.toString()
    }

    /**
     * format date into a more readable format
     *
     * @param date
     * @return formatted date
     */
    private fun getFormattedDate(date: Date?): String {
      var time = ""
      time +=
          date?.let {
            val sdf = SimpleDateFormat("HH:mm d MMM, yyyy", Locale.getDefault())
            sdf.format(date)
          } ?: "Not Found"
      return time
    }
  }
}
