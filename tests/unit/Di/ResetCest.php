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
use UnitTester;

class ResetCest
{
    /**
     * Unit Tests Phalcon\Di :: reset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diReset(UnitTester $I)
    {
        $I->wantToTest('Di - reset()');

        // there is a DI container
        $I->assertInstanceOf(Di::class, Di::getDefault());

        $di = Di::getDefault();

        // delete it
        Di::reset();

        $I->assertNull(Di::getDefault());

        // set it again
        Di::setDefault($di);

        $I->assertInstanceOf(Di::class, Di::getDefault());
    }
}
