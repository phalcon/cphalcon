<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Assets\ResourceInterface;
use UnitTester;

trait AssetsTrait
{
    private function resourceGetType(UnitTester $I, ResourceInterface $resource, string $expected)
    {
        $actual = $resource->getType();
        $I->assertEquals($expected, $actual);
    }

    private function resourceGetResourceKey(UnitTester $I, ResourceInterface $resource, string $expected)
    {
        $actual = $resource->getResourceKey();
        $I->assertEquals($expected, $actual);
    }

    private function resourceGetPath(UnitTester $I, ResourceInterface $resource)
    {
        $expected = 'js/jquery.js';
        $actual   = $resource->getPath();
        $I->assertEquals($expected, $actual);
    }

    private function resourceGetLocal(UnitTester $I, ResourceInterface $resource)
    {
        $actual = $resource->getLocal();
        $I->assertTrue($actual);
    }
}
