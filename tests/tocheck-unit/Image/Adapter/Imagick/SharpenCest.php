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

namespace Phalcon\Test\Unit\Image\Adapter\Imagick;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Test\Fixtures\Traits\ImagickTrait;
use UnitTester;

use function dataDir;
use function outputDir;

class SharpenCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: sharpen()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function imageAdapterImagickSharpen(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - sharpen()');

        $image = new Imagick(
            dataDir('assets/images/phalconphp.jpg')
        );

        $image->setResourceLimit(6, 1);

        // Sharpen the image by 20%
        $image->sharpen(20)->save(outputDir('tests/image/imagick/sharpen.jpg'));

        $I->amInPath(
            outputDir('tests/image/imagick/')
        );

        $I->seeFileFound('sharpen.jpg');

        $I->assertGreaterThan(
            200,
            $image->getWidth()
        );
        $I->assertGreaterThan(
            200,
            $image->getHeight()
        );

        $I->safeDeleteFile('sharpen.jpg');
    }
}
