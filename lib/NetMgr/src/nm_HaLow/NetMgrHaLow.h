/**
 * @author     D.J. Morvay
 */

#ifndef NetMgrHaLow_h
#define NetMgrHaLow_h

#include "mmhal_wlan.h"
#include "HaLowScan.h"
#include "stdint.h"
#include "stdbool.h"
#include <sys/types.h>

class NetMgrWiFiHaLow
{

public:
    NetMgrWiFiHaLow() {}

    ~NetMgrWiFiHaLow() {
        this->off();
    }

    void begin() {
    }

    void startConfig() {
    }

    bool isConfigured() {
        // @Todo implement
        return true;
    }

    void on() {
    }

    void off() {
    }

    void setHostname(const String& hostname) {
    }

    bool isHardwareAvailable() {
        return true;
    }

    bool supportsScan() { return true; }
    bool supports5GHz() { return false;}
    bool supportsStaticIP() { return false; }

    bool isConnected() {
        // @Todo implement
        return true;
    }

    const char* getErrorStr() {
        return NULL;
    }

    const char* getStateStr() {
        return "UNKNOWN";
    }

    String getMacAddress() {
        uint8_t mac[6];
        memset(mac, 0, sizeof(mac));
        mmhal_read_mac_addr(mac);
        return macToString(mac);
    }

    String getLocalIP() {
        // @Todo implement
        return "192.168.1.2";
    }

    String getStatus() {
        // @Todo implement
        return "up";
    }

    String getNetworkSSID() {
        // @Todo implement
        return "UnknownSSID";
    }

    String getNetworkBSSID() {
        // @Todo implement
        return "00:00:00:00:00:00";
    }

    int getRSSI() {
        // @Todo implement
        return 0;
    }

    int scanNetworks() {
        if (!_scanResults) {
            _scanResults = new WiFiAccessPoint[MAX_SCAN_RESULTS];
        }
        ssid_scan();

        while(!is_scan_complete()) {
            // wait
        }

        _scanResultsQty = scan_results(_scanResults, MAX_SCAN_RESULTS);
        return _scanResultsQty;
    }

    void scanDelete() {
        if (_scanResults) {
            delete[] _scanResults;
            _scanResults = nullptr;
            _scanResultsQty = 0;
        }
    }

    bool scanGetResult(int i, String& ssid, String& sec,
                       int& rssi, String& bssid, int& chan)
    {
        if (!_scanResults || i < 0 || i >= _scanResultsQty) {
            return false;
        }

        WiFiAccessPoint& ap = _scanResults[i];
        ssid  = ap.ssid;
        bssid = macToString(ap.bssid);
        rssi  = ap.rssi;
        sec   = wifiSecToStr(ap.security);
        chan  = ap.channel;

        return true;
    }

    bool addNetwork(const String& ssid) {
        // @Todo implement
        return true;
    }

    bool addNetwork(const String& ssid, const String& psk) {
        // @Todo implement

        return true;
    }

    void clearNetworks() {
        // @TODO implement
    }

    void run() {
        // do nothing
    }

public:

    static inline
    const char* wifiSecToStr(WLanSecurityType t) {
      switch (t) {
        case UNSEC:                 return "OPEN";
        case WEP:                   return "WEP";
        case WPA:                   return "WPA";
        case WPA2:                  return "WPA2";
        case WPA_ENTERPRISE:        return "WPA-EAP";
        case WPA2_ENTERPRISE:       return "WPA2-EAP";
        default:                    return "unknown";
      }
    }

    /*
    static inline
    const char* wifiCipherToStr(WLanSecurityCipher t) {
      switch (t) {
        case WLAN_CIPHER_NOT_SET:   return "NONE";
        case WLAN_CIPHER_AES:       return "AES";
        case WLAN_CIPHER_TKIP:      return "TKIP";
        case WLAN_CIPHER_AES_TKIP:  return "AES+TKIP";
        default:    return "unknown";
      }
    }
    */

private:
    WiFiAccessPoint* _scanResults = nullptr;
    uint8_t          _scanResultsQty = 0;
};

#endif /* NetMgrWiFiHaLow_h */
