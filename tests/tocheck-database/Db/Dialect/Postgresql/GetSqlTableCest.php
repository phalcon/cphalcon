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

namespace Phalcon\Tests\Integration\Db\Dialect\Postgresql;

use IntegrationTester;

class GetSqlTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: getSqlTable()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbDialectPostgresqlGetSqlTable(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Postgresql - getSqlTable()');
        $I->skipTest('Need implementation');
    }
}
