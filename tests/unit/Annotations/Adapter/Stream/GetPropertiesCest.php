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

namespace Phalcon\Test\Unit\Annotations\Adapter\Stream;

use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Annotations\Collection;
use TestClass;
use UnitTester;

use function array_keys;
use function dataDir;
use function outputDir;

class GetPropertiesCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Stream :: getProperties()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterStreamGetProperties(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Stream - getProperties()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $adapter = new Stream(
            [
                'annotationsDir' => outputDir('tests/annotations/'),
            ]
        );

        $propertyAnnotations = $adapter->getProperties(
            TestClass::class
        );

        $keys = array_keys($propertyAnnotations);
        $I->assertEquals(
            [
                'testProp1',
                'testProp3',
                'testProp4',
            ],
            $keys
        );

        foreach ($propertyAnnotations as $key => $propertyAnnotation) {
            $I->assertInstanceOf(
                Collection::class,
                $propertyAnnotation
            );
        }

        $I->safeDeleteFile('testclass.php');
    }
}
