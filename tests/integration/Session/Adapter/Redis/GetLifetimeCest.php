<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Adapter\Redis;

use IntegrationTester;

class GetLifetimeCest
{
    /**
     * Tests Phalcon\Session\Adapter\Redis :: getLifetime()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterRedisGetLifetime(IntegrationTester $I)
    {
        $I->wantToTest("Session\Adapter\Redis - getLifetime()");
        $I->skipTest("Need implementation");
    }
}
