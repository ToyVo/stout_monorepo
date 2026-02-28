package com.diekvoss.roomdemo

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.PrimaryKey
import java.util.*

@Entity(tableName = "books") // optional to set table name will be based off class name
class ExampleEntity(
    @PrimaryKey val id: String,
    @ColumnInfo(name = "author_name") val author: String = "",
    @ColumnInfo(name = "book_title") val book: String = "",
    @ColumnInfo(name = "description") val description: String = "",
    @ColumnInfo(name = "last_updated") val lastUpdated: Date?,
)
