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
use Phalcon\Image\Exceptions\ImageTooLarge;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Image\Fake\ImagickTrait;

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
        new Imagick($source, null, null, 100);
    }
}
