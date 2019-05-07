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

namespace Phalcon\Test\Unit\Storage\Adapter\AbstractAdapter;

use UnitTester;

class HasCest
{
    /**
     * Tests Phalcon\Storage\Adapter\AbstractAdapter :: has()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function storageAdapterAbstractAdapterHas(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\AbstractAdapter - has()');

        $I->skipTest('Need implementation');
    }
}
