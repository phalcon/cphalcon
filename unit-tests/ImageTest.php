<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

	public function testGD()
	{
		if (!function_exists('gd_info')) {
			return;
		}

		@unlink('unit-tests/assets/new.jpg');
		@unlink('unit-tests/assets/gd-resize.jpg');
		@unlink('unit-tests/assets/gd-crop.jpg');
		@unlink('unit-tests/assets/gd-rotate.jpg');
		@unlink('unit-tests/assets/gd-flip.jpg');
		@unlink('unit-tests/assets/gd-sharpen.jpg');
		@unlink('unit-tests/assets/gd-reflection.jpg');
		@unlink('unit-tests/assets/gd-watermark.jpg');
		@unlink('unit-tests/assets/gd-background.jpg');

		try {
			$image = new Phalcon\Image\Adapter\GD('unit-tests/assets/new.jpg', 100, 100);
			$image->save();
			$this->assertTrue(file_exists('unit-tests/assets/production/new.jpg'));

			$image = new Phalcon\Image\Adapter\GD('unit-tests/assets/phalconphp.jpg');

			 // Resize to 200 pixels on the shortest side
			$image->resize(200, 200)->save('unit-tests/assets/production/gd-resize.jpg');
			$this->assertTrue(file_exists('unit-tests/assets/production/gd-resize.jpg'));

			// Resize to 200x200 pixels, keeping aspect ratio
			//$image->resize(200, 200, Phalcon\Image::INVERSE);

			// Resize to 500 pixel width, keeping aspect ratio
			//$image->resize(500, NULL);

			// Resize to 500 pixel height, keeping aspect ratio
			//$image->resize(NULL, 500);

			// Resize to 200x500 pixels, ignoring aspect ratio
			//$image->resize(200, 500, Phalcon\Image::NONE);

			// Crop the image to 200x200 pixels, from the center
			$image->crop(200, 200)->save('unit-tests/assets/production/gd-crop.jpg');
			$this->assertTrue(file_exists('unit-tests/assets/production/gd-crop.jpg'));


			// Rotate 45 degrees clockwise
			$image->rotate(45)->save('unit-tests/assets/production/gd-rotate.jpg');
			$this->assertTrue(file_exists('unit-tests/assets/production/gd-rotate.jpg'));

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
		} catch (Exception $e) {
		}
	}

	public function testImagick()
	{
		if (!class_exists('imagick')) {
			return;
		}

		@unlink('unit-tests/assets/production/new.jpg');
		@unlink('unit-tests/assets/production/imagick-resize.jpg');
		@unlink('unit-tests/assets/production/imagick-liquidRescale.jpg');
		@unlink('unit-tests/assets/production/imagick-crop.jpg');
		@unlink('unit-tests/assets/production/imagick-rotate.jpg');
		@unlink('unit-tests/assets/production/imagick-flip.jpg');
		@unlink('unit-tests/assets/production/imagick-sharpen.jpg');
		@unlink('unit-tests/assets/production/imagick-reflection.jpg');
		@unlink('unit-tests/assets/production/imagick-watermark.jpg');
		@unlink('unit-tests/assets/production/imagick-background.jpg');

		try {
			$image = new Phalcon\Image\Adapter\Imagick('unit-tests/assets/new.jpg', 100, 100);
			$image->save();
			$this->assertTrue(file_exists('unit-tests/assets/production/new.jpg'));

			$image = new Phalcon\Image\Adapter\Imagick('unit-tests/assets/phalconphp.jpg');

			 // Resize to 200 pixels on the shortest side
			$image->resize(200, 200)->save('unit-tests/assets/production/imagick-resize.jpg');
			$this->assertTrue(file_exists('unit-tests/assets/production/imagick-resize.jpg'));

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

			 // The images using liquid rescaling resize to 500x500
			//$image->liquidRescale(500, 500, 3, 25);

			// Crop the image to 200x200 pixels, from the center
			$image->crop(200, 200)->save('unit-tests/assets/production/imagick-crop.jpg');
			$this->assertTrue(file_exists('unit-tests/assets/production/imagick-crop.jpg'));


			// Rotate 45 degrees clockwise
			$image->rotate(45)->save('unit-tests/assets/production/imagick-rotate.jpg');
			$this->assertTrue(file_exists('unit-tests/assets/production/imagick-rotate.jpg'));

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
			$image->watermark($mark, TRUE, TRUE)->save('unit-tests/assets/production/imagick-watermark.jpg');
			$this->assertTrue(file_exists('unit-tests/assets/production/imagick-watermark.jpg'));

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
		} catch (Exception $e) {
		}
	}
}