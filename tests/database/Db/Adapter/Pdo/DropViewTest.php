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

final class DropViewTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const SRC  = 'co_scratch_dropview_src';
    private const VIEW = 'co_scratch_dropview';

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
     * Tests Phalcon\Db\Adapter\Pdo :: dropView()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoDropView(): void
    {
        $db = $this->container->get('db');

        $this->assertTrue($db->viewExists(self::VIEW));
        $this->assertTrue($db->dropView(self::VIEW));
        $this->assertFalse($db->viewExists(self::VIEW));
    }
}
