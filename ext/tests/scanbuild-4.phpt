--TEST--
Division by zero - zim_Phalcon_Image_Adapter_Imagick__pixelate
--SKIPIF--
<?php
include('skipif.inc');
if (!extension_loaded('imagick')) {
	die('skip imagick extension is required');
}
?>
--FILE--
<?php
class MyImageAdapter extends \Phalcon\Image\Adapter\Imagick
{
	public function pixelate($amount)
	{
		$this->_pixelate($amount);
	}
}

\Phalcon\Image\Adapter\Imagick::setResourceLimit(6, 1);
$g = new \MyImageAdapter(__DIR__ . '/images/Neighborhood_watch_bw.png');
$g->pixelate(0);
?>
--EXPECT--
