Situm Cordova Plugin
======

> Current Status:

Android: In development (some calls already implemented)
IOS: Not implemented yet


> Android

**setApiKey:**

```javascript
      cordova.plugins.Situm.setApiKey("email", "api_key");
```

**setUserPass:**

```javascript
       cordova.plugins.Situm.setUserPass("email", "password");
```

**fetchBuildings:**

```javascript
       cordova.plugins.Situm.fetchBuildings((buildings) => {
         // buildings -> array of building objects
       });
```

**fetchFloorsFromBuilding:**

```javascript
      let building = {
        id: 0,                      // integer
        user_id: 0,                 // intger
        name: "name",               // string
        description: "description", // string
        created_at: 00-00-0000,     // datetime
        updated_at: 00-00-0000,     // datetime
        location: location,         // object -> see http://developers.situm.es/pages/rest/buildings.html
        corners: corners,           // object -> see http://developers.situm.es/pages/rest/buildings.html
        dimensions: dimensions,     // object -> see http://developers.situm.es/pages/rest/buildings.html
        rotation: 0.00,             // float
        picture_url: "url",         // string optional
        picture_thumb_url: "url",   // string optional
        server_url: "url",          // string optional
        calibration_model: model,   // object -> see http://developers.situm.es/pages/rest/buildings.html
        info: "info",               // string
        floors: floors,             // array of floors see -> http://developers.situm.es/pages/rest/floors.html
        indoor_pois: indoor_pois,   // array of POIs see -> http://developers.situm.es/pages/rest/indoor_pois.html
        outdoor_pois: outdoor_pois, // array of POIs see -> http://developers.situm.es/pages/rest/outdoor_pois.html
        events: events ,            // array of events see -> http://developers.situm.es/pages/rest/events.html
        paths: paths                // object see -> http://developers.situm.es/pages/rest/paths.html
      };
      cordova.plugins.Situm.fetchFloorsFromBuilding(building, (floors) => {
        // floors -> array of floor objects from given building
      });
```

**fetchIndoorPOIsFromBuilding**

```javascript
      cordova.plugin.Situm.fetchIndoorPOIsFromBuilding(building, (indoorPOIs) => {
        // indoorPOIs -> array of POIs indoor building
      });
```

**fetchOutdoorPOIsFromBuilding**

```javascript
      cordova.plugins.Situm.fetchOutdoorPOIsFromBuilding(building, (outdoorPOIs) => {
        // outdoorPOIs -> array of POIs outdoor building
      });
```

**fetchEventsFromBuilding**

```javascript
      cordova.plugins.Situm.fetchEventsFromBuilding(building, (events) => {
        // events -> array of events
      });
```

**fetchMapFromFloor:**

```javascript
      cordova.plugins.Situm.fetchMapFromFloor(floor, (map) => {
        // map -> image encoded as base64 string
      });
```

**fetchPoiCategories:**

```javascript
       cordova.plugins.Situm.fetchPoiCategories((poiCategories) => {
         // poiCategories -> array of POI categories
       });
```

**fetchPoiCategoryIconNormal**

```javascript
      let category = {
          "id": 1,
          "name_en": "Coffee",
          "name_es": "Cafetería",
          "code": "situm-coffee",
          "icon_url": "/uploads/situm/poi_category/icon/1/31cc9fdf-6820-447d-ac13-a0a4d0642d3b.png",
          "selected_icon_url": "/uploads/situm/poi_category/selected_icon/1/eb7c6c7e-33ba-40c5-ae22-e993b64d1439.png",
          "updated_at": "2016-07-11T10:20:39.684+02:00",
          "created_at": "2016-06-23T09:14:05.701+02:00",
          "public": true
      };  
      cordova.plugins.Situm.fetchPoiCategoryIconNormal(category, (icon) => {

      });
```

**fetchPoiCategoryIconSelected**

```javascript
      let category = {
          "id": 1,
          "name_en": "Coffee",
          "name_es": "Cafetería",
          "code": "situm-coffee",
          "icon_url": "/uploads/situm/poi_category/icon/1/31cc9fdf-6820-447d-ac13-a0a4d0642d3b.png",
          "selected_icon_url": "/uploads/situm/poi_category/selected_icon/1/eb7c6c7e-33ba-40c5-ae22-e993b64d1439.png",
          "updated_at": "2016-07-11T10:20:39.684+02:00",
          "created_at": "2016-06-23T09:14:05.701+02:00",
          "public": true
      };  
      cordova.plugins.Situm.fetchPoiCategoryIconSelected(category, (icon) => {

      });
```

**invalidateCache**

```javascript
      cordova.plugins.Situm.invalidateCache((res) => {
          // res -> string message
      });
```

**requestDirections**

```javascript
      // from & to -> POI object
      from = {
        "id": 1110,
        "building_id": 98,
        "name": "Salida de emergencia",
        "category_id": null,
        "created_at": "2016-06-23T09:13:44.238+02:00",
        "updated_at": "2016-06-23T09:13:44.238+02:00",
        "info": "<p>Office information</p>",
        "position": {
          "floor_id": 250,
          "radius": 5,
          "georeferences": {
            "lat": 42.8888740652095,
            "lng": -8.52679516919729
          },
          "cartesians": {
            "x": 118.195381193397,
            "y": 83.5619519803241
          }
        },
        "custom_fields": [
          {
            "key": "active",
            "value": "false"
          }
        ]
      }
      to = {
        "id": 1110,
        "building_id": 98,
        "name": "Salida de emergencia",
        "category_id": null,
        "created_at": "2016-06-23T09:13:44.238+02:00",
        "updated_at": "2016-06-23T09:13:44.238+02:00",
        "info": "<p>Office information</p>",
        "position": {
          "floor_id": 250,
          "radius": 5,
          "georeferences": {
            "lat": 42.8888740652095,
            "lng": -8.52679516919729
          },
          "cartesians": {
            "x": 118.195381193397,
            "y": 83.5619519803241
          }
        },
        "custom_fields": [
          {
            "key": "active",
            "value": "false"
          }
        ]
      }
      cordova.plugins.Situm.requestDirections([from, to], (res) => {
        // res -> route object
      });
```

**startPositioning:**

```javascript
    cordova.plugins.Situm.startPositioning(buildings, callback)
```
**stopPositioning:**

```javascript
    cordova.plugins.Situm.stopPositioning(callback)
```
