
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image\Adapter;

use Phalcon\Image\Enum;

/**
 * Interface for Phalcon\Image\Adapter classes
 */
interface AdapterInterface
{
    public function background(string color, int opacity = 100) -> <AdapterInterface>;

    public function blur(int radius) -> <AdapterInterface>;

    public function crop(int width, int height, int offsetX = null, int offsetY = null) -> <AdapterInterface>;

    public function flip(int direction) -> <AdapterInterface>;

    public function mask(<AdapterInterface> watermark) -> <AdapterInterface>;

    public function pixelate(int amount) -> <AdapterInterface>;

    public function reflection(int height, int opacity = 100, bool fadeIn = false) -> <AdapterInterface>;

    public function render(string ext = null, int quality = 100) -> string;

    public function resize(int width = null, int height = null, int master = Enum::AUTO) -> <AdapterInterface>;

    public function rotate(int degrees) -> <AdapterInterface>;

    public function save(string file = null, int quality = 100) -> <AdapterInterface>;

    public function sharpen(int amount) -> <AdapterInterface>;

    public function text(string text, int offsetX = 0, int offsetY = 0, int opacity = 100, string color = "000000", int size = 12, string fontfile = null) -> <AdapterInterface>;

    public function watermark(<AdapterInterface> watermark, int offsetX = 0, int offsetY = 0, int opacity = 100) -> <AdapterInterface>;
}
