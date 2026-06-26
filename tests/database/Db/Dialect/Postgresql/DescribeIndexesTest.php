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
final class DescribeIndexesTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: describeIndexes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectPostgresqlDescribeIndexes(): void
    {
        $dialect = new Postgresql();

        $expected = "SELECT 0 as c0, t.relname as table_name, "
            . "i.relname as key_name, 3 as c3, "
            . "a.attname as column_name "
            . "FROM pg_class t, pg_class i, pg_index ix, pg_attribute a "
            . "WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid "
            . "AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) "
            . "AND t.relkind = 'r' AND t.relname = 'robots' "
            . "ORDER BY t.relname, i.relname;";

        $this->assertSame(
            $expected,
            $dialect->describeIndexes('robots')
        );
    }
}
