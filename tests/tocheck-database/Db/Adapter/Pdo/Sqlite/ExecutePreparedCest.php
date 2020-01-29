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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;

/**
 * Class ExecutePreparedCest
 */
class ExecutePreparedCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: executePrepared()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteExecutePrepared(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - executePrepared()');
        $I->skipTest('Need implementation');
    }
}
