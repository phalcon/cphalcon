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

namespace Phalcon\Test\Unit\Cache\Backend\File;

use UnitTester;

/**
 * Class IncrementCest
 */
class IncrementCest
{
    /**
     * Tests Phalcon\Cache\Backend\File :: increment()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function cacheBackendFileIncrement(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\File - increment()');
        $I->skipTest('Need implementation');
    }
}
