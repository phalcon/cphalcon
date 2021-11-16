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

use IntegrationTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Statistics\AgeStats;
use Phalcon\Tests\Models\Statistics\CityStats;
use Phalcon\Tests\Models\Statistics\CountryStats;
use Phalcon\Tests\Models\Statistics\GenderStats;
use Phalcon\Tests\Resultsets\Stats;

class ResultsetClassCest
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
     * Checks if resultset class Simple is returned when getResultsetClass()
     * method is not defined
     *
     * @author Eugene Smirnov <ashpumpkin@gmail.com>
     */
    public function testDefaultResultsetClass(IntegrationTester $I)
    {
        $I->assertInstanceOf(
            Simple::class,
            CityStats::find()
        );
    }

    /**
     * Checks if custom resultset object is returned when getResultsetClass()
     * method is presented in model
     *
     * @author Eugene Smirnov <ashpumpkin@gmail.com>
     */
    public function testCustomClassForResultset(IntegrationTester $I)
    {
        $I->assertInstanceOf(
            Stats::class,
            AgeStats::find()
        );
    }

    /**
     * Checks if exception is thrown when custom resultset doesn't implement
     * ResultsetInterface
     *
     * @author Eugene Smirnov <ashpumpkin@gmail.com>
     */
    public function testExceptionOnBadInterface(IntegrationTester $I)
    {
        $I->expectThrowable(
            new Exception(
                'Resultset class "Phalcon\Tests\Models\Statistics\AgeStats" must ' .
                'be an implementation of Phalcon\Mvc\Model\ResultsetInterface'
            ),
            function () {
                CountryStats::find();
            }
        );
    }

    /**
     * Checks if exception is thrown when resultset class doesn\'t exist
     *
     * @author Eugene Smirnov <ashpumpkin@gmail.com>
     */
    public function testExceptionOnUnknownClass(IntegrationTester $I)
    {
        $I->expectThrowable(
            new Exception('Resultset class "Not\Existing\Resultset\Class" not found'),
            function () {
                GenderStats::find();
            }
        );
    }
}
