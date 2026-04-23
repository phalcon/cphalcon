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
use Phalcon\Image\Enum;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\GdTrait;

use function outputDir;

final class WatermarkTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testImageAdapterGdWatermarkJpgInsideJpg(): void
    {
        $this->checkJpegSupport();

        $image = new Gd(
            supportDir('assets/images/example-jpg.jpg')
        );

        $watermark = new Gd(
            supportDir('assets/images/example-jpg.jpg')
        );
        $watermark->resize(250, null, Enum::WIDTH);

        $outputDir   = 'tests/image/gd/';
        $outputImage = 'watermark.jpg';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $offsetX     = 200;
        $offsetY     = 200;
        $opacity     = 50;

        $hash = 'fbf9f3e3c3c18183';

        // Resize to 200 pixels on the shortest side
        $image->watermark($watermark, $offsetX, $offsetY, $opacity)
              ->save($output)
        ;

        $this->assertFileExists(outputDir($outputDir) . $outputImage);

        $this->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $this->safeDeleteFile($outputImage);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testImageAdapterGdWatermarkJpgInsidePng(): void
    {
        $this->checkJpegSupport();

        $image = new Gd(
            supportDir('assets/images/example-png.png')
        );

        $watermark = new Gd(
            supportDir('assets/images/example-jpg.jpg')
        );
        $watermark->resize(50, 50, Enum::NONE);

        $outputDir   = 'tests/image/gd/';
        $outputImage = 'watermark.png';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $offsetX     = 10;
        $offsetY     = 10;
        $opacity     = 50;

        $hash = '107c7c7c7e1c1818';

        // Resize to 200 pixels on the shortest side
        $image->watermark($watermark, $offsetX, $offsetY, $opacity)
              ->save($output)
        ;

        $this->assertFileExists(outputDir($outputDir) . $outputImage);

        $this->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $this->safeDeleteFile($outputImage);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testImageAdapterGdWatermarkPngInsideJpg(): void
    {
        $this->checkJpegSupport();

        $image = new Gd(
            supportDir('assets/images/example-jpg.jpg')
        );

        $watermark = new Gd(
            supportDir('assets/images/example-png.png')
        );

        $outputDir   = 'tests/image/gd/';
        $outputImage = 'watermark.jpg';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $offsetX     = 200;
        $offsetY     = 200;

        $hash = 'fbf9f3e3c3c18183';

        $image->watermark($watermark, $offsetX, $offsetY)
              ->save($output)
        ;

        $this->assertFileExists(outputDir($outputDir) . $outputImage);

        $this->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $this->safeDeleteFile($outputImage);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testImageAdapterGdWatermarkPngInsidePng(): void
    {
        $image = new Gd(
            supportDir('assets/images/example-png.png')
        );

        $watermark = new Gd(
            supportDir('assets/images/example-png.png')
        );
        $watermark->resize(null, 30, Enum::HEIGHT);

        $outputDir   = 'tests/image/gd/';
        $outputImage = 'watermark.png';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $offsetX     = 20;
        $offsetY     = 20;
        $opacity     = 75;

        $hash = '10787c3c3e181818';

        $image->watermark($watermark, $offsetX, $offsetY, $opacity)
              ->save($output)
        ;

        $this->assertFileExists(outputDir($outputDir) . $outputImage);

        $this->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $this->safeDeleteFile($outputImage);
    }
}
