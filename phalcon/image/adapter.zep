
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

namespace Phalcon\Image;

class Adapter {

	protected _image;
	protected _file;
	protected _realpath;
	protected _width;
	protected _height;
	protected _type;
	protected _mime;
	protected static _checked = false;

	/**
	 * Returns the image of images
	 *
	 * @return string
	 */
	public function getImage()
	{
		return this->_image;
	}

	/**
	 * Returns the real path of the image file
	 *
	 * @return string
	 */
	public function getRealPath()
	{
		return this->_realpath;
	}

	/**
	 * Returns the width of images
	 *
	 * @return int
	 */
	public function getWidth()
	{
		return this->_width;
	}

	/**
	 * Returns the height of images
	 *
	 * @return int
	 */
	public function getHeight()
	{
		return this->_height;
	}

	/**
	 * Returns the type of images
	 *
	 * @return int
	 */
	public function getType()
	{
		return this->_type;
	}

	/**
	 * Returns the mime of images
	 *
	 * @return string
	 */
	public function getMime()
	{
		return this->_mime;
	}

	/**
 	 * Resize the image to the given size
	 * 
	 * @param int width
	 * @param int height
	 * @param int master
 	 * @return Phalcon\Image\Adapter
 	 */
	public function resize(int width = null, int height = null, int master = Image::AUTO) -> <Phalcon\Image\Adapter>
	{
		var ratio;

		if master == Image::TENSILE {
			if !width || !height {
				throw new Phalcon\Image\Exception("width and height must be specified");
			}
		} else {
			if master == Image::AUTO {
				if !width || !height {
					throw new Phalcon\Image\Exception("width and height must be specified");
				}

				let master = (this->_width / width) > (this->_height / height) ? Image::WIDTH : Image::HEIGHT;
			}
			if master == Image::INVERSE {
				if !width || !height {
					throw new Phalcon\Image\Exception("width and height must be specified");
				}

				let master = (this->_width / width) > (this->_height / height) ? Image::HEIGHT : Image::WIDTH;
			}
			switch master {
			
				case Image::WIDTH:
					if !width { 
						throw new Phalcon\Image\Exception("width must be specified");
					}
					let height = this->_height * width / this->_width;
					break;

				case Image::HEIGHT:			
					if !height { 
						throw new Phalcon\Image\Exception("height must be specified");
					}
					let width = this->_width * height / this->_height;
					break;

				case Image::PRECISE:
					if !width || !height {
						throw new Phalcon\Image\Exception("width and height must be specified");
					}

					let ratio = this->_width / this->_height;

					if (width / height) > ratio {
						let height = this->_height * width / this->_width;
					} else {
						let width = this->_width * height / this->_height;
					}
					break;

				case Image::NONE:
						if !width {
							let width = this->_width;
						}

						if !height {
							let width = this->_height;
						}
					break;
			}
		}

		let width  = max(round(width), 1);
		let height = max(round(height), 1);

		this->_resize(width, height);

		return this;
	}

	/**
 	 * Crop an image to the given size
 	 *
 	 * @param int width
 	 * @param int height
 	 * @param int offset_x
 	 * @param int offset_y
 	 * @return Phalcon\Image\Adapter
 	 */
	public function crop(int width, int height, int offset_x = null, int offset_y = null) -> <Phalcon\Image\Adapter>
	{
		if !offset_x {
			let offset_x = ((this->_width - width) / 2);
		} else {
			if offset_x < 0 {
				let offset_x = this->_width - width + offset_x;
			}

			if offset_x > this->_width {
				let offset_x = this->_width;
			}
		}

		if !offset_y {
			let offset_y = ((this->_height - height) / 2);
		} else {
			if offset_y < 0 {
				let offset_y = this->_height - height + offset_y;
			}

			if offset_y > this->_height {
				let offset_y = this->_height;
			}
		}

		if width > (this->_width - offset_x) {
			let width = this->_width - offset_x;
		}

		if height > (this->_height - offset_y) {
			let height = this->_height - offset_y;
		}

		this->_crop(width, height);

		return this;
	}

	/**
 	 * Rotate the image by a given amount
 	 *
 	 * @param int degrees
 	 * @return Phalcon\Image\Adapter
 	 */
	public function rotate(int degrees) -> <Phalcon\Image\Adapter>
	{
		if degrees > 180 {
			let degrees %= 360;
			if degrees > 180 {
				let degrees -= 360;
			}
		} else {
			while degrees < -180 {
				let degrees += 360;
			}
		}

		this->_rotate(degrees);

		return this;
	}

	/**
 	 * Flip the image along the horizontal or vertical axis
 	 *
 	 * @param int direction
 	 * @return Phalcon\Image\Adapter
 	 */
	public function flip(int direction) -> <Phalcon\Image\Adapter>
	{
		if direction != Image::HORIZONTAL && direction != Image::VERTICAL {
			let direction = Image::HORIZONTAL;
		}

		this->_flip(direction);

		return this;
	}

	/**
 	 * Sharpen the image by a given amount
 	 *
 	 * @param int amount
 	 * @return Phalcon\Image\Adapter
 	 */
	public function sharpen(int amount) -> <Phalcon\Image\Adapter>
	{
		if amount > 100 {
			let amount = 100;
		} else {
			if amount < 1 {
				let amount = 1;
			}
		}

		this->_sharpen(amount);

		return this;
	}

	/**
 	 * Add a reflection to an image
 	 *
 	 * @param int height
 	 * @param int opacity
 	 * @param boolean fade_in
 	 * @return Phalcon\Image\Adapter
 	 */
	public function reflection(int height, int opacity = 100, boolean fade_in = false) -> <Phalcon\Image\Adapter>
	{
		if height <= 0 || height > this->_height {
			let height = this->_height;
		}

		if opacity < 0 {
			let opacity = 0;
		} else {
			if opacity > 100 {
				let opacity = 100;
			}
		}

		this->_reflection(height, opacity, fade_in);

		return this;
	}

	/**
 	 * Add a watermark to an image with a specified opacity
 	 *
 	 * @param Phalcon\Image\Adapter watermark
 	 * @param int offset_x
 	 * @param int offset_y
 	 * @param int opacity
 	 * @return Phalcon\Image\Adapter
 	 */
	public function watermark(<Phalcon\Image\Adapter> watermark, int offset_x = 0, int offset_y = 0, int opacity = 100) -> <Phalcon\Image\Adapter>
	{
		int tmp;
		let tmp = this->_width - watermark->getWidth();

		if offset_x < 0 {			
			let offset_x = 0;
		} else {
			if offset_x > tmp {
				let offset_x = tmp;
			}
		}
		
		let tmp = this->_height - watermark->getHeight();

		if offset_y < 0 {			
			let offset_y = 0;
		} else {
			if offset_y > tmp {
				let offset_y = tmp;
			}
		}

		if opacity < 0 {			
			let opacity = 0;
		} else {
			if opacity > 100 {
				let opacity = 100;
			}
		}

		this->_watermark(watermark, offset_x, offset_y, opacity);

		return this;
	}

	/**
 	 * Add a text to an image with a specified opacity
 	 *
 	 * @param string text
 	 * @param int offset_x
 	 * @param int offset_y
 	 * @param int opacity
 	 * @param string color
 	 * @param int size
 	 * @param string fontfile
 	 * @return Phalcon\Image\Adapter
 	 */
	public function text(string text, int offset_x = 0, int offset_y = 0, int opacity = 100, string color = "000000", int size = 12, string fontfile = null) -> <Phalcon\Image\Adapter>
	{
		if opacity < 0 {			
			let opacity = 0;
		} else {
			if opacity > 100 {
				let opacity = 100;
			}
		}

		if strlen(color) > 1 && color[0] === '#') {
			let color = substr(color, 1);
		}

		if strlen(color) == 3) {
			let color = preg_replace('/./', '$0$0', color);
		}

		this->_text(text, offset_x, offset_y, opacity, color, size, fontfile);

		return this;
	}

	/**
 	 * Composite one image onto another
 	 *
 	 * @param Phalcon\Image\Adapter watermark
 	 * @return Phalcon\Image\Adapter
 	 */
	public function mask(<Phalcon\Image\Adapter> watermark) -> <Phalcon\Image\Adapter>
	{
		this->_mask(watermark);
		return this;
	}

	/**
 	 * Set the background color of an image
 	 *
 	 * @param string color
 	 * @param int opacity
 	 * @return Phalcon\Image\Adapter
 	 */
	public function background(string color, int opacity = 100) -> <Phalcon\Image\Adapter>
	{
		if strlen(color) > 1 && color[0] === '#') {
			let color = substr(color, 1);
		}

		if strlen(color) == 3) {
			let color = preg_replace('/./', '$0$0', color);
		}

		this->_background(color, opacity);
		return this;
	}

	/**
 	 * Blur image
 	 *
 	 * @param int radius
 	 * @return Phalcon\Image\Adapter
 	 */
	public function blur(int radius) -> <Phalcon\Image\Adapter>
	{
		if radius < 1 {
			let radius = 1;
		} else {
			if radius > 100 {
				let radius = 100;
			}
		}

		this->_blur(radius);
		return this;
	}

	/**
 	 * Pixelate image
 	 *
 	 * @param int amount
 	 * @return Phalcon\Image\Adapter
 	 */
	public function pixelate(int amount) -> <Phalcon\Image\Adapter>
	{
		if amount < 2 {
			let amount = 2;
		}

		this->_pixelate(amount);
		return this;
	}

	/**
 	 * Save the image
 	 *
	 * @param string file
	 * @param int quality
 	 * @return Phalcon\Image\Adapter
 	 */
	public function save(string file = null, int quality = 100) -> <Phalcon\Image\Adapter>
	{
		if !file {
			let file = this->_realpath;
		}

		if quality < 1 {
			let quality = 1;
		} else {
			if quality > 100 {
				let quality = 100;
			}
		}

		this->_save(file, quality);
		return this;
	}

	/**
 	 * Render the image and return the binary string
 	 *
	 * @param string ext
	 * @param int quality
 	 * @return Phalcon\Image\Adapter
 	 */
	public function render(string ext = null, int quality = 100) -> <Phalcon\Image\Adapter>
	{
		if !ext {
			let ext = pathinfo(this->_file, PATHINFO_EXTENSION);
		}

		if empty(ext) {
			let ext = "png";
		}

		if quality < 1 {
			let quality = 1;
		} else {
			if quality > 100 {
				let quality = 100;
			}
		}

		this->_render(ext, quality);
		return this;
	}

}