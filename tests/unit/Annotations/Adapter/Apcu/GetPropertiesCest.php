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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Apcu;

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\Collection;
use TestClass;
use UnitTester;

use function dataDir;

class GetPropertiesCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Apcu :: getProperties()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAdapterApcuGetProperties(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Apcu - getProperties()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $oAdapter = new Apcu(
            [
                'prefix'   => 'nova_prefix',
                'lifetime' => 3600,
            ]
        );

        $aPropertyAnnotations = $oAdapter->getProperties(
            TestClass::class
        );

        $aKeys = array_keys($aPropertyAnnotations);
        $I->assertEquals(
            [
                'testProp1',
                'testProp3',
                'testProp4',
            ],
            $aKeys
        );

        foreach ($aPropertyAnnotations as $oPropertyAnnotation) {
            $I->assertInstanceOf(
                Collection::class,
                $oPropertyAnnotation
            );
        }
    }
}
