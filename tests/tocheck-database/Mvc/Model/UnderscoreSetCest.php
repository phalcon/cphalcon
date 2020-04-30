<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models;

class UnderscoreSetCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSet(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model - __set()");

        $user = new Models\Users();

        $user->id   = 999;
        $user->name = 'Test';

        $I->assertEquals(
            999,
            $user->id
        );

        $I->assertEquals(
            'Test',
            $user->name
        );

        $I->assertEquals(
            [
                'id'   => 999,
                'name' => 'Test',
            ],
            $user->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() whether it is using setters correctly
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSetIsUsingSetters(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model - __set() whether it is using setters correctly");

        $model     = new Models\Select();
        $model->id = 123;

        $I->assertEquals(
            123,
            $model->getId()
        );

        $associativeArray = [
            'firstName' => 'First name',
            'lastName'  => 'Last name',
        ];

        $model->name = $associativeArray;

        $I->assertEquals(
            $associativeArray,
            $model->getName()
        );

        $model->text = 'MyText';

        $I->assertEquals(
            'MyText',
            $model->getText()
        );

        $I->assertEquals(
            [
                'sel_id'   => 123,
                'sel_name' => $associativeArray,
                'sel_text' => 'MyText',
            ],
            $model->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with belongs-to related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSetWithBelongsToRelatedRecord(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with belongs-to related record');

        $robotPart        = new Models\RobotsParts();
        $robotPart->robot = new Models\Robots();

        $robot = $robotPart->robot;

        $I->assertInstanceOf(
            Models\Robots::class,
            $robot
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $robotPart->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with an array as properties of a
     * belongs-to related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSetWithArrayOfBelongsToRelatedRecord(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with an array as properties of a belongs-to related record');

        $robotPart        = new Models\RobotsParts();
        $robotPart->robot = ['name' => 'TestRobotName'];

        $robot = $robotPart->robot;

        $I->assertInstanceOf(
            Models\Robots::class,
            $robot
        );

        $I->assertEquals(
            $robotPart->getDirtyState(),
            Model::DIRTY_STATE_TRANSIENT
        );

        $I->assertEquals(
            'TestRobotName',
            $robot->name
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with has-one related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSetWithHasOneRelatedRecord(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with has-one related record');

        $customer       = new Models\Customers();
        $customer->user = new Models\Users();

        $user = $customer->user;

        $I->assertInstanceOf(
            Models\Users::class,
            $user
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $customer->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with has-one-through related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-11-03
     */
    public function mvcModelUnderscoreSetWithHasOneThroughRelatedRecord(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with has-one-through related record');

        $robot = new Models\Relations\Robots();

        $relationsParts           = new Models\Relations\RelationsParts();
        $relationsParts->oneRobot = $robot;

        $I->assertInstanceOf(
            Models\Relations\Robots::class,
            $relationsParts->oneRobot
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $relationsParts->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with an array as properties of a
     * has-one related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSetWithArrayOfHasOneRelatedRecord(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with an array as properties of a has-one related record');

        $customer       = new Models\Customers();
        $customer->user = ['name' => 'TestUserName'];

        $user = $customer->user;

        $I->assertInstanceOf(
            Models\Users::class,
            $user
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $customer->getDirtyState()
        );

        $I->assertEquals(
            'TestUserName',
            $user->name
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with has-many related records
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSetWithHasManyRelatedRecords(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with has-many related records');

        $robot              = new Models\Robots();
        $robot->robotsParts = [
            new Models\RobotsParts(),
            new Models\RobotsParts(),
        ];

        $robotsParts = $robot->robotsParts;

        $I->assertTrue(is_array($robotsParts));
        $I->assertCount(2, $robotsParts);

        $I->assertInstanceOf(
            Models\RobotsParts::class,
            $robotsParts[0]
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $robot->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with has-many-to-many related records
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSetWithHasManyToManyRelatedRecords(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with has-many-to-many related records');

        $robot           = new Models\Relations\M2MRobots();
        $robot->M2MParts = [
            new Models\Relations\M2MParts(),
            new Models\Relations\M2MParts(),
        ];

        $robotParts = $robot->M2MParts;

        $I->assertTrue(is_array($robotParts));
        $I->assertCount(2, $robotParts);

        $I->assertInstanceOf(
            Models\Relations\M2MParts::class,
            $robotParts[0]
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $robot->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with associative array
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSetWithAssociativeArray(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with associative array');

        $associativeArray = [
            'firstName' => 'First name',
            'lastName'  => 'Last name',
        ];

        $user       = new Models\Users();
        $user->id   = 999;
        $user->name = $associativeArray;

        $I->assertEquals(
            [
                'id'   => 999,
                'name' => $associativeArray,
            ],
            $user->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() undefined property with associative
     * array
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14021
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     */
    public function mvcModelUnderscoreSetUndefinedPropertyWithAssociativeArray(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() undefined property with associative array');

        $associativeArray = [
            'id'   => 123,
            'name' => 'My Name',
        ];

        $user                            = new Models\Users();
        $user->whatEverUndefinedProperty = $associativeArray;

        $I->assertEquals(
            [
                'id'   => null,
                'name' => null,
            ],
            $user->toArray()
        );
    }
}
