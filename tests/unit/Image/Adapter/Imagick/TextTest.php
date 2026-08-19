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

final class TextTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickText(): void
    {
        $image = new Imagick(
            Talon::settings()->supportPath('assets/images/example-jpg.jpg')
        );

        $image->setResourceLimit(6, 1);

        $image->text(
            'Phalcon',
            10,
            10,
            100,
            '000099',
            12,
            Talon::settings()->supportPath('assets/fonts/Roboto-Thin.ttf')
        )
              ->save(Talon::settings()->outputPath('tests/image/imagick/text.jpg'))
        ;

        $this->assertFileExists(
            Talon::settings()->outputPath('tests/image/imagick/text.jpg')
        );

        $expected = 1820;
        $actual   = $image->getWidth();
        $this->assertSame($expected, $actual);

        $expected = 694;
        $actual   = $image->getHeight();
        $this->assertSame($expected, $actual);

        $this->safeDeleteFile('text.jpg');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-19
     */
    public function testImageAdapterImagickTextOpacity(): void
    {
        $font = Talon::settings()->supportPath('assets/fonts/Roboto-Thin.ttf');
        $half = new Imagick(Talon::settings()->supportPath('assets/images/example-jpg.jpg'));
        $full = new Imagick(Talon::settings()->supportPath('assets/images/example-jpg.jpg'));

        $half->text('Phalcon', 10, 10, 50, '000099', 12, $font);
        $full->text('Phalcon', 10, 10, 100, '000099', 12, $font);

        // A partly transparent text must not render as fully opaque
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
