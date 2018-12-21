<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Image\Adapter;

use UnitTester;

class GetHeightCest
{
    /**
     * Tests Phalcon\Image\Adapter :: getHeight()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGetHeight(UnitTester $I)
    {
        $I->wantToTest("Image\Adapter - getHeight()");
        $I->skipTest("Need implementation");
    }
}
