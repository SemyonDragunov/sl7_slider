<?php

/**
 * @author Semyon Dragunov <sam.dragunov@gmail.com>
 * https://github.com/SemyonDragunov
 */

function theme_sl7_slider_configuration_form($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('sl7-slider-configuration', 'order', 'sibling', 'slide-weight');
  $rows = array();

  if (isset($form['slides']) && !empty($form['slides'])) {
    foreach ($form['slides'] as $slide => &$property) {
      if (is_numeric($slide)) {
        // Create an array to hold the table row for the current slide
        $row = [];

        // Add a column containing the slide's title to the current row
        $name = $property['fid'];
        $row[] = [
          'data' => 'Слайд ' . $name['#value'],
        ];
        unset($property['fid']);

        // Add a column containing the slide's weight to the current row
        $weight = $property['weight'];
        $row[] = [
          'data' => drupal_render($weight),
        ];
        unset($property['weight']);

        // Add a column containing the slide's weight to the current row
        $published = $property['published'];
        $row[] = [
          'data' => drupal_render($published),
        ];
        unset($property['published']);

        // Add a column containing the slide's weight to the current row
        $delete = $property['delete'];
        $row[] = [
          'data' => drupal_render($delete),
        ];
        unset($property['delete']);

        // Store the individual row
        $rows[] = [
          'data' => $row,
          'class' => ['draggable'],
        ];
      }
    }
  }

  // Build the draggable table if any rows are available
  if (!empty($rows)) {
    // Create an array of table headers
    $headers = array(
      t('Name'),
      t('Weight'),
      t('Published'),
      t('Delete'),
    );

    // Over-write the 'order' form element with the draggable table
    $form['order'] = array(
      '#theme' => 'table',
      '#header' => $headers,
      '#rows' => $rows,
      '#attributes' => array(
        'id' => 'sl7-slider-configuration',
      ),
    );
  }

  return drupal_render_children($form);
}