
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image;

interface AdapterInterface
{

	public function resize(int width = null, int height = null, int master = Image::AUTO);
	public function crop(int width, int height, int offsetX = null, int offsetY = null);
	public function rotate(int degrees);
	public function flip(int direction);
	public function sharpen(int amount);
	public function reflection(int height, int opacity = 100, bool fadeIn = false);
	public function watermark(<Adapter> watermark, int offsetX = 0, int offsetY = 0, int opacity = 100);
	public function text(string text, int offsetX = 0, int offsetY = 0, int opacity = 100, string color = "000000", int size = 12, string fontfile = null);
	public function mask(<Adapter> watermark);
	public function background(string color, int opacity = 100);
	public function blur(int radius);
	public function pixelate(int amount);
	public function save(string file = null, int quality = 100);
	public function render(string ext = null, int quality = 100);
}
