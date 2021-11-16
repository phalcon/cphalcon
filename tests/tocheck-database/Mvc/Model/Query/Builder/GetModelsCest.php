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

namespace Phalcon\Tests\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Robots;
use Phalcon\Tests\Models\RobotsParts;
use Phalcon\Tests\Models\Stock;

class GetModelsCest
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
     * Tests Phalcon\Mvc\Model\Query\Builder :: getModels()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-04-8
     */
    public function mvcModelQueryBuilderGetModelsNull(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - getModels() - null');

        $manager = $this->getService('modelsManager');

        $builder = $manager->createBuilder();

        $I->assertNull(
            $builder->getModels()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getModels()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-04-8
     */
    public function mvcModelQueryBuilderGetModelsString(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - getModels() - string');

        $manager = $this->getService('modelsManager');

        $builder = $manager
            ->createBuilder()
            ->from(['Stock' => Stock::class])
        ;

        $expected = \Phalcon\Tests\Models\Stock::class;
        $actual   = $builder->getModels();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getModels()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-04-8
     */
    public function mvcModelQueryBuilderGetModelsArray(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - getModels() - array');

        $manager = $this->getService('modelsManager');

        $builder = $manager
            ->createBuilder()
            ->from(['Robots' => Robots::class])
            ->addFrom(RobotsParts::class, 'RobotsParts')
        ;

        $expected = [
            'Robots'      => \Phalcon\Tests\Models\Robots::class,
            'RobotsParts' => \Phalcon\Tests\Models\RobotsParts::class,
        ];
        $actual   = $builder->getModels();
        $I->assertEquals($expected, $actual);
    }
}
