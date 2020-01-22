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

namespace Phalcon\Test\Unit\Annotations\Adapter\Apcu;

use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Annotations\Adapter\Apcu;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Apcu :: __construct()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAdapterApcuConstruct(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Apcu - __construct()');

        $oAdapter = new Apcu(
            [
                'prefix'   => 'nova_prefix',
                'lifetime' => 3600,
            ]
        );

        $I->assertInstanceOf(
            AdapterInterface::class,
            $oAdapter
        );
    }
}
