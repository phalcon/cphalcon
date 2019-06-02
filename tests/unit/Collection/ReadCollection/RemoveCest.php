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

namespace Phalcon\Test\Unit\Collection\ReadCollection;

use Phalcon\Collection\Exception;
use Phalcon\Collection\ReadCollection;
use UnitTester;

class RemoveCest
{
    /**
     * Tests Phalcon\ReadCollection :: remove()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionRemove(UnitTester $I)
    {
        $I->wantToTest('ReadCollection - remove()');

        $data       = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $collection = new ReadCollection($data);

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () use ($collection) {
                $collection->remove('five');
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () use ($collection) {
                $collection->remove('FIVE');
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () use ($collection) {
                unset($collection['five']);
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () use ($collection) {
                $collection->__unset('five');
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () use ($collection) {
                $collection->offsetUnset('five');
            }
        );
    }
}
