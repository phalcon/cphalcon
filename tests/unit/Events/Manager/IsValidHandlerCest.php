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

namespace Phalcon\Tests\Unit\Events\Manager;

use Phalcon\Events\Manager;
use UnitTester;

class IsValidHandlerCest
{
    /**
     * Tests Phalcon\Events\Manager :: isValidHandler()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function eventsManagerIsValidHandler(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - isValidHandler()');

        $manager = new Manager();

        $stringHandler = 'handler';
        $I->assertFalse(
            $manager->isValidHandler($stringHandler)
        );

        $integerHandler = 666;
        $I->assertFalse(
            $manager->isValidHandler($integerHandler)
        );

        $objectHandler = new Manager();
        $I->assertTrue(
            $manager->isValidHandler($objectHandler)
        );

        $callableHandler = [$objectHandler, 'hasListeners'];
        $I->assertTrue(
            $manager->isValidHandler($callableHandler)
        );

        $closureHandler = function () {
            return true;
        };
        $I->assertTrue(
            $manager->isValidHandler($closureHandler)
        );
    }
}
