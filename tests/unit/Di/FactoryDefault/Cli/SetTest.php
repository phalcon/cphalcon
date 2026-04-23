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

final class SetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliSet(): void
    {
        $di = new Di();

        // set non shared service
        $di->set('escaper', Escaper::class);

        $actual = $di->get('escaper');
        $this->assertInstanceOf(Escaper::class, $actual);

        $actual = $di->getService('escaper');
        $this->assertFalse($actual->isShared());

        // set shared service
        $di->set('crypt', Crypt::class, true);

        $actual = $di->get('crypt');
        $this->assertInstanceOf(Crypt::class, $actual);

        $actual = $di->getService('crypt');
        $this->assertTrue($actual->isShared());

        // testing closure
        $returnValue = "Closure Test!";
        $di->set('closure', function () use ($returnValue) {
            return $returnValue;
        });
        $this->assertEquals($returnValue, $di->get('closure'));
    }
}
