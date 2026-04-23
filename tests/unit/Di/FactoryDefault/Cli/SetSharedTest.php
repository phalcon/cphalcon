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
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetSharedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliSetShared(): void
    {
        $di = new Di();

        $di->setShared('escaper', Escaper::class);

        // check shared service
        $actual = $di->getService('escaper');
        $this->assertTrue($actual->isShared());

        $actual = $di->getShared('escaper');
        $this->assertInstanceOf(Escaper::class, $actual);
    }
}
