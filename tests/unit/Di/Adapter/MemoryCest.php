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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Escaper;
use UnitTester;
use Phalcon\Di\Adapter\Memory;

class MemoryCest
{
    /**
     * Unit Tests Phalcon\Adapter\Memory :: set()
     *
     * @author cq-z <64899484@qq.com>
     * @since  2020-08-01
     */
    public function adapterSet(UnitTester $I)
    {
        $I->wantToTest('Adapter\Memory - set()');

        // setup
        $di = new Di();

        $memory = new Memory();
        // check has di
        $I->assertFalse($memory->has());
        // get di and  it to check
        $I->assertEquals(null, $memory->get());
        $memory->set($di);
        // get di and  it to check
        $I->assertEquals($di, $memory->get());
        // check has di
        $I->assertTrue($memory->has());
    }
}
