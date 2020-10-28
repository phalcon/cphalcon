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

namespace Phalcon\Test\Unit\Collection\ReadOnly;

use Phalcon\Collection\Exception;
use Phalcon\Collection\ReadOnly;
use UnitTester;

class SetCest
{
    /**
     * Tests Phalcon\Collection\ReadOnly :: set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionSet(UnitTester $I)
    {
        $I->wantToTest('ReadOnly - set()');

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection = new ReadOnly();
                $collection->set('three', 123);
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection        = new ReadOnly();
                $collection->three = 'Phalcon';
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection = new ReadOnly();
                $collection->offsetSet('three', 123);
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection          = new ReadOnly();
                $collection['three'] = true;
            }
        );
    }
}
