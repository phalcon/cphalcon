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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use Phalcon\Db\Reference;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class DescribeReferencesSqliteTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const CUSTOMERS = 'co_scratch_refs_customers';

    private const ORDERS    = 'co_scratch_refs_orders';

    private const USERS     = 'co_scratch_refs_users';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $this->dropTables();

        $db = $this->container->get('db');

        $db->execute(
            'CREATE TABLE ' . self::CUSTOMERS . ' ('
            . 'a INT, '
            . 'b INT, '
            . 'PRIMARY KEY (a, b))'
        );
        $db->execute(
            'CREATE TABLE ' . self::USERS . ' (id INTEGER PRIMARY KEY)'
        );
        $db->execute(
            'CREATE TABLE ' . self::ORDERS . ' ('
            . 'id INTEGER PRIMARY KEY, '
            . 'user_id INT REFERENCES ' . self::USERS . ' (id), '
            . 'ca INT, '
            . 'cb INT, '
            . 'FOREIGN KEY (ca, cb) REFERENCES ' . self::CUSTOMERS . ' (a, b))'
        );
    }

    public function tearDown(): void
    {
        $this->dropTables();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: describeReferences() -
     * composite key
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-27
     * @issue  https://github.com/phalcon/cphalcon/issues/17814
     */
    #[Group('sqlite')]
    public function testDbAdapterPdoSqliteDescribeReferencesComposite(): void
    {
        $db = $this->container->get('db');

        /**
         * SQLite numbers the keys in the reverse order of the declaration
         */
        $expected = [
            'foreign_key_0' => new Reference(
                'foreign_key_0',
                [
                    'referencedSchema'  => null,
                    'referencedTable'   => self::CUSTOMERS,
                    'columns'           => ['ca', 'cb'],
                    'referencedColumns' => ['a', 'b'],
                ]
            ),
            'foreign_key_1' => new Reference(
                'foreign_key_1',
                [
                    'referencedSchema'  => null,
                    'referencedTable'   => self::USERS,
                    'columns'           => ['user_id'],
                    'referencedColumns' => ['id'],
                ]
            ),
        ];

        $this->assertEquals($expected, $db->describeReferences(self::ORDERS));
    }

    private function dropTables(): void
    {
        $db = $this->container->get('db');

        $db->execute('DROP TABLE IF EXISTS ' . self::ORDERS);
        $db->execute('DROP TABLE IF EXISTS ' . self::USERS);
        $db->execute('DROP TABLE IF EXISTS ' . self::CUSTOMERS);
    }
}
