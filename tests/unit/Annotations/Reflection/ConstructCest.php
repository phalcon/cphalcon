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

namespace Phalcon\Tests\Unit\Annotations\Reflection;

use Phalcon\Annotations\Reflection;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Annotations\Reflection :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-21
     */
    public function annotationsReflectionConstruct(UnitTester $I)
    {
        $I->wantToTest('Annotations\Reflection - __construct()');

        $reflection = new Reflection();

        $I->assertInstanceOf(Reflection::class, $reflection);
    }
}
