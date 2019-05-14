<?php
declare(strict_types=1);

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

/**
 * Class GetDialectCest
 */
class GetDialectCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: getDialect()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlGetDialect(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - getDialect()');
        $I->skipTest('Need implementation');
    }
}
