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
use Phalcon\Image\Exceptions\ImageTooLarge;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\GdTrait;

final class MaxPixelsTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * An image whose header dimensions exceed the configured pixel limit is
     * rejected before the pixel buffer is allocated (CWE-409).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testImageAdapterGdMaxPixelsRejectsOversizedImage(): void
    {
        $image = $this->getImages()['png'];

        $this->expectException(ImageTooLarge::class);
        // The example image is 82x82 = 6724 pixels; cap at 100.
        new Gd($image, null, null, 100);
    }

    /**
     * A generous default still loads normal images.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testImageAdapterGdMaxPixelsAllowsNormalImage(): void
    {
        $image = $this->getImages()['png'];

        $gd = new Gd($image);

        $this->assertInstanceOf(Gd::class, $gd);
    }
}
