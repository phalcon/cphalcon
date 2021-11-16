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
use TestClass;
use UnitTester;

use function dataDir;
use function outputDir;

class WriteCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Stream :: write()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterStreamWrite(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Stream - write()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $adapter = new Stream(
            [
                'annotationsDir' => outputDir('tests/annotations/'),
            ]
        );


        $classAnnotations = $adapter->get(
            TestClass::class
        );

        $adapter->write('testwrite', $classAnnotations);

        $I->assertFileExists(
            outputDir('tests/annotations/testclass.php')
        );

        $I->safeDeleteFile('testwrite.php');
        $I->safeDeleteFile('testclass.php');
    }
}
