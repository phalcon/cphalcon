--TEST--
Dereference of undefined pointer value + segfault in zim_Phalcon_Image_Adapter_GD___construct
--SKIPIF--
<?php
include('skipif.inc');
if (!extension_loaded('gd')) {
	die('skip gd extension is required');
}
?>
--FILE--
<?php
try {
	$g = new \Phalcon\Image\Adapter\Gd(__FILE__);
	assert(false);
}
catch (Exception $e) {
	assert(true);
}
?>
--EXPECT--
