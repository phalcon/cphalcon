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
use PHPUnit\Framework\Attributes\DataProvider;

use function outputDir;
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
                '30787c3c3f1e3c38',
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
                'Width and height must be specified',
            ],
            [
                Enum::TENSILE,
                199,
                null,
                'Width and height must be specified',
            ],
            [
                Enum::AUTO,
                null,
                199,
                'Width and height must be specified',
            ],
            [
                Enum::AUTO,
                199,
                null,
                'Width and height must be specified',
            ],
            [
                Enum::INVERSE,
                null,
                199,
                'Width and height must be specified',
            ],
            [
                Enum::INVERSE,
                199,
                null,
                'Width and height must be specified',
            ],
            [
                Enum::PRECISE,
                null,
                199,
                'Width and height must be specified',
            ],
            [
                Enum::PRECISE,
                199,
                null,
                'Width and height must be specified',
            ],
            [
                Enum::WIDTH,
                199,
                null,
                'Width must be specified',
            ],
            [
                Enum::HEIGHT,
                null,
                199,
                'Height must be specified',
            ],
        ];
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    #[DataProvider('getExamples')]
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
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    #[DataProvider('getExamplesExceptions')]
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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testImageAdapterGdResizeMasterModes(): void
    {
        $this->checkJpegSupport();

        $source = supportDir('assets/images/example-jpg.jpg');

        $original = new Gd($source);
        $sourceWidth  = $original->getWidth();
        $sourceHeight = $original->getHeight();

        // WIDTH master: width is fixed, height scales to preserve the ratio
        $image = new Gd($source);
        $image->resize(100, null, Enum::WIDTH);
        $this->assertSame(100, $image->getWidth());
        $this->assertSame(
            (int) max(round($sourceHeight * 100 / $sourceWidth), 1),
            $image->getHeight()
        );

        // HEIGHT master: height is fixed, width scales to preserve the ratio
        $image = new Gd($source);
        $image->resize(null, 80, Enum::HEIGHT);
        $this->assertSame(80, $image->getHeight());
        $this->assertSame(
            (int) max(round($sourceWidth * 80 / $sourceHeight), 1),
            $image->getWidth()
        );

        // NONE master: both dimensions are used verbatim
        $image = new Gd($source);
        $image->resize(123, 45, Enum::NONE);
        $this->assertSame(123, $image->getWidth());
        $this->assertSame(45, $image->getHeight());

        // TENSILE master: exact stretch to both dimensions
        $image = new Gd($source);
        $image->resize(111, 33, Enum::TENSILE);
        $this->assertSame(111, $image->getWidth());
        $this->assertSame(33, $image->getHeight());

        // PRECISE master: scales to cover the box, preserving the ratio
        $ratio = $sourceWidth / $sourceHeight;
        if ((120 / 80) > $ratio) {
            $expectedWidth  = 120;
            $expectedHeight = (int) max(round($sourceHeight * 120 / $sourceWidth), 1);
        } else {
            $expectedWidth  = (int) max(round($sourceWidth * 80 / $sourceHeight), 1);
            $expectedHeight = 80;
        }

        $image = new Gd($source);
        $image->resize(120, 80, Enum::PRECISE);
        $this->assertSame($expectedWidth, $image->getWidth());
        $this->assertSame($expectedHeight, $image->getHeight());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-28
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16316
     */
    public function testImageAdapterGdResizePreservesTransparency(): void
    {
        $source = supportDir('assets/images/example-png.png');
        $output = outputDir('tests/image/gd/resize-transparency.png');

        $image = new Gd($source);
        $image->resize(50, 50)->save($output);

        $this->assertFileExists($output);

        $resized = imagecreatefrompng($output);
        imagesavealpha($resized, true);
        $color = imagecolorsforindex($resized, imagecolorat($resized, 0, 0));
        imagedestroy($resized);

        $this->assertSame(127, $color['alpha'], 'Transparent pixel must remain transparent after resize');

        $this->safeDeleteFile($output);
    }
}
