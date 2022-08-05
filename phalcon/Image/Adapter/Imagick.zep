
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image\Adapter;

use Imagick as ImagickNative;
use ImagickDraw;
use ImagickDrawException;
use ImagickException;
use ImagickPixel;
use ImagickPixelException;
use Phalcon\Image\Enum;
use Phalcon\Image\Exception;

/**
 * Phalcon\Image\Adapter\Imagick
 *
 * Image manipulation support. Resize, rotate, crop etc.
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
     * @var int
     */
    protected version = 0;

    /**
     * Constructor
     *
     * @param string   $file
     * @param int|null $width
     * @param int|null $height
     *
     * @throws Exception
     * @throws ImagickException
     */
    public function __construct(
        string file,
        int width = null,
        int height = null
    ) {
        var image;

        this->check();

        let this->file  = file;
        let this->image = new ImagickNative();

        if (true === file_exists(this->file)) {
            let this->realpath = realpath(this->file);

            if (true !== this->image->readImage(this->realpath)) {
                throw new Exception(
                    "Imagick::readImage " . this->file . " failed"
                );
            }

            if (!this->image->getImageAlphaChannel()) {
                this->image->setImageAlphaChannel(
                    constant("Imagick::ALPHACHANNEL_SET")
                );
            }
            let this->type = this->image->getImageType();

            /**
             * GIF
             */
            if (this->image->getImageType() == IMAGETYPE_GIF) {
                let image = this->image->coalesceImages();

                this->image->clear();
                this->image->destroy();

                let this->image = image;
            }
        } else {
            if (null === width || null === height) {
                throw new Exception(
                    "Failed to create image from file " . this->file
                );
            }

            this->image->newImage(
                width,
                height,
                new ImagickPixel("transparent")
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
        if (this->image instanceof ImagickNative) {
            this->image->clear();
            this->image->destroy();
        }
    }

    /**
     * This method scales the images using liquid rescaling method. Only support
     * Imagick
     *
     * @param int $width    new width
     * @param int $height   new height
     * @param int $deltaX   How much the seam can traverse on x-axis. Passing
     *                      0 causes the seams to be straight.
     * @param int $rigidity Introduces a bias for non-straight seams. This
     *                      parameter is typically 0.
     *
     * @return AbstractAdapter
     * @throws Exception
     * @throws ImagickException
     */
    public function liquidRescale(
        int width,
        int height,
        int deltaX = 0,
        int rigidity = 0
    ) -> <AbstractAdapter> {
        var image, result;

        let image = this->image;

        image->setIteratorIndex(0);

        while (true) {
            let result = image->liquidRescaleImage(
                width,
                height,
                deltaX,
                rigidity
            );

            if (result !== true) {
                throw new Exception("Imagick::liquidRescale failed");
            }

            if (image->nextImage() === false) {
                break;
            }
        }

        let this->width  = image->getImageWidth();
        let this->height = image->getImageHeight();

        return this;
    }

    /**
     * Sets the limit for a particular resource in megabytes
     *
     * @param int $type
     * @param int $limit
     *
     * @return void
     * @throws Exception
     * @throws ImagickException
     *
     * @link https://www.php.net/manual/en/imagick.constants.php#imagick.constants.resourcetypes
     */
    public function setResourceLimit(int type, int limit) -> void
    {
        /**
         * The constants are all integers and are 0-6
         */
        if (type >= 0 && type <= 6) {
            this->image->setResourceLimit(type, limit);
        } else {
            throw new Exception(
                "Cannot set the Resource Type for this image"
            );
        }
    }

    /**
     * Execute a background.
     *
     * @param int $red
     * @param int $green
     * @param int $blue
     * @param int $opacity
     *
     * @return void
     * @throws Exception
     * @throws ImagickException
     * @throws ImagickPixelException
     */
    protected function processBackground(
        int red,
        int green,
        int blue,
        int opacity
    ) -> void {
        var background, color, opacity, pixel1, pixel2, result;

        let opacity    /= 100;
        let color      = sprintf("rgb(%d, %d, %d)", red, green, blue);
        let pixel1     = new ImagickPixel(color);
        let pixel2     = new ImagickPixel("transparent");
        let background = new ImagickNative();

        this->image->setIteratorIndex(0);

        while (true) {
            background->newImage(this->width, this->height, pixel1);

            if (true !== background->getImageAlphaChannel()) {
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

            let result = background->compositeImage(
                this->image,
                constant("Imagick::COMPOSITE_DISSOLVE"),
                0,
                0
            );

            if (true !== result) {
                throw new Exception("Imagick::compositeImage failed");
            }

            if (true !== this->image->nextImage()) {
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
     *
     * @return void
     * @throws ImagickException
     */
    protected function processBlur(int radius) -> void
    {
        this->image->setIteratorIndex(0);

        while (true) {
            this->image->blurImage(radius, 100);

            if (true !== this->image->nextImage()) {
                break;
            }
        }
    }

    /**
     * Execute a crop.
     *
     * @param int $width
     * @param int $height
     * @param int $offsetX
     * @param int $offsetY
     *
     * @return void
     * @throws ImagickException
     */
    protected function processCrop(
        int width,
        int height,
        int offsetX,
        int offsetY
    ) -> void {
        var image;

        let image = this->image;

        image->setIteratorIndex(0);

        while (true) {
            image->cropImage(width, height, offsetX, offsetY);
            image->setImagePage(width, height, 0, 0);

            if (true !== image->nextImage()) {
                break;
            }
        }

        let this->width  = image->getImageWidth();
        let this->height = image->getImageHeight();
    }

    /**
     * Execute a flip.
     *
     * @param int $direction
     *
     * @return void
     * @throws ImagickException
     */
    protected function processFlip(int direction) -> void
    {
        var method;

        let method = (direction === Enum::HORIZONTAL) ? "flipImage" : "flopImage";

        this->image->setIteratorIndex(0);

        while (true) {
            this->image->{method}();

            if (true !== this->image->nextImage()) {
                break;
            }
        }
    }

    /**
     * Composite one image onto another
     *
     * @param AdapterInterface $image
     *
     * @return void
     * @throws Exception
     * @throws ImagickException
     */
    protected function processMask(<AdapterInterface> image) -> void
    {
        var mask, result;

        let mask = new ImagickNative();

        mask->readImageBlob(image->render());
        this->image->setIteratorIndex(0);

        while (true) {
            this->image->setImageMatte(true);

            let result = this->image->compositeImage(
                mask,
                constant("Imagick::COMPOSITE_DSTIN"),
                0,
                0
            );

            if (result !== true) {
                throw new Exception("Imagick::compositeImage failed");
            }

            if (true !== this->image->nextImage()) {
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
     *
     * @return void
     * @throws ImagickException
     */
    protected function processPixelate(int amount) -> void
    {
        var height, width;

        let width  = this->width / amount;
        let height = this->height / amount;

        this->image->setIteratorIndex(0);

        while (true) {
            this->image->scaleImage(width, height);
            this->image->scaleImage(this->width, this->height);

            if (true !== this->image->nextImage()) {
                break;
            }
        }
    }

    /**
     * Execute a reflection.
     *
     * @param int  $height
     * @param int  $opacity
     * @param bool $fadeIn
     *
     * @return void
     * @throws Exception
     * @throws ImagickException
     */
    protected function processReflection(
        int height,
        int opacity,
        bool fadeIn
    ) -> void {
        var fade, image, pixel, pseudo, reflection, result;
        if (this->version >= 30100) {
            let reflection = clone this->image;
        } else {
            let reflection = clone this->image->$clone();
        }

        reflection->setIteratorIndex(0);

        while (true) {
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

            if (true !== this->image->nextImage()) {
                break;
            }
        }

        let pseudo = fadeIn ? "gradient:black-transparent" : "gradient:transparent-black";
        let fade   = new ImagickNative();

        fade->newPseudoImage(
            reflection->getImageWidth(),
            reflection->getImageHeight(),
            pseudo
        );

        let opacity /= 100;
        reflection->setIteratorIndex(0);

        while (true) {
            let result = reflection->compositeImage(
                fade,
                constant("Imagick::COMPOSITE_DSTOUT"),
                0,
                0
            );

            if (result !== true) {
                throw new Exception("Imagick::compositeImage failed");
            }

            reflection->evaluateImage(
                constant("Imagick::EVALUATE_MULTIPLY"),
                opacity,
                constant("Imagick::CHANNEL_ALPHA")
            );

            if (true !== this->image->nextImage()) {
                break;
            }
        }

        fade->destroy();

        let image  = new ImagickNative();
        let pixel  = new ImagickPixel();
        let height = this->image->getImageHeight() + height;

        this->image->setIteratorIndex(0);

        while (true) {
            image->newImage(this->width, height, pixel);

            image->setImageAlphaChannel(
                constant("Imagick::ALPHACHANNEL_SET")
            );

            image->setColorspace(this->image->getColorspace());
            image->setImageDelay(this->image->getImageDelay());
            let result = image->compositeImage(
                this->image,
                constant("Imagick::COMPOSITE_SRC"),
                0,
                0
            );

            if (result !== true) {
                throw new Exception("Imagick::compositeImage failed");
            }

            if (true !== this->image->nextImage()) {
                break;
            }
        }

        image->setIteratorIndex(0);
        reflection->setIteratorIndex(0);

        while (true) {
            let result = image->compositeImage(
                reflection,
                constant("Imagick::COMPOSITE_OVER"),
                0,
                this->height
            );

            if (result !== true) {
                throw new Exception("Imagick::compositeImage failed");
            }

            if (true !== image->nextImage() || true !== reflection->nextImage()) {
                break;
            }
        }

        reflection->destroy();

        this->image->clear();
        this->image->destroy();

        let this->image  = image;
        let this->width  = this->image->getImageWidth();
        let this->height = this->image->getImageHeight();
    }

    /**
     * Execute a render.
     *
     * @param string $extension
     * @param int    $quality
     *
     * @return string
     * @throws ImagickException
     */
    protected function processRender(string extension, int quality) -> string
    {
        var image;

        let image = this->image;

        image->setFormat(extension);
        image->setImageFormat(extension);
        image->stripImage();

        let this->type = image->getImageType();
        let this->mime = "image/" . image->getImageFormat();

        let extension = strtolower(extension);
        switch (extension) {
            case "gif":
                image->optimizeImageLayers();
                break;
            case "jpg":
            case "jpeg":
                image->setImageCompression(
                    constant("Imagick::COMPRESSION_JPEG")
                );

                image->setImageCompressionQuality(quality);
        }

        return image->getImageBlob();
    }

    /**
     * Execute a resize.
     *
     * @param int $width
     * @param int $height
     *
     * @return void
     * @throws ImagickException
     */
    protected function processResize(int width, int height) -> void
    {
        var image;

        let image = this->image;
        image->setIteratorIndex(0);

        while (true) {
            image->scaleImage(width, height);

            if (true !== image->nextImage()) {
                break;
            }
        }

        let this->width  = image->getImageWidth();
        let this->height = image->getImageHeight();
    }

    /**
     * Execute a rotation.
     *
     * @param int $degrees
     *
     * @return void
     * @throws ImagickException
     */
    protected function processRotate(int degrees) -> void
    {
        var pixel;

        this->image->setIteratorIndex(0);

        let pixel = new ImagickPixel();

        while (true) {
            this->image->rotateImage(pixel, degrees);

            this->image->setImagePage(
                this->width,
                this->height,
                0,
                0
            );

            if (true !== this->image->nextImage()) {
                break;
            }
        }

        let this->width  = this->image->getImageWidth();
        let this->height = this->image->getImageHeight();
    }

    /**
     * Execute a save.
     *
     * @param string $file
     * @param int    $quality
     *
     * @return void
     * @throws ImagickException
     */
    protected function processSave(string file, int quality) -> void
    {
        var extension, fp;

        let extension = pathinfo(file, PATHINFO_EXTENSION);

        this->image->setFormat(extension);
        this->image->setImageFormat(extension);

        let this->type = this->image->getImageType();
        let this->mime = "image/" . this->image->getImageFormat();

        let extension = strtolower(extension);
        switch (extension) {
            case "gif":
                this->image->optimizeImageLayers();
                let fp = fopen(file, "w");

                this->image->writeImagesFile(fp);

                fclose(fp);

                return;
            case "jpg":
            case "jpeg":
                this->image->setImageCompression(
                    constant("Imagick::COMPRESSION_JPEG")
                );
        }

        if (quality >= 0) {
            let quality = this->checkHighLow(quality, 1);
            this->image->setImageCompressionQuality(quality);
        }

        this->image->writeImage(file);
    }

    /**
     * Execute a sharpen.
     *
     * @param int $amount
     *
     * @return void
     * @throws ImagickException
     */
    protected function processSharpen(int amount) -> void
    {
        let amount = (amount < 5) ? 5 : amount;
        let amount = (amount * 3.0) / 100;

        this->image->setIteratorIndex(0);

        while (true) {
            this->image->sharpenImage(0, amount);

            if (true !== this->image->nextImage()) {
                break;
            }
        }
    }

    /**
     * Execute a text
     *
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
     * @throws ImagickDrawException
     * @throws ImagickException
     * @throws ImagickPixelException
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
        var color, draw, gravity, x, y;

        let opacity = opacity / 100;
        let draw    = new ImagickDraw();
        let color   = sprintf("rgb(%d, %d, %d)", red, green, blue);

        draw->setFillColor(new ImagickPixel(color));

        if (null !== fontFile) {
            draw->setFont(fontFile);
        }

        if (size) {
            draw->setFontSize(size);
        }

        if (opacity) {
            draw->setfillopacity(opacity);
        }

        let gravity = null;
        if (typeof offsetX === "boolean") {
            if (typeof offsetY === "boolean") {
                let offsetX = 0;
                let offsetY = 0;
                let gravity = constant("Imagick::GRAVITY_CENTER");
            } elseif (typeof offsetY === "int") {
                let y = (int) offsetY;

                let gravity = (true === offsetX && y < 0) ? constant("Imagick::GRAVITY_SOUTHEAST") : gravity;
                let gravity = (true === offsetX && y >= 0) ? constant("Imagick::GRAVITY_NORTHEAST") : gravity;
                let gravity = (true !== offsetX && y < 0) ? constant("Imagick::GRAVITY_SOUTH") : gravity;
                let gravity = (true !== offsetX && y >= 0) ? constant("Imagick::GRAVITY_NORTH") : gravity;

                let offsetX = 0;
                let offsetY = (y < 0) ? y * -1 : offsetY;
            }
        } elseif (typeof offsetX === "int") {
            let x = (int) offsetX;

            if (offsetX) {
                if (typeof offsetY === "boolean") {
                    let gravity = (true === offsetY && x < 0) ? constant("Imagick::GRAVITY_SOUTHEAST") : gravity;
                    let gravity = (true === offsetY && x >= 0) ? constant("Imagick::GRAVITY_SOUTH") : gravity;
                    let gravity = (true !== offsetY && x < 0) ? constant("Imagick::GRAVITY_EAST") : gravity;
                    let gravity = (true !== offsetY && x >= 0) ? constant("Imagick::GRAVITY_WEST") : gravity;

                    let offsetY = 0;
                    let offsetX = (x < 0) ? x * -1 : offsetX;
                } elseif (typeof offsetY === "long") {
                    let y = (int) offsetY;

                    let offsetX = (x < 0) ? x * -1 : 0;
                    let offsetY = (y < 0) ? y * -1 : offsetY;

                    let gravity = (y < 0) ? constant("Imagick::GRAVITY_SOUTHEAST") : gravity;
                    let gravity = (y >= 0) ? constant("Imagick::GRAVITY_NORTHEAST") : gravity;
                }
            }
        }

        if (null !== gravity) {
            draw->setGravity(gravity);
        }

        this->image->setIteratorIndex(0);

        while (true) {
            this->image->annotateImage(draw, offsetX, offsetY, 0, text);

            if (true !== this->image->nextImage()) {
                break;
            }
        }

        draw->destroy();
    }

    /**
     * Add Watermark
     *
     * @param AdapterInterface $image
     * @param int              $offsetX
     * @param int              $offsetY
     * @param int              $opacity
     *
     * @return void
     * @throws Exception
     * @throws ImagickException
     */
    protected function processWatermark(
        <AdapterInterface> image,
        int offsetX,
        int offsetY,
        int opacity
    ) -> void {
        var result, watermark;

        let opacity   = opacity / 100;
        let watermark = new ImagickNative();

        watermark->readImageBlob(image->render());
        watermark->evaluateImage(
            constant("Imagick::EVALUATE_MULTIPLY"),
            opacity,
            constant("Imagick::CHANNEL_ALPHA")
        );

        this->image->setIteratorIndex(0);

        while (true) {
            let result = this->image->compositeImage(
                watermark,
                constant("Imagick::COMPOSITE_OVER"),
                offsetX,
                offsetY
            );

            if (result !== true) {
                throw new Exception("Imagick::compositeImage failed");
            }

            if (true !== this->image->nextImage()) {
                break;
            }
        }

        watermark->clear();
        watermark->destroy();
    }

    /**
     * Checks if Imagick is enabled
     *
     * @return void
     * @throws Exception
     */
    private function check() -> void
    {
        if (true !== class_exists("imagick")) {
            throw new Exception(
                "Imagick is not installed, or the extension is not loaded"
            );
        }

        if (defined("Imagick::IMAGICK_EXTNUM")) {
            let this->version = constant("Imagick::IMAGICK_EXTNUM");
        }
    }
}
