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

final class ReflectionTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickReflection(): void
    {
        $image = new Imagick(
            Talon::settings()->supportPath('assets/images/example-jpg.jpg')
        );

        $image->setResourceLimit(6, 1);

        // Create a 50 pixel reflection that fades from 0-100% opacity
        $image->reflection(50)
              ->save(Talon::settings()->outputPath('tests/image/imagick/reflection.jpg'))
        ;

        $this->assertFileExists(
            Talon::settings()->outputPath('tests/image/imagick/reflection.jpg')
        );

        $this->assertGreaterThan(
            200,
            $image->getWidth()
        );

        $this->assertGreaterThan(
            200,
            $image->getHeight()
        );

        $this->safeDeleteFile('reflection.jpg');
    }
}
