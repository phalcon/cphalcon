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

namespace Phalcon\Test\Unit\Di\Exception\ServiceResolutionException;

use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Di\Exception\ServiceResolutionException :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function diExceptionServiceResolutionExceptionConstruct(UnitTester $I)
    {
        $I->wantToTest('Di\Exception\ServiceResolutionException - __construct()');
        $I->skipTest('Need implementation');
    }
}
