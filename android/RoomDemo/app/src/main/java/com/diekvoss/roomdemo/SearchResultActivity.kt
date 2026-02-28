package com.diekvoss.roomdemo

import android.app.Activity
import android.app.SearchManager
import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import androidx.recyclerview.widget.LinearLayoutManager
import java.util.*
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.content_main.*

class SearchResultActivity : AppCompatActivity(), ExampleListAdapter.OnDeleteClickListener {
  private lateinit var viewModel: SearchViewModel
  private var exampleListAdapter: ExampleListAdapter? = null
  private val TAG = this.javaClass.simpleName

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)
    setSupportActionBar(toolbar)

    fab.hide()

    viewModel = ViewModelProviders.of(this).get(SearchViewModel::class.java)

    exampleListAdapter = ExampleListAdapter(this, this)
    recyclerview.adapter = exampleListAdapter
    recyclerview.layoutManager = LinearLayoutManager(this)

    handleIntent(intent)
  }

  private fun handleIntent(intent: Intent) {
    if (Intent.ACTION_SEARCH == intent.action) {
      val searchQuery = intent.getStringExtra(SearchManager.QUERY)

      Log.i(TAG, "Search Query is $searchQuery")

      viewModel
          .getBooksByBookOrAuthor("%$searchQuery%")
          ?.observe(
              this,
              Observer { books -> books?.let { exampleListAdapter!!.setBooks(books) } },
          )
    }
  }

  override fun onActivityResult(
      requestCode: Int,
      resultCode: Int,
      data: Intent?,
  ) {
    super.onActivityResult(requestCode, resultCode, data)

    if (requestCode == SearchResultActivity.UPDATE_BOOK_ACTIVITY_REQUEST_CODE &&
        resultCode == Activity.RESULT_OK) {
      // Code to edit book
      val bookId = data!!.getStringExtra(EditItemActivity.ID)
      val authorName = data.getStringExtra(EditItemActivity.UPDATED_AUTHOR)
      val bookName = data.getStringExtra(EditItemActivity.UPDATED_BOOK)
      val description = data.getStringExtra(EditItemActivity.UPDATED_DESCRIPTION)
      val currentTime = Calendar.getInstance().time

      val book = ExampleEntity(bookId!!, authorName!!, bookName!!, description!!, currentTime)

      viewModel.update(book)

      Toast.makeText(applicationContext, R.string.updated, Toast.LENGTH_LONG).show()
    } else {
      Toast.makeText(applicationContext, R.string.not_saved, Toast.LENGTH_LONG).show()
    }
  }

  override fun onDeleteClickListener(myBook: ExampleEntity) {
    viewModel.delete(myBook)
    Toast.makeText(applicationContext, R.string.deleted, Toast.LENGTH_LONG).show()
  }

  companion object {
    const val UPDATE_BOOK_ACTIVITY_REQUEST_CODE = 2
  }
}
