
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
     *
     * @param string $color
     * @param int    $opacity
     *
     * @return AdapterInterface
     */
    public function background(
        string color,
        int opacity = 100
    ) -> <AdapterInterface>;

    /**
     * Blur an image
     *
     * @param int $radius
     *
     * @return AdapterInterface
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
     *
     * @param int $direction
     *
     * @return AdapterInterface
     */
    public function flip(int direction) -> <AdapterInterface>;

    /**
     * Add a mask to an image
     *
     * @param AdapterInterface $mask
     *
     * @return AdapterInterface
     */
    public function mask(<AdapterInterface> mask) -> <AdapterInterface>;

    /**
     * Pixelate an image
     *
     * @param int $amount
     *
     * @return AdapterInterface
     */
    public function pixelate(int amount) -> <AdapterInterface>;

    /**
     * Reflect an image
     *
     * @param int  $height
     * @param int  $opacity
     * @param bool $fadeIn
     *
     * @return AdapterInterface
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
     *
     * @param int $degrees
     *
     * @return AdapterInterface
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
     *
     * @param int $amount
     *
     * @return AdapterInterface
     */
    public function sharpen(int amount) -> <AdapterInterface>;

    /**
     * Adds text on an image
     *
     * @param string      $text
     * @param int         $offsetX
     * @param int         $offsetY
     * @param int         $opacity
     * @param string      $color
     * @param int         $size
     * @param string|null $fontFile
     *
     * @return AdapterInterface
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
     *
     * @param AdapterInterface $watermark
     * @param int              $offsetX
     * @param int              $offsetY
     * @param int              $opacity
     *
     * @return AdapterInterface
     */
    public function watermark(
        <AdapterInterface> watermark,
        int offsetX = 0,
        int offsetY = 0,
        int opacity = 100
    ) -> <AdapterInterface>;
}
