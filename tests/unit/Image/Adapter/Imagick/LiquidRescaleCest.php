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

namespace Phalcon\Tests\Unit\Image\Adapter\Imagick;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Tests\Fixtures\Traits\ImagickTrait;
use UnitTester;

use function dataDir;
use function outputDir;

class LiquidRescaleCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: liquidRescale()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function imageAdapterImagickLiquidRescale(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - liquidRescale()');

        $I->skipTest('Check library support');

        $image = new Imagick(
            dataDir('assets/images/phalconphp.jpg')
        );

        $image->setResourceLimit(6, 1);

        // Resize to 200 pixels on the shortest side
        $image->liquidRescale(200, 200)->save(outputDir('tests/image/imagick/liquidRescale.jpg'));

        $I->amInPath(
            outputDir('tests/image/imagick/')
        );

        $I->seeFileFound('liquidRescale.jpg');

        $I->assertEquals(
            200,
            $image->getWidth()
        );

        $I->assertEquals(
            200,
            $image->getHeight()
        );

        $I->safeDeleteFile('liquidRescale.jpg');
    }
}
