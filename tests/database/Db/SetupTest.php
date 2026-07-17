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

namespace Phalcon\Tests\Database\Db;

use Phalcon\Db\Adapter\Pdo\Mysql as MysqlAdapter;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class SetupTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db :: setup()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbSetup(): void
    {
        $dialect = new Mysql();

        // By default SQL identifiers are escaped
        $this->assertSame('`robots`', $dialect->escape('robots'));

        // Disable identifier escaping globally
        MysqlAdapter::setup(['escapeSqlIdentifiers' => false]);
        $this->assertSame('robots', $dialect->escape('robots'));

        // Restore the default behavior
        MysqlAdapter::setup(['escapeSqlIdentifiers' => true]);
        $this->assertSame('`robots`', $dialect->escape('robots'));
    }
}
