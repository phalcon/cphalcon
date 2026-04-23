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

final class GetServicesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliGetServices(): void
    {
        $di = new Di();

        $numberOfFactoryServices = 13;

        $this->assertCount($numberOfFactoryServices, $di->getServices());

        $di->set('newservice', Escaper::class);

        $this->assertCount($numberOfFactoryServices + 1, $di->getServices());

        $di->remove('newservice');
        $this->assertFalse($di->has('newservice'));
        $this->assertCount($numberOfFactoryServices, $di->getServices());
    }
}
