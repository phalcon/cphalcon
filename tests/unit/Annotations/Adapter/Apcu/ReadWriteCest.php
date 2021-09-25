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

        $sPrefix = 'nova_prefix';
        $sKey    = 'testwrite';

        $oAdapter = new Apcu(
            [
                'prefix'   => $sPrefix,
                'lifetime' => 3600,
            ]
        );

        $oClassAnnotations = $oAdapter->get(
            TestClass::class
        );

        $oAdapter->write($sKey, $oClassAnnotations);

        $oNewClass = $oAdapter->read('testwrite');

        $I->assertInstanceOf(
            Reflection::class,
            $oNewClass
        );

        // Check APC value with Codecept
        $sKeyAPC = strtolower("_PHAN" . $sPrefix . $sKey);

        $I->seeInApc($sKeyAPC);
        $I->seeInApc($sKeyAPC, $oClassAnnotations);
    }
}
