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
 * Class BeginCest
 */
class BeginCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: begin()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteBegin(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - begin()');
        $I->skipTest('Need implementation');
    }
}
