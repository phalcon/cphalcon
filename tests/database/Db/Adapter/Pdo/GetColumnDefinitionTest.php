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

use Phalcon\Db\Column;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function env;

final class GetColumnDefinitionTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: getColumnDefinition()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoGetColumnDefinition(): void
    {
        $db = $this->container->get('db');

        $intColumn = new Column('foo', [
            'type' => Column::TYPE_INTEGER,
            'size' => 10,
        ]);
        $varColumn = new Column('foo', [
            'type' => Column::TYPE_VARCHAR,
            'size' => 100,
        ]);

        $driver = env('driver');
        $expectedInt = [
            'mysql'  => 'INT(10)',
            'pgsql'  => 'INT',
            'sqlite' => 'INTEGER',
        ][$driver];
        $expectedVar = [
            'mysql'  => 'VARCHAR(100)',
            'pgsql'  => 'CHARACTER VARYING(100)',
            'sqlite' => 'VARCHAR(100)',
        ][$driver];

        $this->assertSame($expectedInt, $db->getColumnDefinition($intColumn));
        $this->assertSame($expectedVar, $db->getColumnDefinition($varColumn));
    }
}
