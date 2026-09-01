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

namespace Phalcon\Tests\Database\Db\Dialect\Postgresql;

use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class TableOptionsTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: tableOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectPostgresqlTableOptions(): void
    {
        $dialect = new Postgresql();

        $prefix = "SELECT obj_description(c.oid, 'pg_class') AS table_comment "
            . "FROM pg_class c "
            . "JOIN pg_namespace n ON n.oid = c.relnamespace "
            . "WHERE c.relname = 'robots' AND ";

        $this->assertSame(
            $prefix . "n.nspname = 'schema'",
            $dialect->tableOptions('robots', 'schema')
        );

        $this->assertSame(
            $prefix . "n.nspname = current_schema()",
            $dialect->tableOptions('robots')
        );
    }
}
