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

use Imagick as NativeImagick;
use Phalcon\Image\Adapter\Imagick;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Image\Fake\ImagickTrait;

final class SaveTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickSave(): void
    {
        $image = new Imagick(Talon::settings()->outputPath('tests/image/imagick/new.jpg'), 100, 100);
        $image->setResourceLimit(6, 1);
        $image->save();

        $this->assertFileExists(
            Talon::settings()->outputPath('tests/image/imagick/new.jpg')
        );
        $this->safeDeleteFile('new.jpg');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-19
     */
    public function testImageAdapterImagickSaveAnimatedGif(): void
    {
        $image = new Imagick(
            Talon::settings()->supportPath('assets/images/example-gif-animated-horse.gif')
        );

        $target = Talon::settings()->outputPath('tests/image/imagick/animated.gif');

        // reflection() rebuilds the wand, which is where the format was lost
        $image->reflection(50)
              ->save($target)
        ;

        $this->assertFileExists($target);

        // Saving must keep every frame, not flatten the animation
        $saved = new NativeImagick($target);

        $this->assertSame(15, $saved->getNumberImages());

        $this->safeDeleteFile('animated.gif');
    }
}
