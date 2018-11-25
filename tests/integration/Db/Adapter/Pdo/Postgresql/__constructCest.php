<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;

class __constructCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: __construct()
     *
     * @param IntegrationTester $I
     * 
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoPostgresql__construct(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Postgresql - __construct()");
        $I->skipTest("Need implementation");
    }
}
