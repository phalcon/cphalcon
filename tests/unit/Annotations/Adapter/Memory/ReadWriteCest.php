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
use Phalcon\Annotations\Reflection;
use TestClass;
use UnitTester;

use function dataDir;

class ReadWriteCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Memory :: read() / write()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterMemoryReadWrite(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Memory - read() / write()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $oAdapter = new Memory();

        $oClassAnnotations = $oAdapter->get(
            TestClass::class
        );

        $oAdapter->write('testwrite', $oClassAnnotations);

        $oNewClass = $oAdapter->read('testwrite');

        $I->assertInstanceOf(
            Reflection::class,
            $oNewClass
        );
    }
}
