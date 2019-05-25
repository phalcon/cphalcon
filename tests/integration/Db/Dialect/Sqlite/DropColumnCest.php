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

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use IntegrationTester;
use Phalcon\Db\Exception;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class DropColumnCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: dropColumn()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function dbDialectSqliteDropColumn(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - dropColumn()');

        $dialect = $this->getDialectSqlite();

        $I->expectThrowable(
            new Exception('Dropping DB column is not supported by SQLite'),
            function () use ($dialect) {
                $dialect->dropColumn('table', 'schema', 'column1');
            }
        );
    }
}
