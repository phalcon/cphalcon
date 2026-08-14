
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
use Phalcon\Image\Exceptions\CompositeFailed;
use Phalcon\Image\Exceptions\ExtensionNotLoaded;
use Phalcon\Image\Exceptions\ImageLoadFailed;
use Phalcon\Image\Exceptions\ResizeFailed;
use Phalcon\Image\Exceptions\ResourceTypeError;
use Phalcon\Traits\Php\FileTrait;

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
 *
 * Capabilities:
 *
 * | Aspect              | Support                                        |
 * |---------------------|------------------------------------------------|
 * | Load formats        | Whatever the linked ImageMagick build supports |
 * | Render/save formats | Whatever the linked ImageMagick build supports |
 * | Backend-only API    | liquidRescale(), setResourceLimit()            |
 *
 * Visual semantics differ from the Gd adapter: blur() maps the radius to a
 * blur sigma, while sharpen and reflection use ImageMagick's own scales.
 * Switching the factory backend can change the rendered output.
 *
 * @extends AbstractAdapter<ImagickNative>
 */
class Imagick extends AbstractAdapter
{
    use FileTrait;

    protected int version = 0;

    /**
     * Loads an image from a file, or creates a blank canvas.
     *
     * When the file exists it is loaded. When the file does not exist and both
     * a width and a height are supplied, a blank transparent canvas is created
     * instead - its realpath, mime and type then describe a PNG canvas rather
     * than the named file. Prefer Imagick::create() for the canvas case; this
     * dual mode is slated for removal in the next major version.
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

        if (true === this->phpFileExists(this->file)) {
            let this->realpath = (string) realpath(this->file);

            if (true !== this->image->readImage(this->realpath)) {
                throw new ImageLoadFailed(this->file);
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
                throw new ImageLoadFailed(this->file);
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
     * Creates a blank transparent canvas of the given dimensions, without the
     * load-or-create ambiguity of the constructor.
     *
     * @phpstan-return AbstractAdapter<ImagickNative>
     * @throws Exception
     * @throws ImagickException
     */
    public static function create(int width, int height) -> <AbstractAdapter>
    {
        return new self("", width, height);
    }

    /**
     * This method scales the images using liquid rescaling method. Only support
     * Imagick
     *
     * @phpstan-return AbstractAdapter<ImagickNative>
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

        /** @var ImagickNative $image */
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
                throw new ResizeFailed();
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
        var image;

        /** @var ImagickNative $image */
        let image = this->image;

        /**
         * The constants are all integers and are 0-6
         */
        if (type >= 0 && type <= 6) {
            image->setResourceLimit(type, limit);
        } else {
            throw new ResourceTypeError();
        }
    }

    /**
     * Execute a background.
     *
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
        var background, color, image, localOpacity, pixel1, pixel2, result;

        let localOpacity  = opacity;
        let localOpacity /= 100;
        let color         = sprintf("rgb(%d, %d, %d)", red, green, blue);
        let pixel1        = new ImagickPixel(color);
        let pixel2        = new ImagickPixel("transparent");
        let background    = new ImagickNative();

        /** @var ImagickNative $image */
        let image = this->image;

        image->setIteratorIndex(0);

        while (true) {
            background->newImage(this->width, this->height, pixel1);

            try {
                if (true !== background->getImageAlphaChannel()) {
                    background->setImageAlphaChannel(
                        constant("Imagick::ALPHACHANNEL_SET")
                    );
                }
            } catch ImagickException {
                throw new Exception("Imagick::getImageAlphaChannel failed");
            }

            background->setImageBackgroundColor(pixel2);

            background->evaluateImage(
                constant("Imagick::EVALUATE_MULTIPLY"),
                localOpacity,
                constant("Imagick::CHANNEL_ALPHA")
            );

            background->setColorspace(
                image->getColorspace()
            );

            let result = background->compositeImage(
                image,
                constant("Imagick::COMPOSITE_DISSOLVE"),
                0,
                0
            );

            if (true !== result) {
                throw new CompositeFailed();
            }

            if (true !== image->nextImage()) {
                break;
            }
        }

        image->clear();
        image->destroy();

        let this->image = background;
    }

    /**
     * Blur image
     *
     * @throws ImagickException
     */
    protected function processBlur(int radius) -> void
    {
        var image;

        /** @var ImagickNative $image */
        let image = this->image;

        image->setIteratorIndex(0);

        while (true) {
            image->blurImage(radius, 100);

            if (true !== image->nextImage()) {
                break;
            }
        }
    }

    /**
     * Execute a crop.
     *
     * @throws ImagickException
     */
    protected function processCrop(
        int width,
        int height,
        int offsetX,
        int offsetY
    ) -> void {
        var image;

        /** @var ImagickNative $image */
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
     * @throws ImagickException
     */
    protected function processFlip(int direction) -> void
    {
        var image, method;

        let method = (direction === Enum::HORIZONTAL) ? "flipImage" : "flopImage";

        /** @var ImagickNative $image */
        let image = this->image;

        image->setIteratorIndex(0);

        while (true) {
            image->{method}();

            if (true !== image->nextImage()) {
                break;
            }
        }
    }

    /**
     * Composite one image onto another
     *
     * @throws Exception
     * @throws ImagickException
     */
    protected function processMask(<AdapterInterface> mask) -> void
    {
        var current, image, result;

        let image = new ImagickNative();

        /** @var ImagickNative $current */
        let current = this->image;

        image->readImageBlob(mask->render());
        current->setIteratorIndex(0);

        while (true) {
            current->setImageMatte(true);

            let result = current->compositeImage(
                image,
                constant("Imagick::COMPOSITE_DSTIN"),
                0,
                0
            );

            if (result !== true) {
                throw new CompositeFailed();
            }

            if (true !== current->nextImage()) {
                break;
            }
        }

        image->clear();
        image->destroy();
    }

    /**
     * Pixelate image
     *
     * @throws ImagickException
     */
    protected function processPixelate(int amount) -> void
    {
        var height, image, width;

        let width  = (int) (this->width / amount);
        let height = (int) (this->height / amount);

        /** @var ImagickNative $image */
        let image = this->image;

        image->setIteratorIndex(0);

        while (true) {
            image->scaleImage(width, height);
            image->scaleImage(this->width, this->height);

            if (true !== image->nextImage()) {
                break;
            }
        }
    }

    /**
     * Execute a reflection.
     *
     * @throws Exception
     * @throws ImagickException
     */
    protected function processReflection(
        int height,
        int opacity,
        bool fadeIn
    ) -> void {
        var current, fade, image, pixel, pseudo, reflection, result;

        /** @var ImagickNative $current */
        let current = this->image;

        if (this->version >= 30100) {
            let reflection = clone current;
        } else {
            let reflection = clone current->$clone();
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

            if (true !== current->nextImage()) {
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
                throw new CompositeFailed();
            }

            reflection->evaluateImage(
                constant("Imagick::EVALUATE_MULTIPLY"),
                opacity,
                constant("Imagick::CHANNEL_ALPHA")
            );

            // @phpstan-ignore notIdentical.alwaysTrue (the frame cursor is internal to Imagick)
            if (true !== current->nextImage()) {
                break;
            }
        }

        fade->destroy();

        let image  = new ImagickNative();
        let pixel  = new ImagickPixel();
        let height = current->getImageHeight() + height;

        current->setIteratorIndex(0);

        while (true) {
            image->newImage(this->width, height, pixel);

            image->setImageAlphaChannel(
                constant("Imagick::ALPHACHANNEL_SET")
            );

            image->setColorspace(current->getColorspace());
            image->setImageDelay(current->getImageDelay());
            let result = image->compositeImage(
                current,
                constant("Imagick::COMPOSITE_SRC"),
                0,
                0
            );

            if (result !== true) {
                throw new CompositeFailed();
            }

            // @phpstan-ignore notIdentical.alwaysTrue (the frame cursor is internal to Imagick)
            if (true !== current->nextImage()) {
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
                throw new CompositeFailed();
            }

            if (true !== image->nextImage() || true !== reflection->nextImage()) {
                break;
            }
        }

        reflection->destroy();

        current->clear();
        current->destroy();

        let this->image  = image;
        let this->width  = image->getImageWidth();
        let this->height = image->getImageHeight();
    }

    /**
     * Execute a render.
     *
     * @throws ImagickException
     */
    protected function processRender(string extension, int quality) -> string
    {
        var image;

        /** @var ImagickNative $image */
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
     * @throws ImagickException
     */
    protected function processResize(int width, int height) -> void
    {
        var image;

        /** @var ImagickNative $image */
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
     * @throws ImagickException
     */
    protected function processRotate(int degrees) -> void
    {
        var image, pixel;

        /** @var ImagickNative $image */
        let image = this->image;

        image->setIteratorIndex(0);

        let pixel = new ImagickPixel();

        while (true) {
            image->rotateImage(pixel, degrees);

            image->setImagePage(
                this->width,
                this->height,
                0,
                0
            );

            if (true !== image->nextImage()) {
                break;
            }
        }

        let this->width  = image->getImageWidth();
        let this->height = image->getImageHeight();
    }

    /**
     * Execute a save.
     *
     * @throws ImagickException
     */
    protected function processSave(string file, int quality) -> bool
    {
        var extension, fp, image;

        /** @var ImagickNative $image */
        let image = this->image;

        let extension = pathinfo(file, PATHINFO_EXTENSION);

        image->setFormat(extension);
        image->setImageFormat(extension);

        let this->type = image->getImageType();
        let this->mime = "image/" . image->getImageFormat();

        let extension = strtolower(extension);
        switch (extension) {
            case "gif":
                image->optimizeImageLayers();

                /** @var resource $fp */
                let fp = this->phpFopen(file, "w");

                image->writeImagesFile(fp);

                this->phpFclose(fp);

                return;
            case "jpg":
            case "jpeg":
                image->setImageCompression(
                    constant("Imagick::COMPRESSION_JPEG")
                );
        }

        if (quality >= 0) {
            let quality = this->checkHighLow(quality, 1);
            image->setImageCompressionQuality(quality);
        }

        image->writeImage(file);

        return true;
    }

    /**
     * Execute a sharpen.
     *
     * @throws ImagickException
     */
    protected function processSharpen(int amount) -> void
    {
        var image;

        let amount = (amount < 5) ? 5 : amount;
        let amount = (amount * 3.0) / 100;

        /** @var ImagickNative $image */
        let image = this->image;

        image->setIteratorIndex(0);

        while (true) {
            image->sharpenImage(0, amount);

            if (true !== image->nextImage()) {
                break;
            }
        }
    }

    /**
     * Execute a text
     *
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
        var color, draw, gravity, image, x, y;

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

        /** @var ImagickNative $image */
        let image = this->image;

        image->setIteratorIndex(0);

        while (true) {
            // @phpstan-ignore argument.type (offsetY stays boolean when offsetX is 0)
            image->annotateImage(draw, offsetX, offsetY, 0, text);

            if (true !== image->nextImage()) {
                break;
            }
        }

        draw->destroy();
    }

    /**
     * Add Watermark
     *
     * @throws Exception
     * @throws ImagickException
     */
    protected function processWatermark(
        <AdapterInterface> watermark,
        int offsetX,
        int offsetY,
        int opacity
    ) -> void {
        var current, image, result;

        let opacity = opacity / 100;
        let image   = new ImagickNative();

        image->readImageBlob(watermark->render());
        image->evaluateImage(
            constant("Imagick::EVALUATE_MULTIPLY"),
            opacity,
            constant("Imagick::CHANNEL_ALPHA")
        );

        /** @var ImagickNative $current */
        let current = this->image;

        current->setIteratorIndex(0);

        while (true) {
            let result = current->compositeImage(
                image,
                constant("Imagick::COMPOSITE_OVER"),
                offsetX,
                offsetY
            );

            if (result !== true) {
                throw new CompositeFailed();
            }

            if (true !== current->nextImage()) {
                break;
            }
        }

        image->clear();
        image->destroy();
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
            throw new ExtensionNotLoaded("Imagick");
        }

        if (defined("Imagick::IMAGICK_EXTNUM")) {
            let this->version = constant("Imagick::IMAGICK_EXTNUM");
        }
    }
}
