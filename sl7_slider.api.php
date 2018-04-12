<?php 

/**
 * Implements hook_sl7_slider_theme().
 * 
 * Инициирование типа дизайна.
 * 
 * title - Название.
 * css - CSS файл.
 */
function hook_sl7_slider_theme() {
	$path = drupal_get_path('module', 'sl7_slider');
	
	$themes['dark'] = array(
		'title' => 'Тёмный',
		'css' => $path . '/css/sl7_slider.css',
	);
	
	return $themes;
}