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
use Phalcon\Image\Enum;
use Phalcon\Image\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\GdTrait;

use function supportDir;

final class ResizeTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                supportDir('assets/images/example-jpg.jpg'),
                'resize.jpg',
                75,
                197,
                'fbf9f3e3c3c1c183',
            ],
            [
                supportDir('assets/images/example-png.png'),
                'resize.jpg',
                50,
                50,
                'bf9f8fc5bf9bc0d0',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getExamplesExceptions(): array
    {
        return [
            [
                Enum::TENSILE,
                null,
                199,
                'width and height must be specified',
            ],
            [
                Enum::TENSILE,
                199,
                null,
                'width and height must be specified',
            ],
            [
                Enum::AUTO,
                null,
                199,
                'width and height must be specified',
            ],
            [
                Enum::AUTO,
                199,
                null,
                'width and height must be specified',
            ],
            [
                Enum::INVERSE,
                null,
                199,
                'width and height must be specified',
            ],
            [
                Enum::INVERSE,
                199,
                null,
                'width and height must be specified',
            ],
            [
                Enum::PRECISE,
                null,
                199,
                'width and height must be specified',
            ],
            [
                Enum::PRECISE,
                199,
                null,
                'width and height must be specified',
            ],
            [
                Enum::WIDTH,
                199,
                null,
                'width must be specified',
            ],
            [
                Enum::HEIGHT,
                null,
                199,
                'height must be specified',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testImageAdapterGdResize(
        string $source,
        string $file,
        int $height,
        int $width,
        string $hash
    ): void {
        $this->checkJpegSupport();

        $outputDir = 'tests/image/gd/';
        $output    = outputDir($outputDir . '/' . $file);

        $image = new Gd($source);

        $image->resize($width, $height)
              ->save($output)
        ;

        $this->assertFileExists(outputDir($outputDir) . $file);

        $actual = $image->getWidth();
        $this->assertSame($width, $actual);

        $actual = $image->getHeight();
        $this->assertSame($height, $actual);

        $actual = $this->checkImageHash($output, $hash);
        $this->assertTrue($actual);

        $this->safeDeleteFile($file);
    }

    /**
     * @dataProvider getExamplesExceptions
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testImageAdapterGdResizeExceptions(
        int $master,
        ?int $height,
        ?int $width,
        string $message
    ): void {
        $this->checkJpegSupport();

        $source = supportDir('assets/images/example-jpg.jpg');
        $image  = new Gd($source);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage($message);
        $image->resize($width, $height, $master);
    }
}
