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
use Phalcon\Http\Request;

class GetRebindersCest
{
    /**
     * Unit Tests Phalcon\Di :: getRebinders()
     *
     * @author Timur Flush <https://github.com/TimurFlush>
     * @since  2020-02-10
     */
    public function diGetRebindersWithKey(UnitTester $I)
    {
        $I->wantToTest('Di - getRebinders() with key');

        $di = new Di();

        $di->set('request', 'definition');

        $expected1 = function (Di $di, Request $service) {
            $service->setStrictHostCheck(true);
        };

        $expected2 = function (Di $di, Request $service) {
            $service->setStrictHostCheck(false);
        };

        $di->rebind('request', $expected1);
        $di->rebind('request', $expected2);

        $list = $di->getRebinders('request');

        foreach ($list as $key => $actual) {
            if ($key === 0) {
                $I->assertSame($expected1, $actual);
            } elseif ($key === 1) {
                $I->assertSame($expected2, $actual);
            }
        }
    }

    /**
     * Unit Tests Phalcon\Di :: getRebinders()
     *
     * @author Timur Flush <https://github.com/TimurFlush>
     * @since  2020-02-10
     */
    public function diGetRebindersWithoutKey(UnitTester $I)
    {
        $I->wantToTest('Di - getRebinders() without key');

        $di = new Di();

        $di->set('request', 'definition');

        $expected1 = function (Di $di, Request $service) {
            $service->setStrictHostCheck(false);
        };

        $expected2 = function (Di $di, Request $service) {
            $service->setStrictHostCheck(true);
        };

        $di->rebind('request', $expected1);
        $di->rebind('request', $expected2);

        $list = $di->getRebinders()['request'];

        foreach ($list as $key => $actual) {
            if ($key === 0) {
                $I->assertSame($expected1, $actual);
            } elseif ($key === 1) {
                $I->assertSame($expected2, $actual);
            }
        }
    }

    /**
     * Unit Tests Phalcon\Di :: getRebinders()
     *
     * @author Timur Flush <https://github.com/TimurFlush>
     * @since  2020-02-10
     */
    public function diGetRebindersIfServiceNotExists(UnitTester $I)
    {
        $I->wantToTest('Di - getRebinders() if service does not exist');

        $di = new Di();

        $di->set('request', 'definition');
        $di->set('response', 'definition');

        $di->rebind('request', function () {});
        $di->rebind('response', function () {});

        $rebinders = $di->getRebinders();


        $I->assertTrue(
            is_array($rebinders) && empty($rebinders)
        );
    }
}
