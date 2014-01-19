--TEST--
Segmentation fault in zim_Phalcon_Image_Adapter_Imagick_check - https://github.com/phalcon/cphalcon/issues/1368
--SKIPIF--
<?php
include('skipif.inc');
if (!class_exists('imagick')) {
	die('skip imagick extension is required');
}
?>
--FILE--
<?php
try {
	new \Phalcon\Image\Adapter\Imagick('');
}
catch (Exception $e) {
}
?>
--EXPECT--
