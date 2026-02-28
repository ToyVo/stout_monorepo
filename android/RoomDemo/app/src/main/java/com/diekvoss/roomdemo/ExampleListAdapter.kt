package com.diekvoss.roomdemo

import android.app.Activity
import android.content.Context
import android.content.Intent
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import java.text.SimpleDateFormat
import java.util.*
import kotlinx.android.synthetic.main.list_item.view.*

class ExampleListAdapter(
    private val context: Context,
    private val onDeleteClickListener: OnDeleteClickListener,
) : RecyclerView.Adapter<ExampleListAdapter.ExampleViewHolder>() {
  companion object {
    const val ID = "id"
    const val AUTHOR = "author"
    const val BOOK = "book"
    const val DESCRIPTION = "description"
    const val LAST_UPDATED = "last_updated"
  }

  interface OnDeleteClickListener {
    fun onDeleteClickListener(myBook: ExampleEntity)
  }

  private var exampleList: List<ExampleEntity> = mutableListOf()

  override fun onCreateViewHolder(
      parent: ViewGroup,
      viewType: Int,
  ): ExampleViewHolder {
    val itemView = LayoutInflater.from(context).inflate(R.layout.list_item, parent, false)
    return ExampleViewHolder(itemView)
  }

  override fun onBindViewHolder(
      holder: ExampleViewHolder,
      position: Int,
  ) {
    val example = exampleList[position]
    holder.setData(example.book, example.lastUpdated, position)
    holder.setListeners()
  }

  override fun getItemCount(): Int = exampleList.size

  fun setBooks(books: List<ExampleEntity>) {
    exampleList = books
    notifyDataSetChanged()
  }

  inner class ExampleViewHolder(
      itemView: View,
  ) : RecyclerView.ViewHolder(itemView) {
    private var pos: Int = 0

    fun setData(
        book: String,
        lastUpdated: Date?,
        position: Int,
    ) {
      //            itemView.tvAuthor.text = author
      itemView.tvBook.text = book
      itemView.tvLastUpdated.text = getFormattedDate(lastUpdated)
      this.pos = position
    }

    fun setListeners() {
      itemView.setOnClickListener {
        val intent = Intent(context, EditItemActivity::class.java)
        intent.putExtra(ID, exampleList[pos].id)
        intent.putExtra(AUTHOR, exampleList[pos].author)
        intent.putExtra(BOOK, exampleList[pos].book)
        intent.putExtra(DESCRIPTION, exampleList[pos].description)
        intent.putExtra(LAST_UPDATED, getFormattedDate(exampleList[pos].lastUpdated))
        (context as Activity).startActivityForResult(
            intent,
            MainActivity.UPDATE_NOTE_ACTIVITY_REQUEST_CODE,
        )
      }

      itemView.ivRowDelete.setOnClickListener {
        onDeleteClickListener.onDeleteClickListener(exampleList[pos])
      }
    }

    private fun getFormattedDate(lastUpdated: Date?): String {
      var time = "Last Updated: "
      time +=
          lastUpdated?.let {
            val sdf = SimpleDateFormat("HH:mm d MMM, yyyy", Locale.getDefault())
            sdf.format(lastUpdated)
          } ?: "Not Found"
      return time
    }
  }
}
