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
use TestClass;
use UnitTester;

use function dataDir;

class GetMethodCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Apcu :: getMethod()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAdapterApcuGetMethod(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Apcu - getMethod()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $oAdapter = new Apcu(
            [
                'prefix'   => 'nova_prefix',
                'lifetime' => 3600,
            ]
        );

        $sMethodAnnotation = $oAdapter->getMethod(
            TestClass::class,
            'testMethod1'
        );

        $I->assertInstanceOf(
            Collection::class,
            $sMethodAnnotation
        );
    }
}
