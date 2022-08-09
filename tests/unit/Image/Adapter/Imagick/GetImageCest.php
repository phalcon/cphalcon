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

class GetImageCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: getImage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function imageAdapterImagickGetImage(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - getImage()');

        $image = new Imagick(
            dataDir('assets/images/example-jpg.jpg')
        );

        $class = \Imagick::class;
        $actual = $image->getImage();
        $I->assertInstanceOf($class, $actual);
    }
}
