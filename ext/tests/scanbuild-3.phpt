--TEST--
Division by zero - zim_Phalcon_Image_Adapter_GD__reflection
--SKIPIF--
<?php
include('skipif.inc');
if (!extension_loaded('gd')) {
	die('skip gd extension is required');
}
?>
--FILE--
<?php
$g = new \Phalcon\Image\Adapter\Gd(__DIR__ . '/images/Neighborhood_watch_bw.png');
$g->reflection(0);
?>
--EXPECT--
