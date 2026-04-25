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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\ObjectsMigration;
use Phalcon\Tests\Support\Models\Objects;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class InvokeFinderTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'random data', 1);
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     * @group pgsql
     */
    public function testMvcModelInvokeFinder(): void
    {
        $record = Objects::findFirstByObjId(1);

        $this->assertSame(1, (int) $record->obj_id);
        $this->assertSame('random data', $record->obj_name);
        $this->assertSame(1, (int) $record->obj_type);

        $connection = self::getConnection();
        $migration  = new ObjectsMigration($connection, false);
        $migration->insert(2, 'random one', 1);
        $migration->insert(3, 'random two', 1);

        $data = Objects::findByObjType(1);

        $this->assertCount(3, $data);


        $record = $data[0];
        $this->assertSame(1, (int) $record->obj_id);
        $this->assertSame('random data', $record->obj_name);
        $this->assertSame(1, (int) $record->obj_type);

        $record = $data[1];
        $this->assertSame(2, (int) $record->obj_id);
        $this->assertSame('random one', $record->obj_name);
        $this->assertSame(1, (int) $record->obj_type);

        $record = $data[2];
        $this->assertSame(3, (int) $record->obj_id);
        $this->assertSame('random two', $record->obj_name);
        $this->assertSame(1, (int) $record->obj_type);
    }
}
