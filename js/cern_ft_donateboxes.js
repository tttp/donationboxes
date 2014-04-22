(function($){

  $(function(){
    var $labels = $('.cern-ft-donateboxes > .dqx-column > label');
    var $boxes = $labels.parent();
    var $container = $boxes.parent();
    var boxesByRadioId = {};
    var selectors = [];

    $labels.each(function(){
      var $label = $(this);
      var $box = $label.parent();
      var id = $label.attr('for');
      if (!id) {
        return;
      }
      boxesByRadioId[id] = $box;
      selectors.push('input#' + id);
    });

    $(selectors.join(', ')).change(function(e){
      $container.addClass('some-amount-chosen');
      var $radio = $(this);
      var id = $radio.attr('id');
      $boxes.removeClass('active');
      if (boxesByRadioId[id]) {
        boxesByRadioId[id].addClass('active');
      }
    });

    // $('#priceset-div').hide();
  });

})(jQuery);
