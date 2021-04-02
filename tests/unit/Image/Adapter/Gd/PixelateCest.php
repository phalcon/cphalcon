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

class PixelateCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: pixelate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdPixelate(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - pixelate()');

        $this->checkJpegSupport($I);

        $params = [
            [7, 'fbf9f7e3c3c18183'],
            [21, 'fbf9f7e3c1c3c183'],
            [35, 'fbf9f3e3c3c18183'],
            [60, 'fbfbf3e3c3c3c383'],
        ];
        foreach ($params as [$amount, $hash]) {
            $image = new Gd(
                dataDir('assets/images/phalconphp.jpg')
            );

            $outputDir   = 'tests/image/gd';
            $outputImage = $amount . '-pixelate.jpg';
            $output      = outputDir($outputDir . '/' . $outputImage);

            $image->pixelate($amount)->save($output);

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
