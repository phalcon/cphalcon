<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;

/**
 * Class SetDialectCest
 */
class SetDialectCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: setDialect()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteSetDialect(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - setDialect()');
        $I->skipTest('Need implementation');
    }
}
