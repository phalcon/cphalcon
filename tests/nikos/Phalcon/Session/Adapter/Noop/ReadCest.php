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

namespace Phalcon\Test\Unit\Session\Adapter\Noop;

use UnitTester;

class ReadCest
{
    /**
     * Tests Phalcon\Session\Adapter\Noop :: read()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function sessionAdapterNoopRead(UnitTester $I)
    {
        $I->wantToTest('Session\Adapter\Noop - read()');

        $I->skipTest('Need implementation');
    }
}
