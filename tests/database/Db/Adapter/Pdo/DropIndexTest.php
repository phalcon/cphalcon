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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class DropIndexTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const INDEX = 'co_scratch_dropindex_name_idx';

    private const TABLE = 'co_scratch_dropindex';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);
        $db->execute(
            'CREATE TABLE ' . self::TABLE . ' (id integer primary key, name varchar(50))'
        );
        $db->execute(
            'CREATE INDEX ' . self::INDEX . ' ON ' . self::TABLE . ' (name)'
        );
    }

    public function tearDown(): void
    {
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: dropIndex()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoDropIndex(): void
    {
        $db = $this->container->get('db');

        $this->assertTrue($db->dropIndex(self::TABLE, '', self::INDEX));

        $names = [];
        foreach ($db->describeIndexes(self::TABLE) as $idx) {
            $names[] = $idx->getName();
        }
        $this->assertNotContains(self::INDEX, $names);
    }
}
