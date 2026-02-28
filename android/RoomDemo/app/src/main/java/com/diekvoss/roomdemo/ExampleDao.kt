package com.diekvoss.roomdemo

import androidx.lifecycle.LiveData
import androidx.room.*

@Dao
interface ExampleDao {
  @Insert fun insert(entity: ExampleEntity)

  //    @Query("SELECT * FROM books")
  //    fun getAllBooks(): LiveData<List<ExampleEntity>>

  @get:Query("SELECT * FROM books") val allBooks: LiveData<List<ExampleEntity>>

  @Query(
      "SELECT * FROM books WHERE book_title LIKE :searchString OR author_name LIKE :searchString")
  fun getBooksByBookOrAuthor(searchString: String): LiveData<List<ExampleEntity>>

  @Update fun update(entity: ExampleEntity)

  @Delete fun delete(entity: ExampleEntity)
}
