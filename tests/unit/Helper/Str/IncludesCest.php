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

namespace Phalcon\Tests\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class IncludesCest
{
    /**
     * Tests Phalcon\Helper\Str :: includes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrIncludes(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - includes()');

        $source = 'Mary had a little lamb';
        $actual = Str::includes('lamb', $source);
        $I->assertTrue($actual);

        $actual = Str::includes('unknown', $source);
        $I->assertFalse($actual);

        $actual = Str::includes('Mary', $source);
        $I->assertTrue($actual);
    }
}
