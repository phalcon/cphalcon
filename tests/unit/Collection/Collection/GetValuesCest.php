<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Collection\Collection;

use Codeception\Example;
use Phalcon\Collection;
use stdClass;
use UnitTester;

class GetValuesCest
{
    /**
     * Tests Phalcon\Collection :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionGetValues(UnitTester $I)
    {
        $I->wantToTest('Collection - getValues()');

        $data = [
            'one'   => 'two',
            'Three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);

        $expected = [
            'two',
            'four',
            'six',
        ];

        $I->assertEquals(
            $expected,
            $collection->getValues(false)
        );
    }
}
