<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\IsAnagram;
use UnitTester;

/**
 * Class IsAnagramCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class IsAnagramCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: isAnagram()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrIsAnagram(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - isAnagram()');

        $object = new IsAnagram();
        $actual = $object('rail safety', 'fairy tales');
        $I->assertTrue($actual);
    }
}
