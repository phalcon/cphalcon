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

use Phalcon\Encryption\Crypt;
use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use UnitTester;

class OffsetSetCest
{
    /**
     * Unit Tests Phalcon\Di\Di :: offsetSet()
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
