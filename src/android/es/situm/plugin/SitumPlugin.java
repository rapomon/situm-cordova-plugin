/**
 */
package es.situm.plugin;

import android.es.situm.plugin.PluginHelper;
import android.util.Log;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import es.situm.sdk.SitumSdk;
import es.situm.sdk.model.cartography.Building;
import es.situm.sdk.utils.Handler;
import es.situm.sdk.error.Error;

import java.util.Collection;
import java.util.Date;

public class SitumPlugin extends CordovaPlugin {
  
  private static final String TAG = "SitumPlugin";

  private Building selectedBuilding;

  public void initialize(CordovaInterface cordova, CordovaWebView webView) {
    super.initialize(cordova, webView);
    Log.d(TAG, "Initializing Situm Plugin");
    SitumSdk.init(cordova.getActivity());
    es.situm.sdk.SitumSdk.configuration().setApiKey("alberto.doval@cocodin.com", "391b363b6f1a00acf10f67471380980dcdf989ffafc08601229b6c67bb4d1a11");
  }

  public boolean execute(String action, JSONArray args, final CallbackContext callbackContext) throws JSONException {
    Log.d(TAG, "execute: " + action);
    if(action.equals("echo")) {
      String phrase = args.getString(0);
      Log.d(TAG, phrase);
    } else if(action.equals("fetchBuildings")) {
      PluginHelper.fetchBuildings(cordova, webView, args, callbackContext);
    } else if(action.equals("startPositioning")) {
      PluginHelper.startPositioning(cordova, webView, args, callbackContext);
    }
    else if(action.equals("stopPositioning")) {
      PluginHelper.stopPositioning(cordova, webView, args, callbackContext);
    }
    return true;
  }

}
