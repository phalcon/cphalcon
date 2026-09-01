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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Image\Fake\ImagickTrait;

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
            Talon::settings()->supportPath('assets/images/example-jpg.jpg')
        );

        $image->setResourceLimit(6, 1);

        $mark = new Imagick(
            Talon::settings()->supportPath('assets/images/example-png.png')
        );

        // Add a watermark to the bottom right of the image
        $image->watermark($mark, 10, 10)
              ->save(Talon::settings()->outputPath('tests/image/imagick/watermark.jpg'))
        ;

        $this->assertFileExists(
            Talon::settings()->outputPath('tests/image/imagick/watermark.jpg')
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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-19
     */
    public function testImageAdapterImagickWatermarkOpacity(): void
    {
        $plain  = new Imagick(Talon::settings()->supportPath('assets/images/example-jpg.jpg'));
        $marked = new Imagick(Talon::settings()->supportPath('assets/images/example-jpg.jpg'));

        $marked->watermark(new Imagick(Talon::settings()->supportPath('assets/images/example-png.png')), 10, 10, 50);

        // A partly transparent watermark must still change the image
        $this->assertNotSame(
            $this->imageSignature($plain),
            $this->imageSignature($marked)
        );
    }

    private function imageSignature(Imagick $image): string
    {
        return $image->getImage()->getImageSignature();
    }
}
