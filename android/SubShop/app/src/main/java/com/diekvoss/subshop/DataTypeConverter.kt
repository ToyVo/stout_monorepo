package com.diekvoss.subshop

import androidx.room.TypeConverter
import java.util.*

/** convert date into a usable value to put into the database */
class DataTypeConverter {
  /**
   * @param date
   * @return date converted to database usable form
   */
  @TypeConverter fun dateToLong(date: Date?): Long? = date?.time

  /**
   * @param timestamp
   * @return long converted back to date
   */
  @TypeConverter fun longToDate(timestamp: Long?): Date? = timestamp?.let { Date(it) }
}
