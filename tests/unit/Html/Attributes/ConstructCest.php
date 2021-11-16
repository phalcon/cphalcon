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

namespace Phalcon\Tests\Unit\Html\Attributes;

use Phalcon\Support\Collection;
use Phalcon\Html\Attributes;
use UnitTester;

class ConstructCest
{
    /**
     * Unit Tests Phalcon\Html\Attributes :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function htmlAttributesConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - __construct()');

        $attributes = new Attributes();
        $I->assertInstanceOf(Attributes::class, $attributes);
        $I->assertInstanceOf(Collection::class, $attributes);
    }
}
