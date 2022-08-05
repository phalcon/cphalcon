
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
use Phalcon\Image\Exception;

class Gd extends AbstractAdapter
{
    /**
     * @param string   $file
     * @param int|null $width
     * @param int|null $height
     *
     * @throws Exception
     */
    public function __construct(
        string file,
        int width = null,
        int height = null
    ) {
        var imageInfo;

        this->check();

        let this->file = file;
        let this->type = 0;

        if (true === file_exists(this->file)) {
            let this->realpath = realpath(this->file);
            let imageInfo      = getimagesize(this->file);

            if (false !== imageInfo) {
                let this->width  = imageInfo[0];
                let this->height = imageInfo[1];
                let this->type   = imageInfo[2];
                let this->mime   = imageInfo["mime"];
            }

            switch (this->type) {
                case IMAGETYPE_GIF:
                    let this->image = imagecreatefromgif(this->file);
                    break;

                case IMAGETYPE_JPEG:
                case IMAGETYPE_JPEG2000:
                    let this->image = imagecreatefromjpeg(this->file);
                    break;

                case IMAGETYPE_PNG:
                    let this->image = imagecreatefrompng(this->file);
                    break;

                case IMAGETYPE_WEBP:
                    let this->image = imagecreatefromwebp(this->file);
                    break;

                case IMAGETYPE_WBMP:
                    let this->image = imagecreatefromwbmp(this->file);
                    break;

                case IMAGETYPE_XBM:
                    let this->image = imagecreatefromxbm(this->file);
                    break;

                default:
                    if (this->mime) {
                        throw new Exception(
                            "Installed GD does not support " . this->mime . " images"
                        );
                    }

                    throw new Exception(
                        "Installed GD does not support such images"
                    );
            }

            imagesavealpha(this->image, true);
        } else {
            if (null === width || null === height) {
                throw new Exception(
                    "Failed to create image from file " . this->file
                );
            }

            let this->image = imagecreatetruecolor(width, height);

            imagealphablending(this->image, true);
            imagesavealpha(this->image, true);

            let this->realpath = this->file;
            let this->width    = width;
            let this->height   = height;
            let this->type     = 3;
            let this->mime     = "image/png";
        }
    }

    /**
     * Destructor
     */
    public function __destruct()
    {
        var image;

        let image = this->image;

        if (null !== image) {
            imagedestroy(image);
        }

        let this->image = null;
    }

    /**
     * @return string
     * @throws Exception
     */
    public function getVersion() -> string
    {
        var info, matches, version;

        if (true !== function_exists("gd_info")) {
            throw new Exception(
                "GD is either not installed or not enabled, check your configuration"
            );
        }

        let version = null;

        if (defined("GD_VERSION")) {
            let version = GD_VERSION;
        } else {
            let info    = gd_info();
            let matches = null;

            if (
                preg_match(
                    "/\\d+\\.\\d+(?:\\.\\d+)?/",
                    info["GD Version"],
                    matches
                )
            ) {
                let version = matches[0];
            }
        }

        return version;
    }

    /**
     * @param int $red
     * @param int $green
     * @param int $blue
     * @param int $opacity
     *
     * @return void
     */
    protected function processBackground(
        int red,
        int green,
        int blue,
        int opacity
    ) -> void {
        var background, color, copy, image;

        let opacity    = (int) round(abs((opacity * 127 / 100) - 127));
        let image      = this->image;
        let background = this->processCreate(this->width, this->height);

        let color = imagecolorallocatealpha(
            background,
            red,
            green,
            blue,
            opacity
        );

        imagealphablending(background, true);

        let copy = imagecopy(
            background,
            image,
            0,
            0,
            0,
            0,
            this->width,
            this->height
        );
        if (false !== copy) {
            imagedestroy(image);

            let this->image = background;
        }
    }

    /**
     * @param int $radius
     *
     * @return void
     */
    protected function processBlur(int radius) -> void
    {
        var counter;

        let counter = 0;
        while (counter < radius) {
            imagefilter(this->image, IMG_FILTER_GAUSSIAN_BLUR);

            let counter++;
        }
    }

    /**
     * @param int $width
     * @param int $height
     *
     * @return false|resource
     */
    protected function processCreate(int width, int height)
    {
        var image;

        let image = imagecreatetruecolor(width, height);

        imagealphablending(image, false);
        imagesavealpha(image, true);

        return image;
    }

    /**
     * @param int $width
     * @param int $height
     * @param int $offsetX
     * @param int $offsetY
     *
     * @return void
     */
    protected function processCrop(
        int width,
        int height,
        int offsetX,
        int offsetY
    ) -> void {
        var image;
        array rect;

        let rect = [
            "x"      : offsetX,
            "y"      : offsetY,
            "width"  : width,
            "height" : height
        ];

        let image = imagecrop(this->image, rect);

        imagedestroy(this->image);

        let this->image  = image;
        let this->width  = imagesx(image);
        let this->height = imagesy(image);
    }

    /**
     * @param int $direction
     *
     * @return void
     */
    protected function processFlip(int direction) -> void
    {
        if (direction === Enum::HORIZONTAL) {
            imageflip(this->image, IMG_FLIP_HORIZONTAL);
        } else {
            imageflip(this->image, IMG_FLIP_VERTICAL);
        }
    }

    /**
     * @param AdapterInterface $mask
     *
     * @return void
     */
    protected function processMask(<AdapterInterface> mask)
    {
        var alpha, blue, color, index, green, maskHeight, maskImage,
            maskWidth, newImage, red, tempImage, x, y;

        let maskImage  = imagecreatefromstring(mask->render());
        let maskWidth  = (int) imagesx(maskImage);
        let maskHeight = (int) imagesy(maskImage);
        let alpha      = 127;

        imagesavealpha(maskImage, true);

        let newImage = this->processCreate(this->width, this->height);

        imagesavealpha(newImage, true);

        let color = imagecolorallocatealpha(
            newImage,
            0,
            0,
            0,
            alpha
        );

        imagefill(newImage, 0, 0, color);

        if (this->width !== maskWidth || this->height !== maskHeight) {
            let tempImage = imagecreatetruecolor(this->width, this->height);

            imagecopyresampled(
                tempImage,
                maskImage,
                0,
                0,
                0,
                0,
                this->width,
                this->height,
                maskWidth,
                maskHeight
            );

            imagedestroy(maskImage);

            let maskImage = tempImage;
        }

        let x = 0;
        while (x < this->width) {
            let y = 0;
            while (y < this->height) {
                let index = imagecolorat(maskImage, x, y);
                let color = imagecolorsforindex(maskImage, index);

                if (true === isset(color["red"])) {
                    let alpha = 127 - intval(color["red"] / 2);
                }

                let index = imagecolorat(this->image, x, y);
                let color = imagecolorsforindex(this->image, index);
                let red   = color["red"];
                let green = color["green"];
                let blue  = color["blue"];
                let color = imagecolorallocatealpha(
                    newImage,
                    red,
                    green,
                    blue,
                    alpha
                );

                imagesetpixel(newImage, x, y, color);

                let y++;
            }

            let x++;
        }

        imagedestroy(this->image);
        imagedestroy(maskImage);

        let this->image = newImage;
    }

    /**
     * @param int $amount
     *
     * @return void
     */
    protected function processPixelate(int amount) -> void
    {
        var color, x, x1, x2, y, y1, y2;

        let x = 0;

        while (x < this->width) {
            let y = 0;

            while (y < this->height) {
                let x1 = (int) (x + (amount / 2));
                let y1 = (int) (y + (amount / 2));

                if (x1 >= this->width || y1 >= this->height) {
                    break;
                }

                let color = imagecolorat(this->image, x1, y1);
                let x2    = x + amount;
                let y2    = y + amount;

                imagefilledrectangle(
                    this->image,
                    x,
                    y,
                    x2,
                    y2,
                    color
                );

                let y += amount;
            }

            let x += amount;
        }
    }

    /**
     * @param int  $height
     * @param int  $opacity
     * @param bool $fadeIn
     *
     * @return void
     */
    protected function processReflection(
        int height,
        int opacity,
        bool fadeIn
    ) -> void {
        var line, reflection;
        int destinationY, destinationOpacity, offset, stepping, sourceY;

        let opacity = (int) round(abs((opacity * 127 / 100) - 127));

        if (opacity < 127) {
            let stepping = (127 - opacity) / height;
        } else {
            let stepping = 127 / height;
        }

        let reflection = this->processCreate(
            this->width,
            this->height + height
        );

        imagecopy(
            reflection,
            this->image,
            0,
            0,
            0,
            0,
            this->width,
            this->height
        );

        let offset = 0;
        while (height >= offset) {
            let sourceY      = this->height - offset - 1;
            let destinationY = this->height + offset;

            if (fadeIn) {
                let destinationOpacity = (int) round(
                    opacity + (stepping * (height - offset))
                );
            } else {
                let destinationOpacity = (int) round(
                    opacity + (stepping * offset)
                );
            }

            let line = this->processCreate(this->width, 1);

            imagecopy(
                line,
                this->image,
                0,
                0,
                0,
                sourceY,
                this->width,
                1
            );

            imagefilter(
                line,
                IMG_FILTER_COLORIZE,
                0,
                0,
                0,
                destinationOpacity
            );

            imagecopy(
                reflection,
                line,
                0,
                destinationY,
                0,
                0,
                this->width,
                1
            );

            let offset++;
        }

        imagedestroy(this->image);

        let this->image  = reflection;
        let this->width  = imagesx(reflection);
        let this->height = imagesy(reflection);
    }

    /**
     * @param string $extension
     * @param int    $quality
     *
     * @return false|string
     * @throws Exception
     */
    protected function processRender(string extension, int quality)
    {
        let extension = strtolower(extension);

        ob_start();
        switch (extension) {
            case "gif":
                imagegif(this->image);
                break;
            case "jpg":
            case "jpeg":
                imagejpeg(this->image, null, quality);
                break;
            case "png":
                imagepng(this->image);
                break;
            case "wbmp":
                imagewbmp(this->image);
                break;
            case "webp":
                imagewebp(this->image);
                break;
            case "xbm":
                imagexbm(this->image, null);
                break;
            default:
                throw new Exception(
                    "Installed GD does not support '" . extension . "' images"
                );
        }

        return ob_get_clean();
    }

    /**
     * @param int $width
     * @param int $height
     *
     * @return void
     */
    protected function processResize(int width, int height) -> void
    {
        var image;

        let image = imagescale(this->image, width, height);

        imagedestroy(this->image);

        let this->image  = image;
        let this->width  = imagesx(image);
        let this->height = imagesy(image);
    }

    /**
     * @param int $degrees
     *
     * @return void
     */
    protected function processRotate(int degrees) -> void
    {
        var copy, height, image, transparent, width;

        let transparent = imagecolorallocatealpha(
            this->image,
            0,
            0,
            0,
            127
        );

        let image = imagerotate(
            this->image,
            360 - degrees,
            transparent
        );

        imagesavealpha(image, true);

        let width  = imagesx(image);
        let height = imagesy(image);

        let copy = imagecopymerge(
            this->image,
            image,
            0,
            0,
            0,
            0,
            width,
            height,
            100
        );
        if (false !== copy) {
            imagedestroy(this->image);

            let this->image  = image;
            let this->width  = width;
            let this->height = height;
        }
    }

    /**
     * @param string $file
     * @param int    $quality
     *
     * @return bool
     * @throws Exception
     */
    protected function processSave(string file, int quality) -> bool
    {
        var extension;

        let extension = pathinfo(file, PATHINFO_EXTENSION);

        // If no extension is given, revert to the original type.
        if (true === empty(extension)) {
            let extension = image_type_to_extension(this->type, false);
        }

        let extension = strtolower(extension);
        switch (extension) {
            case "gif":
                let this->type = IMAGETYPE_GIF;
                imagegif(this->image, file);
                break;
            case "jpg":
            case "jpeg":
                let this->type = IMAGETYPE_JPEG;

                if (quality >= 0) {
                    let quality = this->checkHighLow(quality, 1);
                    imagejpeg(this->image, file, quality);
                } else {
                    imagejpeg(this->image, file);
                }
                break;
            case "png":
                let this->type = IMAGETYPE_PNG;
                imagepng(this->image, file);
                break;
            case "wbmp":
                let this->type = IMAGETYPE_WBMP;
                imagewbmp(this->image, file);
                break;
            case "webp":
                let this->type = IMAGETYPE_WEBP;
                imagewebp(this->image, file);
                break;
            case "xbm":
                let this->type = IMAGETYPE_XBM;
                imagexbm(this->image, file);
                break;
            default:
                throw new Exception(
                    "Installed GD does not support '" . extension . "' images"
                );
        }

        let this->mime = image_type_to_mime_type(this->type);

        return true;
    }

    /**
     * @param int $amount
     *
     * @return void
     */
    protected function processSharpen(int amount) -> void
    {
        var result;
        array matrix;

        let amount = (int) round(abs(-18 + (amount * 0.08)), 2);

        let matrix = [
            [-1, -1, -1],
            [-1, amount, -1],
            [-1, -1, -1]
        ];

        let result = imageconvolution(
            this->image,
            matrix,
            amount - 8,
            0
        );
        if (true === result) {
            let this->width  = imagesx(this->image);
            let this->height = imagesy(this->image);
        }
    }

    /**
     * @param string      $text
     * @param mixed       $offsetX
     * @param mixed       $offsetY
     * @param int         $opacity
     * @param int         $red
     * @param int         $green
     * @param int         $blue
     * @param int         $size
     * @param string|null $fontFile
     *
     * @return void
     * @throws Exception
     */
    protected function processText(
        string text,
        offsetX,
        offsetY,
        int opacity,
        int red,
        int green,
        int blue,
        int size,
        string fontFile = null
    ) -> void {
        var angle, bottomLeftX, bottomLeftY, color, height, space,
            topRightX, topRightY, width;

        let bottomLeftX = 0;
        let bottomLeftY = 0;
        let topRightX   = 0;
        let topRightY   = 0;
        let offsetX     = (int) offsetX;
        let offsetY     = (int) offsetY;

        let opacity = (int) round(abs((opacity * 127 / 100) - 127));

        if (true !== empty(fontFile)) {
            let space = imagettfbbox(size, 0, fontFile, text);

            if (false === space) {
                throw new Exception("Call to imagettfbbox() failed");
            }

            if (true === isset(space[0])) {
                let bottomLeftX = (int) space[0];
                let bottomLeftY = (int) space[1];
                let topRightX   = (int) space[4];
                let topRightY   = (int) space[5];
            }

            let width  = abs(topRightX - bottomLeftX) + 10;
            let height = abs(topRightY - bottomLeftY) + 10;

            if (offsetX < 0) {
                let offsetX = this->width - width + offsetX;
            }

            if (offsetY < 0) {
                let offsetY = this->height - height + offsetY;
            }

            let color = imagecolorallocatealpha(
                this->image,
                red,
                green,
                blue,
                opacity
            );

            let angle = 0;
            imagettftext(
                this->image,
                size,
                angle,
                offsetX,
                offsetY,
                color,
                fontFile,
                text
            );
        } else {
            let width  = imagefontwidth(size) * strlen(text);
            let height = imagefontheight(size);

            if (offsetX < 0) {
                let offsetX = this->width - width + offsetX;
            }

            if (offsetY < 0) {
                let offsetY = this->height - height + offsetY;
            }

            let color = imagecolorallocatealpha(
                this->image,
                red,
                green,
                blue,
                opacity
            );

            imagestring(
                this->image,
                size,
                offsetX,
                offsetY,
                text,
                color
            );
        }
    }

    protected function processWatermark(
        <AdapterInterface> watermark,
        int offsetX,
        int offsetY,
        int opacity
    ) -> void {
        var color, copy, overlay;
        int height, width;

        let overlay = imagecreatefromstring(watermark->render());

        imagesavealpha(overlay, true);

        let width  = (int) imagesx(overlay);
        let height = (int) imagesy(overlay);

        if (opacity < 100) {
            let opacity = (int) round(
                abs(
                    (opacity * 127 / 100) - 127
                )
            );

            let color = imagecolorallocatealpha(
                overlay,
                127,
                127,
                127,
                opacity
            );

            imagelayereffect(overlay, IMG_EFFECT_OVERLAY);

            imagefilledrectangle(overlay, 0, 0, width, height, color);
        }

        imagealphablending(this->image, true);

        let copy = imagecopy(
            this->image,
            overlay,
            offsetX,
            offsetY,
            0,
            0,
            width,
            height
        );
        if (true === copy) {
            imagedestroy(overlay);
        }
    }

    /**
     * Checks the installed version of GD
     *
     * @return void
     * @throws Exception
     */
    private function check() -> void
    {
        var version;

        let version = this->getVersion();

        if (true !== version_compare(version, "2.0.1", ">=")) {
            throw new Exception(
                "Phalcon\\Image\\Adapter\\GD requires GD " .
                "version '2.0.1' or greater, you have " . version
            );
        }
    }
}
