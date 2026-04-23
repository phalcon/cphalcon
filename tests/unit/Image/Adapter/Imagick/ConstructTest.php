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
use Phalcon\Image\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\ImagickTrait;

use function supportDir;

final class ConstructTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-08-02
     */
    public function testImageAdapterImagickConstruct(): void
    {
        $source = supportDir('assets/images/example-jpg.jpg');
        $source = str_replace('/', DIRECTORY_SEPARATOR, $source);
        $image  = new Imagick($source);

        $this->assertInstanceOf(Imagick::class, $image);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-08-02
     */
    public function testImageAdapterImagickConstructNewImage(): void
    {
        $image = new Imagick('new-image.png', 100, 100);

        $this->assertInstanceOf(Imagick::class, $image);

        $expected = 100;
        $actual   = $image->getWidth();
        $this->assertSame($expected, $actual);

        $expected = 100;
        $actual   = $image->getHeight();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-08-02
     */
    public function testImageAdapterImagickConstructNewImageNoDimensionsException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Failed to create image from file non-existing.png');

        new Imagick('non-existing.png');
    }
}
