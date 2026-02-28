package com.diekvoss.roomdemo

import android.app.Activity
import android.app.SearchManager
import android.content.ComponentName
import android.content.Context
import android.content.Intent
import android.os.Bundle
import android.view.Menu
import android.widget.SearchView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import androidx.recyclerview.widget.LinearLayoutManager
import java.util.*
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.content_main.*

class MainActivity : AppCompatActivity(), ExampleListAdapter.OnDeleteClickListener {
  companion object {
    private const val NEW_NOTE_ACTIVITY_REQUEST_CODE = 1
    const val UPDATE_NOTE_ACTIVITY_REQUEST_CODE = 2
  }

  private lateinit var viewModel: MainActivityViewModel

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)
    setSupportActionBar(toolbar)

    val exampleListAdapter = ExampleListAdapter(this, this)
    recyclerview.adapter = exampleListAdapter
    recyclerview.layoutManager = LinearLayoutManager(this)

    fab.setOnClickListener {
      val intent = Intent(this, NewItemActivity::class.java)
      startActivityForResult(intent, NEW_NOTE_ACTIVITY_REQUEST_CODE)
    }

    viewModel = ViewModelProviders.of(this).get(MainActivityViewModel::class.java)

    viewModel.allBooks.observe(
        this,
        Observer { books -> books?.let { exampleListAdapter.setBooks(books) } },
    )
  }

  override fun onActivityResult(
      requestCode: Int,
      resultCode: Int,
      data: Intent?,
  ) {
    super.onActivityResult(requestCode, resultCode, data)

    if (requestCode == NEW_NOTE_ACTIVITY_REQUEST_CODE && resultCode == Activity.RESULT_OK) {
      val id = UUID.randomUUID().toString()
      val authorName = data?.getStringExtra(NewItemActivity.NEW_AUTHOR)
      val bookName = data?.getStringExtra(NewItemActivity.NEW_BOOK)
      val description = data?.getStringExtra(NewItemActivity.NEW_DESCRIPTION)
      val currentTime = Calendar.getInstance().time

      val book = ExampleEntity(id, authorName!!, bookName!!, description!!, currentTime)

      viewModel.insert(book)

      Toast.makeText(applicationContext, R.string.saved, Toast.LENGTH_LONG).show()
    } else if (requestCode == UPDATE_NOTE_ACTIVITY_REQUEST_CODE &&
        resultCode == Activity.RESULT_OK) {
      val id = data?.getStringExtra(EditItemActivity.ID)
      val authorName = data?.getStringExtra(EditItemActivity.UPDATED_AUTHOR)
      val bookName = data?.getStringExtra(EditItemActivity.UPDATED_BOOK)
      val description = data?.getStringExtra(EditItemActivity.UPDATED_DESCRIPTION)
      val currentTime = Calendar.getInstance().time

      val book = ExampleEntity(id!!, authorName!!, bookName!!, description!!, currentTime)

      viewModel.update(book)

      Toast.makeText(applicationContext, getString(R.string.updated), Toast.LENGTH_SHORT).show()
    } else {
      Toast.makeText(applicationContext, R.string.not_saved, Toast.LENGTH_LONG).show()
    }
  }

  override fun onDeleteClickListener(myBook: ExampleEntity) {
    viewModel.delete(myBook)
    Toast.makeText(applicationContext, getString(R.string.deleted), Toast.LENGTH_LONG).show()
  }

  override fun onCreateOptionsMenu(menu: Menu): Boolean {
    // Inflate the menu; this adds items to the action bar if it is present.
    menuInflater.inflate(R.menu.menu_main, menu)

    val searchManager = getSystemService(Context.SEARCH_SERVICE) as SearchManager
    val searchView = menu.findItem(R.id.search).actionView as SearchView

    val componentName = ComponentName(this, SearchResultActivity::class.java)
    val searchableInfo = searchManager.getSearchableInfo(componentName)
    searchView.setSearchableInfo(searchableInfo)

    return true
  }
}
