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

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;
use TestClass;
use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Apcu :: get()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAdapterApcuGet(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Apcu - get()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $oAdapter = new Apcu(
            [
                'prefix'   => 'nova_prefix',
                'lifetime' => 3600,
            ]
        );

        $oClassAnnotations = $oAdapter->get(
            TestClass::class
        );

        $I->assertInternalType('object', $oClassAnnotations);

        $I->assertInstanceOf(
            Reflection::class,
            $oClassAnnotations
        );

        $I->assertInstanceOf(
            Collection::class,
            $oClassAnnotations->getClassAnnotations()
        );
    }
}
