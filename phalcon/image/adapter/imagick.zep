
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

namespace Phalcon\Image\Adapter;

use Phalcon\Image\Adapter;
use Phalcon\Image\AdapterInterface;
use Phalcon\Image\Exception;

/**
 * Phalcon\Image\Adapter\Imagick
 *
 * Image manipulation support. Allows images to be resized, cropped, etc.
 *
 *<code>
 * $image = new Phalcon\Image\Adapter\Imagick("upload/test.jpg");
 * $image->resize(200, 200)->rotate(90)->crop(100, 100);
 * if ($image->save()) {
 *     echo 'success';
 * }
 *</code>
 */
class Imagick extends Adapter implements AdapterInterface
{
	protected static _version = 0;
	protected static _checked = false;

	/**
	 * Checks if Imagick is enabled
	 */
	public static function check() -> boolean
	{
		if self::_checked {
			return true;
		}

		if !class_exists("imagick") {
			throw new Exception("Imagick is not installed, or the extension is not loaded");
		}

		if defined("Imagick::IMAGICK_EXTNUM") {
			let self::_version = constant("Imagick::IMAGICK_EXTNUM");
		}

		let self::_checked = true;

		return self::_checked;
	}

	/**
	 * \Phalcon\Image\Adapter\Imagick constructor
	 */
	public function __construct(string! file, int width = null, int height = null)
	{
		var image;

		if !self::_checked {
			self::check();
		}

		let this->_file = file;

		let this->_image = new \Imagick();

		if file_exists(this->_file) {
			let this->_realpath = realpath(this->_file);

			if !this->_image->readImage(this->_realpath) {
				 throw new Exception("Imagick::readImage ".this->_file." failed");
			}

			if !this->_image->getImageAlphaChannel() {
				this->_image->setImageAlphaChannel(constant("Imagick::ALPHACHANNEL_SET"));
			}

			if this->_type == 1 {
				let image = this->_image->coalesceImages();
				this->_image->clear();
				this->_image->destroy();

				let this->_image = image;
			}
		} else {
			if !width || !height {
				throw new Exception("Failed to create image from file " . this->_file);
			}

			this->_image->newImage(width, height, new \ImagickPixel("transparent"));
			this->_image->setFormat("png");
			this->_image->setImageFormat("png");

			let this->_realpath = this->_file;
		}

		let this->_width = this->_image->getImageWidth();
		let this->_height = this->_image->getImageHeight();
		let this->_type = this->_image->getImageType();
		let this->_mime = "image/".this->_image->getImageFormat();
	}

	/**
	 * Execute a resize.
	 */
	protected function _resize(int width, int height)
	{
		this->_image->setIteratorIndex(0);

		loop {
			this->_image->scaleImage(width, height);
			if this->_image->nextImage() === false {
				break;
			}
		}

		let this->_width = this->_image->getImageWidth();
		let this->_height = this->_image->getImageHeight();
	}

	/**
	 * This method scales the images using liquid rescaling method. Only support Imagick
	 *
	 * @param int $width   new width
	 * @param int $height  new height
	 * @param int $deltaX How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight.
	 * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.
	 */
	protected function _liquidRescale(int width, int height, int deltaX, int rigidity)
	{
		var ret;
		this->_image->setIteratorIndex(0);

		loop {
			let ret = this->_image->liquidRescaleImage(width, height, deltaX, rigidity);
			if ret !== true {
				throw new Exception("Imagick::liquidRescale failed");
			}

			if this->_image->nextImage() === false {
				break;
			}
		}

		let this->_width = this->_image->getImageWidth();
		let this->_height = this->_image->getImageHeight();
	}

	/**
	 * Execute a crop.
	 */
	protected function _crop(int width, int height, int offsetX, int offsetY)
	{
		var image;

		let image = this->_image;

		image->setIteratorIndex(0);

		loop {

			image->cropImage(width, height, offsetX, offsetY);
			image->setImagePage(width, height, 0, 0);

			if !image->nextImage() {
				break;
			}
		}

		let this->_width  = image->getImageWidth();
		let this->_height = image->getImageHeight();
	}

	/**
	 * Execute a rotation.
	 */
	protected function _rotate(int degrees)
	{
		var pixel;

		this->_image->setIteratorIndex(0);

		let pixel = new \ImagickPixel();

		loop {
			this->_image->rotateImage(pixel, degrees);
			this->_image->setImagePage(this->_width, this->_height, 0, 0);
			if this->_image->nextImage() === false {
				break;
			}
		}

		let this->_width = this->_image->getImageWidth();
		let this->_height = this->_image->getImageHeight();
	}

	/**
	 * Execute a flip.
	 */
	protected function _flip(int direction)
	{
		var func;

		let func = "flipImage";
		if direction == \Phalcon\Image::HORIZONTAL {
		   let func = "flopImage";
		}

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->{func}();
			if this->_image->nextImage() === false {
				break;
			}
		}
	}

	/**
	 * Execute a sharpen.
	 */
	protected function _sharpen(int amount)
	{
		let amount = (amount < 5) ? 5 : amount;
		let amount = (amount * 3.0) / 100;

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->sharpenImage(0, amount);
			if this->_image->nextImage() === false {
				break;
			}
		}
	}

	/**
	 * Execute a reflection.
	 */
	protected function _reflection(int height, int opacity, boolean fadeIn)
	{
		var reflection, fade, pseudo, image, pixel, ret;

		if self::_version >= 30100 {
			let reflection = clone this->_image;
		} else {
			let reflection = clone this->_image->$clone();
		}

		reflection->setIteratorIndex(0);

		loop {
			reflection->flipImage();
			reflection->cropImage(reflection->getImageWidth(), height, 0, 0);
			reflection->setImagePage(reflection->getImageWidth(), height, 0, 0);
			if reflection->nextImage() === false {
				break;
			}
		}

		let pseudo = fadeIn ? "gradient:black-transparent" : "gradient:transparent-black",
			fade = new \Imagick();

		fade->newPseudoImage(reflection->getImageWidth(), reflection->getImageHeight(), pseudo);

		let opacity /= 100;

		reflection->setIteratorIndex(0);

		loop {
			let ret = reflection->compositeImage(fade, constant("Imagick::COMPOSITE_DSTOUT"), 0, 0);
			if ret !== true {
				throw new Exception("Imagick::compositeImage failed");
			}

			reflection->evaluateImage(constant("Imagick::EVALUATE_MULTIPLY"), opacity, constant("Imagick::CHANNEL_ALPHA"));
			if reflection->nextImage() === false {
				break;
			}
		}

		fade->destroy();

		let image = new \Imagick(),
			pixel = new \ImagickPixel(),
			height = this->_image->getImageHeight() + height;

		this->_image->setIteratorIndex(0);

		loop {
			image->newImage(this->_width, height, pixel);
			image->setImageAlphaChannel(constant("Imagick::ALPHACHANNEL_SET"));
			image->setColorspace(this->_image->getColorspace());
			image->setImageDelay(this->_image->getImageDelay());
			let ret = image->compositeImage(this->_image, constant("Imagick::COMPOSITE_SRC"), 0, 0);

			if ret !== true {
				throw new Exception("Imagick::compositeImage failed");
			}

			if this->_image->nextImage() === false {
				break;
			}
		}

		image->setIteratorIndex(0);
		reflection->setIteratorIndex(0);

		loop {
			let ret = image->compositeImage(reflection, constant("Imagick::COMPOSITE_OVER"), 0, this->_height);

			if ret !== true {
				throw new Exception("Imagick::compositeImage failed");
			}

			if image->nextImage() === false || reflection->nextImage() === false {
				break;
			}
		}

		reflection->destroy();

		this->_image->clear();
		this->_image->destroy();

		let this->_image = image;
		let this->_width = this->_image->getImageWidth();
		let this->_height = this->_image->getImageHeight();
	}

	/**
	 * Execute a watermarking.
	 */
	protected function _watermark(<Adapter> image, int offsetX, int offsetY, int opacity)
	{
		var watermark, ret;

		let opacity = opacity / 100,
			watermark = new \Imagick();

		watermark->readImageBlob(image->render());
		watermark->setImageOpacity(opacity);

		this->_image->setIteratorIndex(0);

		loop {
			let ret = this->_image->compositeImage(watermark, constant("Imagick::COMPOSITE_OVER"), offsetX, offsetY);

			if ret !== true {
				throw new Exception("Imagick::compositeImage failed");
			}

			if this->_image->nextImage() === false {
				break;
			}
		}

		watermark->clear();
		watermark->destroy();
	}

	/**
	 * Execute a text
	 */
	protected function _text(string text, int offsetX, int offsetY, int opacity, int r, int g, int b, int size, string fontfile)
	{
		var draw, color, pixel, gravity;

		let opacity = opacity / 100;

		let draw = new \ImagickDraw();

		let color = sprintf("rgb(%d, %d, %d)", r, g, b);
		let pixel = new \ImagickPixel(color);

		draw->setFillColor(pixel);

		if fontfile {
			draw->setFont(fontfile);
		}

		if size {
			draw->setFontSize(size);
		}

		if opacity {
			draw->setfillopacity(opacity);
		}

		if offsetX < 0 {
			let offsetX = abs(offsetX);
			if offsetY < 0 {
				let offsetY = abs(offsetY);
				let gravity = constant("Imagick::GRAVITY_SOUTHEAST");
			} else {
				let gravity = constant("Imagick::GRAVITY_NORTHEAST");
			}
		} else {
			/*if y < 0 { where y comes from??
				let offsetY = abs(offsetY);
				let gravity = constant("Imagick::GRAVITY_SOUTHWEST");
			} else {
				let gravity = constant("Imagick::GRAVITY_NORTHWEST");
			}*/
		}

		draw->setGravity(gravity);

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->annotateImage(draw, offsetX, offsetY, 0, text);
			if this->_image->nextImage() === false {
				break;
			}
		}
		draw->destroy();
	}

	/**
	 * Composite one image onto another
	 *
	 * @param Adapter $mask mask Image instance
	 */
	protected function _mask(<Adapter> image)
	{
		var mask, ret;

		let mask = new \Imagick();

		mask->readImageBlob(image->render());
		this->_image->setIteratorIndex(0);

		loop {
			this->_image->setImageMatte(1);
			let ret = this->_image->compositeImage(mask, constant("Imagick::COMPOSITE_DSTIN"), 0, 0);

			if ret !== true {
				throw new Exception("Imagick::compositeImage failed");
			}

			if this->_image->nextImage() === false {
				break;
			}
		}

		mask->clear();
		mask->destroy();
	}

	/**
	 * Execute a background.
	 */
	protected function _background(int r, int g, int b, int opacity)
	{
		var background, color, pixel1, pixel2, ret;

		let color = sprintf("rgb(%d, %d, %d)", r, g, b);
		let pixel1 = new \ImagickPixel(color);
		let opacity = opacity / 100;

		let pixel2 = new \ImagickPixel("transparent");

		let background = new \Imagick();
		this->_image->setIteratorIndex(0);

		loop {
			background->newImage(this->_width, this->_height, pixel1);
			if !background->getImageAlphaChannel() {
				background->setImageAlphaChannel(constant("Imagick::ALPHACHANNEL_SET"));
			}
			background->setImageBackgroundColor(pixel2);
			background->evaluateImage(constant("Imagick::EVALUATE_MULTIPLY"), opacity, constant("Imagick::CHANNEL_ALPHA"));
			background->setColorspace(this->_image->getColorspace());
			let ret = background->compositeImage(this->_image, constant("Imagick::COMPOSITE_DISSOLVE"), 0, 0);

			if ret !== true {
				throw new Exception("Imagick::compositeImage failed");
			}

			if this->_image->nextImage() === false {
				break;
			}
		}

		this->_image->clear();
		this->_image->destroy();

		let this->_image = background;
	}

	/**
	 * Blur image
	 *
	 * @param int $radius Blur radius
	 */
	protected function _blur(int radius)
	{
		this->_image->setIteratorIndex(0);

		loop {
			this->_image->blurImage(radius, 100);
			if this->_image->nextImage() === false {
				break;
			}
		}
	}

	/**
	 * Pixelate image
	 *
	 * @param int $amount amount to pixelate
	 */
	protected function _pixelate(int amount)
	{
		int width, height;

		let width = this->_width / amount;
		let height = this->_height / amount;

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->scaleImage(width, height);
			this->_image->scaleImage(this->_width, this->_height);
			if this->_image->nextImage() === false{
				break;
			}
		}
	}

	/**
	 * Execute a save.
	 */
	protected function _save(string file, int quality)
	{
		var ext, fp;

		let ext = pathinfo(file, PATHINFO_EXTENSION);

		this->_image->setFormat(ext);
		this->_image->setImageFormat(ext);

		let this->_type = this->_image->getImageType();
		let this->_mime = "image/" . this->_image->getImageFormat();

		if strcasecmp(ext, "gif") == 0 {
			this->_image->optimizeImageLayers();
			let fp= fopen(file, "w");
			this->_image->writeImagesFile(fp);
			fclose(fp);
			return;
		} else {
			if strcasecmp(ext, "jpg") == 0 || strcasecmp(ext, "jpeg") == 0 {
				this->_image->setImageCompression(constant("Imagick::COMPRESSION_JPEG"));
			}
			this->_image->setImageCompressionQuality(quality);
			this->_image->writeImage(file);
		}
	}

	/**
	 * Execute a render.
	 */
	protected function _render(string extension, int quality) -> string
	{
		var image;

		let image = this->_image;

		image->setFormat(extension);
		image->setImageFormat(extension);
		image->stripImage();

		let this->_type = image->getImageType(),
			this->_mime = "image/" . image->getImageFormat();

		if strcasecmp(extension, "gif") === 0 {
			image->optimizeImageLayers();
		} else {
			if strcasecmp(extension, "jpg") === 0 || strcasecmp(extension, "jpeg") === 0 {
				image->setImageCompression(constant("Imagick::COMPRESSION_JPEG"));
			}
			image->setImageCompressionQuality(quality);
		}

		return image->getImageBlob();
	}

	/**
	 * Destroys the loaded image to free up resources.
	 */
	public function __destruct()
	{
		if this->_image instanceof \Imagick {
			this->_image->clear();
			this->_image->destroy();
		}
	}

	/**
	 * Get instance
	 */
	public function getInternalImInstance() -> <\Imagick>
	{
		return this->_image;
	}

	/**
	 * Sets the limit for a particular resource in megabytes
	 * @param int type Refer to the list of resourcetype constants (@see http://php.net/manual/ru/imagick.constants.php#imagick.constants.resourcetypes.)
	 * @param int limit The resource limit. The unit depends on the type of the resource being limited.
	 */
	public function setResourceLimit(int type, int limit)
	{
		this->_image->setResourceLimit(type, limit);
	}

}
