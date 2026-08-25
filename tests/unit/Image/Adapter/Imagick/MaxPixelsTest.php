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

use Phalcon\Image\Adapter\AbstractAdapter;
use Phalcon\Image\Adapter\Imagick;
use Phalcon\Image\Exceptions\ImageTooLarge;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Image\Fake\ImagickTrait;
use ReflectionProperty;

final class MaxPixelsTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * A generous default still loads normal images.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testImageAdapterImagickMaxPixelsAllowsNormalImage(): void
    {
        $source = Talon::settings()->supportPath('assets/images/example-jpg.jpg');
        $source = str_replace('/', DIRECTORY_SEPARATOR, $source);

        $image = new Imagick($source);

        $this->assertInstanceOf(Imagick::class, $image);
    }

    /**
     * Without an explicit limit the adapter falls back to the default cap
     * instead of leaving the check disabled (CWE-409).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testImageAdapterImagickMaxPixelsFallsBackToDefault(): void
    {
        $source = Talon::settings()->supportPath('assets/images/example-jpg.jpg');
        $source = str_replace('/', DIRECTORY_SEPARATOR, $source);

        $image = new Imagick($source);

        $this->assertSame(
            AbstractAdapter::DEFAULT_MAX_PIXELS,
            $this->getMaxPixels($image)
        );
    }

    /**
     * A zero limit also falls back to the default cap (CWE-409).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testImageAdapterImagickMaxPixelsFallsBackToDefaultOnZero(): void
    {
        $source = Talon::settings()->supportPath('assets/images/example-jpg.jpg');
        $source = str_replace('/', DIRECTORY_SEPARATOR, $source);

        $image = new Imagick($source, null, null, 0);

        $this->assertSame(
            AbstractAdapter::DEFAULT_MAX_PIXELS,
            $this->getMaxPixels($image)
        );
    }

    /**
     * An image whose header dimensions exceed the configured pixel limit is
     * rejected before readImage() decodes the pixel buffer (CWE-409).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testImageAdapterImagickMaxPixelsRejectsOversizedImage(): void
    {
        $source = Talon::settings()->supportPath('assets/images/example-jpg.jpg');
        $source = str_replace('/', DIRECTORY_SEPARATOR, $source);

        $this->expectException(ImageTooLarge::class);
        // The example image is 1820x694 = 1263080 pixels; cap at 100.
        $this->expectExceptionMessage(
            'Image size 1263080 pixels exceeds the maximum allowed 100 pixels'
        );
        new Imagick($source, null, null, 100);
    }

    private function getMaxPixels(Imagick $adapter): int
    {
        $property = new ReflectionProperty(Imagick::class, 'maxPixels');
        $property->setAccessible(true);

        return (int) $property->getValue($adapter);
    }
}
