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

            $image->text($text, $offsetX, $offsetY, $opacity, $color, $size, $font)
                  ->save($output)
            ;

            $I->amInPath(
                outputDir($outputDir)
            );

            $I->seeFileFound($outputImage);

            $I->assertTrue(
                $this->checkImageHash($output, $hash)
            );

            $I->safeDeleteFile($outputImage);
        }
    }
}
