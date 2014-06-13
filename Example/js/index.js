var app = {
    initialize: function () {
        this.bindEvents();
    },
    bindEvents: function () {
        document.addEventListener('deviceready', this.onDeviceReady, false);
        document.addEventListener('onInterstitialReceive', this.onInterstitialReceive, false);
        document.addEventListener('onBannerReceive', this.onBaiduEventReceive, false);
        document.addEventListener('onAdSwitch', this.onBaiduEventReceive, false);
    },
    onDeviceReady: function () {
        app.receivedEvent('deviceready');
    },
    onInterstitialReceive: function (message) {
        baiduAd.showInterstitial();
    },
    onBaiduEventReceive: function (message) {
        console.log('接收到 Event: ' + message.type);
    },
    receivedEvent: function (id) {
        app.addBanner();
        app.addInterstitial();
        var parentElement = document.getElementById(id);
        var listeningElement = parentElement.querySelector('.listening');
        var receivedElement = parentElement.querySelector('.received');

        listeningElement.setAttribute('style', 'display:none;');
        receivedElement.setAttribute('style', 'display:block;');

        console.log('Received Event: ' + id);
    },

    addBanner: function () {
        var successCreateBannerView = function () {
            baiduAd.showBanner(8);
        };
        var errorCreateBannerView = function (message) {
            console.log("创建广告条失败 " + message);
        };
        baiduAd.initBanner("debug", "debug", successCreateBannerView, errorCreateBannerView);
    },

    addInterstitial: function () {
        var successCreateInterstitial = function () {
            baiduAd.cacheInterstitial();
        };
        baiduAd.initInterstitial("debug", "debug", successCreateInterstitial);
    },

    showInterstitial: function () {
        var isReadySuccess = function (isReady) {
            if (isReady) {
                baiduAd.showInterstitial();
            } else {
                baiduAd.cacheInterstitial();
            }
        };
        baiduAd.isInterstitialReady(isReadySuccess);
    },
    disposePlugin: function () {
        baiduAd.disposePlugin();
    }
};
