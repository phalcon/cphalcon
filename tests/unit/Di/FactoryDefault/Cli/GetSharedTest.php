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

namespace Phalcon\Tests\Unit\Di\FactoryDefault\Cli;

use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Encryption\Crypt;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSharedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliGetShared(): void
    {
        $di = new Di();

        // check non shared service
        $di->set('escaper', Escaper::class);
        $actual = $di->getShared('escaper');

        $this->assertInstanceOf(Escaper::class, $actual);

        $expected = new Escaper();
        $this->assertEquals($expected, $actual);

        // check shared service
        $di->set('crypt', Crypt::class, true);
        $actual = $di->getShared('crypt');

        $this->assertInstanceOf(Crypt::class, $actual);

        $actual   = $di->getShared('crypt');
        $expected = new Crypt();

        $this->assertEquals($expected, $actual);
    }
}
