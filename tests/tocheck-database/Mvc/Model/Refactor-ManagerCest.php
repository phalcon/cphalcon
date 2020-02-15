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
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\Row;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Relations\RobotsParts;

class ManagerCest
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
     * Tests model source from different classes
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-06
     */
    public function testModelSourceShouldBeTheSame(IntegrationTester $I)
    {
        $manager = new Manager();

        $robots = new People(null, null, $manager);

        $I->assertEquals(
            'personas',
            $robots->getSource()
        );

        $I->assertEquals(
            'personas',
            $robots->getModelsManager()->getModelSource($robots)
        );
    }

    /**
     * Tests Model::getRelated with the desired fields
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12972
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-10-02
     */
    public function shouldReturnDesiredFieldsFromRelatedModel(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check test');

        $parts = RobotsParts::findFirst();

        $robot = $parts->getRobots();

        $I->assertInstanceOf(
            Row::class,
            $robot
        );

        $I->assertEquals(
            [
                'id'   => 1,
                'name' => 'Robotina',
            ],
            $robot->toArray()
        );

        $robot = $parts->getRobots(
            [
                'columns' => 'id,type,name',
            ]
        );

        $I->assertInstanceOf(
            Row::class,
            $robot
        );

        $I->assertEquals(
            [
                'id'   => 1,
                'type' => 'mechanical',
                'name' => 'Robotina',
            ],
            $robot->toArray()
        );
    }
}
