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

namespace Phalcon\Test\Unit\Debug;

use UnitTester;

/**
 * Class SetUriCest
 */
class SetUriCest
{
    /**
     * Tests Phalcon\Debug :: setUri()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugSetUri(UnitTester $I)
    {
        $I->wantToTest('Debug - setUri()');
        $I->skipTest('Need implementation');
    }
}
