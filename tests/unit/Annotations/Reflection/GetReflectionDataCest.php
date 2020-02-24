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

namespace Phalcon\Test\Unit\Annotations\Reflection;

use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Reflection;
use UnitTester;

use function dataDir;

class GetReflectionDataCest
{
    /**
     * executed before each test
     */
    protected function _before(UnitTester $I)
    {
        require_once dataDir('fixtures/Annotations/TestClass.php');
    }

    /**
     * Tests Phalcon\Annotations\Reflection :: getReflectionData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-21
     */
    public function annotationsReflectionGetReflectionData(UnitTester $I)
    {
        $I->wantToTest('Annotations\Reflection - getReflectionData()');

        $reader     = new Reader();
        $data       = $reader->parse('TestClass');
        $reflection = new Reflection($data);

        $I->assertEquals($data, $reflection->getReflectionData());
    }
}
