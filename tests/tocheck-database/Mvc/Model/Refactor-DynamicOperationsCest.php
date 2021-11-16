<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Mvc\Model;

use DateTime;
use IntegrationTester;
use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Db\RawValue;
use Phalcon\Events\Event;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Dynamic\Personas;
use Phalcon\Tests\Models\Dynamic\Personers;
use Phalcon\Tests\Models\Dynamic\Robots;

class DynamicOperationsCest
{
    use DiTrait;

    protected $tracer = [];

    public function _before(IntegrationTester $I)
    {
        $this->tracer = [];
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $connection = $this->container->get('db');
        $manager    = $this->newEventsManager();
        $manager->attach(
            'db',
            function (Event $event, AdapterInterface $connection) {
                if ($event->getType() == 'beforeQuery') {
                    $this->tracer[] = $connection->getSqlStatement();
                }
            }
        );

        $connection->setEventsManager($manager);
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests dynamic update create then update
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/12766
     * @since  2017-04-04
     */
    public function shouldSaveSnapshotWhenHavingPublicPropertyWithNullValue(IntegrationTester $I)
    {
        $robots           = new Robots();
        $robots->name     = 'Test';
        $robots->type     = 'mechanical';
        $robots->datetime = date('Y-m-d');
        $robots->text     = 'text';

        $I->assertTrue($robots->create());
        $I->assertNull($robots->deleted);

        $robots->deleted = date('Y-m-d');

        $I->assertTrue($robots->update());
        $I->assertEquals(date('Y-m-d'), $robots->deleted);

        $I->assertTrue($robots->delete());
    }

    /**
     * Tests dynamic update with default use case.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-01
     */
    public function shouldWorkUsingDynamicUpdate(IntegrationTester $I)
    {
        $persona = Personas::findFirst();
        $I->assertTrue($persona->save());

        // For Personas::useDynamicUpdate(false)
        // ------------------------------------
        // 1. Check table
        // 2. Describe table
        // 3. Personas::findFirst
        // 4. Personas::save
        //
        // For Personas::useDynamicUpdate(true)
        // ------------------------------------
        // 1. Check table
        // 2. Describe table
        // 3. Personas::findFirst
        $I->assertCount(3, $this->tracer);

        $persona->nombres = 'Other Name ' . mt_rand(0, 150000);

        $I->assertEquals(['nombres'], $persona->getChangedFields());
        $I->assertTrue($persona->save());
        $I->assertEquals($this->tracer[3], 'UPDATE `personas` SET `nombres` = ? WHERE `cedula` = ?');

        $persona->nombres   = 'Other Name ' . mt_rand(0, 150000);
        $persona->direccion = 'Address ' . mt_rand(0, 150000);

        $I->assertEquals(['nombres', 'direccion'], $persona->getChangedFields());
        $I->assertTrue($persona->save());
        $I->assertEquals($this->tracer[4], 'UPDATE `personas` SET `nombres` = ?, `direccion` = ? WHERE `cedula` = ?');
    }

    /**
     * Tests dynamic update with renamed model fields.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-01
     */
    public function shouldWorkUsingDynamicUpdateForRenamedModelFields(IntegrationTester $I)
    {
        $persona = Personers::findFirst();
        $I->assertTrue($persona->save());

        // For Personers::useDynamicUpdate(false)
        // ------------------------------------
        // 1. Check table
        // 2. Describe table
        // 3. Personas::findFirst
        // 4. Personas::save
        //
        // For Personers::useDynamicUpdate(true)
        // ------------------------------------
        // 1. Check table
        // 2. Describe table
        // 3. Personas::findFirst
        $I->assertCount(3, $this->tracer);

        $persona->navnes = 'Other Name ' . mt_rand(0, 150000);

        $I->assertEquals(['navnes'], $persona->getChangedFields());
        $I->assertTrue($persona->save());
        $I->assertEquals($this->tracer[3], 'UPDATE `personas` SET `nombres` = ? WHERE `cedula` = ?');

        $persona->navnes  = 'Other Name ' . mt_rand(0, 150000);
        $persona->adresse = 'Address ' . mt_rand(0, 150000);

        $I->assertEquals(['navnes', 'adresse'], $persona->getChangedFields());
        $I->assertTrue($persona->save());
        $I->assertEquals($this->tracer[4], 'UPDATE `personas` SET `nombres` = ?, `direccion` = ? WHERE `cedula` = ?');

        // Cleanup for future tests in this class
        $this->tracer = [];
    }

    /**
     * Tests dynamic update soft delete with renamed model.
     *
     * @author limx <715557344@qq.com>
     * @since  2018-02-24
     */
    public function shouldWorkUsingDynamicUpdateSoftDeleteForRenamedModel(IntegrationTester $I)
    {
        $persona = Personers::findFirst();
        $I->assertTrue($persona->delete());
        $I->assertEquals('X', $persona->status);
    }

    /**
     * Tests dynamic update and rawvalue
     *
     * @author limingxinleo <715557344@qq.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/13170
     * @since  2017-11-20
     */
    public function shouldWorkUsingDynamicUpdateForRawValue(IntegrationTester $I)
    {
        $robot           = new Robots();
        $robot->name     = 'Test';
        $robot->type     = 'mechanical';
        $robot->datetime = (new DateTime())->format('Y-m-d');
        $robot->text     = 'text';
        $robot->year     = 1;
        $robot->save();

        $robot = Robots::findFirst([
            'conditions' => 'year = ?0',
            'bind'       => [1],
        ]);

        $robot->year = new RawValue('year + 1');
        $I->assertTrue($robot->save());

        $robot = Robots::findFirst($robot->id);
        $I->assertEquals(2, $robot->year);
    }
}
