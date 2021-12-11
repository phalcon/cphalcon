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

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use UnitTester;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Di\Di :: offsetUnset()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-28
     */
    public function diOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Di - offsetUnset()');

        $di = new Di();

        $escaper = new Escaper();

        $di->set('escaper', $escaper);

        $I->assertTrue(
            $di->has('escaper')
        );

        unset(
            $di['escaper']
        );

        $I->assertFalse(
            $di->has('escaper')
        );
    }
}
