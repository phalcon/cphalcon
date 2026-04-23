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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-12-16
     */
    public function testFormsFormGetSetDI(): void
    {
        $container = new Di();
        $form      = new Form();

        $class  = FactoryDefault::class;
        $actual = $form->getDI();
        $this->assertInstanceOf($class, $actual);

        $form->setDI($container);

        $expected = $container;
        $actual   = $form->getDI();
        $this->assertSame($expected, $actual);
    }
}
