
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
 	 * @return Phalcon\Image\Adapter
 	 */
	public function resize(int width, int height, int master = Image::AUTO) -> <Phalcon\Image\Adapter>
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
			} else if master == Image::INVERSE {
				if !width || !height {
					throw new Phalcon\Image\Exception("width and height must be specified");
				}

				let master = (this->_width / width) > (this->_height / height) ? Image::HEIGHT : Image::WIDTH;
			}

			if master == Image::WIDTH {
				if !width { 
					throw new Phalcon\Image\Exception("width must be specified");
				}
				height = this->_height * width / this->_width;
			} else if master == Image::HEIGHT {				
				if !height { 
					throw new Phalcon\Image\Exception("height must be specified");
				}
				width = this->_width * height / this->_height;
			} else if master == Image::PRECISE {
				if !width || !height {
					throw new Phalcon\Image\Exception("width and height must be specified");
				}

				let ratio = this->_width / this->_height;

				if (width / height) > ratio {
					height = this->_height * width / this->_width;
				} else {
					width = this->_width * height / this->_height;
				}
			} else if master == Image::NONE {
				if !width {
					let width = this->_width;
				}

				if !height {
					let width = this->_height;
				}
			}
		}

		width  = max(round(width), 1);
		height = max(round(height), 1);

		this->_resize(width, height);

		return this;
	}

}