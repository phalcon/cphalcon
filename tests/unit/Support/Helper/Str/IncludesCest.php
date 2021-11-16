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

use Phalcon\Support\Helper\Str\Includes;
use UnitTester;

/**
 * Class IncludesCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class IncludesCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: includes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrIncludes(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - includes()');

        $object = new Includes();
        $source = 'Mary had a little lamb';
        $actual = $object($source, 'lamb');
        $I->assertTrue($actual);

        $actual = $object($source, 'unknown');
        $I->assertFalse($actual);

        $actual = $object($source, 'Mary');
        $I->assertTrue($actual);
    }
}
