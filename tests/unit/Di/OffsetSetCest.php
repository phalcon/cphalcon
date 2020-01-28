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

class OffsetSetCest
{
    /**
     * Unit Tests Phalcon\Di :: offsetSet()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diOffsetSet(UnitTester $I)
    {
        $I->wantToTest('Di - offsetSet()');

        $di = new Di();

        $di->offsetSet('escaper', Escaper::class);

        $actual = $di->offsetGet('escaper');

        $I->assertInstanceOf(Escaper::class, $actual);

        $di['crypt'] = new Crypt();

        $actual = $di->offsetGet('crypt');

        $I->assertInstanceOf(Crypt::class, $actual);
    }
}
