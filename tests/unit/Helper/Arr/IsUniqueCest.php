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

namespace Phalcon\Test\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

/**
 * Class IsUniqueCest
 */
class IsUniqueCest
{
    /**
     * Tests Phalcon\Helper\Arr :: isUnique()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrIsUnique(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - isUnique()');
        $collection = [
            'Phalcon',
            'Framework',
        ];
        $actual   = Arr::isUnique($collection);
        $I->assertTrue($actual);

        $collection = [
            'Phalcon',
            'Framework',
            'Phalcon',
        ];
        $actual   = Arr::isUnique($collection);
        $I->assertFalse($actual);
    }
}
