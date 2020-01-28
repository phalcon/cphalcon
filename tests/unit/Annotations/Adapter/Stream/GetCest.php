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
use Phalcon\Annotations\Reflection;
use TestClass;
use UnitTester;

use function dataDir;
use function outputDir;

class GetCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Stream :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterStreamGet(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Stream - get()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $adapter = new Stream(
            [
                'annotationsDir' => outputDir('tests/annotations/'),
            ]
        );


        $classAnnotations = $adapter->get(
            TestClass::class
        );

        $I->assertInternalType('object', $classAnnotations);

        $I->assertInstanceOf(
            Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            Collection::class,
            $classAnnotations->getClassAnnotations()
        );

        $I->safeDeleteFile('testclass.php');
    }
}
