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

namespace Phalcon\Test\Unit\Mvc\Micro\Collection;

use UnitTester;

/**
 * Class SetHandlerCest
 */
class SetHandlerCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: setHandler()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcMicroCollectionSetHandler(UnitTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - setHandler()');
        $I->skipTest('Need implementation');
    }
}
