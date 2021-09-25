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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Stream;

use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Annotations\Collection;
use TestClass;
use UnitTester;

use function array_keys;
use function dataDir;
use function outputDir;

class GetMethodsCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Stream :: getMethods()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterStreamGetMethods(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Stream - getMethods()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $adapter = new Stream(
            [
                'annotationsDir' => outputDir('tests/annotations/'),
            ]
        );

        $methodAnnotations = $adapter->getMethods(
            TestClass::class
        );

        $keys = array_keys($methodAnnotations);
        $I->assertEquals(
            [
                'testMethod1',
                'testMethod3',
                'testMethod4',
                'testMethod5',
            ],
            $keys
        );

        foreach ($methodAnnotations as $key => $methodAnnotation) {
            $I->assertInstanceOf(
                Collection::class,
                $methodAnnotation
            );
        }

        $I->safeDeleteFile('testclass.php');
    }
}
