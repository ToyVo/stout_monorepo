package com.diekvoss.roomdemo

import android.app.Application
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.LiveData

class MainActivityViewModel(
    application: Application,
) : AndroidViewModel(application) {
  private val exampleRepository = ExampleRepository(application)
  val allBooks: LiveData<List<ExampleEntity>> = exampleRepository.allBooks

  fun insert(exampleEntity: ExampleEntity) {
    exampleRepository.insert(exampleEntity)
  }

  fun update(exampleEntity: ExampleEntity) {
    exampleRepository.update(exampleEntity)
  }

  fun delete(exampleEntity: ExampleEntity) {
    exampleRepository.delete(exampleEntity)
  }
}
