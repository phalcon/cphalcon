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

namespace Phalcon\Test\Unit\Mvc\Micro;

use UnitTester;

/**
 * Class HasServiceCest
 */
class HasServiceCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: hasService()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcMicroHasService(UnitTester $I)
    {
        $I->wantToTest('Mvc\Micro - hasService()');
        $I->skipTest('Need implementation');
    }
}
