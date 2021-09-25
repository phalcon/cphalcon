<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Traits;

use UnitTester;

/**
 * Trait GdTrait
 */
trait GdTrait
{
    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('gd');
    }

    /**
     * @param UnitTester $I
     */
    private function checkJpegSupport(UnitTester $I): void
    {
        if (!$this->hasJpegSupport()) {
            $I->skipTest(
                "Extension 'gd' is compiled without JPEG support."
            );
        }
    }

    /**
     * @return bool
     */
    private function hasJpegSupport(): bool
    {
        $gdInfo = gd_info();

        return !empty($gdInfo['JPEG Support']);
    }

    /**
     * Images to process
     */
    private function getImages(): array
    {
        $images = [
            'png' => dataDir('assets/images/logo.png'),
        ];

        if (true === $this->hasJpegSupport()) {
            $images['jpg'] = dataDir('assets/images/phalconphp.jpg');
        }

        return $images;
    }

    /**
     * @param string $image    path to image
     * @param string $hash     expected hash
     * @param float  $simility percent of similarity
     *
     * @return bool
     */
    private function checkImageHash(string $image, string $hash, float $simility = 70.0): bool
    {
        $imageHash = $this->hashAsString($this->getHash($image));

        return $this->getSimilarityHamming($imageHash, $hash) >= round($simility, 1);
    }


    /**
     * Compare hash strings (no rotation) this assumes the strings will be the
     * same length, which they will be as hashes.
     *
     * @author https://github.com/xwiz/phash
     *
     * @param array|string $hash1
     * @param array|string $hash2
     * @param int          $precision
     *
     * @return float
     */
    private function getSimilarityHamming($hash1, $hash2, int $precision = 1): float
    {
        $percentage = .0;

        if (is_array($hash1)) {
            $similarity = count($hash1);

            // take the hamming distance between the hashes.
            foreach ($hash1 as $key => $val) {
                if ($hash1[$key] != $hash2[$key]) {
                    $similarity--;
                }
            }

            $percentage = round(($similarity / count($hash1) * 100), $precision);
        } elseif (is_string($hash1)) {
            $similarity = strlen($hash1);

            // take the hamming distance between the strings.
            for ($i = 0; $i < strlen($hash1); $i++) {
                if ($hash1[$i] != $hash2[$i]) {
                    $similarity--;
                }
            }

            $percentage = round(($similarity / strlen($hash1) * 100), $precision);
        }

        return $percentage;
    }

    /**
     * @author https://github.com/xwiz/phash
     *
     * @param string $filepath
     *
     * @return array|string
     */
    private function getHash(string $filepath)
    {
        $scale   = 8;
        $product = $scale * $scale;
        $img     = file_get_contents($filepath);
        if (!$img) {
            return 'failed to load ' . $filepath;
        }

        $img = imagecreatefromstring($img);
        if (!$img) {
            // error, unsupported format.
            $supportedFormats = '';
            $needle           = 'Support';
            $needleLen        = strlen($needle);
            foreach (gd_info() as $key => $val) {
                if (!$val || strlen($key) <= $needleLen || substr($key, -$needleLen) !== $needle) {
                    continue;
                }
                $supportedFormats .= trim(substr($key, 0, strlen($key) - $needleLen)) . ', ';
            }
            $supportedFormats = rtrim($supportedFormats, ', ');

            return 'the image format is not supported. supported formats: ' . $supportedFormats;
        }

        // test image for same size
        $width  = imagesx($img);
        $height = imagesy($img);

        if ($width != $scale || $height !== $scale) {
            $img = $this->makeThumbnail($img, $scale, $scale, $width, $height);
        }

        $averageValue = 0;
        $grayscale    = [];

        for ($y = 0; $y < $scale; $y++) {
            for ($x = 0; $x < $scale; $x++) {
                // get the rgb value for current pixel
                $rgb = imagecolorat($img, $x, $y);
                // extract each value for r, g, b
                $red                           = ($rgb & 0xFF0000) >> 16;
                $green                         = ($rgb & 0x00FF00) >> 8;
                $blue                          = ($rgb & 0x0000FF);
                $gray                          = $red + $blue + $green;
                $gray                          /= 12;
                $gray                          = floor($gray);
                $grayscale[$x + ($y * $scale)] = $gray;
                $averageValue                  += $gray;
            }
        }
        $averageValue /= $product;
        $averageValue = floor($averageValue);

        $phash = array_fill(0, $product, 0);
        for ($i = 0; $i < $product; $i++) {
            $rgb = $grayscale[$i];
            if ($rgb >= $averageValue) {
                $this->leftShift($phash, 1, ($product - $i));
            }
        }

        // free memory
        imagedestroy($img);

        return $phash;
    }

    /**
     * @author https://github.com/xwiz/phash
     *
     * @param array $hash
     * @param bool  $hex
     *
     * @return string|null
     */
    private function hashAsString(array $hash, $hex = true): ?string
    {
        $i      = 0;
        $bucket = null;
        $result = null;
        if ($hex == true) {
            foreach ($hash as $bit) {
                $i++;
                $bucket .= $bit;
                if ($i == 4) {
                    $result .= dechex(bindec($bucket));
                    $i      = 0;
                    $bucket = null;
                }
            }

            return $result;
        }

        return implode(null, $hash);
    }

    /**
     * @author https://github.com/xwiz/phash
     *
     * @param $img
     * @param $thumbwidth
     * @param $thumbheight
     * @param $width
     * @param $height
     *
     * @return false|resource
     */
    private function makeThumbnail($img, int $thumbwidth, int $thumbheight, int $width, int $height)
    {
        // Create the image in memory.
        $finalimg = imagecreatetruecolor($thumbwidth, $thumbheight);

        // Fast copy and resize old image into new image.
        $this->fastimagecopyresampled($finalimg, $img, 0, 0, 0, 0, $thumbwidth, $thumbheight, $width, $height);

        // release the source object
        imagedestroy($img);

        return $finalimg;
    }

    /**
     * @author https://github.com/xwiz/phash
     *
     * @param     $dst_image
     * @param     $src_image
     * @param     $dst_x
     * @param     $dst_y
     * @param     $src_x
     * @param     $src_y
     * @param     $dst_w
     * @param     $dst_h
     * @param     $src_w
     * @param     $src_h
     * @param int $quality
     *
     * @return bool
     */
    private function fastimagecopyresampled(
        &$dst_image,
        $src_image,
        $dst_x,
        $dst_y,
        $src_x,
        $src_y,
        $dst_w,
        $dst_h,
        $src_w,
        $src_h,
        $quality = 3
    ): bool {
        // Plug-and-Play fastimagecopyresampled function replaces much slower imagecopyresampled.
        // Just include this function and change all "imagecopyresampled" references to "fastimagecopyresampled".
        // Typically from 30 to 60 times faster when reducing high resolution images down to thumbnail size
        // using the default quality setting.
        // Author: Tim Eckel - Date: 09/07/07 - Version: 1.1 - Project: FreeRingers.net - Freely distributable
        // These comments must remain.
        // Optional "quality" parameter (defaults is 3). Fractional values are allowed,
        // for example 1.5. Must be greater than zero.
        // Between 0 and 1 = Fast, but mosaic results, closer to 0 increases the mosaic effect.
        // 1 = Up to 350 times faster. Poor results, looks very similar to imagecopyresized.
        // 2 = Up to 95 times faster.  Images appear a little sharp, some prefer this over a quality of 3.
        // 3 = Up to 60 times faster.  Will give high quality smooth results very close to imagecopyresampled.
        // 4 = Up to 25 times faster.  Almost identical to imagecopyresampled for most images.
        // 5 = No speedup. Just uses imagecopyresampled, no advantage over imagecopyresampled.

        if (empty($src_image) || empty($dst_image) || $quality <= 0) {
            return false;
        }
        if ($quality < 5 && (($dst_w * $quality) < $src_w || ($dst_h * $quality) < $src_h)) {
            $temp = imagecreatetruecolor($dst_w * $quality + 1, $dst_h * $quality + 1);
            imagecopyresized(
                $temp,
                $src_image,
                0,
                0,
                $src_x,
                $src_y,
                $dst_w * $quality + 1,
                $dst_h * $quality + 1,
                $src_w,
                $src_h
            );
            imagecopyresampled(
                $dst_image,
                $temp,
                $dst_x,
                $dst_y,
                0,
                0,
                $dst_w,
                $dst_h,
                $dst_w * $quality,
                $dst_h * $quality
            );
            imagedestroy($temp);
        } else {
            imagecopyresampled($dst_image, $src_image, $dst_x, $dst_y, $src_x, $src_y, $dst_w, $dst_h, $src_w, $src_h);
        }

        return true;
    }

    /**
     * Performs a left shift on the supplied binary array
     *
     * @author https://github.com/xwiz/phash
     *
     * @param array binary array to perform shift on
     * @param int integer value to shift
     * @param int amount of places to left shift
     */
    private function leftShift(&$bin, $val, $places): void
    {
        if ($places < 1) {
            return;
        }
        $bin[count($bin) - $places] = $val;
    }
}
