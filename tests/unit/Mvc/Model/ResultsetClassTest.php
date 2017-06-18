<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Mvc\Model\Exception;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Resultsets\Stats;
use Phalcon\Test\Models\Statistics;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Test\Models\Statistics\AgeStats;

/**
 * \Phalcon\Test\Unit\Mvc\Model\ResultsetClassTest
 * Tests the Phalcon\Mvc\Model::getResultsetClass() component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Eugene Smirnov <ashpumpkin@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ResultsetClassTest extends UnitTest
{
    /**
     * Checks if resultset class Simple is returned when getResultsetClass() method is not defined
     *
     * @author Eugene Smirnov <ashpumpkin@gmail.com>
     */
    public function testDefaultResultsetClass()
    {
        $this->specify(
            'Find() method should return the default resultset simple class if getResultsetClass() ' .
            'method is not presented in the model',
            function () {
                expect(Statistics\CityStats::find())->isInstanceOf(Simple::class);
            }
        );
    }

    /**
     * Checks if custom resultset object is returned when getResultsetClass() method is presented in model
     *
     * @author Eugene Smirnov <ashpumpkin@gmail.com>
     */
    public function testCustomClassForResultset()
    {
        $this->specify(
            'Find() method should return custom resultset if getResultsetClass() method is presented in model',
            function () {
                expect(AgeStats::find())->isInstanceOf(Stats::class);
            }
        );
    }

    /**
     * Checks if exception is thrown when custom resultset doesn't implement ResultsetInterface
     *
     * @author Eugene Smirnov <ashpumpkin@gmail.com>
     */
    public function testExceptionOnBadInterface()
    {
        $this->specify(
            "Find() method should throw an exception if resultset doesn't implement interface",
            function () {
                Statistics\CountryStats::find();
            },
            ['throws' => [
                Exception::class,
                sprintf(
                    'Resultset class "%s" must be an implementation of %s',
                    AgeStats::class,
                    ResultsetInterface::class
                )
            ]]
        );
    }

    /**
     * Checks if exception is thrown when resultset class doesn\'t exist
     *
     * @author Eugene Smirnov <ashpumpkin@gmail.com>
     */
    public function testExceptionOnUnknownClass()
    {
        $this->specify(
            "Find() method should throw an exception if resultset class doesn't exist",
            function () {
                Statistics\GenderStats::find();
            },
            ['throws' => [
                Exception::class,
                'Resultset class "Not\Existing\Resultset\Class" not found'
            ]]
        );
    }
}
