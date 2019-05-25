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

namespace Phalcon\Test\Unit\Collection;

use UnitTester;

class UnderscoreSetCest
{
    /**
     * Unit Tests Phalcon\Collection :: __set()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function collectionUnderscoreSet(UnitTester $I)
    {
        $I->wantToTest('Collection - __set()');

        $I->skipTest('Need implementation');
    }
}
