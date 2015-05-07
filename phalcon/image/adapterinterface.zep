
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

namespace Phalcon\Image;

interface AdapterInterface
{

	public function resize(int width = null, int height = null, int master = Image::AUTO);
	public function crop(int width, int height, int offsetX = null, int offsetY = null);
	public function rotate(int degrees);
	public function flip(int direction);
	public function sharpen(int amount);
	public function reflection(int height, int opacity = 100, boolean fadeIn = false);
	public function watermark(<Adapter> watermark, int offsetX = 0, int offsetY = 0, int opacity = 100);
	public function text(string text, int offsetX = 0, int offsetY = 0, int opacity = 100, string color = "000000", int size = 12, string fontfile = null);
	public function mask(<Adapter> watermark);
	public function background(string color, int opacity = 100);
	public function blur(int radius);
	public function pixelate(int amount);
	public function save(string file = null, int quality = 100);
	public function render(string ext = null, int quality = 100);
}