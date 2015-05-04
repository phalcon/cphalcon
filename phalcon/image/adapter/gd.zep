
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

class Gd extends Adapter implements AdapterInterface
{
	protected static _checked = false;

	public static function check() -> boolean
	{
		var version, info, matches;

		if self::_checked {
			return true;
		}

		if !function_exists("gd_info") {
			throw new Exception("GD is either not installed or not enabled, check your configuration");
		}

		let version = null;
		if defined("GD_VERSION") {
			let version = GD_VERSION;
		} else {
			let info = gd_info(), matches = null;
			if preg_match("/\\d+\\.\\d+(?:\\.\\d+)?/", info["GD Version"], matches) {
				let version = matches[0];
			}
		}

		if !version_compare(version, "2.0.1", ">=") {
			throw new Exception("Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have " . version);
		}

		let self::_checked = true;

		return self::_checked;
	}

	public function __construct(string! file, int width = null, int height = null)
	{
		var imageinfo;

		if !self::_checked {
			self::check();
		}

		let this->_file = file;

		if file_exists(this->_file) {

			let this->_realpath = realpath(this->_file);
			let imageinfo = getimagesize(this->_file);

			if imageinfo {
				let this->_width = imageinfo[0];
				let this->_height = imageinfo[1];
				let this->_type = imageinfo[2];
				let this->_mime = imageinfo["mime"];
			}

			switch this->_type {
				case 1:
					let this->_image = imagecreatefromgif(this->_file);
					break;
				case 2:
					let this->_image = imagecreatefromjpeg(this->_file);
					break;
				case 3:
					let this->_image = imagecreatefrompng(this->_file);
					break;
				case 15:
					let this->_image = imagecreatefromwbmp(this->_file);
					break;
				case 16:
					let this->_image = imagecreatefromxbm(this->_file);
					break;
				default:
					if this->_mime {
						throw new Exception("Installed GD does not support " . this->_mime . " images");
					} else {
						throw new Exception("Installed GD does not support such images");
					}
					break;
			}

			imagesavealpha(this->_image, true);

		} else {
			if !width || !height {
				throw new Exception("Failed to create image from file " . this->_file);
			}

			let this->_image = imagecreatetruecolor(width, height);
			imagealphablending(this->_image, true);
			imagesavealpha(this->_image, true);

			let this->_realpath = this->_file;
			let this->_width    = width;
			let this->_height   = height;
			let this->_type     = 3;
			let this->_mime     = "image/png";
		}
	}

	protected function _resize(int width, int height)
	{
		var image, pre_width, pre_height, reduction_width, reduction_height;

		if version_compare(PHP_VERSION, "5.5.0") < 0 {

			let pre_width = this->_width;
			let pre_height = this->_height;

			if width > (this->_width / 2) && height > (this->_height / 2) {
				let reduction_width  = round(width  * 1.1);
				let reduction_height = round(height * 1.1);

				while pre_width / 2 > reduction_width && pre_height / 2 > reduction_height {
					let pre_width /= 2;
					let pre_height /= 2;
				}

				let image = this->_create(pre_width, pre_height);

				if imagecopyresized(image, this->_image, 0, 0, 0, 0, pre_width, pre_height, this->_width, this->_height) {
					imagedestroy(this->_image);
					let this->_image = image;
				}
			}

			let image = this->_create(width, height);

			if imagecopyresampled(image, this->_image, 0, 0, 0, 0, width, height, pre_width, pre_height) {
				imagedestroy(this->_image);
				let this->_image = image;
				let this->_width  = imagesx(image);
				let this->_height = imagesy(image);
			}
		} else {
			let image = imagescale(this->_image, width, height);
			imagedestroy(this->_image);
			let this->_image = image;
			let this->_width  = imagesx(image);
			let this->_height = imagesy(image);
		}
	}

	protected function _crop(int width, int height, int offsetX, int offsetY)
	{
		var image, rect;

		if version_compare(PHP_VERSION, "5.5.0") < 0 {
			let image = this->_create(width, height);
			if (imagecopyresampled(image, this->_image, 0, 0, offsetX, offsetY, width, height, width, height)) {
				imagedestroy(this->_image);
				let this->_image = image;
				let this->_width  = imagesx(image);
				let this->_height = imagesy(image);
			}
		} else {
			let rect = ["x": offsetX, "y": offsetY, "width": width, "height": height];
			let image = imagecrop(this->_image, rect);
			imagedestroy(this->_image);
			let this->_image = image;
			let this->_width  = imagesx(image);
			let this->_height = imagesy(image);
		}
	}

	protected function _rotate(int degrees)
	{
		var image, transparent, width, height;

		let transparent = imagecolorallocatealpha(this->_image, 0, 0, 0, 127);
		let image = imagerotate(this->_image, 360 - degrees, transparent, 1);

		imagesavealpha(image, TRUE);

		let width  = imagesx(image);
		let height = imagesy(image);

		if imagecopymerge(this->_image, image, 0, 0, 0, 0, width, height, 100) {
			imagedestroy(this->_image);
			let this->_image = image;
			let this->_width  = width;
			let this->_height = height;
		}
	}

	protected function _flip(int direction)
	{
		var image, x;

		if version_compare(PHP_VERSION, "5.5.0") < 0 {

			let image = this->_create(this->_width, this->_height);

			if direction == \Phalcon\Image::HORIZONTAL {
				let x = 0;
				while x < this->_width {
					let x++;
					imagecopy(image, this->_image, x, 0, this->_width - x - 1, 0, 1, this->_height);
				}
			} else {
				let x = 0;
				while x < this->_height {
					let x++;
					imagecopy(image, this->_image, 0, x, 0, this->_height - x - 1, this->_width, 1);
				}
			}

			imagedestroy(this->_image);
			let this->_image = image;

			let this->_width  = imagesx(image);
			let this->_height = imagesy(image);
		} else {

			if direction == \Phalcon\Image::HORIZONTAL {
				imageflip(this->_image, IMG_FLIP_HORIZONTAL);
			} else {
				imageflip(this->_image, IMG_FLIP_VERTICAL);
			}

		}
	}

	protected function _sharpen(int amount)
	{
		var matrix;

		let amount = (int) round(abs(-18 + (amount * 0.08)), 2);

		let matrix = [
			[-1,   -1,    -1],
			[-1, amount, -1],
			[-1,   -1,    -1]
		];

		if imageconvolution(this->_image, matrix, amount - 8, 0) {
			let this->_width  = imagesx(this->_image);
			let this->_height = imagesy(this->_image);
		}
	}

	protected function _reflection(int height, int opacity, boolean fadeIn)
	{
		var reflection, line;
		int stepping, offset, src_y, dst_y, dst_opacity;

		let opacity = (int) round(abs((opacity * 127 / 100) - 127));

		if opacity < 127 {
			let stepping = (127 - opacity) / height;
		} else {
			let stepping = 127 / height;
		}

		let reflection = this->_create(this->_width, this->_height + height);

		imagecopy(reflection, this->_image, 0, 0, 0, 0, this->_width, this->_height);

		let offset = 0;
		while height >= offset {

			let src_y = this->_height - offset - 1;
			let dst_y = this->_height + offset;

			if fadeIn {
				let dst_opacity = (int) round(opacity + (stepping * (height - offset)));
			} else {
				let dst_opacity = (int) round(opacity + (stepping * offset));
			}

			let line = this->_create(this->_width, 1);

			imagecopy(line, this->_image, 0, 0, 0, src_y, this->_width, 1);
			imagefilter(line, IMG_FILTER_COLORIZE, 0, 0, 0, dst_opacity);
			imagecopy(reflection, line, 0, dst_y, 0, 0, this->_width, 1);
			let offset++;
		}

		imagedestroy(this->_image);
		let this->_image = reflection;
		let this->_width  = imagesx(reflection);
		let this->_height = imagesy(reflection);
	}

	protected function _watermark(<Adapter> watermark, int offsetX, int offsetY, int opacity)
	{
		var overlay, color;
		int width, height;

		let overlay = imagecreatefromstring(watermark->render());

		imagesavealpha(overlay, true);

		let width  = (int) imagesx(overlay);
		let height = (int) imagesy(overlay);

		if opacity < 100 {
			let opacity = (int) round(abs((opacity * 127 / 100) - 127));
			let color = imagecolorallocatealpha(overlay, 127, 127, 127, opacity);

			imagelayereffect(overlay, IMG_EFFECT_OVERLAY);

			imagefilledrectangle(overlay, 0, 0, width, height, color);
		}

		imagealphablending(this->_image, true);

		if imagecopy(this->_image, overlay, offsetX, offsetY, 0, 0, width, height) {
			imagedestroy(overlay);
		}
	}

	protected function _text(string text, int offsetX, int offsetY, int opacity, int r, int g, int b, int size, string fontfile)
	{
		var space, color, angle;
		int s0 = 0, s1 = 0, s4 = 0, s5 = 0, width, height;

		let opacity = (int) round(abs((opacity * 127 / 100) - 127));

		if fontfile {

			let space = imagettfbbox(size, 0, fontfile, text);

			if isset space[0] {
				let s0 = (int) space[0];
				let s1 = (int) space[1];
				let s4 = (int) space[4];
				let s5 = (int) space[5];
			}

			if !s0 || !s1 || !s4 || !s5 {
				throw new Exception("Call to imagettfbbox() failed");
			}

			let width  = abs(s4 - s0) + 10;
			let height = abs(s5 - s1) + 10;

			if offsetX < 0 {
				let offsetX = this->_width - width + offsetX;
			}

			if offsetY < 0 {
				let offsetY = this->_height - height + offsetY;
			}

			let color = imagecolorallocatealpha(this->_image, r, g, b, opacity);
			let angle = 0;

			imagettftext(this->_image, size, angle, offsetX, offsetY, color, fontfile, text);
		} else {
			let width  = (int) imagefontwidth(size) * strlen(text);
			let height = (int) imagefontheight(size);

			if offsetX < 0 {
				let offsetX = this->_width - width + offsetX;
			}

			if offsetY < 0 {
				let offsetY = this->_height - height + offsetY;
			}

			let color = imagecolorallocatealpha(this->_image, r, g, b, opacity);
			imagestring(this->_image, size, offsetX, offsetY, text, color);
		}
	}

	protected function _mask(<Adapter> mask)
	{
		var maskImage, newimage, tempImage, color, index, r, g, b;
		int mask_width, mask_height, x, y, alpha;

		let maskImage   = imagecreatefromstring(mask->render());
		let mask_width  = (int) imagesx(maskImage);
		let mask_height = (int) imagesy(maskImage);
		let alpha = 127;

		imagesavealpha(maskImage, true);

		let newimage = this->_create(this->_width, this->_height);
		imagesavealpha(newimage, true);

		let color = imagecolorallocatealpha(newimage, 0, 0, 0, alpha);

		imagefill(newimage, 0, 0, color);

		if this->_width != mask_width || this->_height != mask_height {
			let tempImage = imagecreatetruecolor(this->_width, this->_height);

			imagecopyresampled(tempImage, maskImage, 0, 0, 0, 0, this->_width, this->_height, mask_width, mask_height);
			imagedestroy(maskImage);

			let maskImage = tempImage;
		}

		let x = 0;
		while x < this->_width {

			let y = 0;
			while y < this->_height {

				let index = imagecolorat(maskImage, x, y),
					color = imagecolorsforindex(maskImage, index);

				if isset color["red"] {
					let alpha = 127 - intval(color["red"] / 2);
				}

				let index = imagecolorat(this->_image, x, y),
					color = imagecolorsforindex(this->_image, index),
					r = color["red"], g = color["green"], b = color["blue"],
					color = imagecolorallocatealpha(newimage, r, g, b, alpha);

				imagesetpixel(newimage, x, y, color);
				let y++;
			}
			let x++;
		}

		imagedestroy(this->_image);
		imagedestroy(maskImage);
		let this->_image = newimage;
	}

	protected function _background(int r, int g, int b, int opacity)
	{
		var background, color;

		let opacity = (opacity * 127 / 100) - 127;

		let background = this->_create(this->_width, this->_height);

		let color = imagecolorallocatealpha(background, r, g, b, opacity);
		imagealphablending(background, true);

		if imagecopy(background, this->_image, 0, 0, 0, 0, this->_width, this->_height) {
			imagedestroy(this->_image);
			let this->_image = background;
		}
	}

	protected function _blur(int radius)
	{
		int i;
		let i = 0;
		while i < radius {
			imagefilter(this->_image, IMG_FILTER_GAUSSIAN_BLUR);
			let i++;
		}
	}

	protected function _pixelate(int amount)
	{
		var color;
		int x, y, x1, y1, x2, y2;

		let x = 0;
		while x < this->_width {
			let y = 0;
			while y < this->_height {
				let x1 = x + amount/2;
				let y1 = y + amount/2;
				let color = imagecolorat(this->_image, x1, y1);

				let x2 = x + amount;
				let y2 = y + amount;
				imagefilledrectangle(this->_image, x1, y1, x2, y2, color);

				let y += amount;
			}
			let x += amount;
		}
	}

	protected function _save(string file, int quality)
	{
		var ext;

		let ext = strtolower(pathinfo(file, PATHINFO_EXTENSION));

		if strcmp(ext, "gif") == 0 {
			let this->_type = 1;
			let this->_mime = image_type_to_mime_type(this->_type);
			imagegif(this->_image, file);
			return true;
		}
		if strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0 {
			let this->_type = 2;
			let this->_mime = image_type_to_mime_type(this->_type);
			imagejpeg(this->_image, file, quality);
			return true;
		}
		if strcmp(ext, "png") == 0 {
			let this->_type = 3;
			let this->_mime = image_type_to_mime_type(this->_type);
			imagepng(this->_image, file);
			return true;
		}
		if strcmp(ext, "wbmp") == 0 {
			let this->_type = 15;
			let this->_mime = image_type_to_mime_type(this->_type);
			imagewbmp(this->_image, file);
			return true;
		}
		if strcmp(ext, "xbm") == 0 {
			let this->_type = 16;
			let this->_mime = image_type_to_mime_type(this->_type);
			imagexbm(this->_image, file);
			return true;
		}

		throw new Exception("Installed GD does not support '" . ext . "' images");
	}

	protected function _render(string ext, int quality)
	{
		let ext = strtolower(ext);
                ob_start();
		if strcmp(ext, "gif") == 0 {
			imagegif(this->_image);
			return ob_get_clean();
		}
		if strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0 {
			imagejpeg(this->_image, null, quality);
			return ob_get_clean();
		}
		if strcmp(ext, "png") == 0 {
			imagepng(this->_image);
			return ob_get_clean();
		}
		if strcmp(ext, "wbmp") == 0 {
			imagewbmp(this->_image);
			return ob_get_clean();
		}
		if strcmp(ext, "xbm") == 0 {
			imagexbm(this->_image, null);
			return ob_get_clean();
		}

		throw new Exception("Installed GD does not support '" . ext . "' images");
	}

	protected function _create(int width, int height)
	{
		var image;

		let image = imagecreatetruecolor(width, height);

		imagealphablending(image, false);
		imagesavealpha(image, true);

		return image;
	}

	public function __destruct()
	{
		var image;

		let image = this->_image;
		if typeof image  == "resource" {
			imagedestroy(image);
		}
	}

}
