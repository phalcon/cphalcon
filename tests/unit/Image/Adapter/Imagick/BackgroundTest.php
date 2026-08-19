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

final class BackgroundTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickBackground(): void
    {
        $image = new Imagick(
            Talon::settings()->supportPath('assets/images/example-jpg.jpg')
        );

        $image->setResourceLimit(6, 1);

        // Add a watermark to the bottom right of the image
        $image->background('#000')
              ->save(Talon::settings()->outputPath('tests/image/imagick/background.jpg'))
        ;

        $this->assertFileExists(
            Talon::settings()->outputPath('tests/image/imagick/background.jpg')
        );

        $this->assertGreaterThan(
            200,
            $image->getWidth()
        );

        $this->assertGreaterThan(
            200,
            $image->getHeight()
        );

        $this->safeDeleteFile('background.jpg');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-19
     */
    public function testImageAdapterImagickBackgroundOpacity(): void
    {
        // The source needs an alpha channel; an opaque JPEG has nothing to dissolve
        $file = Talon::settings()->supportPath('assets/images/example-png.png');

        $half = new Imagick($file);
        $full = new Imagick($file);

        $half->background('#ff0000', 50);
        $full->background('#ff0000', 100);

        // A percentage below 100 must not collapse onto the opaque result
        $this->assertNotSame(
            $this->imageSignature($full),
            $this->imageSignature($half)
        );
    }

    private function imageSignature(Imagick $image): string
    {
        return $image->getImage()->getImageSignature();
    }
}
