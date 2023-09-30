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

use DatabaseTester;
use PDO;
use Phalcon\Tests\Fixtures\Migrations\ObjectsMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Objects;

/**
 * Class GetMessagesCest
 */
class GetMessagesCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->clear();
    }

    /**
     * Tests Phalcon\Mvc\Model :: getMessages()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetMessages(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getMessages()');

        $record         = new Objects();
        $record->obj_id = 1;
        $result         = $record->save();
        $I->assertFalse($result);

        $messages = $record->getMessages();

        $expectedCount = 2;
        $I->assertCount($expectedCount, $messages);

        $expected = 'obj_name is required';
        $actual   = $messages[0]->getMessage();
        $I->assertSame($expected, $actual);

        $expected = 'obj_type is required';
        $actual   = $messages[1]->getMessage();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: getMessages() - filtered
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-09-30
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetMessagesFiltered(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getMessages() - filtered');

        $record         = new Objects();
        $record->obj_id = 1;
        $result         = $record->save();
        $I->assertFalse($result);

        $messages = $record->getMessages();

        $expectedCount = 2;
        $I->assertCount($expectedCount, $messages);

        /**
         * Filter by field obj_name
         */
        $messages = $record->getMessages('obj_name');

        $expectedCount = 1;
        $I->assertCount($expectedCount, $messages);

        $expected = 'obj_name is required';
        $actual   = $messages[0]->getMessage();
        $I->assertSame($expected, $actual);

        /**
         * Filter by field obj_type
         */
        $messages = $record->getMessages('obj_type');

        $expectedCount = 1;
        $I->assertCount($expectedCount, $messages);

        $expected = 'obj_type is required';
        $actual   = $messages[0]->getMessage();
        $I->assertSame($expected, $actual);

        /**
         * Filter by both fields
         */
        $messages = $record->getMessages(['obj_name', 'obj_type']);

        $expectedCount = 2;
        $I->assertCount($expectedCount, $messages);

        $expected = 'obj_name is required';
        $actual   = $messages[0]->getMessage();
        $I->assertSame($expected, $actual);

        $expected = 'obj_type is required';
        $actual   = $messages[1]->getMessage();
        $I->assertSame($expected, $actual);
    }
}
