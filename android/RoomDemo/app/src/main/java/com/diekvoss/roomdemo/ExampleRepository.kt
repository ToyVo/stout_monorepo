package com.diekvoss.roomdemo

import android.app.Application
import android.os.AsyncTask
import androidx.lifecycle.LiveData

class ExampleRepository(
    application: Application,
) {
  val allBooks: LiveData<List<ExampleEntity>>
  private val exampleDao: ExampleDao

  init {
    val exampleDb = ExampleRoomDatabase.getDatabase(application)
    exampleDao = exampleDb!!.exampleDao()
    allBooks = exampleDao.allBooks
  }

  fun getBooksByBookOrAuthor(searchQuery: String): LiveData<List<ExampleEntity>>? =
      exampleDao.getBooksByBookOrAuthor(searchQuery)

  fun insert(entity: ExampleEntity) {
    InsertAsyncTask(exampleDao).execute(entity)
  }

  fun update(entity: ExampleEntity) {
    UpdateAsyncTask(exampleDao).execute(entity)
  }

  fun delete(entity: ExampleEntity) {
    DeleteAsyncTask(exampleDao).execute(entity)
  }

  companion object {
    private class InsertAsyncTask(
        private val exampleDao: ExampleDao,
    ) : AsyncTask<ExampleEntity, Void, Unit>() {
      override fun doInBackground(vararg entities: ExampleEntity) {
        exampleDao.insert(entities[0])
      }
    }

    private class UpdateAsyncTask(
        private val exampleDao: ExampleDao,
    ) : AsyncTask<ExampleEntity, Void, Unit>() {
      override fun doInBackground(vararg entities: ExampleEntity) {
        exampleDao.update(entities[0])
      }
    }

    private class DeleteAsyncTask(
        private val exampleDao: ExampleDao,
    ) : AsyncTask<ExampleEntity, Void, Unit>() {
      override fun doInBackground(vararg entities: ExampleEntity) {
        exampleDao.delete(entities[0])
      }
    }
  }
}
