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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\GdTrait;

use function outputDir;
use function supportDir;

final class TextTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                1,
                'Hello Phalcon!',
                false,
                false,
                100,
                '000000',
                12,
                null,
                'fbf9f3e3c3c18183',
            ],
            [
                2,
                'Hello Phalcon!',
                50,
                false,
                100,
                '000000',
                12,
                null,
                'fbf9f3e3c3c18183',
            ],
            [
                3,
                'Hello Phalcon!',
                50,
                75,
                100,
                '000000',
                12,
                null,
                'fbf9f3e3c3c18183',
            ],
            [
                4,
                'Hello Phalcon!',
                50,
                75,
                60,
                '000000',
                12,
                null,
                'fbf9f3e3c3c18183',
            ],
            [
                5,
                'Hello Phalcon!',
                50,
                75,
                60,
                '00FF00',
                12,
                null,
                'fbf9f3e3c3c18183',
            ],
            [
                6,
                'Hello Phalcon!',
                50,
                75,
                60,
                '0000FF',
                24,
                null,
                'fbf9f3e3c3c18183',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testImageAdapterGdText(
        int $index,
        string $text,
        bool | int $offsetX,
        bool | int $offsetY,
        int $opacity,
        string $color,
        int $size,
        ?string $font,
        string $hash
    ): void {
        $this->checkJpegSupport();

        $outputDir   = 'tests/image/gd/';
        $image       = new Gd(supportDir('assets/images/example-jpg.jpg'));
        $outputImage = $index . 'text.jpg';
        $output      = outputDir($outputDir . '/' . $outputImage);

        $image
            ->text(
                $text,
                $offsetX,
                $offsetY,
                $opacity,
                $color,
                $size,
                $font
            )
            ->save($output)
        ;

        $this->assertFileExists(outputDir($outputDir) . $outputImage);

        $this->assertTrue($this->checkImageHash($output, $hash));
        $this->safeDeleteFile($outputImage);
    }

    /**
     * @issue  15188
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     */
    public function testImageAdapterGdTextWithFont(): void
    {
        $this->checkJpegSupport();

        $outputDir = 'tests/image/gd/';

        $image       = supportDir('assets/images/example-jpg.jpg');
        $outputImage = '15188-text.jpg';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $text        = 'Hello Phalcon!';
        $offsetX     = 50;
        $offsetY     = 75;
        $opacity     = 60;
        $color       = '0000FF';
        $size        = 24;
        $font        = supportDir('assets/fonts/Roboto-Light.ttf');
        $hash        = 'fbf9f3e3c3c18183';

        $object = new Gd($image);
        $object
            ->text($text, $offsetX, $offsetY, $opacity, $color, $size, $font)
            ->save($output)
        ;

        $this->assertFileExists(outputDir($outputDir) . $outputImage);

        $this->assertTrue($this->checkImageHash($output, $hash));
        $this->safeDeleteFile($outputImage);
    }
}
