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

namespace Phalcon\Test\Unit\Html\Attributes;

use UnitTester;

class UnderscoreUnsetCest
{
    /**
     * Unit Tests Phalcon\Html\Attributes :: __unset()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesUnderscoreUnset(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - __unset()');

        $I->skipTest('Need implementation');
    }
}
