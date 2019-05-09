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

namespace Phalcon\Test\Unit\Logger\Adapter\Stream;

use UnitTester;

class AddCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: add()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function loggerAdapterStreamAdd(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - add()');

        $I->skipTest('Need implementation');
    }
}
