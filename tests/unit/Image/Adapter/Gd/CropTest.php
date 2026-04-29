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

namespace Phalcon\Tests\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\GdTrait;

final class CropTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testImageAdapterGdCropJpg(): void
    {
        $this->checkJpegSupport();

        $image = new Gd(supportDir('assets/images/example-jpg.jpg'));

        $outputDir = 'tests/image/gd/';
        $width     = 200;
        $height    = 200;
        $cropImage = 'crop.jpg';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $hash      = 'ffffffb803402030';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height)
              ->save(outputDir($outputDir . '/' . $cropImage))
        ;

        $this->assertFileExists(outputDir($outputDir) . $cropImage);

        $actual = $image->getWidth();
        $this->assertSame($width, $actual);

        $actual = $image->getHeight();
        $this->assertSame($height, $actual);

        $actual = $this->checkImageHash($output, $hash);
        $this->assertTrue($actual);

        $this->safeDeleteFile($cropImage);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-28
     *
     * @issue  16156
     */
    public function testImageAdapterGdCropJpgWithZeroOffset(): void
    {
        $this->checkJpegSupport();

        $source = supportDir('assets/images/example-jpg.jpg');
        $output = outputDir('tests/image/gd/crop-zero-offset.jpg');

        $original = imagecreatefromjpeg($source);
        $expected = imagecolorat($original, 0, 0);
        imagedestroy($original);

        $image = new Gd($source);
        $image->crop(200, 200, 0, 0)->save($output);

        $cropped = imagecreatefromjpeg($output);
        $actual  = imagecolorat($cropped, 0, 0);
        imagedestroy($cropped);

        $this->assertSame(
            $expected,
            $actual,
            'Crop with offset (0,0) must start from the top-left, not the center'
        );

        $this->safeDeleteFile($output);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testImageAdapterGdCropJpgWithOffset(): void
    {
        $this->checkJpegSupport();

        $image = new Gd(supportDir('assets/images/example-jpg.jpg'));

        $outputDir = 'tests/image/gd/';
        $width     = 200;
        $height    = 200;
        $offsetX   = 200;
        $offsetY   = 200;
        $cropImage = 'cropwithoffset.jpg';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $hash      = 'fffff00000000000';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height, $offsetX, $offsetY)
              ->save($output)
        ;

        $this->assertFileExists(outputDir($outputDir) . $cropImage);

        $actual = $image->getWidth();
        $this->assertSame($width, $actual);

        $actual = $image->getHeight();
        $this->assertSame($height, $actual);

        $actual = $this->checkImageHash($output, $hash);
        $this->assertTrue($actual);

        $this->safeDeleteFile($cropImage);
    }
}
