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

use Phalcon\Support\Collection\ReadOnly;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Support\Collection\ReadOnly :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionConstruct(UnitTester $I)
    {
        $I->wantToTest('Support\Collection\ReadOnly - __construct()');
        $collection = new ReadOnly();

        $class = ReadOnly::class;
        $I->assertInstanceOf($class, $collection);
    }
}
