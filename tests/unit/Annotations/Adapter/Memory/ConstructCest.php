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

namespace Phalcon\Test\Unit\Annotations\Adapter\Memory;

use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Annotations\Adapter\Memory;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Memory :: __construct()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAdapterMemoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Memory - __construct()');
        
        $oAdapter = new Memory();

        $I->assertInstanceOf(
            AdapterInterface::class,
            $oAdapter
        );
    }
}
