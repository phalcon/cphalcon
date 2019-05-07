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

namespace Phalcon\Test\Unit\Session\Adapter\AbstractAdapter;

use UnitTester;

class ReadCest
{
    /**
     * Tests Phalcon\Session\Adapter\AbstractAdapter :: read()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function sessionAdapterAbstractAdapterRead(UnitTester $I)
    {
        $I->wantToTest('Session\Adapter\AbstractAdapter - read()');

        $I->skipTest('Need implementation');
    }
}
