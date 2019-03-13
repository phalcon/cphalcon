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

/**
 * Class SerializeCest
 */
class SerializeCest
{
    /**
     * Tests Phalcon\Registry :: serialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionSerialize(UnitTester $I)
    {
        $I->wantToTest('Registry - serialize()');
        $data     = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $registry = new Registry($data);

        $expected = serialize($data);
        $actual   = $registry->serialize();
        $I->assertEquals($expected, $actual);
    }
}
