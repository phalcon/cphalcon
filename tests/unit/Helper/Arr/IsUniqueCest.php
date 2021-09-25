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

namespace Phalcon\Tests\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class IsUniqueCest
{
    /**
     * Tests Phalcon\Helper\Arr :: isUnique()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrIsUnique(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - isUnique()');


        $collection = [
            'Phalcon',
            'Framework',
        ];

        $I->assertTrue(
            Arr::isUnique($collection)
        );


        $collection = [
            'Phalcon',
            'Framework',
            'Phalcon',
        ];

        $I->assertFalse(
            Arr::isUnique($collection)
        );
    }
}
