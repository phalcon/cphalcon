
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

namespace Phalcon\Image\Adapter;

class Imagick extends Phalcon\Logger\Adapter implements Phalcon\Image\AdapterInterface
{
	protected int _version = 0;

	public static function check()
	{
		if (self::_checked) {
			return true;
		}

		if !class_exists("imagick") {
			throw new \Phalcon\Image\Exception("Imagick is not installed, or the extension is not loaded");
			return;
		}

		if defined("Imagick::IMAGICK_EXTNUM") {
			let this->_version = Imagick::IMAGICK_EXTNUM;
		}

		let self::_checked = true;

		return self::_checked;
	}

	public function __construct(string! file, int width = null, int height = null)
	{
		var image;

		if !self::_checked {
			self::check();
		}

		let this->_file = file;

		let this->_image = new Imagick();

		if file_exists(this->_file) {
			let this->_realpath = realpath(this->_file);

			if !this->_image->readImage(this->_realpath) {
				 throw new \Phalcon\Image\Exception("Imagick::readImage ".this->_file." failed");
				 return;
			}

			if !this->_image->getImageAlphaChannel() {
				this->_image->setImageAlphaChannel(Imagick::ALPHACHANNEL_SET);
			}
			
			if this->_type == 1 {
				let image = this->_image->coalesceImages();
				this->_image->clear();
				this->_image->destroy();

				let this->_image = image;
			}
		} else {
			if !width || !height {
				throw new \Phalcon\Image\Exception("Failed to create image from file " . this->_file);
			}

			this->_image->newImage(width, height, new ImagickPixel("transparent"));
			this->_image->setFormat("png");
			this->_image->setImageFormat("png");

			let this->_realpath = this->_file;
		}


		let this->_width = this->_image->getImageWidth();
		let this->_height = this->_image->getImageHeight();
		let this->_type = this->_image->getImageType();
		let this->_mime = "image/".this->_image->getImageFormat();
	}

	protected function _resize(int width, int height)
	{
		this->_image->setIteratorIndex(0);

		loop {
			this->_image->scaleImage(width, height);
			if  !this->_image->nextImage() {
				break;
			}
		}

		let this->_width = this->_image->getImageWidth();
		let this->_height = this->_image->getImageHeight();
	}

	protected function _crop(int width, int height, int offset_x, int offset_y)
	{
		this->_image->setIteratorIndex(0);

		loop {
			this->_image->cropImage(width, height, offset_x, offset_y);
			this->_image->setImagePage(width, height, 0, 0);
			if  !this->_image->nextImage() {
				break;
			}
		}

		let this->_width = this->_image->getImageWidth();
		let this->_height = this->_image->getImageHeight();
	}

	protected function _rotate(int degrees)
	{
		var pixel;

		this->_image->setIteratorIndex(0);

		let pixel = new ImagickPixel();

		loop {
			this->_image->rotateImage(pixel, degrees);
			this->_image->setImagePage(this->_width, this->_height, 0, 0);
			if  !this->_image->nextImage() {
				break;
			}
		}

		let this->_width = this->_image->getImageWidth();
		let this->_height = this->_image->getImageHeight();
	}

	protected function _flip(int direction)
	{
		var func;

		let func = "flipImage";
		if direction === Image::HORIZONTAL {
		   let func = "flopImage";
		}

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->{func}();
			if  !this->_image->nextImage() {
				break;
			}
		}
	}

	protected function _sharpen(int amount)
	{
		let amount = (amount < 5) ? 5 : amount;
		let amount = (amount * 3.0) / 100;

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->sharpenImage(0, amount);
			if  !this->_image->nextImage() {
				break;
			}
		}
	}

	protected function _reflection(int height, int opacity, boolean fade_in)
	{
		var reflection, fade, pseudo, image, pixel;

		if this->_version >= 30100 {
			let reflection = clone this->_image;
		}
		else {
			let reflection = clone this->_image->clone();
		}

		reflection->setIteratorIndex(0);

		loop {
			reflection->flipImage();
			reflection->cropImage(reflection->getImageWidth(), height, 0, 0);
			reflection->setImagePage(reflection->getImageWidth(), height, 0, 0);
			if  !reflection->nextImage() {
				break;
			}
		}

		let pseudo = fade_in ? "gradient:black-transparent" : "gradient:transparent-black";

		let fade = new Imagick();

		fade->newPseudoImage(reflection->getImageWidth(), reflection->getImageHeight(), pseudo);

		let opacity /= 100;

		reflection->setIteratorIndex(0);

		loop {
			reflection->compositeImage(fade, Imagick::COMPOSITE_DSTOUT, 0, 0);
			reflection->evaluateImage(Imagick::EVALUATE_MULTIPLY, opacity / 100, Imagick::CHANNEL_ALPHA);
			if  !reflection->nextImage() {
				break;
			}
		}
		
		fade->destroy();

		let image = new Imagick();
		let pixel = new ImagickPixel();
		let height = this->_image->getImageHeight() + height;

		this->_image->setIteratorIndex(0);

		loop {
			image->newImage(this->_width, height, pixel);
			image->setImageAlphaChannel(Imagick::ALPHACHANNEL_SET);
			image->setColorspace(this->_image->getColorspace());
			image->setImageDelay(this->_image->getImageDelay());
			image->compositeImage(this->_image, Imagick::COMPOSITE_SRC, 0, 0);

			if  !this->_image->nextImage() {
				break;
			}
		}

		image->setIteratorIndex(0);
		reflection->setIteratorIndex(0);

		loop {
			image->compositeImage(reflection, Imagick::COMPOSITE_OVER, 0, this->_height);
			image->setImageAlphaChannel(Imagick::ALPHACHANNEL_SET);
			image->setColorspace(this->_image->getColorspace());
			image->setImageDelay(this->_image->getImageDelay());
			image->compositeImage(this->_image, Imagick::COMPOSITE_SRC, 0, 0);

			if  !image->nextImage() || !reflection->nextImage() {
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

	protected function _watermark(<Phalcon\Image\Adapter> image, int offset_x, int offset_y, int opacity)
	{
		var watermark;

		let opacity = opacity / 100;

		let watermark = new Imagick();
		
		watermark->readImageBlob(image->render());
		watermark->setImageOpacity(opacity);

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->compositeImage(watermark, Imagick::COMPOSITE_OVER, offset_x, offset_y);
			if  !this->_image->nextImage() {
				break;
			}
		}

		watermark->clear();
		watermark->destroy();
	}

	protected function _text(string text, int offset_x, int offset_y, int opacity, int r, int g, int b, int size, string fontfile)
	{
		var draw, color, pixel, gravity;

		let opacity = opacity / 100;

		let draw = new ImagickDraw();

		let color = sprintf("rgb(%d, %d, %d)", r, g, b);		
		let pixel = new ImagickPixel(color);

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

		if (offset_x < 0) {
			let offset_x = abs(offset_x);
			if (offset_y < 0) {
				let offset_y = abs(offset_y);
				let gravity = Imagick::GRAVITY_SOUTHEAST;
			} else {		
				let gravity = Imagick::GRAVITY_NORTHEAST;
			}
		} else {
			if (y < 0) {
				let offset_y = abs(offset_y);
				let gravity = Imagick::GRAVITY_SOUTHWEST;
			} else {
				let gravity = Imagick::GRAVITY_NORTHWEST;
			}
		}

		draw->setGravity(gravity);

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->annotateImage(draw, offset_x, offset_y, 0, text);
			if  !this->_image->nextImage() {
				break;
			}
		}
		draw->destroy();
	}

	protected function _mask(<Phalcon\Image\Adapter> image)
	{
		var mask;

		let opacity = opacity / 100;

		let mask = new Imagick();
		
		mask->readImageBlob(image->render());

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->setImageMatte(1);
			this->_image->compositeImage(mask, Imagick::COMPOSITE_DSTIN, 0, 0);
			if  !this->_image->nextImage() {
				break;
			}
		}

		mask->clear();
		mask->destroy();
	}

	protected function _background(int r, int g, int b, int opacity)
	{
		var background, color, pixel1, pixel2;

		let color = sprintf("rgb(%d, %d, %d)", r, g, b);		
		let pixel1 = new ImagickPixel(color);
		let opacity = opacity / 100;

		let pixel2 = new ImagickPixel("transparent");

		let background = new Imagick();
		this->_image->setIteratorIndex(0);

		loop {
			background->newImage(this->_width, this->_height, pixel1);
			if !background->getImageAlphaChannel() {
				background->setImageAlphaChannel(Imagick::ALPHACHANNEL_SET);
			}
			background->setImageBackgroundColor(pixel2);
			background->evaluateImage(Imagick::EVALUATE_MULTIPLY£¬opacity, Imagick::CHANNEL_ALPHA);		
			background->setColorspace(this->_image->getColorspace());
			background->compositeImage(this->_image, Imagick::COMPOSITE_DISSOLVE, 0, 0);
			if  !this->_image->nextImage() {
				break;
			}
		}

		this->_image->clear();
		this->_image->destroy();

		let this->_image = background;
	}

	protected function _blur(int radius)
	{
		this->_image->setIteratorIndex(0);

		loop {
			this->_image->blurImage(radius, 100);
			if  !this->_image->nextImage() {
				break;
			}
		}
	}

	protected function _pixelate(int amount)
	{
		int width, height;

		width = this->_width / amount;
		height = this->_height / amount;

		this->_image->setIteratorIndex(0);

		loop {
			this->_image->scaleImage(width, height);
			this->_image->scaleImage(this->_width, this->_height);
			if  !this->_image->nextImage() {
				break;
			}
		}
	}

	protected function _save(string file, int quality)
	{
		var ext, fp;

		let ext = pathinfo(file, PATHINFO_EXTENSION);
		
		this->_image->setFormat(ext);
		this->_image->setImageFormat(ext);

		let this->_type = this->_image->getImageType();
		let this->_mime = "image/".this->_image->getImageFormat();

		if strcasecmp(ext, "gif") == 0 {
			this->_image->optimizeImageLayers();
			let fp= fopen(file, "w");
			this->_image->writeImagesFile(fp);
			fclose(fp);
			return;
		} else {
			if strcasecmp(ext, "jpg") == 0 || strcasecmp(ext, "jpeg") == 0 {
				this->_image->setImageCompression(Imagick::COMPRESSION_JPEG);
			}
			this->_image->setImageCompressionQuality(quality);
			this->_image->writeImage(file);
		}
	}

	protected function _render(string ext, int quality)
	{
		this->_image->setFormat(ext);
		this->_image->setImageFormat(ext);
		let this->_type = this->_image->getImageType();
		let this->_mime = "image/".this->_image->getImageFormat();

		if strcasecmp(ext, "gif") == 0 {
			this->_image->optimizeImageLayers();
			return this->_image->getImagesBlob();
			return;
		} else {
			if strcasecmp(ext, "jpg") == 0 || strcasecmp(ext, "jpeg") == 0 {
				this->_image->setImageCompression(Imagick::COMPRESSION_JPEG);
			}
			this->_image->setImageCompressionQuality(quality);
			return this->_image->getImageBlob(file);
		}
	}

	public function __destruct()
	{
		if this->_image {
			this->_image->clear();
			this->_image->destroy();
		}
	}

}