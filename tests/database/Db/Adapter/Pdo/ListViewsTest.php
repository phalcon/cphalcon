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

final class ListViewsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const SRC  = 'co_scratch_listviews_src';
    private const VIEW = 'co_scratch_listviews';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $db = $this->container->get('db');
        $db->execute('DROP VIEW IF EXISTS ' . self::VIEW);
        $db->execute('DROP TABLE IF EXISTS ' . self::SRC);
        $db->execute(
            'CREATE TABLE ' . self::SRC . ' (id integer primary key, name varchar(50))'
        );
        $db->execute(
            'CREATE VIEW ' . self::VIEW . ' AS SELECT id, name FROM ' . self::SRC
        );
    }

    public function tearDown(): void
    {
        $db = $this->container->get('db');
        $db->execute('DROP VIEW IF EXISTS ' . self::VIEW);
        $db->execute('DROP TABLE IF EXISTS ' . self::SRC);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: listViews()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoListViews(): void
    {
        $db = $this->container->get('db');

        $views = $db->listViews();
        $this->assertIsArray($views);
        $this->assertContains(self::VIEW, $views);
    }
}
