<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Db\Dialect\Postgresql;

use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ListTablesTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: listTables()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectPostgresqlListTables(): void
    {
        $dialect = new Postgresql();

        $this->assertSame(
            "SELECT t.table_name FROM information_schema.tables t "
            . "JOIN pg_namespace n ON n.nspname = t.table_schema "
            . "JOIN pg_class c ON c.relnamespace = n.oid AND c.relname = t.table_name "
            . "WHERE t.table_schema = 'public' AND NOT c.relispartition "
            . "ORDER BY t.table_name",
            $dialect->listTables()
        );

        $this->assertSame(
            "SELECT t.table_name FROM information_schema.tables t "
            . "JOIN pg_namespace n ON n.nspname = t.table_schema "
            . "JOIN pg_class c ON c.relnamespace = n.oid AND c.relname = t.table_name "
            . "WHERE t.table_schema = 'myschema' AND NOT c.relispartition "
            . "ORDER BY t.table_name",
            $dialect->listTables('myschema')
        );
    }
}
