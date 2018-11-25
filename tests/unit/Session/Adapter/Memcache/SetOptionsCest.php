<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Session\Adapter\Memcache;

use UnitTester;

class SetOptionsCest
{
    /**
     * Tests Phalcon\Session\Adapter\Memcache :: setOptions()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterMemcacheSetOptions(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Memcache - setOptions()");
        $I->skipTest("Need implementation");
    }
}
