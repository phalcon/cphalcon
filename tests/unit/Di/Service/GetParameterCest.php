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

namespace Phalcon\Tests\Unit\Di\Service;

use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class GetParameterCest
 *
 * @package Phalcon\Tests\Unit\Di\Service
 */
class GetParameterCest
{
    /**
     * Unit Tests Phalcon\Di\Service :: getParameter() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceGetParameterEmpty(UnitTester $I)
    {
        $I->wantToTest('Di\Service - getParameter()');

        $service = new Service(
            [
                'className' => Escaper::class,
                'arguments' => [],
            ],
            false
        );

        $actual = $service->getParameter(1);
        $I->assertNull($actual);
    }

    /**
     * Unit Tests Phalcon\Di\Service :: getParameter() - in position
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceGetParameterInPosition(UnitTester $I)
    {
        $I->wantToTest('Di\Service - getParameter() - in position');

        $service = new Service(
            [
                'className' => Escaper::class,
                'arguments' => [
                    0 => 1,
                    1 => 'two',
                ],
            ]
        );

        $expected = 1;
        $actual   = $service->getParameter(0);
        $I->assertEquals($expected, $actual);

        $expected = 'two';
        $actual   = $service->getParameter(1);
        $I->assertEquals($expected, $actual);

        $actual = $service->getParameter(2);
        $I->assertNull($actual);
    }
}
