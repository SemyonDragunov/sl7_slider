(function($) {
  Drupal.behaviors.sl7_slider = {
    attach: function (context, settings) {
      if (settings.autoPlay == 0) {
        settings.autoPlay = false;
      }

      $("#sl7-slider").owlCarousel({
        items: 1,
        singleItem: true,
        autoPlay: settings.autoPlay,
        navigation: !!settings.navigation,
        navigationText: false,
        pagination: !!settings.pagination,
        transitionStyle: settings.transitionStyle,
        addClassActive: true,
        lazyLoad: true,
        lazyEffect: settings.transitionStyle
      });
    }
  };
})(jQuery);