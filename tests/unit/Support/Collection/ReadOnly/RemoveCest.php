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

namespace Phalcon\Tests\Unit\Support\Collection\ReadOnly;

use Phalcon\Support\Collection\Exception;
use Phalcon\Support\Collection\ReadOnly;
use UnitTester;

class RemoveCest
{
    /**
     * Tests Phalcon\Support\Collection\ReadOnly :: remove()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionRemove(UnitTester $I)
    {
        $I->wantToTest('Support\Collection\ReadOnly - remove()');

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
