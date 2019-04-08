<?php declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Stock;

/**
 * Class GetModelsCest
 */
class GetModelsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getModels()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-04-8
     */
    public function mvcModelQueryBuilderGetModelsNull(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - getModels() - null');
        $manager = $this->getService('modelsManager');
        $builder = $manager->createBuilder();

        $expected = null;
        $actual   = $builder->getModels();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getModels()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-04-8
     */
    public function mvcModelQueryBuilderGetModelsString(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - getModels() - string');
        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(['Stock' => Stock::class]);

        $expected = 'Phalcon\\Test\\Models\\Stock';
        $actual   = $builder->getModels();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getModels()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-04-8
     */
    public function mvcModelQueryBuilderGetModelsArray(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - getModels() - array');
        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(['Robots' => Robots::class])
            ->addFrom(RobotsParts::class, 'RobotsParts');

        $expected = [
            'Robots'      => 'Phalcon\Test\Models\Robots',
            'RobotsParts' => 'Phalcon\Test\Models\RobotsParts',
        ];
        $actual   = $builder->getModels();
        $I->assertEquals($expected, $actual);
    }
}
