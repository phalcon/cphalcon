
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image\Adapter;

use GdImage;
use Phalcon\Contracts\Image\ImageTypes;
use Phalcon\Image\Enum;
use Phalcon\Image\Exception;
use Phalcon\Image\Exceptions\ExtensionNotLoaded;
use Phalcon\Image\Exceptions\ImageLoadFailed;
use Phalcon\Image\Exceptions\TextRenderingFailed;
use Phalcon\Image\Exceptions\UnsupportedImageType;
use Phalcon\Image\Exceptions\VersionMismatch;
use Phalcon\Traits\Php\FileTrait;
use Phalcon\Traits\Php\InfoTrait;

/**
 * Image manipulation backed by the GD extension.
 *
 * Capabilities:
 *
 * | Aspect              | Support                                     |
 * |---------------------|---------------------------------------------|
 * | Load formats        | GIF, JPEG, JPEG 2000, PNG, WEBP, WBMP, XBM  |
 * | Render/save formats | GIF, JPEG, PNG, WBMP, WEBP, XBM             |
 * | Backend-only API    | none                                        |
 *
 * Unsupported render/save formats raise
 * Phalcon\Image\Exceptions\UnsupportedImageType. Visual semantics differ from
 * the Imagick adapter: blur() applies repeated 3x3 Gaussian convolutions
 * (the radius is the number of passes), while sharpen and reflection use GD's
 * own scales. Switching the factory backend can change the rendered output.
 *
 * @extends AbstractAdapter<GdImage>
 *
 * @phpstan-import-type image_crop_rectangle from ImageTypes
 * @phpstan-import-type image_text_bounds from ImageTypes
 */
class Gd extends AbstractAdapter
{
    use FileTrait;
    use InfoTrait;

    /**
     * Loads an image from a file, or creates a blank canvas.
     *
     * When the file exists it is loaded. When the file does not exist and both
     * a width and a height are supplied, a blank true-color canvas is created
     * instead - its realpath, mime and type then describe a PNG canvas rather
     * than the named file. Prefer Gd::create() for the canvas case; this dual
     * mode is slated for removal in the next major version.
     *
     * @param string   $file
     * @param int|null $width
     * @param int|null $height
     *
     * @throws Exception
     */
    public function __construct(
        string file,
        int width = null,
        int height = null,
        int maxPixels = 0
    ) {
        var image, imageInfo;

        this->check();

        let this->file      = file;
        let this->type      = 0;
        let this->maxPixels = maxPixels > 0 ? maxPixels : self::DEFAULT_MAX_PIXELS;

        if (true === this->phpFileExists(this->file)) {
            let this->realpath = (string) realpath(this->file);
            let imageInfo      = getimagesize(this->file);

            if (false !== imageInfo) {
                /**
                 * Reject an oversized image from its header dimensions before
                 * imagecreatefrom*() allocates the pixel buffer (CWE-409).
                 */
                this->assertPixelLimit((int) imageInfo[0], (int) imageInfo[1]);

                let this->width  = imageInfo[0];
                let this->height = imageInfo[1];
                let this->type   = imageInfo[2];
                let this->mime   = imageInfo["mime"];
            } else {
                throw new ImageLoadFailed(this->file);
            }

            switch (this->type) {
                case IMAGETYPE_GIF:
                    let image = imagecreatefromgif(this->file);
                    break;

                case IMAGETYPE_JPEG:
                case IMAGETYPE_JPEG2000:
                    let image = imagecreatefromjpeg(this->file);
                    break;

                case IMAGETYPE_PNG:
                    let image = imagecreatefrompng(this->file);
                    break;

                case IMAGETYPE_WEBP:
                    let image = imagecreatefromwebp(this->file);
                    break;

                case IMAGETYPE_WBMP:
                    let image = imagecreatefromwbmp(this->file);
                    break;

                case IMAGETYPE_XBM:
                    let image = imagecreatefromxbm(this->file);
                    break;

                default:
                    throw new UnsupportedImageType(this->mime);
            }

            /** @var GdImage $image */
            let this->image = image;

            imagesavealpha(this->image, true);
        } else {
            if (null === width || null === height) {
                throw new ImageLoadFailed(this->file);
            }

            /**
             * @var positive-int $height
             * @var positive-int $width
             */
            let image = imagecreatetruecolor(width, height);

            /** @var GdImage $image */
            let this->image = image;

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
        let this->image = null;
    }

    /**
     * Creates a blank true-color canvas of the given dimensions, without the
     * load-or-create ambiguity of the constructor.
     *
     * @phpstan-return AbstractAdapter<GdImage>
     * @throws Exception
     */
    public static function create(int width, int height) -> <AbstractAdapter>
    {
        return new self("", width, height);
    }

    /**
     * @throws Exception
     */
    public function getVersion() -> string
    {
        var info, matches, reported, version;

        if (true !== this->phpFunctionExists("gd_info")) {
            throw new ExtensionNotLoaded("GD");
        }

        let version = "";

        if (defined("GD_VERSION")) {
            let version = GD_VERSION;
        } else {
            let info    = gd_info();
            let matches = null;

            /** @var string $reported */
            let reported = info["GD Version"];

            if (
                preg_match(
                    "/\\d+\\.\\d+(?:\\.\\d+)?/",
                    reported,
                    matches
                )
            ) {
                let version = matches[0];
            }
        }

        return version;
    }

    protected function processBackground(
        int red,
        int green,
        int blue,
        int opacity
    ) -> void {
        var background, color, copy, image;

        /** @var int<0, 127> $opacity */
        let opacity = (int) round(abs((opacity * 127 / 100) - 127));

        /** @var GdImage $image */
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
            let this->image = background;
        }
    }

    protected function processBlur(int radius) -> void
    {
        var counter, image;

        /** @var GdImage $image */
        let image = this->image;

        let counter = 0;
        while (counter < radius) {
            imagefilter(image, IMG_FILTER_GAUSSIAN_BLUR);

            let counter++;
        }
    }

    /**
     * @phpstan-return GdImage
     */
    protected function processCreate(int width, int height)
    {
        var image;

        /**
         * @var positive-int $height
         * @var positive-int $width
         */
        let image = imagecreatetruecolor(width, height);

        /** @var GdImage $image */
        imagealphablending(image, false);
        imagesavealpha(image, true);

        return image;
    }

    protected function processCrop(
        int width,
        int height,
        int offsetX,
        int offsetY
    ) -> void {
        var current, image;
        array rect;

        /** @var image_crop_rectangle $rect */
        let rect = [
            "x"      : offsetX,
            "y"      : offsetY,
            "width"  : width,
            "height" : height
        ];

        /** @var GdImage $current */
        let current = this->image;

        /** @var GdImage $image */
        let image = imagecrop(current, rect);

        let this->image  = image;
        let this->width  = imagesx(image);
        let this->height = imagesy(image);
    }

    protected function processFlip(int direction) -> void
    {
        var image;

        /** @var GdImage $image */
        let image = this->image;

        if (direction === Enum::HORIZONTAL) {
            imageflip(image, IMG_FLIP_HORIZONTAL);
        } else {
            imageflip(image, IMG_FLIP_VERTICAL);
        }
    }

    protected function processMask(<AdapterInterface> mask)
    {
        var alpha, blue, color, current, height, index, green, maskHeight,
            maskImage, maskWidth, newImage, pixel, red, tempImage, width, x, y;

        /** @var GdImage $maskImage */
        let maskImage = imagecreatefromstring(mask->render());

        /** @var GdImage $current */
        let current = this->image;

        let maskWidth  = (int) imagesx(maskImage);
        let maskHeight = (int) imagesy(maskImage);

        /** @var int<0, 127> $alpha */
        let alpha = 127;

        imagesavealpha(maskImage, true);

        let newImage = this->processCreate(this->width, this->height);

        imagesavealpha(newImage, true);

        /** @var int<0, max> $color */
        let color = imagecolorallocatealpha(
            newImage,
            0,
            0,
            0,
            alpha
        );

        imagefill(newImage, 0, 0, color);

        if (this->width !== maskWidth || this->height !== maskHeight) {
            /** @var positive-int $width */
            let width = this->width;

            /** @var positive-int $height */
            let height = this->height;

            /** @var GdImage $tempImage */
            let tempImage = imagecreatetruecolor(width, height);

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

            let maskImage = tempImage;
        }

        let x = 0;
        while (x < this->width) {
            let y = 0;
            while (y < this->height) {
                /** @var int<0, max> $index */
                let index = imagecolorat(maskImage, x, y);
                let color = imagecolorsforindex(maskImage, index);

                /** @var int<0, 127> $alpha */
                let alpha = 127 - intval(color["red"] / 2);

                /** @var int<0, max> $index */
                let index = imagecolorat(current, x, y);
                let color = imagecolorsforindex(current, index);
                let red   = color["red"];
                let green = color["green"];
                let blue  = color["blue"];

                /** @var int<0, max> $pixel */
                let pixel = imagecolorallocatealpha(
                    newImage,
                    red,
                    green,
                    blue,
                    alpha
                );

                imagesetpixel(newImage, x, y, pixel);

                let y++;
            }

            let x++;
        }

        let this->image = newImage;
    }

    protected function processPixelate(int amount) -> void
    {
        var color, image, x, x1, x2, y, y1, y2;

        /** @var GdImage $image */
        let image = this->image;

        let x = 0;

        while (x < this->width) {
            let y = 0;

            while (y < this->height) {
                let x1 = (int) (x + (amount / 2));
                let y1 = (int) (y + (amount / 2));

                if (x1 >= this->width || y1 >= this->height) {
                    break;
                }

                /** @var int<0, max> $color */
                let color = imagecolorat(image, x1, y1);
                let x2    = x + amount;
                let y2    = y + amount;

                imagefilledrectangle(
                    image,
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

    protected function processReflection(
        int height,
        int opacity,
        bool fadeIn
    ) -> void {
        var image, line, reflection;
        int destinationY, destinationOpacity, offset, stepping, sourceY;

        /** @var int<0, 127> $opacity */
        let opacity = (int) round(abs((opacity * 127 / 100) - 127));

        /** @var GdImage $image */
        let image = this->image;

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
            image,
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
                image,
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

        let this->image  = reflection;
        let this->width  = imagesx(reflection);
        let this->height = imagesy(reflection);
    }

    protected function processRender(string extension, int quality) -> false | string
    {
        var image;

        /** @var GdImage $image */
        let image = this->image;

        let extension = strtolower(extension);

        ob_start();
        switch (extension) {
            case "gif":
                imagegif(image);
                break;
            case "jpg":
            case "jpeg":
                imagejpeg(image, null, quality);
                break;
            case "png":
                imagepng(image);
                break;
            case "wbmp":
                imagewbmp(image);
                break;
            case "webp":
                imagewebp(image);
                break;
            case "xbm":
                imagexbm(image, null);
                break;
            default:
                throw new UnsupportedImageType(extension);
        }

        return ob_get_clean();
    }

    protected function processResize(int width, int height) -> void
    {
        var current, image;

        /** @var GdImage $current */
        let current = this->image;

        /**
         * @var positive-int $height
         * @var positive-int $width
         */
        let image = imagecreatetruecolor(width, height);

        /** @var GdImage $image */
        imagealphablending(image, false);
        imagesavealpha(image, true);
        imagecopyresampled(image, current, 0, 0, 0, 0, width, height, this->width, this->height);

        let this->image  = image;
        let this->width  = imagesx(image);
        let this->height = imagesy(image);
    }

    protected function processRotate(int degrees) -> void
    {
        var copy, current, height, image, transparent, width;

        /** @var GdImage $current */
        let current = this->image;

        /** @var int<0, max> $transparent */
        let transparent = imagecolorallocatealpha(
            current,
            0,
            0,
            0,
            127
        );

        /** @var GdImage $image */
        let image = imagerotate(
            current,
            360 - degrees,
            transparent
        );

        imagesavealpha(image, true);

        let width  = imagesx(image);
        let height = imagesy(image);

        let copy = imagecopymerge(
            current,
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
            let this->image  = image;
            let this->width  = width;
            let this->height = height;
        }
    }

    /**
     * @throws Exception
     */
    protected function processSave(string file, int quality) -> bool
    {
        var extension, image;

        /** @var GdImage $image */
        let image = this->image;

        let extension = pathinfo(file, PATHINFO_EXTENSION);

        // If no extension is given, revert to the original type.
        if (true === empty(extension)) {
            let extension = (string) image_type_to_extension(this->type, false);
        }

        let extension = strtolower(extension);
        switch (extension) {
            case "gif":
                let this->type = IMAGETYPE_GIF;
                imagegif(image, file);
                break;
            case "jpg":
            case "jpeg":
                let this->type = IMAGETYPE_JPEG;

                if (quality >= 0) {
                    let quality = this->checkHighLow(quality, 1);
                    imagejpeg(image, file, quality);
                } else {
                    imagejpeg(image, file);
                }
                break;
            case "png":
                let this->type = IMAGETYPE_PNG;
                imagepng(image, file);
                break;
            case "wbmp":
                let this->type = IMAGETYPE_WBMP;
                imagewbmp(image, file);
                break;
            case "webp":
                let this->type = IMAGETYPE_WEBP;
                imagewebp(image, file);
                break;
            case "xbm":
                let this->type = IMAGETYPE_XBM;
                imagexbm(image, file);
                break;
            default:
                throw new UnsupportedImageType(extension);
        }

        let this->mime = image_type_to_mime_type(this->type);

        return true;
    }

    protected function processSharpen(int amount) -> void
    {
        var image, result;
        array matrix;

        let amount = (int) round(abs(-18 + (amount * 0.08)), 2);

        let matrix = [
            [-1, -1, -1],
            [-1, amount, -1],
            [-1, -1, -1]
        ];

        /** @var GdImage $image */
        let image = this->image;

        let result = imageconvolution(
            image,
            matrix,
            amount - 8,
            0
        );
        if (true === result) {
            let this->width  = imagesx(image);
            let this->height = imagesy(image);
        }
    }

    /**
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
        var angle, bottomLeftX, bottomLeftY, color, height, image, space,
            topRightX, topRightY, width;

        /** @var GdImage $image */
        let image = this->image;

        let bottomLeftX = 0;
        let bottomLeftY = 0;
        let topRightX   = 0;
        let topRightY   = 0;
        let offsetX     = (int) offsetX;
        let offsetY     = (int) offsetY;

        /** @var int<0, 127> $opacity */
        let opacity = (int) round(abs((opacity * 127 / 100) - 127));

        if (true !== empty(fontFile)) {
            /** @var false|image_text_bounds $space */
            let space = imagettfbbox(size, 0, fontFile, text);

            if (false === space) {
                throw new TextRenderingFailed();
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

            /** @var int<0, max> $color */
            let color = imagecolorallocatealpha(
                image,
                red,
                green,
                blue,
                opacity
            );

            let angle = 0;
            imagettftext(
                image,
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

            /** @var int<0, max> $color */
            let color = imagecolorallocatealpha(
                image,
                red,
                green,
                blue,
                opacity
            );

            imagestring(
                image,
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
        var color, image, overlay;
        int height, width;

        /** @var GdImage $overlay */
        let overlay = imagecreatefromstring(watermark->render());

        /** @var GdImage $image */
        let image = this->image;

        imagesavealpha(overlay, true);

        let width  = (int) imagesx(overlay);
        let height = (int) imagesy(overlay);

        if (opacity < 100) {
            /** @var int<0, 127> $opacity */
            let opacity = (int) round(
                abs(
                    (opacity * 127 / 100) - 127
                )
            );

            /** @var int<0, max> $color */
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

        imagealphablending(image, true);

        imagecopy(
            image,
            overlay,
            offsetX,
            offsetY,
            0,
            0,
            width,
            height
        );
    }

    /**
     * Checks the installed version of GD
     *
     * @throws Exception
     */
    private function check() -> void
    {
        var version;

        let version = this->getVersion();

        if (true !== version_compare(version, "2.0.1", ">=")) {
            throw new VersionMismatch(version);
        }
    }
}
