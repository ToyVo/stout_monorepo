package com.diekvoss.testmaps

import android.app.Activity
import android.content.Intent
import android.content.IntentSender
import android.content.pm.PackageManager
import android.location.Address
import android.location.Geocoder
import android.location.Location
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import com.google.android.gms.common.api.ResolvableApiException
import com.google.android.gms.location.*
import com.google.android.gms.maps.CameraUpdateFactory
import com.google.android.gms.maps.GoogleMap
import com.google.android.gms.maps.OnMapReadyCallback
import com.google.android.gms.maps.SupportMapFragment
import com.google.android.gms.maps.model.*
import com.google.android.libraries.places.api.Places
import com.google.android.libraries.places.api.model.Place
import com.google.android.libraries.places.widget.Autocomplete
import com.google.android.libraries.places.widget.AutocompleteActivity
import com.google.android.libraries.places.widget.model.AutocompleteActivityMode
import java.io.IOException
import kotlinx.android.synthetic.main.activity_maps.*

class MapsActivity :
    AppCompatActivity(),
    OnMapReadyCallback,
    GoogleMap.OnPolylineClickListener,
    GoogleMap.OnPolygonClickListener,
    GoogleMap.OnMarkerClickListener {
  private lateinit var map: GoogleMap
  private lateinit var fusedLocationClient: FusedLocationProviderClient
  private lateinit var lastLocation: Location
  private lateinit var locationCallback: LocationCallback
  private lateinit var locationRequest: LocationRequest

  private var locationUpdateState = false

  private val DOT = Dot()
  private val DASH = Dash(PATTERN_DASH_LENGTH_PX.toFloat())
  private val GAP = Gap(PATTERN_GAP_LENGTH_PX.toFloat())

  // Create a stroke pattern of a gap followed by a dot.
  private val PATTERN_POLYLINE_DOTTED = listOf(GAP, DOT)

  // Create a stroke pattern of a gap followed by a dash.
  private val PATTERN_POLYGON_ALPHA = listOf(GAP, DASH)

  // Create a stroke pattern of a dot followed by a gap, a dash, and another gap.
  private val PATTERN_POLYGON_BETA = listOf(DOT, GAP, DASH, GAP)

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_maps)

    // Obtain the SupportMapFragment and get notified when the map is ready to be used.
    val mapFragment = supportFragmentManager.findFragmentById(R.id.map) as SupportMapFragment
    mapFragment.getMapAsync(this)

    fusedLocationClient = LocationServices.getFusedLocationProviderClient(this)

    locationCallback =
        object : LocationCallback() {
          override fun onLocationResult(locationResult: LocationResult?) {
            super.onLocationResult(locationResult)

            lastLocation = locationResult!!.lastLocation
            placeMarkerOnMap(LatLng(lastLocation.latitude, lastLocation.longitude))
          }
        }

    createLocationRequest()

    fab.setOnClickListener { loadPlacePicker() }
  }

  /**
   * Manipulates the map once available. This callback is triggered when the map is ready to be
   * used. This is where we can add markers or lines, add listeners or move the camera. In this
   * case, we just add a marker near Sydney, Australia. If Google Play services is not installed on
   * the device, the user will be prompted to install it inside the SupportMapFragment. This method
   * will only be triggered once the user has installed Google Play services and returned to the
   * app.
   */
  override fun onMapReady(googleMap: GoogleMap) {
    map = googleMap

    // Add polylines to the map.
    // Polylines are useful to show a route or some other connection between points.
    val polyline1 =
        map.addPolyline(
            PolylineOptions()
                .clickable(true)
                .add(
                    LatLng(-35.016, 143.321),
                    LatLng(-34.747, 145.592),
                    LatLng(-34.364, 147.891),
                    LatLng(-33.501, 150.217),
                    LatLng(-32.306, 149.248),
                    LatLng(-32.491, 147.309),
                ),
        )
    // Store a data object with the polyline, used here to indicate an arbitrary type.
    polyline1.tag = "A"
    // Style the polyline.
    stylePolyline(polyline1)

    val polyline2 =
        map.addPolyline(
            PolylineOptions()
                .clickable(true)
                .add(
                    LatLng(-29.501, 119.700),
                    LatLng(-27.456, 119.672),
                    LatLng(-25.971, 124.187),
                    LatLng(-28.081, 126.555),
                    LatLng(-28.848, 124.229),
                    LatLng(-28.215, 123.938),
                ),
        )
    polyline2.tag = "B"
    stylePolyline(polyline2)

    // Add polygons to indicate areas on the map.
    val polygon1 =
        map.addPolygon(
            PolygonOptions()
                .clickable(true)
                .add(
                    LatLng(-27.457, 153.040),
                    LatLng(-33.852, 151.211),
                    LatLng(-37.813, 144.962),
                    LatLng(-34.928, 138.599),
                ),
        )
    // Store a data object with the polygon, used here to indicate an arbitrary type.
    polygon1.tag = "alpha"
    // Style the polygon.
    stylePolygon(polygon1)

    val polygon2 =
        map.addPolygon(
            PolygonOptions()
                .clickable(true)
                .add(
                    LatLng(-31.673, 128.892),
                    LatLng(-31.952, 115.857),
                    LatLng(-17.785, 122.258),
                    LatLng(-12.4258, 130.7932),
                ),
        )
    polygon2.tag = "beta"
    stylePolygon(polygon2)

    // map.mapType = GoogleMap.MAP_TYPE_TERRAIN
    map.setMapStyle(MapStyleOptions.loadRawResourceStyle(this, R.raw.style_json))

    //        // Add a marker in Sydney and move the camera
    //        val myPlace = LatLng(40.73, -73.99)
    //        map.addMarker(MarkerOptions().position(myPlace).title("Marker at New York"))
    //        map.moveCamera(CameraUpdateFactory.newLatLngZoom(myPlace, 12f))

    map.uiSettings.isZoomControlsEnabled = true

    // Set listeners for click events.
    map.setOnPolylineClickListener(this)
    map.setOnPolygonClickListener(this)
    map.setOnMarkerClickListener(this)

    getPermission()
    getLocation()
  }

  private fun getPermission() {
    if (ActivityCompat.checkSelfPermission(
        this,
        android.Manifest.permission.ACCESS_FINE_LOCATION,
    ) != PackageManager.PERMISSION_GRANTED) {
      ActivityCompat.requestPermissions(
          this,
          arrayOf(android.Manifest.permission.ACCESS_FINE_LOCATION),
          LOCATION_PERMISSION_REQUEST_CODE,
      )
      return
    }
  }

  private fun getLocation() {
    map.isMyLocationEnabled = true

    fusedLocationClient.lastLocation.addOnSuccessListener(this) { location ->
      if (location != null) {
        lastLocation = location
        val currentLatLng = LatLng(location.latitude, location.longitude)
        placeMarkerOnMap(currentLatLng)
        map.animateCamera(CameraUpdateFactory.newLatLngZoom(currentLatLng, 12.0f))
      }
    }
  }

  private fun getAddress(location: LatLng): String {
    val geocoder = Geocoder(this)
    val addresses: List<Address>?
    val address: Address?
    var addressText = ""

    try {
      addresses = geocoder.getFromLocation(location.latitude, location.longitude, 1)

      if (null != addresses && addresses.isNotEmpty()) {
        address = addresses[0]
        for (i in 0 until address.maxAddressLineIndex) {
          addressText +=
              if (i == 0) {
                address.getAddressLine(i)
              } else {
                "\n" +
                    address.getAddressLine(
                        i,
                    )
              }
        }
      }
    } catch (e: IOException) {
      Log.e("MapsActivity", e.localizedMessage!!)
    }

    return addressText
  }

  private fun placeMarkerOnMap(location: LatLng) {
    val markerOptions = MarkerOptions().position(location)
    //        markerOptions.icon(
    //            BitmapDescriptorFactory.fromBitmap(
    //                BitmapFactory.decodeResource(
    //                    resources,
    //                    R.mipmap.ic_user_location
    //                )
    //            )
    //        )

    val titleStr = getAddress(location)
    markerOptions.title(titleStr)
    // markerOptions.icon(BitmapDescriptorFactory.defaultMarker(BitmapDescriptorFactory.HUE_GREEN))
    map.addMarker(markerOptions)
  }

  private fun stylePolyline(polyline: Polyline) {
    when (polyline.tag.toString()) {
      "A" -> {
        polyline.startCap =
            CustomCap(BitmapDescriptorFactory.fromResource(R.drawable.ic_arrow), 10f)
      }

      "B" -> {
        polyline.startCap = RoundCap()
      }
    }

    polyline.endCap = RoundCap()
    polyline.width = POLYLINE_STROKE_WIDTH_PX.toFloat()
    polyline.color = COLOR_BLACK_ARGB
    polyline.jointType = JointType.ROUND
  }

  private fun stylePolygon(polygon: Polygon) {
    var pattern: List<PatternItem>? = null
    var strokeColor = COLOR_BLACK_ARGB
    var fillColor = COLOR_WHITE_ARGB

    when (polygon.tag.toString()) {
      // If no type is given, allow the API to use the default.
      "alpha" -> {
        // Apply a stroke pattern to render a dashed line, and define colors.
        pattern = PATTERN_POLYGON_ALPHA
        strokeColor = COLOR_GREEN_ARGB
        fillColor = COLOR_PURPLE_ARGB
      }

      "beta" -> {
        // Apply a stroke pattern to render a line of dots and dashes, and define colors.
        pattern = PATTERN_POLYGON_BETA
        strokeColor = COLOR_ORANGE_ARGB
        fillColor = COLOR_BLUE_ARGB
      }
    }

    polygon.strokePattern = pattern
    polygon.strokeWidth = POLYGON_STROKE_WIDTH_PX.toFloat()
    polygon.strokeColor = strokeColor
    polygon.fillColor = fillColor
  }

  override fun onPolylineClick(polyline: Polyline?) {
    if (polyline != null) {
      // Flip from solid stroke to dotted stroke pattern.
      if (polyline.pattern == null || !polyline.pattern!!.contains(DOT)) {
        polyline.pattern = PATTERN_POLYLINE_DOTTED
      } else {
        // The default pattern is a solid stroke.
        polyline.pattern = null
      }

      Toast.makeText(
              this,
              "Route type " + polyline.tag.toString(),
              Toast.LENGTH_SHORT,
          )
          .show()
    }
  }

  override fun onPolygonClick(polygon: Polygon?) {
    if (polygon != null) {
      // Flip the values of the red, green, and blue components of the polygon's color.
      var color = polygon.strokeColor xor 0x00ffffff
      polygon.strokeColor = color
      color = polygon.fillColor xor 0x00ffffff
      polygon.fillColor = color

      Toast.makeText(
              this,
              "Area type " + polygon.tag.toString(),
              Toast.LENGTH_SHORT,
          )
          .show()
    }
  }

  override fun onMarkerClick(marker: Marker?) = false

  private fun startLocationUpdates() {
    if (ActivityCompat.checkSelfPermission(
        this,
        android.Manifest.permission.ACCESS_FINE_LOCATION,
    ) != PackageManager.PERMISSION_GRANTED) {
      ActivityCompat.requestPermissions(
          this,
          arrayOf(android.Manifest.permission.ACCESS_FINE_LOCATION),
          LOCATION_PERMISSION_REQUEST_CODE,
      )
      return
    }

    fusedLocationClient.requestLocationUpdates(
        locationRequest,
        locationCallback,
        null, // Looper
    )
  }

  private fun createLocationRequest() {
    locationRequest = LocationRequest()
    locationRequest.interval = 10000
    locationRequest.fastestInterval = 5000
    locationRequest.priority = LocationRequest.PRIORITY_HIGH_ACCURACY

    val builder = LocationSettingsRequest.Builder().addLocationRequest(locationRequest)

    val client = LocationServices.getSettingsClient(this)
    val task = client.checkLocationSettings(builder.build())

    task.addOnSuccessListener {
      locationUpdateState = true
      startLocationUpdates()
    }
    task.addOnFailureListener { e ->
      if (e is ResolvableApiException) {
        // Location settings are not satisfied, but this can be fixed
        // by showing the user a dialog.
        try {
          // Show the dialog by calling startResolutionForResult(),
          // and check the result in onActivityResult().
          e.startResolutionForResult(
              this@MapsActivity,
              REQUEST_CHECK_SETTINGS,
          )
        } catch (sendEx: IntentSender.SendIntentException) {
          // Ignore the error.
        }
      }
    }
  }

  override fun onActivityResult(
      requestCode: Int,
      resultCode: Int,
      data: Intent?,
  ) {
    super.onActivityResult(requestCode, resultCode, data)
    if (requestCode == REQUEST_CHECK_SETTINGS) {
      if (resultCode == Activity.RESULT_OK) {
        locationUpdateState = true
        startLocationUpdates()
      }
    }
    if (requestCode == AUTOCOMPLETE_REQUEST_CODE) {
      when (resultCode) {
        Activity.RESULT_OK -> {
          data?.let {
            val place = Autocomplete.getPlaceFromIntent(data)
            var addressText: String = place.name.toString()
            addressText += "\n" + place.address.toString()

            place.latLng?.let { location -> placeMarkerOnMap(location) }
          }
        }

        AutocompleteActivity.RESULT_ERROR -> {
          Log.i("", "error")
        }

        Activity.RESULT_CANCELED -> {
          Log.i("", "cancelled")
        }
      }
    }
  }

  override fun onPause() {
    super.onPause()
    fusedLocationClient.removeLocationUpdates(locationCallback)
  }

  override fun onResume() {
    super.onResume()
    if (!locationUpdateState) {
      startLocationUpdates()
    }
  }

  private fun loadPlacePicker() {
    if (!Places.isInitialized()) {
      Places.initialize(applicationContext, getString(R.string.google_maps_key))
    }

    val fields = listOf(Place.Field.ID, Place.Field.NAME)

    val intent = Autocomplete.IntentBuilder(AutocompleteActivityMode.FULLSCREEN, fields).build(this)

    startActivityForResult(intent, AUTOCOMPLETE_REQUEST_CODE)
  }

  companion object {
    private const val LOCATION_PERMISSION_REQUEST_CODE = 1
    private const val REQUEST_CHECK_SETTINGS = 2
    private const val AUTOCOMPLETE_REQUEST_CODE = 3

    private const val COLOR_BLACK_ARGB = -0x1000000
    private const val COLOR_WHITE_ARGB = -0x1
    private const val COLOR_GREEN_ARGB = -0xc771c4
    private const val COLOR_PURPLE_ARGB = -0x7e387c
    private const val COLOR_ORANGE_ARGB = -0xa80e9
    private const val COLOR_BLUE_ARGB = -0x657db

    private const val POLYLINE_STROKE_WIDTH_PX = 12
    private const val POLYGON_STROKE_WIDTH_PX = 8
    private const val PATTERN_DASH_LENGTH_PX = 20
    private const val PATTERN_GAP_LENGTH_PX = 20
  }
}
