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

class MaskCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: mask()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdMask(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - mask()');

        $this->checkJpegSupport($I);

        $image = new Gd(
            dataDir('assets/images/logo.png')
        );

        $mask = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );

        $outputDir   = 'tests/image/gd';
        $outputImage = 'mask.png';
        $output      = outputDir($outputDir . '/' . $outputImage);

        $hash = '30787c3c3f191800';

        // Resize to 200 pixels on the shortest side
        $mask->mask($image)->save($output);

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
