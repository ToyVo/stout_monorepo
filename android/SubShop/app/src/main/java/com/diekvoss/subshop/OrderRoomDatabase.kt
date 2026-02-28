package com.diekvoss.subshop

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase
import androidx.room.TypeConverters

/** Order Database */
@Database(entities = [OrderEntity::class], version = 1)
@TypeConverters(DataTypeConverter::class)
abstract class OrderRoomDatabase : RoomDatabase() {
  abstract fun orderDao(): OrderDao

  companion object {
    private var roomInstance: OrderRoomDatabase? = null

    /**
     * get singleton instance of database
     *
     * @param context
     * @return Singleton Database
     */
    fun getDatabase(context: Context): OrderRoomDatabase? {
      if (roomInstance == null) {
        synchronized(OrderRoomDatabase::class.java) {
          if (roomInstance == null) {
            roomInstance =
                Room.databaseBuilder<OrderRoomDatabase>(
                        context.applicationContext,
                        OrderRoomDatabase::class.java,
                        "order_database",
                    )
                    .build()
          }
        }
      }
      return roomInstance
    }
  }
}
