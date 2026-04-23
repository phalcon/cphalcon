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

final class CropTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickCrop(): void
    {
        $image = new Imagick(
            supportDir('assets/images/example-jpg.jpg')
        );

        $image->setResourceLimit(6, 1);

        // Crop the image to 200x200 pixels, from the center
        $image->crop(200, 200)
              ->save(outputDir('tests/image/imagick/crop.jpg'))
        ;

        $this->assertFileExists(
            outputDir('tests/image/imagick/crop.jpg')
        );

        $expected = 200;
        $actual   = $image->getWidth();
        $this->assertSame($expected, $actual);

        $expected = 200;
        $actual   = $image->getHeight();
        $this->assertSame($expected, $actual);

        $this->safeDeleteFile('crop.jpg');
    }
}
