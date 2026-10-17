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
use Phalcon\Talon\Talon;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class DescribeReferencesPostgresqlTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const CODE_FK    = 'co_scratch_refs_code_fk';

    private const LINES      = 'co_scratch_refs_lines';

    private const ORDERS     = 'co_scratch_refs_orders';

    private const PRODUCTS   = 'co_scratch_refs_products';

    private const RETURNS    = 'co_scratch_refs_returns';

    private const REVERSE_FK = 'co_scratch_refs_reverse_fk';

    private const SHARED_FK  = 'co_scratch_refs_fk';

    private const SHIPMENTS  = 'co_scratch_refs_shipments';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $this->dropTables();

        $db = $this->container->get('db');

        $db->execute(
            'CREATE TABLE ' . self::ORDERS . ' (id integer PRIMARY KEY)'
        );
        $db->execute(
            'CREATE TABLE ' . self::LINES . ' ('
            . 'order_id integer NOT NULL, '
            . 'number integer NOT NULL, '
            . 'PRIMARY KEY (order_id, number))'
        );

        // A unique index that is not a constraint
        $db->execute(
            'CREATE TABLE ' . self::PRODUCTS . ' ('
            . 'id integer PRIMARY KEY, '
            . 'code varchar(10) NOT NULL)'
        );
        $db->execute(
            'CREATE UNIQUE INDEX co_scratch_refs_products_code ON '
            . self::PRODUCTS . ' (code)'
        );

        $db->execute(
            'CREATE TABLE ' . self::SHIPMENTS . ' ('
            . 'id integer PRIMARY KEY, '
            . 'order_id integer, '
            . 'line_no integer, '
            . 'product_code varchar(10), '
            . 'CONSTRAINT ' . self::SHARED_FK . ' '
            . 'FOREIGN KEY (order_id, line_no) '
            . 'REFERENCES ' . self::LINES . ' (order_id, number), '
            . 'CONSTRAINT ' . self::REVERSE_FK . ' '
            . 'FOREIGN KEY (line_no, order_id) '
            . 'REFERENCES ' . self::LINES . ' (number, order_id) '
            . 'ON UPDATE CASCADE ON DELETE SET NULL, '
            . 'CONSTRAINT ' . self::CODE_FK . ' '
            . 'FOREIGN KEY (product_code) '
            . 'REFERENCES ' . self::PRODUCTS . ' (code) '
            . 'ON UPDATE RESTRICT ON DELETE SET DEFAULT)'
        );

        // PostgreSQL makes foreign key names unique only per table
        $db->execute(
            'CREATE TABLE ' . self::RETURNS . ' ('
            . 'id integer PRIMARY KEY, '
            . 'order_id integer, '
            . 'CONSTRAINT ' . self::SHARED_FK . ' '
            . 'FOREIGN KEY (order_id) '
            . 'REFERENCES ' . self::ORDERS . ' (id))'
        );
    }

    public function tearDown(): void
    {
        $this->dropTables();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: describeReferences() -
     * composite key
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17680
     */
    #[Group('pgsql')]
    public function testDbAdapterPdoPostgresqlDescribeReferencesComposite(): void
    {
        $db = $this->container->get('db');

        $expected = new Reference(
            self::SHARED_FK,
            [
                'referencedTable'   => self::LINES,
                'referencedSchema'  => Talon::settings()->getDatabaseOptions('pgsql')['dbname'],
                'columns'           => ['order_id', 'line_no'],
                'referencedColumns' => ['order_id', 'number'],
                'onUpdate'          => 'NO ACTION',
                'onDelete'          => 'NO ACTION',
            ]
        );

        $references = $db->describeReferences(self::SHIPMENTS);

        $this->assertCount(3, $references);
        $this->assertArrayHasKey(self::SHARED_FK, $references);
        $this->assertEquals($expected, $references[self::SHARED_FK]);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: describeReferences() -
     * composite key with the columns in a different order than the
     * referenced primary key
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17680
     */
    #[Group('pgsql')]
    public function testDbAdapterPdoPostgresqlDescribeReferencesCompositeReordered(): void
    {
        $db = $this->container->get('db');

        $expected = new Reference(
            self::REVERSE_FK,
            [
                'referencedTable'   => self::LINES,
                'referencedSchema'  => Talon::settings()->getDatabaseOptions('pgsql')['dbname'],
                'columns'           => ['line_no', 'order_id'],
                'referencedColumns' => ['number', 'order_id'],
                'onUpdate'          => 'CASCADE',
                'onDelete'          => 'SET NULL',
            ]
        );

        $references = $db->describeReferences(self::SHIPMENTS, 'public');

        $this->assertArrayHasKey(self::REVERSE_FK, $references);
        $this->assertEquals($expected, $references[self::REVERSE_FK]);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: describeReferences() -
     * the same foreign key name on two tables in the same schema
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17680
     */
    #[Group('pgsql')]
    public function testDbAdapterPdoPostgresqlDescribeReferencesSameNameOtherTable(): void
    {
        $db = $this->container->get('db');

        $expected = [
            self::SHARED_FK => new Reference(
                self::SHARED_FK,
                [
                    'referencedTable'   => self::ORDERS,
                    'referencedSchema'  => Talon::settings()->getDatabaseOptions('pgsql')['dbname'],
                    'columns'           => ['order_id'],
                    'referencedColumns' => ['id'],
                    'onUpdate'          => 'NO ACTION',
                    'onDelete'          => 'NO ACTION',
                ]
            ),
        ];

        $this->assertEquals($expected, $db->describeReferences(self::RETURNS));
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: describeReferences() -
     * key that references a unique index that is not a constraint
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17680
     */
    #[Group('pgsql')]
    public function testDbAdapterPdoPostgresqlDescribeReferencesUniqueIndex(): void
    {
        $db = $this->container->get('db');

        $expected = new Reference(
            self::CODE_FK,
            [
                'referencedTable'   => self::PRODUCTS,
                'referencedSchema'  => Talon::settings()->getDatabaseOptions('pgsql')['dbname'],
                'columns'           => ['product_code'],
                'referencedColumns' => ['code'],
                'onUpdate'          => 'RESTRICT',
                'onDelete'          => 'SET DEFAULT',
            ]
        );

        $references = $db->describeReferences(self::SHIPMENTS);

        $this->assertArrayHasKey(self::CODE_FK, $references);
        $this->assertEquals($expected, $references[self::CODE_FK]);
    }

    private function dropTables(): void
    {
        $db = $this->container->get('db');

        $db->execute('DROP TABLE IF EXISTS ' . self::RETURNS);
        $db->execute('DROP TABLE IF EXISTS ' . self::SHIPMENTS);
        $db->execute('DROP TABLE IF EXISTS ' . self::PRODUCTS);
        $db->execute('DROP TABLE IF EXISTS ' . self::LINES);
        $db->execute('DROP TABLE IF EXISTS ' . self::ORDERS);
    }
}
