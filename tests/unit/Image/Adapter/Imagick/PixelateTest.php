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

final class PixelateTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickPixelate(): void
    {
        $source = Talon::settings()->supportPath('assets/images/example-jpg.jpg');
        $output = Talon::settings()->outputPath('tests/image/imagick/pixelate.jpg');

        $image = new Imagick($source);
        $image->setResourceLimit(6, 1);

        $image->pixelate(10)
              ->save($output)
        ;

        $this->assertFileExists($output);

        $this->safeDeleteFile($output);
    }
}
