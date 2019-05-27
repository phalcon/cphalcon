<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use UnitTester;

class TextCest
{
    /**
     * Tests Phalcon\Image\Adapter\Gd :: text()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdText(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - text()');

        $outputDir = 'tests/image/gd';
        $params = [
            ["Hello Phalcon!", false, false, 100, '000000', 12, null, '46adab392b4f41cdbe50cc55aa1b8c31'],
            ["Hello Phalcon!", 50, false, 100, '000000', 12, null, '5c93d2a2be969f316fd6ebf58281b01d'],
            ["Hello Phalcon!", 50, 75, 100, '000000', 12, null, 'eb20b8c4ece04141e74d5d04eba1f5fe'],
            ["Hello Phalcon!", 50, 75, 60, '000000', 12, null, '147a8e48c6e33e32346da10cfae994ba'],
            ["Hello Phalcon!", 50, 75, 60, '00FF00', 12, null, '82bdbff2d6946369c4b66cf604aa5dd7'],
            ["Hello Phalcon!", 50, 75, 60, '0000FF', 24, null, '147a8e48c6e33e32346da10cfae994ba'],
        ];
        $i = 0;

        foreach ($params as list($text, $offsetX, $offsetY, $opacity, $color, $size, $font, $md5)) {
            $image = new Gd(
                dataDir('assets/images/phalconphp.jpg')
            );

            $outputImage = $i++ . 'text.jpg';
            $output = outputDir($outputDir . '/' . $outputImage);

            $image->text($text, $offsetX, $offsetY, $opacity, $color, $size, $font)
                ->save($output);

            $I->amInPath(
                outputDir($outputDir)
            );

            $I->seeFileFound($outputImage);

            $I->assertSame(
                $md5,
                md5_file($output),
                'Checking MD5'
            );

            $I->safeDeleteFile($outputImage);
        }
    }
}
