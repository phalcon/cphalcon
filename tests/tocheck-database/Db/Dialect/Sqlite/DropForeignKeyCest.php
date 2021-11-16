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

class DropForeignKeyCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: dropForeignKey()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function dbDialectSqliteDropForeignKey(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - dropForeignKey()');

        $dialect = new Sqlite();

        $I->expectThrowable(
            new Exception(
                'Dropping a foreign key constraint is not supported by SQLite'
            ),
            function () use ($dialect) {
                $dialect->dropForeignKey('table', 'schema', 'reference1');
            }
        );
    }
}
