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
use UnitTester;

class GetSetParamsCest
{
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
            'one' => 'two',
            'three' => 'four',
        ];

        $actual = $dispatcher->getParams();
        $I->assertEmpty($actual);

        $dispatcher->setParams($params);

        $expected = $params;
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
    }
}
