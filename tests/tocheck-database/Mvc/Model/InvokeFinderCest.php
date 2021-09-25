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

namespace Phalcon\Tests\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Migrations\ObjectsMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Objects;

/**
 * Class InvokeFinderCest
 */
class InvokeFinderCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model :: invokeFinder()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelInvokeFinder(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - invokeFinder()');

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        /**
         * Setup the table
         */
        $db        = $this->container->get('db');
        $migration = new ObjectsMigration();

        $migration($db);

        $record = Objects::findFirstByObjId(1);

        $I->assertEquals(1, $record->obj_id);
        $I->assertEquals('random data', $record->obj_name);
        $I->assertEquals(1, $record->obj_type);

        $migration->insertObject($db, 2, 'random one', 1);
        $migration->insertObject($db, 3, 'random two', 1);

        $data = Objects::findByObjType(1);

        $I->assertEquals(3, count($data));

        $data = Objects::findByObjType(
            1,
            [
                'order' => 'obj_name ASC',
            ]
        );

        $I->assertEquals(3, count($data));

        $record = $data[0];
        $I->assertEquals(1, $record->obj_id);
        $I->assertEquals('random data', $record->obj_name);
        $I->assertEquals(1, $record->obj_type);

        $record = $data[1];
        $I->assertEquals(2, $record->obj_id);
        $I->assertEquals('random one', $record->obj_name);
        $I->assertEquals(1, $record->obj_type);

        $record = $data[2];
        $I->assertEquals(3, $record->obj_id);
        $I->assertEquals('random two', $record->obj_name);
        $I->assertEquals(1, $record->obj_type);
    }
}
