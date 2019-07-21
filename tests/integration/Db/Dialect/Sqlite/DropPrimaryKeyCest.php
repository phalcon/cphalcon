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
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Db\Exception;

class DropPrimaryKeyCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: dropPrimaryKey()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function dbDialectSqliteDropPrimaryKey(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - dropPrimaryKey()');

        $dialect = new Sqlite();

        $I->expectThrowable(
            new Exception(
                'Removing a primary key after table has been created is not supported by SQLite'
            ),
            function () use ($dialect) {
                $dialect->dropPrimaryKey('table', 'schema');
            }
        );
    }
}
