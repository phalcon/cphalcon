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
use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

class BackgroundCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: background()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdBackground(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - background()');

        $params = [
            [200, null, Enum::WIDTH, '000000', 30, '10787c3c1e1c3818'],
            [null, 150, Enum::HEIGHT, '00FF00', 75, '10787c3c1e1c3818'],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($params as [$width, $height, $master, $color, $opacity, $hash]) {
            $resultImage = $color . 'bg.png';
            $output      = outputDir($outputDir . '/' . $resultImage);

            $image = new Gd(
                dataDir('assets/images/logo.png')
            );

            $image->background($color, $opacity)
                  ->resize($width, $height, $master)
                  ->save($output)
            ;

            $I->amInPath(
                outputDir($outputDir)
            );

            $I->seeFileFound($resultImage);

            $I->assertTrue(
                $this->checkImageHash($output, $hash)
            );

            $I->safeDeleteFile($resultImage);
        }
    }
}
