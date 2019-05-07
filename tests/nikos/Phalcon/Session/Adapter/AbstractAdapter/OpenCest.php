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

class OpenCest
{
    /**
     * Tests Phalcon\Session\Adapter\AbstractAdapter :: open()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function sessionAdapterAbstractAdapterOpen(UnitTester $I)
    {
        $I->wantToTest('Session\Adapter\AbstractAdapter - open()');

        $I->skipTest('Need implementation');
    }
}
