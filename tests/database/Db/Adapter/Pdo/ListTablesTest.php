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

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class ListTablesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const PARTITION   = 'co_scratch_listtables_2026';

    private const PARTITIONED = 'co_scratch_listtables_parted';

    private const SEQUENCE    = 'co_scratch_listtables_seq';

    private const TABLE       = 'co_scratch_listtables';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->dropScratchTables();
        $db = $this->container->get('db');
        $db->execute(
            'CREATE TABLE ' . self::TABLE . ' (id integer primary key, name varchar(50))'
        );
    }

    public function tearDown(): void
    {
        $this->dropScratchTables();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: listTables()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoListTables(): void
    {
        $db = $this->container->get('db');

        $tables = $db->listTables();
        $this->assertIsArray($tables);
        $this->assertContains(self::TABLE, $tables);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: listTables() - no partitions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     * @issue  https://github.com/phalcon/cphalcon/issues/17769
     */
    #[Group('pgsql')]
    public function testDbAdapterPdoListTablesNoPartitions(): void
    {
        $db = $this->container->get('db');
        $db->execute(
            'CREATE TABLE ' . self::PARTITIONED . ' (id integer, d date) PARTITION BY RANGE (d)'
        );
        $db->execute(
            'CREATE TABLE ' . self::PARTITION . ' PARTITION OF ' . self::PARTITIONED
            . " FOR VALUES FROM ('2026-01-01') TO ('2027-01-01')"
        );

        $tables = $db->listTables();
        $this->assertContains(self::TABLE, $tables);
        $this->assertContains(self::PARTITIONED, $tables);
        $this->assertNotContains(self::PARTITION, $tables);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: listTables() - no sequences
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     * @issue  https://github.com/phalcon/cphalcon/issues/17769
     */
    #[Group('mysql')]
    public function testDbAdapterPdoListTablesNoSequences(): void
    {
        if (!$this->isMariaDb()) {
            $this->markTestSkipped('Only MariaDB has sequences');
        }

        $db = $this->container->get('db');
        $db->execute('CREATE SEQUENCE ' . self::SEQUENCE);

        $tables = $db->listTables();
        $this->assertContains(self::TABLE, $tables);
        $this->assertNotContains(self::SEQUENCE, $tables);
    }

    /**
     * DROP TABLE also removes a MariaDB sequence and the partitions of a
     * PostgreSQL table.
     */
    private function dropScratchTables(): void
    {
        $db = $this->container->get('db');
        foreach ([self::PARTITIONED, self::SEQUENCE, self::TABLE] as $name) {
            $db->execute('DROP TABLE IF EXISTS ' . $name);
        }
    }
}
