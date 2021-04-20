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

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;
use function dataDir;
use function outputDir;

class TextCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: text()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdText(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - text()');

        $this->checkJpegSupport($I);

        $outputDir = 'tests/image/gd';

        $params = [
            [
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

        $i = 0;

        foreach ($params as [$text, $offsetX, $offsetY, $opacity, $color, $size, $font, $hash]) {
            $image = new Gd(
                dataDir('assets/images/phalconphp.jpg')
            );

            $outputImage = $i++ . 'text.jpg';
            $output      = outputDir($outputDir . '/' . $outputImage);

            //imagettfbbox ( float $size , float $angle , string $fontfile , string $text ) : array
            $image->text($text, $offsetX, $offsetY, $opacity, $color, $size, $font)
                  ->save($output)
            ;

            $I->amInPath(outputDir($outputDir));
            $I->seeFileFound($outputImage);

            $I->assertTrue($this->checkImageHash($output, $hash));
            $I->safeDeleteFile($outputImage);
        }
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: text()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     * @issue  15188
     */
    public function imageAdapterGdTextWithFont(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - text() - with font');

        $this->checkJpegSupport($I);

        $outputDir = 'tests/image/gd';


        $image       = dataDir('assets/images/phalconphp.jpg');
        $outputImage = '15188-text.jpg';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $fontPath    = dataDir('assets/fonts/Roboto-Light.ttf');

        $text = 'Hello Phalcon!';
        $offsetX = 50;
        $offsetY = 75;
        $opacity = 60;
        $color   = '0000FF';
        $size    = 24;
        $font    = dataDir('assets/fonts/Roboto-Light.ttf');
        $hash    = 'fbf9f3e3c3c18183';

        $object = new Gd($image);
        $object
            ->text($text, $offsetX, $offsetY, $opacity, $color, $size, $font)
            ->save($output)
        ;

        $I->amInPath(outputDir($outputDir));
        $I->seeFileFound($outputImage);

        $I->assertTrue($this->checkImageHash($output, $hash));
        $I->safeDeleteFile($outputImage);
    }
}
