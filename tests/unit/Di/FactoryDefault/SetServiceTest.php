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

namespace Phalcon\Tests\Unit\Di\FactoryDefault;

use Phalcon\Di\FactoryDefault;
use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetServiceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function testDiFactoryDefaultSetRaw(): void
    {
        $container = new FactoryDefault();

        $expected = new Service(Escaper::class);
        $actual   = $container->setService('escaper', $expected);
        $this->assertSame($expected, $actual);
    }
}
