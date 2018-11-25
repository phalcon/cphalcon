<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Frontend\None;

use UnitTester;

class BeforeStoreCest
{
    /**
     * Tests Phalcon\Cache\Frontend\None :: beforeStore()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheFrontendNoneBeforeStore(UnitTester $I)
    {
        $I->wantToTest("Cache\Frontend\None - beforeStore()");
        $I->skipTest("Need implementation");
    }
}
