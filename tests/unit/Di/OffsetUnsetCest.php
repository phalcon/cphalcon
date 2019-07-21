<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Escaper;
use UnitTester;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Di :: offsetUnset()
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
