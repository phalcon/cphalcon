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

namespace Phalcon\Tests\Unit\Collection\ReadOnly;

use Phalcon\Collection\Exception;
use Phalcon\Collection\ReadOnly;
use UnitTester;

class RemoveCest
{
    /**
     * Tests Phalcon\Collection\ReadOnly :: remove()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionRemove(UnitTester $I)
    {
        $I->wantToTest('ReadOnly - remove()');

        $data       = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $collection = new ReadOnly($data);

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
