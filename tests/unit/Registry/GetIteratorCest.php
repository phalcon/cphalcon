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
 * Class GetIteratorCest
 */
class GetIteratorCest
{
    /**
     * Tests Phalcon\Registry :: getIterator()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionGetIterator(UnitTester $I)
    {
        $I->wantToTest('Registry - getIterator()');
        $data     = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $registry = new Registry($data);

        foreach ($registry as $key => $value) {
            $I->assertEquals($data[$key], $registry[$key]);
        }
    }
}
