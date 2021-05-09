
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

/**
 * Phalcon\Image\Adapter\Imagick
 *
 * Image manipulation support. Allows images to be resized, cropped, etc.
 *
 *```php
 * $image = new \Phalcon\Image\Adapter\Imagick("upload/test.jpg");
 *
 * $image->resize(200, 200)->rotate(90)->crop(100, 100);
 *
 * if ($image->save()) {
 *     echo "success";

 * }
 *```
 */
class Imagick extends AbstractAdapter
{
    /**
     * @var bool
     */
    protected static checked = false;

    /**
     * @var int
     */
    protected static version = 0;

    /**
     * \Phalcon\Image\Adapter\Imagick constructor
     */
    public function __construct(string! file, int width = null, int height = null)
    {
        var image;

        if !self::checked {
            self::check();
        }

        let this->file = file;
        let this->image = new \Imagick();

        if file_exists(this->file) {
            let this->realpath = realpath(this->file);

            if unlikely !this->image->readImage(this->realpath) {
                 throw new Exception(
                     "Imagick::readImage " . this->file . " failed"
                 );
            }

            if !this->image->getImageAlphaChannel() {
                this->image->setImageAlphaChannel(
                    constant("Imagick::ALPHACHANNEL_SET")
                );
            }

            if this->type == 1 {
                let image = this->image->coalesceImages();

                this->image->clear();
                this->image->destroy();

                let this->image = image;
            }
        } else {
            if unlikely (!width || !height) {
                throw new Exception(
                    "Failed to create image from file " . this->file
                );
            }

            this->image->newImage(
                width,
                height,
                new \ImagickPixel("transparent")
            );

            this->image->setFormat("png");
            this->image->setImageFormat("png");

            let this->realpath = this->file;
        }

        let this->width  = this->image->getImageWidth();
        let this->height = this->image->getImageHeight();
        let this->type   = this->image->getImageType();
        let this->mime   = "image/" . this->image->getImageFormat();
    }

    /**
     * Destroys the loaded image to free up resources.
     */
    public function __destruct()
    {
        if this->image instanceof \Imagick {
            this->image->clear();
            this->image->destroy();
        }
    }

    /**
     * Checks if Imagick is enabled
     */
    public static function check() -> bool
    {
        if self::checked {
            return true;
        }

        if unlikely !class_exists("imagick") {
            throw new Exception(
                "Imagick is not installed, or the extension is not loaded"
            );
        }

        if defined("Imagick::IMAGICK_EXTNUM") {
            let self::version = constant("Imagick::IMAGICK_EXTNUM");
        }

        let self::checked = true;

        return self::checked;
    }

    /**
     * Get instance
     */
    public function getInternalImInstance() -> <\Imagick>
    {
        return this->image;
    }

    /**
     * Sets the limit for a particular resource in megabytes
     *
     * @link http://php.net/manual/ru/imagick.constants.php#imagick.constants.resourcetypes
     */
    public function setResourceLimit(int type, int limit) -> void
    {
        this->image->setResourceLimit(type, limit);
    }

    /**
     * Execute a background.
     */
    protected function processBackground(int r, int g, int b, int opacity) -> void
    {
        var background, color, pixel1, pixel2, ret;

        let opacity /= 100;
        let color = sprintf("rgb(%d, %d, %d)", r, g, b);
        let pixel1 = new \ImagickPixel(color);
        let pixel2 = new \ImagickPixel("transparent");
        let background = new \Imagick();

        this->image->setIteratorIndex(0);

        loop {
            background->newImage(this->width, this->height, pixel1);

            if !background->getImageAlphaChannel() {
                background->setImageAlphaChannel(
                    constant("Imagick::ALPHACHANNEL_SET")
                );
            }

            background->setImageBackgroundColor(pixel2);

            background->evaluateImage(
                constant("Imagick::EVALUATE_MULTIPLY"),
                opacity,
                constant("Imagick::CHANNEL_ALPHA")
            );

            background->setColorspace(
                this->image->getColorspace()
            );

            let ret = background->compositeImage(
                this->image,
                constant("Imagick::COMPOSITE_DISSOLVE"),
                0,
                0
            );

            if unlikely ret !== true {
                throw new Exception("Imagick::compositeImage failed");
            }

            if this->image->nextImage() === false {
                break;
            }
        }

        this->image->clear();
        this->image->destroy();

        let this->image = background;
    }

    /**
     * Blur image
     *
     * @param int $radius Blur radius
     */
    protected function processBlur(int radius) -> void
    {
        this->image->setIteratorIndex(0);

        loop {
            this->image->blurImage(radius, 100);

            if this->image->nextImage() === false {
                break;
            }
        }
    }

    /**
     * Execute a crop.
     */
    protected function processCrop(int width, int height, int offsetX, int offsetY) -> void
    {
        var image;

        let image = this->image;

        image->setIteratorIndex(0);

        loop {
            image->cropImage(width, height, offsetX, offsetY);
            image->setImagePage(width, height, 0, 0);

            if !image->nextImage() {
                break;
            }
        }

        let this->width  = image->getImageWidth();
        let this->height = image->getImageHeight();
    }

    /**
     * Execute a flip.
     */
    protected function processFlip(int direction) -> void
    {
        var func;

        let func = "flipImage";

        if direction == Enum::HORIZONTAL {
           let func = "flopImage";
        }

        this->image->setIteratorIndex(0);

        loop {
            this->image->{func}();

            if this->image->nextImage() === false {
                break;
            }
        }
    }

    /**
     * This method scales the images using liquid rescaling method. Only support
     * Imagick
     *
     * @param int $width   new width
     * @param int $height  new height
     * @param int $deltaX How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight.
     * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.
     */
    protected function processLiquidRescale(int width, int height, int deltaX, int rigidity) -> void
    {
        var ret, image;

        let image = this->image;

        image->setIteratorIndex(0);

        loop {
            let ret = image->liquidRescaleImage(
                width,
                height,
                deltaX,
                rigidity
            );

            if unlikely ret !== true {
                throw new Exception("Imagick::liquidRescale failed");
            }

            if image->nextImage() === false {
                break;
            }
        }

        let this->width = image->getImageWidth();
        let this->height = image->getImageHeight();
    }

    /**
     * Composite one image onto another
     */
    protected function processMask(<AdapterInterface> image) -> void
    {
        var mask, ret;

        let mask = new \Imagick();

        mask->readImageBlob(
            image->render()
        );

        this->image->setIteratorIndex(0);

        loop {
            this->image->setImageMatte(1);

            let ret = this->image->compositeImage(
                mask,
                constant("Imagick::COMPOSITE_DSTIN"),
                0,
                0
            );

            if unlikely ret !== true {
                throw new Exception("Imagick::compositeImage failed");
            }

            if this->image->nextImage() === false {
                break;
            }
        }

        mask->clear();
        mask->destroy();
    }

    /**
     * Pixelate image
     *
     * @param int $amount amount to pixelate
     */
    protected function processPixelate(int amount) -> void
    {
        int width, height;

        let width = this->width / amount;
        let height = this->height / amount;

        this->image->setIteratorIndex(0);

        loop {
            this->image->scaleImage(width, height);
            this->image->scaleImage(this->width, this->height);

            if this->image->nextImage() === false{
                break;
            }
        }
    }

    /**
     * Execute a reflection.
     */
    protected function processReflection(int height, int opacity, bool fadeIn) -> void
    {
        var reflection, fade, pseudo, image, pixel, ret;

        if self::version >= 30100 {
            let reflection = clone this->image;
        } else {
            let reflection = clone this->image->$clone();
        }

        reflection->setIteratorIndex(0);

        loop {
            reflection->flipImage();

            reflection->cropImage(
                reflection->getImageWidth(),
                height,
                0,
                0
            );

            reflection->setImagePage(
                reflection->getImageWidth(),
                height,
                0,
                0
            );

            if reflection->nextImage() === false {
                break;
            }
        }

        let pseudo = fadeIn ? "gradient:black-transparent" : "gradient:transparent-black",
            fade = new \Imagick();

        fade->newPseudoImage(
            reflection->getImageWidth(),
            reflection->getImageHeight(),
            pseudo
        );

        let opacity /= 100;

        reflection->setIteratorIndex(0);

        loop {
            let ret = reflection->compositeImage(
                fade,
                constant("Imagick::COMPOSITE_DSTOUT"),
                0,
                0
            );

            if unlikely ret !== true {
                throw new Exception("Imagick::compositeImage failed");
            }

            reflection->evaluateImage(
                constant("Imagick::EVALUATE_MULTIPLY"),
                opacity,
                constant("Imagick::CHANNEL_ALPHA")
            );

            if reflection->nextImage() === false {
                break;
            }
        }

        fade->destroy();

        let image = new \Imagick(),
            pixel = new \ImagickPixel(),
            height = this->image->getImageHeight() + height;

        this->image->setIteratorIndex(0);

        loop {
            image->newImage(this->width, height, pixel);

            image->setImageAlphaChannel(
                constant("Imagick::ALPHACHANNEL_SET")
            );

            image->setColorspace(
                this->image->getColorspace()
            );

            image->setImageDelay(
                this->image->getImageDelay()
            );

            let ret = image->compositeImage(
                this->image,
                constant("Imagick::COMPOSITE_SRC"),
                0,
                0
            );

            if unlikely ret !== true {
                throw new Exception("Imagick::compositeImage failed");
            }

            if this->image->nextImage() === false {
                break;
            }
        }

        image->setIteratorIndex(0);
        reflection->setIteratorIndex(0);

        loop {
            let ret = image->compositeImage(
                reflection,
                constant("Imagick::COMPOSITE_OVER"),
                0,
                this->height
            );

            if unlikely ret !== true {
                throw new Exception("Imagick::compositeImage failed");
            }

            if image->nextImage() === false || reflection->nextImage() === false {
                break;
            }
        }

        reflection->destroy();

        this->image->clear();
        this->image->destroy();

        let this->image = image;
        let this->width = this->image->getImageWidth();
        let this->height = this->image->getImageHeight();
    }

    /**
     * Execute a render.
     */
    protected function processRender(string extension, int quality) -> string
    {
        var image;

        let image = this->image;

        image->setFormat(extension);
        image->setImageFormat(extension);
        image->stripImage();

        let this->type = image->getImageType(),
            this->mime = "image/" . image->getImageFormat();

        if strcasecmp(extension, "gif") === 0 {
            image->optimizeImageLayers();
        } else {
            if strcasecmp(extension, "jpg") === 0 || strcasecmp(extension, "jpeg") === 0 {
                image->setImageCompression(
                    constant("Imagick::COMPRESSION_JPEG")
                );
            }

            image->setImageCompressionQuality(quality);
        }

        return image->getImageBlob();
    }

    /**
     * Execute a resize.
     */
    protected function processResize(int width, int height) -> void
    {
        var image;

        let image = this->image;

        image->setIteratorIndex(0);

        loop {
            image->scaleImage(width, height);

            if image->nextImage() === false {
                break;
            }
        }

        let this->width = image->getImageWidth();
        let this->height = image->getImageHeight();
    }

    /**
     * Execute a rotation.
     */
    protected function processRotate(int degrees) -> void
    {
        var pixel;

        this->image->setIteratorIndex(0);

        let pixel = new \ImagickPixel();

        loop {
            this->image->rotateImage(pixel, degrees);

            this->image->setImagePage(
                this->width,
                this->height,
                0,
                0
            );

            if this->image->nextImage() === false {
                break;
            }
        }

        let this->width = this->image->getImageWidth();
        let this->height = this->image->getImageHeight();
    }

    /**
     * Execute a save.
     */
    protected function processSave(string file, int quality) -> void
    {
        var ext, fp;

        let ext = pathinfo(file, PATHINFO_EXTENSION);

        this->image->setFormat(ext);
        this->image->setImageFormat(ext);

        let this->type = this->image->getImageType();
        let this->mime = "image/" . this->image->getImageFormat();

        if strcasecmp(ext, "gif") == 0 {
            this->image->optimizeImageLayers();

            let fp = fopen(file, "w");

            this->image->writeImagesFile(fp);

            fclose(fp);

            return;
        }

        if strcasecmp(ext, "jpg") == 0 || strcasecmp(ext, "jpeg") == 0 {
            this->image->setImageCompression(
                constant("Imagick::COMPRESSION_JPEG")
            );
        }

        if quality >= 0 {
            if quality < 1 {
                let quality = 1;
            } elseif quality > 100 {
                let quality = 100;
            }

            this->image->setImageCompressionQuality(quality);
        }

        this->image->writeImage(file);
    }

    /**
     * Execute a sharpen.
     */
    protected function processSharpen(int amount)
    {
        let amount = (amount < 5) ? 5 : amount;
        let amount = (amount * 3.0) / 100;

        this->image->setIteratorIndex(0);

        loop {
            this->image->sharpenImage(0, amount);

            if this->image->nextImage() === false {
                break;
            }
        }
    }

    /**
     * Execute a text
     */
    protected function processText(string text, var offsetX, var offsetY, int opacity, int r, int g, int b, int size, string fontfile)
    {
        var x, y, draw, color, gravity;

        let opacity = opacity / 100,
            draw = new \ImagickDraw(),
            color = sprintf("rgb(%d, %d, %d)", r, g, b);

        draw->setFillColor(
            new \ImagickPixel(color)
        );

        if fontfile {
            draw->setFont(fontfile);
        }

        if size {
            draw->setFontSize(size);
        }

        if opacity {
            draw->setfillopacity(opacity);
        }

        let gravity = null;

        if typeof offsetX == "boolean" {
            if typeof offsetY == "boolean" {
                let offsetX = 0,
                    offsetY = 0;

                let gravity = constant("Imagick::GRAVITY_CENTER");
            } else {
                if typeof offsetY == "int" {
                    let y = (int) offsetY;

                    if offsetX {
                        if y < 0 {
                            let offsetX = 0,
                                offsetY = y * -1,
                                gravity = constant("Imagick::GRAVITY_SOUTHEAST");
                        } else {
                            let offsetX = 0,
                                gravity = constant("Imagick::GRAVITY_NORTHEAST");
                        }
                    } else {
                        if y < 0 {
                            let offsetX = 0,
                                offsetY = y * -1,
                                gravity = constant("Imagick::GRAVITY_SOUTH");
                        } else {
                            let offsetX = 0,
                                gravity = constant("Imagick::GRAVITY_NORTH");
                        }
                    }
                }
            }
        } else {
            if typeof offsetX == "int" {
                let x = (int) offsetX;

                if offsetX {
                    if typeof offsetY == "boolean" {
                        if offsetY {
                            if x < 0 {
                                let offsetX = x * -1,
                                    offsetY = 0,
                                    gravity = constant("Imagick::GRAVITY_SOUTHEAST");
                            } else {
                                let offsetY = 0,
                                    gravity = constant("Imagick::GRAVITY_SOUTH");
                            }
                        } else {
                            if x < 0 {
                                let offsetX = x * -1,
                                    offsetY = 0,
                                    gravity = constant("Imagick::GRAVITY_EAST");
                            } else {
                                let offsetY = 0,
                                    gravity = constant("Imagick::GRAVITY_WEST");
                            }
                        }
                    } else {
                        if typeof offsetY == "long" {
                            let x = (int) offsetX,
                                y = (int) offsetY;

                            if x < 0 {
                                if y < 0 {
                                    let offsetX = x * -1,
                                        offsetY = y * -1,
                                        gravity = constant("Imagick::GRAVITY_SOUTHEAST");
                                } else {
                                    let offsetX    = x * -1,
                                        gravity = constant("Imagick::GRAVITY_NORTHEAST");
                                }
                            } else {
                                if y < 0 {
                                    let offsetX = 0,
                                        offsetY = y * -1,
                                        gravity = constant("Imagick::GRAVITY_SOUTHWEST");
                                } else {
                                    let offsetX = 0,
                                        gravity = constant("Imagick::GRAVITY_NORTHWEST");
                                }
                            }
                        }
                    }
                }
            }
        }

        draw->setGravity(gravity);

        this->image->setIteratorIndex(0);

        loop {
            this->image->annotateImage(draw, offsetX, offsetY, 0, text);

            if this->image->nextImage() === false {
                break;
            }
        }

        draw->destroy();
    }

    /**
     * Execute a watermarking.
     */
    protected function processWatermark(<AdapterInterface> image, int offsetX, int offsetY, int opacity)
    {
        var watermark, ret;

        let opacity = opacity / 100,
            watermark = new \Imagick();

        watermark->readImageBlob(
            image->render()
        );

        watermark->evaluateImage(
            constant("Imagick::EVALUATE_MULTIPLY"),
            opacity,
            constant("Imagick::CHANNEL_ALPHA")
        );

        this->image->setIteratorIndex(0);

        loop {
            let ret = this->image->compositeImage(
                watermark,
                constant("Imagick::COMPOSITE_OVER"),
                offsetX,
                offsetY
            );

            if unlikely ret !== true {
                throw new Exception("Imagick::compositeImage failed");
            }

            if this->image->nextImage() === false {
                break;
            }
        }

        watermark->clear();
        watermark->destroy();
    }
}
