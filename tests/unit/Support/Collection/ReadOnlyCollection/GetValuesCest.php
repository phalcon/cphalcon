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

namespace Phalcon\Tests\Unit\Support\Collection\ReadOnlyCollection;

use Phalcon\Support\Collection\ReadOnlyCollection;
use UnitTester;

class GetValuesCest
{
    /**
     * Tests Phalcon\Support\Collection\ReadOnlyCollection :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionReadOnlyCollectionGetValues(UnitTester $I)
    {
        $I->wantToTest('Support\Collection\ReadOnlyCollection - getValues()');

        $data = [
            'one'   => 'two',
            'Three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadOnlyCollection($data);

        $expected = [
            'two',
            'four',
            'six',
        ];

        $actual = $collection->getValues();
        $I->assertEquals($expected, $actual);
    }
}
