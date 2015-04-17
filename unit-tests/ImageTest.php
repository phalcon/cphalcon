<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
	+------------------------------------------------------------------------+
	| This source file is subject to the New BSD License that is bundled     |
	| with this package in the file docs/LICENSE.txt.                        |
	|                                                                        |
	| If you did not receive a copy of the license and are unable to         |
	| obtain it through the world-wide-web, please send an email             |
	| to license@phalconphp.com so we can send you a copy immediately.       |
	+------------------------------------------------------------------------+
	| Authors: Andres Gutierrez <andres@phalconphp.com>                      |
	|          Eduar Carvajal <eduar@phalconphp.com>                         |
	+------------------------------------------------------------------------+
*/

class ImageTest extends PHPUnit_Framework_TestCase
{

	/**
	 * @large
	 */
	public function testGD()
	{
		if (!function_exists('gd_info')) {
			$this->markTestSkipped("Skipped");
			return;
		}

		@unlink('unit-tests/assets/production/gd-new.jpg');
		@unlink('unit-tests/assets/production/gd-resize.jpg');
		@unlink('unit-tests/assets/production/gd-crop.jpg');
		@unlink('unit-tests/assets/production/gd-rotate.jpg');
		@unlink('unit-tests/assets/production/gd-flip.jpg');
		@unlink('unit-tests/assets/production/gd-sharpen.jpg');
		@unlink('unit-tests/assets/production/gd-reflection.jpg');
		@unlink('unit-tests/assets/production/gd-watermark.jpg');
		@unlink('unit-tests/assets/production/gd-mask.jpg');
		@unlink('unit-tests/assets/production/gd-background.jpg');

		// Create new image
		$image = new Phalcon\Image\Adapter\GD('unit-tests/assets/production/gd-new.jpg', 100, 100);
		$image->save();
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-new.jpg'));

		$image = new Phalcon\Image\Adapter\GD('unit-tests/assets/phalconphp.jpg');

		 // Resize to 200 pixels on the shortest side
		$image->resize(200, 200)->save('unit-tests/assets/production/gd-resize.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-resize.jpg'));

		$tmp = imagecreatefromjpeg('unit-tests/assets/production/gd-resize.jpg');
		$width = imagesx($tmp);
		$height = imagesy($tmp);
		$this->assertTrue($width <= 200);
		$this->assertTrue($height <= 200);

		$this->assertTrue($image->getWidth() <= 200);
		$this->assertTrue($image->getHeight() <= 200);

		// Resize to 200x200 pixels, keeping aspect ratio
		//$image->resize(200, 200, Phalcon\Image::INVERSE);

		// Resize to 500 pixel width, keeping aspect ratio
		//$image->resize(500, NULL);

		// Resize to 500 pixel height, keeping aspect ratio
		//$image->resize(NULL, 500);

		// Resize to 200x500 pixels, ignoring aspect ratio
		//$image->resize(200, 500, Phalcon\Image::NONE);

		// Crop the image to 200x200 pixels, from the center
		$image = new Phalcon\Image\Adapter\GD('unit-tests/assets/phalconphp.jpg');
		$image->crop(200, 200)->save('unit-tests/assets/production/gd-crop.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-crop.jpg'));

		$tmp = imagecreatefromjpeg('unit-tests/assets/production/gd-crop.jpg');
		$width = imagesx($tmp);
		$height = imagesy($tmp);
		$this->assertEquals($width, 200);
		$this->assertEquals($height, 200);

		$this->assertTrue($image->getWidth() == 200);
		$this->assertTrue($image->getHeight() == 200);


		// Rotate 45 degrees clockwise
		$image->rotate(45)->save('unit-tests/assets/production/gd-rotate.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-rotate.jpg'));

		$this->assertTrue($image->getWidth() > 200);
		$this->assertTrue($image->getHeight() > 200);

		// Rotate 90% counter-clockwise
		//$image->rotate(-90);

		// Flip the image from top to bottom
		$image->flip(Phalcon\Image::HORIZONTAL)->save('unit-tests/assets/production/gd-flip.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-flip.jpg'));

		// Flip the image from left to right
		//$image->flip(Phalcon\Image::VERTICAL);

		// Sharpen the image by 20%
		$image->sharpen(20)->save('unit-tests/assets/production/gd-sharpen.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-sharpen.jpg'));

		// Create a 50 pixel reflection that fades from 0-100% opacity
		$image->reflection(50)->save('unit-tests/assets/production/gd-reflection.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-reflection.jpg'));

		// Create a 50 pixel reflection that fades from 100-0% opacity
		//$image->reflection(50, 100, TRUE)->save('reflection.jpg');

		// Create a 50 pixel reflection that fades from 0-60% opacity
		//$image->reflection(50, 60, TRUE);

		// Add a watermark to the bottom right of the image
		$mark = new Phalcon\Image\Adapter\GD('unit-tests/assets/logo.png');
		$image->watermark($mark, TRUE, TRUE)->save('unit-tests/assets/production/gd-watermark.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-watermark.jpg'));

		// Mask image
		$mask = new Phalcon\Image\Adapter\GD('unit-tests/assets/logo.png');
		$image->mask($mask)->save('unit-tests/assets/production/gd-mask.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-mask.jpg'));

		// Add a text to the bottom right of the image
		$image->text('hello', TRUE, TRUE);

		// Set font size
		// $image->text('hello', TRUE, TRUE, NULL, NULL, 12);

		// Set font
		// $image->text('hello', TRUE, TRUE, NULL, NULL, 12, /usr/share/fonts/truetype/wqy/wqy-microhei.ttc);

		// Add a text to the center of the image
		//$image->text('hello');

		// Make the image background black
		$mark->background('#000')->save('unit-tests/assets/production/gd-background.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/gd-background.jpg'));

		// Make the image background black with 50% opacity
		//$image->background('#000', 50);

		// Save the image as a PNG
		//$image->save('saved/gd.png');

		// Overwrite the original image
		//$image->save();

		// Render the image at 50% quality
		//$data = $image->render(NULL, 50);

		// Render the image as a PNG
		//$data = $image->render('png');
	}

	/**
	 * @medium
	 */
	public function testImagick()
	{
		if (!class_exists('imagick')) {
			$this->markTestSkipped("Skipped");
			return;
		}

		@unlink('unit-tests/assets/production/imagick-new.jpg');
		@unlink('unit-tests/assets/production/imagick-resize.jpg');
		@unlink('unit-tests/assets/production/imagick-liquidRescale.jpg');
		@unlink('unit-tests/assets/production/imagick-crop.jpg');
		@unlink('unit-tests/assets/production/imagick-rotate.jpg');
		@unlink('unit-tests/assets/production/imagick-flip.jpg');
		@unlink('unit-tests/assets/production/imagick-sharpen.jpg');
		@unlink('unit-tests/assets/production/imagick-reflection.jpg');
		@unlink('unit-tests/assets/production/imagick-watermark.jpg');
		@unlink('unit-tests/assets/production/imagick-mask.jpg');
		@unlink('unit-tests/assets/production/imagick-background.jpg');

		// Create new image
		$image = new Phalcon\Image\Adapter\Imagick('unit-tests/assets/production/imagick-new.jpg', 100, 100);
		$image->setResourceLimit(6, 1);
		$image->save();
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-new.jpg'));

		$image = new Phalcon\Image\Adapter\Imagick('unit-tests/assets/phalconphp.jpg');
		$image->setResourceLimit(6, 1);

		 // Resize to 200 pixels on the shortest side
		$image->resize(200, 200)->save('unit-tests/assets/production/imagick-resize.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-resize.jpg'));
		$this->assertTrue($image->getWidth() <= 200);
		$this->assertTrue($image->getHeight() <= 200);

		// Resize to 200x200 pixels, keeping aspect ratio
		//$image->resize(200, 200, Phalcon\Image::INVERSE);

		// Resize to 500 pixel width, keeping aspect ratio
		//$image->resize(500, NULL);

		// Resize to 500 pixel height, keeping aspect ratio
		//$image->resize(NULL, 500);

		// Resize to 200x500 pixels, ignoring aspect ratio
		//$image->resize(200, 500, Phalcon\Image::NONE);

		 // The images using liquid rescaling resize to 200x200
		$image->liquidRescale(200, 200)->save('unit-tests/assets/production/imagick-liquidRescale.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-liquidRescale.jpg'));
		$this->assertTrue($image->getWidth() == 200);
		$this->assertTrue($image->getHeight() == 200);

		 // The images using liquid rescaling resize to 500x500
		//$image->liquidRescale(500, 500, 3, 25);

		// Crop the image to 200x200 pixels, from the center

		$image = new Phalcon\Image\Adapter\Imagick('unit-tests/assets/phalconphp.jpg');
		$image->setResourceLimit(6, 1);
		$image->crop(200, 200)->save('unit-tests/assets/production/imagick-crop.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-crop.jpg'));

		$this->assertTrue($image->getWidth() == 200);
		$this->assertTrue($image->getHeight() == 200);

		// Rotate 45 degrees clockwise
		$image->rotate(45)->save('unit-tests/assets/production/imagick-rotate.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-rotate.jpg'));

		$this->assertTrue($image->getWidth() > 200);
		$this->assertTrue($image->getHeight() > 200);

		// Rotate 90% counter-clockwise
		//$image->rotate(-90);

		// Flip the image from top to bottom
		$image->flip(Phalcon\Image::HORIZONTAL)->save('unit-tests/assets/production/imagick-flip.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-flip.jpg'));

		// Flip the image from left to right
		//$image->flip(Phalcon\Image::VERTICAL);

		// Sharpen the image by 20%
		$image->sharpen(20)->save('unit-tests/assets/production/imagick-sharpen.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-sharpen.jpg'));

		// Create a 50 pixel reflection that fades from 0-100% opacity
		$image->reflection(50)->save('unit-tests/assets/production/imagick-reflection.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-reflection.jpg'));

		// Create a 50 pixel reflection that fades from 100-0% opacity
		//$image->reflection(50, 100, TRUE)->save('reflection.jpg');

		// Create a 50 pixel reflection that fades from 0-60% opacity
		//$image->reflection(50, 60, TRUE);

		// Add a watermark to the bottom right of the image
		$mark = new Phalcon\Image\Adapter\Imagick('unit-tests/assets/logo.png');
		$image->setResourceLimit(6, 1);
		$image->watermark($mark, TRUE, TRUE)->save('unit-tests/assets/production/imagick-watermark.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-watermark.jpg'));

		// Mask image
		$mask = new Phalcon\Image\Adapter\Imagick('unit-tests/assets/logo.png');
		$image->setResourceLimit(6, 1);
		$image->mask($mask)->save('unit-tests/assets/production/imagick-mask.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-mask.jpg'));

//		// Add a text to the bottom right of the image
//		$image->text('hello', TRUE, TRUE);

		// Set font size
		//$image->text('hello', TRUE, TRUE, NULL, NULL, 12);

		// Set font
		//$image->text('hello', TRUE, TRUE, NULL, NULL, 12, /usr/share/fonts/truetype/wqy/wqy-microhei.ttc);

		// Add a text to the center of the image
		//$image->text('hello');

		// Make the image background black
		$mark->background('#000')->save('unit-tests/assets/production/imagick-background.jpg');
		$this->assertTrue(file_exists('unit-tests/assets/production/imagick-background.jpg'));

		// Make the image background black with 50% opacity
		//$image->background('#000', 50);

		// Save the image as a PNG
		//$image->save('saved/gd.png');

		// Overwrite the original image
		//$image->save();

		// Render the image at 50% quality
		//$data = $image->render(NULL, 50);

		// Render the image as a PNG
		//$data = $image->render('png');
	}
}
