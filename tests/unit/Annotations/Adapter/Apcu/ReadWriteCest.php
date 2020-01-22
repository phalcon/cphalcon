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

namespace Phalcon\Test\Unit\Annotations\Adapter\Apcu;

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\Reflection;
use TestClass;
use UnitTester;

use function dataDir;

class ReadWriteCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Apcu :: read() / write()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterApcuReadWrite(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Apcu - read() / write()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $oAdapter = new Apcu(
            [
                'prefix'   => 'nova_prefix',
                'lifetime' => 3600,
            ]
        );

        $oClassAnnotations = $oAdapter->get(
            TestClass::class
        );

        $oAdapter->write('testwrite', $oClassAnnotations);

        $oNewClass = $oAdapter->read('testwrite');

        $I->assertInstanceOf(
            Reflection::class,
            $oNewClass
        );

        $I->safeDeleteFile('testclass.php');
    }
}
