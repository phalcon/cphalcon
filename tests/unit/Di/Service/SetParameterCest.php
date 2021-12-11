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

use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Di\ServiceInterface;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class SetParameterCest
 *
 * @package Phalcon\Tests\Unit\Di\Service
 */
class SetParameterCest
{
    /**
     * Unit Tests Phalcon\Di\Service :: setParameter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceSetParameter(UnitTester $I)
    {
        $I->wantToTest('Di\Service - setParameter()');

        $service = new Service(
            [
                'className' => Escaper::class,
            ],
            true
        );

        $expected = [
            'className' => Escaper::class,
        ];
        $actual   = $service->getDefinition();
        $I->assertEquals($expected, $actual);

        $actual = $service->setParameter(1, ['one']);

        $class = ServiceInterface::class;
        $I->assertInstanceOf($class, $actual);

        $class = Service::class;
        $I->assertInstanceOf($class, $actual);

        $expected = [
            'className' => Escaper::class,
            'arguments' => [1 => ['one']],
        ];
        $actual   = $service->getDefinition();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Unit Tests Phalcon\Di\Service :: setParameter() - with arguments
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceSetParameterWithArguments(UnitTester $I)
    {
        $I->wantToTest('Di\Service - setParameter() - with arguments');

        $service = new Service(
            [
                'className' => Escaper::class,
                'arguments' => [
                    0 => ['one'],
                ],
            ],
            true
        );

        $expected = [
            'className' => Escaper::class,
            'arguments' => [
                0 => ['one'],
            ],
        ];
        $actual   = $service->getDefinition();
        $I->assertEquals($expected, $actual);

        $service->setParameter(0, ['seven']);

        $expected = [
            'className' => Escaper::class,
            'arguments' => [0 => ['seven']],
        ];
        $actual   = $service->getDefinition();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Unit Tests Phalcon\Di\Service :: setParameter() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceSetParameterException(UnitTester $I)
    {
        $I->wantToTest('Di\Service - setParameter() - exception');

        $I->expectThrowable(
            new Exception(
                'Definition must be an array to update its parameters'
            ),
            function () {
                $service = new Service(Escaper::class);
                $service->setParameter(1, [1]);
            }
        );
    }
}
