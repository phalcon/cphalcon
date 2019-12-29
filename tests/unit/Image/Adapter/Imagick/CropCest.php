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

class CropCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: crop()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function imageAdapterImagickCrop(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - crop()');

        $image = new Imagick(
            dataDir('assets/images/phalconphp.jpg')
        );

        $image->setResourceLimit(6, 1);

        // Crop the image to 200x200 pixels, from the center
        $image->crop(200, 200)->save(outputDir('tests/image/imagick/crop.jpg'));

        $I->amInPath(
            outputDir('tests/image/imagick/')
        );

        $I->seeFileFound('crop.jpg');

        $I->assertEquals(
            200,
            $image->getWidth()
        );
        $I->assertEquals(
            200,
            $image->getHeight()
        );

        $I->safeDeleteFile('crop.jpg');
    }
}
