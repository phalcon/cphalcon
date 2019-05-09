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

use Phalcon\Helper\Str;
use UnitTester;

class IsAnagramCest
{
    /**
     * Tests Phalcon\Helper\Str :: isAnagram()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrIsAnagram(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - isAnagram()');

        $actual = Str::isAnagram('rail safety', 'fairy tales');
        $I->assertTrue($actual);
    }
}
