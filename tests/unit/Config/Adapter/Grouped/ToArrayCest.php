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

namespace Phalcon\Test\Unit\Config\Adapter\Grouped;

use UnitTester;

class ToArrayCest
{
    /**
     * Tests Phalcon\Config\Adapter\Grouped :: toArray()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterGroupedToArray(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Grouped - toArray()');

        $I->skipTest('Need implementation');
    }
}
