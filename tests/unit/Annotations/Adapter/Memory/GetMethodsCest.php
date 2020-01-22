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

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Collection;
use TestClass;
use UnitTester;

use function dataDir;

class GetMethodsCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Memory :: getMethods()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAdapterMemoryGetMethods(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Memory - getMethods()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $oAdapter = new Memory();

        $aMethodAnnotations = $oAdapter->getMethods(
            TestClass::class
        );

        $aKeys = array_keys($aMethodAnnotations);
        $I->assertEquals(
            [
                'testMethod1',
                'testMethod3',
                'testMethod4',
                'testMethod5',
            ],
            $aKeys
        );

        foreach ($aMethodAnnotations as $oMethodAnnotation) {
            $I->assertInstanceOf(
                Collection::class,
                $oMethodAnnotation
            );
        }

        $I->safeDeleteFile('testclass.php');
    }
}
