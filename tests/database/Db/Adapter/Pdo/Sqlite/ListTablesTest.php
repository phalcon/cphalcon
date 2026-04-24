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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo\Sqlite;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class ListTablesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: listTables()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  sqlite
     */
    public function testDbAdapterPdoSqliteListTables(): void
    {
        $db = $this->container->get('db');

        $expected = [
            'album',
            'album_photo',
            'albums',
            'artists',
            'co_customers',
            'co_customers_defaults',
            'co_dialect',
            'co_invoices',
            'co_manufacturers',
            'co_rb_test_model',
            'co_setters',
            'co_sources',
            'complex_default',
            'objects',
            'personas',
            'ph_select',
            'photo',
            'songs',
            'sqlite_sequence',
            'stuff',
            'table_with_uuid_primary',
        ];

        $this->assertEquals($expected, $db->listTables());
        $this->assertEquals($expected, $db->listTables('public'));
    }
}
