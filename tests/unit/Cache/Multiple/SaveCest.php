<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Multiple;

use UnitTester;

class SaveCest
{
    /**
     * Tests Phalcon\Cache\Multiple :: save()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheMultipleSave(UnitTester $I)
    {
        $I->wantToTest("Cache\Multiple - save()");
        $I->skipTest("Need implementation");
    }
}
