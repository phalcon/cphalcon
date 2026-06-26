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

final class EscapeStringTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: escapeString()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    public function testDbAdapterPdoEscapeStringMysql(): void
    {
        $this->assertEscapesAndRoundTrips("O'Brien");
        $this->assertEscapesAndRoundTrips('plain value');
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: escapeString()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('pgsql')]
    public function testDbAdapterPdoEscapeStringPostgresql(): void
    {
        $this->assertEscapesAndRoundTrips("O'Brien");
        $this->assertEscapesAndRoundTrips('plain value');
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: escapeString()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('sqlite')]
    public function testDbAdapterPdoEscapeStringSqlite(): void
    {
        $this->assertEscapesAndRoundTrips("O'Brien");
        $this->assertEscapesAndRoundTrips('plain value');
    }

    private function assertEscapesAndRoundTrips(string $raw): void
    {
        $db      = $this->container->get('db');
        $escaped = $db->escapeString($raw);

        $this->assertIsString($escaped);
        $this->assertNotSame($raw, $escaped);
        $this->assertStringStartsWith("'", $escaped);
        $this->assertStringEndsWith("'", $escaped);

        $row = $db->fetchOne('SELECT ' . $escaped . ' AS value');
        $this->assertSame($raw, $row['value']);
    }
}
