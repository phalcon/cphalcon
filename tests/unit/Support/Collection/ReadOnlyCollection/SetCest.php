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

use Phalcon\Support\Collection\Exception;
use Phalcon\Support\Collection\ReadOnlyCollection;
use UnitTester;

class SetCest
{
    /**
     * Tests Phalcon\Support\Collection\ReadOnlyCollection :: set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionSet(UnitTester $I)
    {
        $I->wantToTest('Support\Collection\ReadOnlyCollection - set()');

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection = new ReadOnlyCollection();
                $collection->set('three', 123);
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection        = new ReadOnlyCollection();
                $collection->three = 'Phalcon';
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection = new ReadOnlyCollection();
                $collection->offsetSet('three', 123);
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection          = new ReadOnlyCollection();
                $collection['three'] = true;
            }
        );
    }
}
