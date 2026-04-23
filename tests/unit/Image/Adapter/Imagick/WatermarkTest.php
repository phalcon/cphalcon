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

namespace Phalcon\Tests\Unit\Image\Adapter\Imagick;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\ImagickTrait;

use function outputDir;
use function supportDir;

final class WatermarkTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickWatermark(): void
    {
        $image = new Imagick(
            supportDir('assets/images/example-jpg.jpg')
        );

        $image->setResourceLimit(6, 1);

        $mark = new Imagick(
            supportDir('assets/images/example-png.png')
        );

        // Add a watermark to the bottom right of the image
        $image->watermark($mark, 10, 10)
              ->save(outputDir('tests/image/imagick/watermark.jpg'))
        ;

        $this->assertFileExists(
            outputDir('tests/image/imagick/watermark.jpg')
        );

        $this->assertGreaterThan(
            200,
            $image->getWidth()
        );

        $this->assertGreaterThan(
            200,
            $image->getHeight()
        );

        $this->safeDeleteFile('watermark.jpg');
    }
}
