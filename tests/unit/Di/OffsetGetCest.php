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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di;
use Phalcon\Di\Exception;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class OffsetGetCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class OffsetGetCest
{
    /**
     * Unit Tests Phalcon\Di :: offsetGet()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diOffsetGet(UnitTester $I)
    {
        $I->wantToTest('Di - offsetGet()');

        $container = new Di();

        $container->set('escaper', Escaper::class);

        $class  = Escaper::class;
        $actual = $container->offsetGet('escaper');
        $I->assertInstanceOf($class, $actual);

        $actual = $container['escaper'];
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Unit Tests Phalcon\Di :: offsetGet() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diOffsetGetException(UnitTester $I)
    {
        $I->wantToTest('Di - offsetGet() - exception');

        $container = new Di();

        $I->expectThrowable(
            new Exception(
                "Service 'non-exists' was not found " .
                "in the dependency injection container"
            ),
            function () use ($container) {
                $container['non-exists'];
            }
        );

        $I->expectThrowable(
            new Exception(
                "Service 'non-exists' was not found " .
                "in the dependency injection container"
            ),
            function () use ($container) {
                $container->offsetGet('non-exists');
            }
        );
    }
}
