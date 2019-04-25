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
 * Class GetPrefixCest
 */
class GetPrefixCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: getPrefix()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamGetPrefix(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - getPrefix()');

        $I->skipTest('Need implementation');
    }
}
