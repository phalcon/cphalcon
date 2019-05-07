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

namespace Phalcon\Test\Unit\Http\Request;

use UnitTester;

class IsDeleteCest
{
    /**
     * Tests Phalcon\Http\Request :: isDelete()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpRequestIsDelete(UnitTester $I)
    {
        $I->wantToTest('Http\Request - isDelete()');

        $I->skipTest('Need implementation');
    }
}
