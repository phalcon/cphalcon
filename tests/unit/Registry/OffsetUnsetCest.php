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

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class OffsetUnsetCest
{
    /**
     * Unit Tests Phalcon\Registry :: offsetUnset()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function registryOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Registry - offsetUnset()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);



        unset($registry['five']);

        $I->assertEquals(
            [
                'one'   => 'two',
                'three' => 'four',
            ],
            $registry->toArray()
        );



        $registry->offsetUnset('one');

        $I->assertEquals(
            [
                'three' => 'four',
            ],
            $registry->toArray()
        );
    }
}
