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

namespace Phalcon\Test\Unit\Image\Adapter\Imagick;

use Phalcon\Image;
use Phalcon\Image\Adapter\Imagick;
use Phalcon\Test\Fixtures\Traits\ImagickTrait;
use UnitTester;
use function dataFolder;
use function outputFolder;

class FlipCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: flip()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-02-19
     */
    public function imageAdapterImagickFlip(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - flip()');

        $image = new Imagick(
            dataFolder('assets/images/phalconphp.jpg')
        );

        $image->setResourceLimit(6, 1);

        // Flip the image from top to bottom
        $image->flip(Image::HORIZONTAL)->save(outputFolder('tests/image/imagick/flip.jpg'));

        $I->amInPath(
            outputFolder('tests/image/imagick/')
        );

        $I->seeFileFound('flip.jpg');

        $I->assertGreaterThan(
            200,
            $image->getWidth()
        );

        $I->assertGreaterThan(
            200,
            $image->getHeight()
        );

        $I->safeDeleteFile('flip.jpg');
    }
}
