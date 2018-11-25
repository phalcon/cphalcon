<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Image\Adapter\Imagick;

use UnitTester;

class CropCest
{
    /**
     * Tests Phalcon\Image\Adapter\Imagick :: crop()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterImagickCrop(UnitTester $I)
    {
        $I->wantToTest("Image\Adapter\Imagick - crop()");
        $I->skipTest("Need implementation");
    }
}
