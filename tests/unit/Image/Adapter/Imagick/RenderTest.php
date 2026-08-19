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

final class RenderTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickRender(): void
    {
        $source = Talon::settings()->supportPath('assets/images/example-jpg.jpg');
        $image  = new Imagick($source);
        $image->setResourceLimit(6, 1);

        $result = $image->render('jpg', 75);

        $this->assertNotEmpty($result);
        $this->assertIsString($result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-08-02
     */
    public function testImageAdapterImagickRenderDefaultExtension(): void
    {
        $source = Talon::settings()->supportPath('assets/images/example-jpg.jpg');
        $image  = new Imagick($source);
        $image->setResourceLimit(6, 1);

        $result = $image->render();

        $this->assertNotEmpty($result);
        $this->assertIsString($result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-19
     */
    public function testImageAdapterImagickRenderAnimatedGif(): void
    {
        $image = new Imagick(
            Talon::settings()->supportPath('assets/images/example-gif-animated-horse.gif')
        );

        $rendered = new NativeImagick();
        $rendered->readImageBlob($image->render('gif'));

        // Rendering must keep every frame, not return the current one alone
        $this->assertSame(15, $rendered->getNumberImages());

        // reflection() rebuilds the wand, leaving its frames without a format
        $image->reflection(50);

        $reflected = new NativeImagick();
        $reflected->readImageBlob($image->render('gif'));

        $this->assertSame(15, $reflected->getNumberImages());
    }
}
