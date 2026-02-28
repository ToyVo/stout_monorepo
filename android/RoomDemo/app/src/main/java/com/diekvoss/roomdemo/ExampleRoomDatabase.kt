package com.diekvoss.roomdemo

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase
import androidx.room.TypeConverters
import androidx.room.migration.Migration
import androidx.sqlite.db.SupportSQLiteDatabase

@Database(entities = [ExampleEntity::class], version = 3)
@TypeConverters(DataTypeConverter::class)
abstract class ExampleRoomDatabase : RoomDatabase() {
  abstract fun exampleDao(): ExampleDao

  companion object {
    private var roomInstance: ExampleRoomDatabase? = null

    private val MIGRATION_1_2: Migration =
        object : Migration(1, 2) {
          override fun migrate(database: SupportSQLiteDatabase) {
            database.execSQL(
                "ALTER TABLE books ADD COLUMN description TEXT DEFAULT 'Add Description' NOT NULL")
          }
        }

    private val MIGRATION_2_3 =
        object : Migration(2, 3) {
          override fun migrate(database: SupportSQLiteDatabase) {
            database.execSQL(
                "ALTER TABLE books " + " ADD COLUMN last_updated INTEGER DEFAULT NULL",
            )
          }
        }

    fun getDatabase(context: Context): ExampleRoomDatabase? {
      if (roomInstance == null) {
        synchronized(ExampleRoomDatabase::class.java) {
          if (roomInstance == null) {
            roomInstance =
                Room.databaseBuilder<ExampleRoomDatabase>(
                        context.applicationContext,
                        ExampleRoomDatabase::class.java,
                        "example_database",
                    )
                    .addMigrations(MIGRATION_1_2, MIGRATION_2_3)
                    .build()
          }
        }
      }
      return roomInstance
    }
  }
}
