package com.diekvoss.subshop.screens.receipt

import android.app.Activity
import android.content.Intent
import android.graphics.ImageDecoder
import android.net.Uri
import android.os.Build
import android.os.Bundle
import android.provider.MediaStore
import android.view.*
import android.widget.Toast
import androidx.databinding.DataBindingUtil
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProviders
import androidx.navigation.fragment.findNavController
import androidx.navigation.fragment.navArgs
import com.diekvoss.subshop.OrderEntity
import com.diekvoss.subshop.R
import com.diekvoss.subshop.databinding.ReceiptFragmentBinding
import com.diekvoss.subshop.screens.history.OrderHistoryViewModel
import java.util.*
import kotlinx.android.synthetic.main.receipt_fragment.*

/**
 * receiptFragment
 *
 * @property binding
 */
class ReceiptFragment : Fragment() {
  private lateinit var binding: ReceiptFragmentBinding
  private lateinit var viewModel: OrderHistoryViewModel
  private val args: ReceiptFragmentArgs by navArgs()
  private var REQUEST = 1000
  private var imageUri: Uri? = null

  /**
   * onCreateView
   *
   * @param inflater
   * @param container
   * @param savedInstanceState
   */
  override fun onCreateView(
      inflater: LayoutInflater,
      container: ViewGroup?,
      savedInstanceState: Bundle?,
  ): View? {
    // inflate view
    binding = DataBindingUtil.inflate(inflater, R.layout.receipt_fragment, container, false)

    // setup navigation
    binding.returnToWelcomeButton.setOnClickListener {
      viewModel.insertOrder(
          OrderEntity(
              UUID.randomUUID().toString(),
              binding.sandwichTypeText.text.toString(),
              binding.priceText.text.toString().toDouble(),
              Date(),
          ),
      )
      findNavController()
          .navigate(ReceiptFragmentDirections.actionReceiptFragmentToWelcomeFragment())
    }

    viewModel = ViewModelProviders.of(this).get(OrderHistoryViewModel::class.java)

    setHasOptionsMenu(true)
    return binding.root
  }

  /**
   * setup the text from the order received
   *
   * @param view
   * @param savedInstanceState
   */
  override fun onViewCreated(
      view: View,
      savedInstanceState: Bundle?,
  ) {
    super.onViewCreated(view, savedInstanceState)
    val order = args.sandwichOrder
    var total = order.breadType.price + order.sandwichType.price
    var toppings = ""
    if (order.toppings.isNotEmpty()) {
      toppings = "with:"
      for (topping in order.toppings) {
        total += topping.price
        toppings += "\t" + topping.name + "\n"
      }
    }
    binding.breadTypeText.text = order.breadType.name
    binding.sandwichTypeText.text = order.sandwichType.name
    binding.priceText.text = total.toString()
    binding.summaryText.text = toppings
  }

  /** @return Intent for opening the image */
  private fun getOpenImageIntent(): Intent =
      Intent().apply {
        action = Intent.ACTION_GET_CONTENT
        type = "image/*"
        putExtra("return-data", true)
      }

  /** @return intent to share the image */
  private fun getShareImageIntent(): Intent =
      Intent().apply {
        action = Intent.ACTION_SEND
        type = context?.contentResolver?.getType(imageUri!!)
        putExtra(Intent.EXTRA_STREAM, imageUri!!)
        putExtra("sms_body", summary_text.text.toString())
      }

  /**
   * inflate menu, doesn't show if they can't resolve
   *
   * @param menu
   * @param inflater
   */
  override fun onCreateOptionsMenu(
      menu: Menu,
      inflater: MenuInflater,
  ) {
    super.onCreateOptionsMenu(menu, inflater)
    inflater.inflate(R.menu.navdrawer_menu, menu)

    if (getOpenImageIntent().resolveActivity(activity?.packageManager!!) == null) {
      menu.findItem(R.id.open_image_menu).isVisible = false
      menu.findItem(R.id.share_image_menu).isVisible = false
    }
  }

  /**
   * get the image back from the intent
   *
   * @param requestCode
   * @param resultCode
   * @param data
   */
  override fun onActivityResult(
      requestCode: Int,
      resultCode: Int,
      data: Intent?,
  ) {
    if (requestCode == REQUEST && resultCode == Activity.RESULT_OK) {
      imageUri = data?.data
      if (Build.VERSION.SDK_INT < 28) {
        val bitmap = MediaStore.Images.Media.getBitmap(context?.contentResolver!!, imageUri!!)
        image.setImageBitmap(bitmap)
      } else {
        val source = ImageDecoder.createSource(context?.contentResolver!!, imageUri!!)
        val bitmap = ImageDecoder.decodeBitmap(source)
        image.setImageBitmap(bitmap)
      }
    }
    super.onActivityResult(requestCode, resultCode, data)
  }

  /**
   * detect item detected doesn't let you share if there is no image loaded
   *
   * @param item item selected
   */
  override fun onOptionsItemSelected(item: MenuItem): Boolean {
    when (item.itemId) {
      R.id.open_image_menu -> {
        startActivityForResult(getOpenImageIntent(), REQUEST)
      }

      R.id.share_image_menu -> {
        if (imageUri == null) {
          Toast.makeText(context, "No Image has been opened yet", Toast.LENGTH_LONG).show()
        } else {
          startActivity(getShareImageIntent())
        }
      }
    }
    return super.onOptionsItemSelected(item)
  }
}
