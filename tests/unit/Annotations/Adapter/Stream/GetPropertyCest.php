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

use function dataDir;
use function outputDir;

class GetPropertyCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Stream :: getProperty()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterStreamGetProperty(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Stream - getProperty()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $adapter = new Stream(
            [
                'annotationsDir' => outputDir('tests/annotations/'),
            ]
        );

        $propertyAnnotation = $adapter->getProperty(
            TestClass::class,
            'testProp1'
        );

        $I->assertInstanceOf(
            Collection::class,
            $propertyAnnotation
        );

        $I->safeDeleteFile('testclass.php');
    }
}
