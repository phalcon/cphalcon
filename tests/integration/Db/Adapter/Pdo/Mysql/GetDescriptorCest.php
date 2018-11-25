<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;

class GetDescriptorCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: getDescriptor()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlGetDescriptor(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - getDescriptor()");
        $I->skipTest("Need implementation");
    }
}
