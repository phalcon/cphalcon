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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Di\Service;
use Phalcon\Escaper;
use UnitTester;

class RebindersApplyingCest
{
    /**
     * Unit Tests Phalcon\Di :: rebind()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-10
     */
    public function diApplyingRebindersOnNonShared(UnitTester $I)
    {
        $I->wantToTest('Di - applyingRebinders');

        $di = new Di();

        $di->set('someService', function () {
            $std = new \stdClass();
            $std->counter = 0;
            $std->lastRebind = false;
            return $std;
        });

        $di->rebind('someService', function (Di $di, \stdClass $std) {
            $std->counter++;
        });

        $di->rebind('someService', function (Di $di, \stdClass $std) {
            $std->counter++;
        });  

        $di->rebind('someService', function (Di $di, \stdClass $std) {
            $std->lastRebind = true;
        });

        $std = $di->get('someService');

        $expectedCounter = 2;
        $actualCounter   = $std->counter;

        $I->assertSame($expectedCounter, $actualCounter);

        /*
         * Check the integrity of the non shared service by define new rebind on the resolved shared service
         */
        $di->rebind('someService', function (Di $di, \stdClass $std) {
            $std->lastRebind = false;
        });

        $std = $di->get('someService');

        $expectedLastRebind = false;
        $actualLastRebind   = $std->lastRebind;

        $I->assertSame($expectedLastRebind, $actualLastRebind);
    }

    /**
     * Unit Tests Phalcon\Di :: rebind()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-10
     */
    public function diApplyingRebindersOnShared(UnitTester $I)
    {
        $I->wantToTest('Di - applyingRebinders');

        $di = new Di();

        $di->setShared('someService', function () {
            $std = new \stdClass();
            $std->counter = 0;
            $std->lastRebind = true;
            return $std;
        });

        $di->rebind('someService', function (Di $di, \stdClass $std) {
            $std->counter++;
        });

        $di->rebind('someService', function (Di $di, \stdClass $std) {
            $std->counter++;
        });  

        $di->rebind('someService', function (Di $di, \stdClass $std) {
            $std->lastRebind = false;
        });

        $stdViaGet = $std = $di->get('someService');
        $stdViaGetShared  = $di->getShared('someService');

        $I->assertSame($stdViaGet, $stdViaGetShared);

        $expectedCounter = 2;
        $actualCounter   = $std->counter;

        $I->assertSame($expectedCounter, $actualCounter);

        /*
         * Check the integrity of the shared service by define new rebind on the resolved shared service
         */
        $di->rebind('someService', function (Di $di, \stdClass $std) {
            $std->lastRebind = true;
        });

        $std = $di->get('someService');

        $expectedLastRebind = false;
        $actualLastRebind   = $std->lastRebind;

        $I->assertSame($expectedLastRebind, $actualLastRebind);
    }
}
