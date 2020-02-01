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

namespace Phalcon\Test\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Objects;

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
        $migration  = new InvoicesMigration($connection);
        $migration->clear();
    }

    /**
     * Tests Phalcon\Mvc\Model :: getMessages()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    public function mvcModelGetMessages(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getMessages()');

        $record         = new Objects();
        $record->obj_id = 1;
        $result         = $record->save();
        $I->assertFalse($result);

        $messages = $record->getMessages();

        $I->assertCount(2, $messages);
        $I->assertEquals(
            'obj_name is required',
            $messages[0]->getMessage()
        );
        $I->assertEquals(
            'obj_type is required',
            $messages[1]->getMessage()
        );
    }
}
