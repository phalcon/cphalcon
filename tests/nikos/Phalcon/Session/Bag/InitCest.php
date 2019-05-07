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

namespace Phalcon\Test\Unit\Session\Bag;

use UnitTester;

class InitCest
{
    /**
     * Tests Phalcon\Session\Bag :: init()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function sessionBagInit(UnitTester $I)
    {
        $I->wantToTest('Session\Bag - init()');

        $I->skipTest('Need implementation');
    }
}
