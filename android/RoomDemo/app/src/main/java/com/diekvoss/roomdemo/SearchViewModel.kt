package com.diekvoss.roomdemo

import android.app.Application
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.LiveData

class SearchViewModel(
    application: Application,
) : AndroidViewModel(application) {
  private val exampleRepository = ExampleRepository(application)

  fun getBooksByBookOrAuthor(searchQuery: String): LiveData<List<ExampleEntity>>? =
      exampleRepository.getBooksByBookOrAuthor(searchQuery)

  fun update(entity: ExampleEntity) {
    exampleRepository.update(entity)
  }

  fun delete(entity: ExampleEntity) {
    exampleRepository.delete(entity)
  }
}
