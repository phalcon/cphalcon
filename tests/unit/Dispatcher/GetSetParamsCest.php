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

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Mvc\Dispatcher;
use Phalcon\Tests\Controllers\DispatcherParametersController;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

class GetSetParamsCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Dispatcher :: getParams()/setParams
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function dispatcherGetParams(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getParams()/setParams()');

        $dispatcher = new Dispatcher();
        $params     = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $actual = $dispatcher->getParams();
        $I->assertEmpty($actual);

        $dispatcher->setParams($params);

        $expected = $params;
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Dispatcher :: getParams()/setParams - kept between calls
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function dispatcherGetParamsKeptBetweenCalls(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getParams()/setParams() - kept between calls');

        $this->setNewFactoryDefault();

        $dispatcher = new Dispatcher();
        $dispatcher->setDI($this->container);

        $dispatcher->setControllerSuffix("");
        $dispatcher->setControllerName(DispatcherParametersController::class);

        $actual = $dispatcher->getParams();
        $I->assertEmpty($actual);

        $params     = [
            "trace" => [],
        ];
        $dispatcher->setParams($params);
        $dispatcher->dispatch();

        $expected = [
            "trace" => [
                "beforeExecuteRoute",
                "afterExecuteRoute",
            ],
        ];
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
    }
}
