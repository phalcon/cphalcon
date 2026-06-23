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
            "SELECT table_name FROM information_schema.tables "
            . "WHERE table_schema = 'public' ORDER BY table_name",
            $dialect->listTables()
        );

        $this->assertSame(
            "SELECT table_name FROM information_schema.tables "
            . "WHERE table_schema = 'myschema' ORDER BY table_name",
            $dialect->listTables('myschema')
        );
    }
}
