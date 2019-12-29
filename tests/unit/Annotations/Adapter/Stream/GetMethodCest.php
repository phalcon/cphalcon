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

use function dataDir;
use function outputDir;

class GetMethodCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Stream :: getMethod()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterStreamGetMethod(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Stream - getMethod()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $adapter = new Stream(
            [
                'annotationsDir' => outputDir('tests/annotations/'),
            ]
        );

        $methodAnnotation = $adapter->getMethod(
            TestClass::class,
            'testMethod1'
        );

        $I->assertInstanceOf(
            Collection::class,
            $methodAnnotation
        );

        $I->safeDeleteFile('testclass.php');
    }
}
