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

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\ObjectsMigration;
use Phalcon\Tests\Support\Models\Objects;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetMessagesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->clear();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelGetMessages(): void
    {
        $record         = new Objects();
        $record->obj_id = 1;
        $result         = $record->save();
        $this->assertFalse($result);

        $messages = $record->getMessages();

        $expectedCount = 2;
        $this->assertCount($expectedCount, $messages);

        $expected = 'obj_name is required';
        $actual   = $messages[0]->getMessage();
        $this->assertSame($expected, $actual);

        $expected = 'obj_type is required';
        $actual   = $messages[1]->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-09-30
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelGetMessagesFiltered(): void
    {
        $record         = new Objects();
        $record->obj_id = 1;
        $result         = $record->save();
        $this->assertFalse($result);

        $messages = $record->getMessages();

        $expectedCount = 2;
        $this->assertCount($expectedCount, $messages);

        /**
         * Filter by field obj_name
         */
        $messages = $record->getMessages('obj_name');

        $expectedCount = 1;
        $this->assertCount($expectedCount, $messages);

        $expected = 'obj_name is required';
        $actual   = $messages[0]->getMessage();
        $this->assertSame($expected, $actual);

        /**
         * Filter by field obj_type
         */
        $messages = $record->getMessages('obj_type');

        $expectedCount = 1;
        $this->assertCount($expectedCount, $messages);

        $expected = 'obj_type is required';
        $actual   = $messages[0]->getMessage();
        $this->assertSame($expected, $actual);

        /**
         * Filter by both fields
         */
        $messages = $record->getMessages(['obj_name', 'obj_type']);

        $expectedCount = 2;
        $this->assertCount($expectedCount, $messages);

        $expected = 'obj_name is required';
        $actual   = $messages[0]->getMessage();
        $this->assertSame($expected, $actual);

        $expected = 'obj_type is required';
        $actual   = $messages[1]->getMessage();
        $this->assertSame($expected, $actual);
    }
}
