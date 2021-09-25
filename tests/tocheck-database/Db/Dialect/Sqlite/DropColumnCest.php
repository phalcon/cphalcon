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

namespace Phalcon\Tests\Integration\Db\Dialect\Sqlite;

use IntegrationTester;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Db\Exception;

class DropColumnCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: dropColumn()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function dbDialectSqliteDropColumn(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - dropColumn()');

        $dialect = new Sqlite();

        $I->expectThrowable(
            new Exception('Dropping DB column is not supported by SQLite'),
            function () use ($dialect) {
                $dialect->dropColumn('table', 'schema', 'column1');
            }
        );
    }
}
