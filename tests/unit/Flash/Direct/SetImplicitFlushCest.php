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

namespace Phalcon\Test\Unit\Flash\Direct;

use UnitTester;

class SetImplicitFlushCest
{
    /**
     * Tests Phalcon\Flash\Direct :: setImplicitFlush()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function flashDirectSetImplicitFlush(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - setImplicitFlush()');

        $I->skipTest('Need implementation');
    }
}
