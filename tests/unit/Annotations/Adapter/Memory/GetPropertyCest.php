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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Memory;

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Collection;
use TestClass;
use UnitTester;

class GetPropertyCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Memory :: getProperty()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAdapterMemoryGetProperty(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Memory - getProperty()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $oAdapter = new Memory();

        $oPropertyAnnotations = $oAdapter->getProperty(
            TestClass::class,
            'testProp1'
        );

        $I->assertInstanceOf(
            Collection::class,
            $oPropertyAnnotations
        );
    }
}
