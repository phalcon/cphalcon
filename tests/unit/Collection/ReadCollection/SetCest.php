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

class SetCest
{
    /**
     * Tests Phalcon\Collection :: set()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionSet(UnitTester $I)
    {
        $I->wantToTest('Collection - set()');

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection = new ReadCollection();
                $collection->set('three', 123);
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection        = new ReadCollection();
                $collection->three = 'Phalcon';
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection = new ReadCollection();
                $collection->offsetSet('three', 123);
            }
        );

        $I->expectThrowable(
            new Exception('The object is read only'),
            function () {
                $collection          = new ReadCollection();
                $collection['three'] = true;
            }
        );
    }
}
