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

namespace Phalcon\Test\Unit\Helper\Str;

use UnitTester;

class EndsWithCest
{
    /**
     * Tests Phalcon\Helper\Str :: endsWith()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function helperStrEndsWith(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - endsWith()');

        $I->skipTest('Need implementation');
    }
}
