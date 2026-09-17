
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
    /**
     * Add a background to an image
     */
    public function background(
        string color,
        int opacity = 100
    ) -> <AdapterInterface>;

    /**
     * Blur an image
     */
    public function blur(int radius) -> <AdapterInterface>;

    /**
     * Crop an image
     *
     * @param int      $width
     * @param int      $height
     * @param int|null $offsetX
     * @param int|null $offsetY
     *
     * @return AdapterInterface
     */
    public function crop(
        int width,
        int height,
        int offsetX = null,
        int offsetY = null
    ) -> <AdapterInterface>;

    /**
     * Flip an image
     */
    public function flip(int direction) -> <AdapterInterface>;

    public function getHeight() -> int;

    public function getWidth() -> int;

    /**
     * Add a mask to an image
     */
    public function mask(<AdapterInterface> mask) -> <AdapterInterface>;

    /**
     * Pixelate an image
     */
    public function pixelate(int amount) -> <AdapterInterface>;

    /**
     * Reflect an image
     */
    public function reflection(
        int height,
        int opacity = 100,
        bool fadeIn = false
    ) -> <AdapterInterface>;

    /**
     * Render an image
     *
     * @param string|null $extension
     * @param int         $quality
     *
     * @return string
     */
    public function render(string extension = null, int quality = 100) -> string;

    /**
     * Resize an image
     *
     * @param int|null $width
     * @param int|null $height
     * @param int      $master
     *
     * @return AdapterInterface
     */
    public function resize(
        int width = null,
        int height = null,
        int master = Enum::AUTO
    ) -> <AdapterInterface>;

    /**
     * Rotate an image
     */
    public function rotate(int degrees) -> <AdapterInterface>;

    /**
     * Save an image
     *
     * @param string|null $file
     * @param int         $quality
     *
     * @return AdapterInterface
     */
    public function save(
        string file = null,
        int quality = 100
    ) -> <AdapterInterface>;

    /**
     * Sharpen an image
     */
    public function sharpen(int amount) -> <AdapterInterface>;

    /**
     * Adds text on an image
     */
    public function text(
        string text,
        int offsetX = 0,
        int offsetY = 0,
        int opacity = 100,
        string color = "000000",
        int size = 12,
        string fontFile = null
    ) -> <AdapterInterface>;

    /**
     * Add a watermark on an image
     */
    public function watermark(
        <AdapterInterface> watermark,
        int offsetX = 0,
        int offsetY = 0,
        int opacity = 100
    ) -> <AdapterInterface>;
}
