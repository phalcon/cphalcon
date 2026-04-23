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

namespace Phalcon\Tests\Unit\Di\Service;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class IsResolvedResolveTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceIsResolvedResolve(): void
    {
        $container = new Di();

        $container->set(
            'resolved',
            function () {
                return new Escaper();
            }
        );

        $container->set(
            'notResolved',
            function () {
                return new Escaper();
            }
        );

        $actual = $container->getService('resolved')
                            ->isResolved()
        ;
        $this->assertFalse($actual);

        $actual = $container->getService('notResolved')
                            ->isResolved()
        ;
        $this->assertFalse($actual);

        $container->get('resolved');

        $actual = $container->getService('resolved')
                            ->isResolved()
        ;
        $this->assertTrue($actual);

        $actual = $container->getService('notResolved')
                            ->isResolved()
        ;
        $this->assertFalse($actual);

        $container->getService('notResolved')
                  ->resolve()
        ;

        $actual = $container->getService('notResolved')
                            ->isResolved()
        ;
        $this->assertTrue($actual);
    }
}
