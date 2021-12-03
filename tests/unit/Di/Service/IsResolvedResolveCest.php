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

use Phalcon\Di;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class ResolveCest
 *
 * @package Phalcon\Tests\Unit\Di\Service
 */
class IsResolvedResolveCest
{
    /**
     * Unit Tests Phalcon\Di\Service :: isResolved()/resolve()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceIsResolvedResolve(UnitTester $I)
    {
        $I->wantToTest('Di\Service - isResolved()/resolve()');

        $container = new Di();

        $container->set(
            'resolved',
            function () {
                return new Escaper();
            }
        );

        $container->set(
            'notResolved',
            function () {
                return new Escaper();
            }
        );

        $actual = $container->getService('resolved')->isResolved();
        $I->assertFalse($actual);

        $actual = $container->getService('notResolved')->isResolved();
        $I->assertFalse($actual);

        $container->get('resolved');

        $actual = $container->getService('resolved')->isResolved();
        $I->assertTrue($actual);

        $actual = $container->getService('notResolved')->isResolved();
        $I->assertFalse($actual);

        $container->getService('notResolved')->resolve();

        $actual = $container->getService('notResolved')->isResolved();
        $I->assertTrue($actual);
    }
}
