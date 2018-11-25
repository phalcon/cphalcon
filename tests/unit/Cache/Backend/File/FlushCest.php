<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Backend\File;

use UnitTester;

class FlushCest
{
    /**
     * Tests Phalcon\Cache\Backend\File :: flush()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendFileFlush(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\File - flush()");
        $I->skipTest("Need implementation");
    }
}
