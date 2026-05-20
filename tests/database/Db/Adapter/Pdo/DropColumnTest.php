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

final class DropColumnTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const TABLE = 'co_scratch_dropcolumn';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);
        $db->execute(
            'CREATE TABLE ' . self::TABLE . ' (id integer primary key, name varchar(50), extra integer)'
        );
    }

    public function tearDown(): void
    {
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: dropColumn()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoDropColumn(): void
    {
        $db = $this->container->get('db');

        $this->assertTrue($db->dropColumn(self::TABLE, '', 'extra'));

        $names = [];
        foreach ($db->describeColumns(self::TABLE) as $col) {
            $names[] = $col->getName();
        }
        $this->assertNotContains('extra', $names);
    }
}
