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

use Phalcon\Collection\ReadOnly;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Collection\ReadOnly :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionConstruct(UnitTester $I)
    {
        $I->wantToTest('ReadOnly - __construct()');
        $collection = new ReadOnly();

        $class = ReadOnly::class;
        $I->assertInstanceOf($class, $collection);
    }
}
