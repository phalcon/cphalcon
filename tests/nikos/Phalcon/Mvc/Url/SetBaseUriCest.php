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

namespace Phalcon\Test\Unit\Mvc\Url;

use UnitTester;

/**
 * Class SetBaseUriCest
 */
class SetBaseUriCest
{
    /**
     * Tests Phalcon\Mvc\Url :: setBaseUri()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcUrlSetBaseUri(UnitTester $I)
    {
        $I->wantToTest('Mvc\Url - setBaseUri()');
        $I->skipTest('Need implementation');
    }
}
