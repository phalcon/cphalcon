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

use Phalcon\Crypt;
use Phalcon\Di;
use Phalcon\Escaper;
use UnitTester;

class SetCest
{
    /**
     * Unit Tests Phalcon\Di :: set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diSet(UnitTester $I)
    {
        $I->wantToTest('Di - set()');

        $di = new Di();

        // set non shared service
        $di->set('escaper', Escaper::class);

        $actual = $di->get('escaper');
        $I->assertInstanceOf(Escaper::class, $actual);

        $actual = $di->getService('escaper');
        $I->assertFalse($actual->isShared());

        // set shared service
        $di->set('crypt', Crypt::class, true);

        $actual = $di->get('crypt');
        $I->assertInstanceOf(Crypt::class, $actual);

        $actual = $di->getService('crypt');
        $I->assertTrue($actual->isShared());

        // testing closure
        $returnValue = "Closure Test!";
        $di->set('closure', function () use ($returnValue) {
            return $returnValue;
        });
        $I->assertEquals($returnValue, $di->get('closure'));
    }
}
