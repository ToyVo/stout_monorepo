package com.diekvoss.subshop

import android.os.Parcelable
import kotlinx.android.parcel.Parcelize

@Parcelize
data class SandwichOrder(
    val breadType: SandwichItem,
    val sandwichType: SandwichItem,
    val toppings: Set<SandwichItem>,
) : Parcelable

@Parcelize
data class SandwichItem(
    val name: String,
    val price: Double,
) : Parcelable
