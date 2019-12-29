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

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use UnitTester;

class GetDefaultCest
{
    /**
     * Unit Tests Phalcon\Di\FactoryDefault :: getDefault()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diFactoryDefaultGetDefault(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault - getDefault()');

        $I->skipTest('Need implementation');
    }
}
