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

namespace Phalcon\Test\Unit\Di\Exception;

use UnitTester;

class ConstructCest
{
    /**
     * Unit Tests Phalcon\Di\Exception :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-13
     */
    public function diExceptionConstruct(UnitTester $I)
    {
        $I->wantToTest('Di\Exception - __construct()');

        $I->skipTest('Need implementation');
    }
}
