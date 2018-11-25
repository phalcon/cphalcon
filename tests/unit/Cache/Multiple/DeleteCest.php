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

class DeleteCest
{
    /**
     * Tests Phalcon\Cache\Multiple :: delete()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheMultipleDelete(UnitTester $I)
    {
        $I->wantToTest("Cache\Multiple - delete()");
        $I->skipTest("Need implementation");
    }
}
