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
use Phalcon\Tests\Fixtures\Traits\GdTrait;
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

        $image = new Gd(dataDir('assets/images/example-png.png'));
        $mask  = new Gd(dataDir('assets/images/example-jpg.jpg'));

        $outputDir   = 'tests/image/gd';
        $outputImage = 'mask.png';
        $output      = outputDir($outputDir . '/' . $outputImage);

        $hash = 'fbf9f3e3c3c1c183';

        // Resize to 200 pixels on the shortest side
        $mask->mask($image)
             ->save($output)
        ;

        $I->amInPath(outputDir($outputDir));
        $I->seeFileFound($outputImage);

        $actual = $this->checkImageHash($output, $hash);
        $I->assertTrue($actual);

        $I->safeDeleteFile($output);
    }
}
