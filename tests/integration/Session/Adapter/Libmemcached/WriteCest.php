<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Adapter\Libmemcached;

use IntegrationTester;

class WriteCest
{
    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: write()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedWrite(IntegrationTester $I)
    {
        $I->wantToTest("Session\Adapter\Libmemcached - write()");
        $I->skipTest("Need implementation");
    }
}
