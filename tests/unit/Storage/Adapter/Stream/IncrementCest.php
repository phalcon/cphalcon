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

namespace Phalcon\Test\Unit\Storage\Adapter\Stream;

use UnitTester;

/**
 * Class IncrementCest
 */
class IncrementCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: increment()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamIncrement(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - increment()');

        $I->skipTest('Need implementation');
    }
}
