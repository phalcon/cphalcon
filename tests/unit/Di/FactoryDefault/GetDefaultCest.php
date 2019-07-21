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

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use UnitTester;

class GetDefaultCest
{
    /**
     * Unit Tests Phalcon\Di\FactoryDefault :: getDefault()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-13
     */
    public function diFactoryDefaultGetDefault(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault - getDefault()');

        $I->skipTest('Need implementation');
    }
}
