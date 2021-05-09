
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
     * @var bool
     */
    protected static checked = false;

    public function __construct(string! file, int width = null, int height = null)
    {
        var imageinfo;

        if !self::checked {
            self::check();
        }

        let this->file = file;

        if file_exists(this->file) {
            let this->realpath = realpath(this->file);
            let imageinfo = getimagesize(this->file);

            if imageinfo {
                let this->width = imageinfo[0];
                let this->height = imageinfo[1];
                let this->type = imageinfo[2];
                let this->mime = imageinfo["mime"];
            }

            switch this->type {
                case 1:
                    let this->image = imagecreatefromgif(this->file);
                    break;

                case 2:
                    let this->image = imagecreatefromjpeg(this->file);
                    break;

                case 3:
                    let this->image = imagecreatefrompng(this->file);
                    break;

                case 15:
                    let this->image = imagecreatefromwbmp(this->file);
                    break;

                case 16:
                    let this->image = imagecreatefromxbm(this->file);
                    break;

                default:
                    if this->mime {
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
            if unlikely !width || !height {
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

    public function __destruct()
    {
        var image;

        let image = this->image;

        if typeof image  == "resource" {
            imagedestroy(image);
        }
    }

    public static function check() -> bool
    {
        var version;

        if self::checked {
            return true;
        }

        if unlikely !function_exists("gd_info") {
            throw new Exception(
                "GD is either not installed or not enabled, check your configuration"
            );
        }

        let version = self::getVersion();

        if unlikely !version_compare(version, "2.0.1", ">=") {
            throw new Exception(
                "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have " . version
            );
        }

        let self::checked = true;

        return self::checked;
    }

    public static function getVersion() -> string
    {
        var version, info, matches;

        if unlikely !function_exists("gd_info") {
            throw new Exception(
                "GD is either not installed or not enabled, check your configuration"
            );
        }

        let version = null;

        if defined("GD_VERSION") {
            let version = GD_VERSION;
        } else {
            let info = gd_info(),
                matches = null;

            if preg_match("/\\d+\\.\\d+(?:\\.\\d+)?/", info["GD Version"], matches) {
                let version = matches[0];
            }
        }

        return version;
    }

    protected function processBackground(int r, int g, int b, int opacity)
    {
        var background, color;

        let opacity = (int) round(abs((opacity * 127 / 100) - 127));

        let background = this->processCreate(this->width, this->height);

        let color = imagecolorallocatealpha(background, r, g, b, opacity);

        imagealphablending(background, true);

        if imagecopy(background, this->image, 0, 0, 0, 0, this->width, this->height) {
            imagedestroy(this->image);

            let this->image = background;
        }
    }

    protected function processBlur(int radius)
    {
        int i;

        let i = 0;

        while i < radius {
            imagefilter(this->image, IMG_FILTER_GAUSSIAN_BLUR);

            let i++;
        }
    }

    protected function processCreate(int width, int height)
    {
        var image;

        let image = imagecreatetruecolor(width, height);

        imagealphablending(image, false);
        imagesavealpha(image, true);

        return image;
    }

    protected function processCrop(int width, int height, int offsetX, int offsetY)
    {
        var image, rect;

        let rect = [
            "x": offsetX,
            "y": offsetY,

            "width":  width,
            "height": height
        ];

        let image = imagecrop(this->image, rect);

        imagedestroy(this->image);

        let this->image = image;
        let this->width  = imagesx(image);
        let this->height = imagesy(image);
    }

    protected function processFlip(int direction)
    {
        if direction == Enum::HORIZONTAL {
            imageflip(this->image, IMG_FLIP_HORIZONTAL);
        } else {
            imageflip(this->image, IMG_FLIP_VERTICAL);
        }
    }

    protected function processMask(<AdapterInterface> mask)
    {
        var maskImage, newimage, tempImage, color, index, r, g, b;
        int mask_width, mask_height, x, y, alpha;

        let maskImage = imagecreatefromstring(
            mask->render()
        );

        let mask_width  = (int) imagesx(maskImage);
        let mask_height = (int) imagesy(maskImage);
        let alpha = 127;

        imagesavealpha(maskImage, true);

        let newimage = this->processCreate(this->width, this->height);

        imagesavealpha(newimage, true);

        let color = imagecolorallocatealpha(newimage, 0, 0, 0, alpha);

        imagefill(newimage, 0, 0, color);

        if this->width != mask_width || this->height != mask_height {
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
                mask_width,
                mask_height
            );

            imagedestroy(maskImage);

            let maskImage = tempImage;
        }

        let x = 0;

        while x < this->width {
            let y = 0;

            while y < this->height {
                let index = imagecolorat(maskImage, x, y),
                    color = imagecolorsforindex(maskImage, index);

                if isset color["red"] {
                    let alpha = 127 - intval(color["red"] / 2);
                }

                let index = imagecolorat(this->image, x, y),
                    color = imagecolorsforindex(this->image, index),
                    r = color["red"],
                    g = color["green"],
                    b = color["blue"],
                    color = imagecolorallocatealpha(newimage, r, g, b, alpha);

                imagesetpixel(newimage, x, y, color);

                let y++;
            }

            let x++;
        }

        imagedestroy(this->image);
        imagedestroy(maskImage);

        let this->image = newimage;
    }

    protected function processPixelate(int amount)
    {
        var color;
        int x, y, x1, y1, x2, y2;

        let x = 0;

        while x < this->width {
            let y = 0;

            while y < this->height {
                let x1 = x + amount/2;
                let y1 = y + amount/2;

                if (x1 >= this->width || y1 >= this->height) {
                    break;
                }

                let color = imagecolorat(this->image, x1, y1);

                let x2 = x + amount;
                let y2 = y + amount;

                imagefilledrectangle(this->image, x, y, x2, y2, color);

                let y += amount;
            }

            let x += amount;
        }
    }

    protected function processReflection(int height, int opacity, bool fadeIn)
    {
        var reflection, line;
        int stepping, offset, src_y, dst_y, dst_opacity;

        let opacity = (int) round(abs((opacity * 127 / 100) - 127));

        if opacity < 127 {
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

        while height >= offset {
            let src_y = this->height - offset - 1;
            let dst_y = this->height + offset;

            if fadeIn {
                let dst_opacity = (int) round(
                    opacity + (stepping * (height - offset))
                );
            } else {
                let dst_opacity = (int) round(
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
                src_y,
                this->width,
                1
            );

            imagefilter(
                line,
                IMG_FILTER_COLORIZE,
                0,
                0,
                0,
                dst_opacity
            );

            imagecopy(
                reflection,
                line,
                0,
                dst_y,
                0,
                0,
                this->width,
                1
            );

            let offset++;
        }

        imagedestroy(this->image);

        let this->image = reflection;
        let this->width  = imagesx(reflection);
        let this->height = imagesy(reflection);
    }

    protected function processRender(string ext, int quality)
    {
        let ext = strtolower(ext);

        ob_start();

        if strcmp(ext, "gif") == 0 {
            imagegif(this->image);
        } elseif strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0 {
            imagejpeg(this->image, null, quality);
        } elseif strcmp(ext, "png") == 0 {
            imagepng(this->image);
        } elseif strcmp(ext, "wbmp") == 0 {
            imagewbmp(this->image);
        } elseif strcmp(ext, "xbm") == 0 {
            imagexbm(this->image, null);
        } else {
            throw new Exception(
                "Installed GD does not support '" . ext . "' images"
            );
        }

        return ob_get_clean();
    }

    protected function processResize(int width, int height)
    {
        var image;

        let image = imagescale(this->image, width, height);

        imagedestroy(this->image);

        let this->image = image;
        let this->width  = imagesx(image);
        let this->height = imagesy(image);
    }

    protected function processRotate(int degrees)
    {
        var image, transparent, width, height;

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
            transparent,
            1
        );

        imagesavealpha(image, TRUE);

        let width  = imagesx(image);
        let height = imagesy(image);

        if imagecopymerge(this->image, image, 0, 0, 0, 0, width, height, 100) {
            imagedestroy(this->image);

            let this->image = image;
            let this->width  = width;
            let this->height = height;
        }
    }

    protected function processSave(string file, int quality)
    {
        var ext;

        let ext = pathinfo(file, PATHINFO_EXTENSION);

        // If no extension is given, revert to the original type.
        if !ext {
            let ext = image_type_to_extension(this->type, false);
        }

        let ext = strtolower(ext);

        if strcmp(ext, "gif") == 0 {
            let this->type = 1;
            let this->mime = image_type_to_mime_type(this->type);

            imagegif(this->image, file);

            return true;
        }

        if strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0 {
            let this->type = 2;
            let this->mime = image_type_to_mime_type(this->type);

            if quality >= 0 {
                if quality < 1 {
                    let quality = 1;
                } elseif quality > 100 {
                    let quality = 100;
                }

                imagejpeg(this->image, file, quality);
            } else {
                imagejpeg(this->image, file);
            }

            return true;
        }

        if strcmp(ext, "png") == 0 {
            let this->type = 3;
            let this->mime = image_type_to_mime_type(this->type);

            imagepng(this->image, file);

            return true;
        }

        if strcmp(ext, "wbmp") == 0 {
            let this->type = 15;
            let this->mime = image_type_to_mime_type(this->type);

            imagewbmp(this->image, file);

            return true;
        }

        if strcmp(ext, "xbm") == 0 {
            let this->type = 16;
            let this->mime = image_type_to_mime_type(this->type);

            imagexbm(this->image, file);

            return true;
        }

        throw new Exception(
            "Installed GD does not support '" . ext . "' images"
        );
    }

    protected function processSharpen(int amount)
    {
        var matrix;

        let amount = (int) round(abs(-18 + (amount * 0.08)), 2);

        let matrix = [
            [-1,   -1,    -1],
            [-1, amount, -1],
            [-1,   -1,    -1]
        ];

        if imageconvolution(this->image, matrix, amount - 8, 0) {
            let this->width  = imagesx(this->image);
            let this->height = imagesy(this->image);
        }
    }

    protected function processText(
        string text,
        int offsetX,
        int offsetY,
        int opacity,
        int r,
        int g,
        int b,
        int size,
        string fontfile
    ) {
        var space, color, angle;
        int bottomLeftX = 0, bottomLeftY = 0, topRightX = 0, topRightY = 0,
        width, height;

        let opacity = (int) round(abs((opacity * 127 / 100) - 127));

        if fontfile {
            let space = imagettfbbox(size, 0, fontfile, text);

            if false === space {
                throw new Exception("Call to imagettfbbox() failed");
            }

            if isset space[0] {
                let bottomLeftX = (int) space[0],
                    bottomLeftY = (int) space[1],
                    topRightX   = (int) space[4],
                    topRightY   = (int) space[5];
            }

            let width  = abs(topRightX - bottomLeftX) + 10;
            let height = abs(topRightY - bottomLeftY) + 10;

            if offsetX < 0 {
                let offsetX = this->width - width + offsetX;
            }

            if offsetY < 0 {
                let offsetY = this->height - height + offsetY;
            }

            let color = imagecolorallocatealpha(this->image, r, g, b, opacity);

            let angle = 0;

            imagettftext(
                this->image,
                size,
                angle,
                offsetX,
                offsetY,
                color,
                fontfile,
                text
            );
        } else {
            let width  = (int) imagefontwidth(size) * strlen(text);
            let height = (int) imagefontheight(size);

            if offsetX < 0 {
                let offsetX = this->width - width + offsetX;
            }

            if offsetY < 0 {
                let offsetY = this->height - height + offsetY;
            }

            let color = imagecolorallocatealpha(this->image, r, g, b, opacity);

            imagestring(this->image, size, offsetX, offsetY, text, color);
        }
    }

    protected function processWatermark(<AdapterInterface> watermark, int offsetX, int offsetY, int opacity)
    {
        var overlay, color;
        int width, height;

        let overlay = imagecreatefromstring(
            watermark->render()
        );

        imagesavealpha(overlay, true);

        let width  = (int) imagesx(overlay);
        let height = (int) imagesy(overlay);

        if opacity < 100 {
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

        if imagecopy(this->image, overlay, offsetX, offsetY, 0, 0, width, height) {
            imagedestroy(overlay);
        }
    }
}
