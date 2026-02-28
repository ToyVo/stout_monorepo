package com.diekvoss.subshop

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.PrimaryKey
import java.util.*

@Entity(tableName = "orders")
data class OrderEntity(
    @PrimaryKey val uid: String,
    @ColumnInfo(name = "sub_type") val subType: String,
    @ColumnInfo(name = "price") val price: Double,
    @ColumnInfo(name = "date") val date: Date,
)
