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

use Phalcon\Collection\ReadCollection;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Collection :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionConstruct(UnitTester $I)
    {
        $I->wantToTest('Collection - __construct()');
        $collection = new ReadCollection();

        $class = ReadCollection::class;
        $I->assertInstanceOf($class, $collection);
    }
}
