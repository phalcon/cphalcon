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

namespace Phalcon\Tests\Database\Db\Dialect\Sqlite;

use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ListTablesTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: listTables()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectSqliteListTables(): void
    {
        $dialect = new Sqlite();

        $expected = "SELECT tbl_name FROM sqlite_master "
            . "WHERE type = 'table' ORDER BY tbl_name";

        $this->assertSame($expected, $dialect->listTables());
        $this->assertSame($expected, $dialect->listTables('schema'));
    }
}
